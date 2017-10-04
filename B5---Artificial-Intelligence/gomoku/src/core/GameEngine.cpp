//
//  GameEngine.cpp
//  gomoku
//
//  Created by Fabien Martinez on 12/10/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <QtWidgets>
#include <QAction>
#include <include/arbiter/Map.h>
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Stats.h"
#include "Wallpaper.h"
#include "Error.hpp"
#include "GameEngine.h"
#include "IntroState.h"
#include "ui_stats.h"

GameEngine::GameEngine(Arbiter *arbiter) : m_arbiter(arbiter),
                           m_ai(false), m_ai_turn(false){
    try {
        setupUi(this);
        this->playerOneStats = new Stats(this->playerOne);
        this->playerTwoStats = new Stats(this->playerTwo);
        playerTwoStats->setLabel();
        this->initMap();
        connect(this->quitMenu, SIGNAL(triggered()), this, SLOT(on_quitBtn_clicked()));
        this->isSave = false;
    } catch (ErrorGomoku const &e) {
        throw ErrorGomoku(e.what(), "GameEngine");
    }
}

GameEngine::~GameEngine() {
}

void GameEngine::initMap() {
    try {
        this->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        this->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        QTableWidgetItem *item = new QTableWidgetItem("");
        for (int i = 0; i < 19; i++) { for (int j = 0; j < 19; j++) { this->tableWidget->setItem(i, j, new QTableWidgetItem(*item)); } }
        QPalette *palette = new QPalette();
        palette->setBrush(QPalette::Base, *(new QBrush(QPixmap("./assets/gomoku.png").scaled(this->tableWidget->columnWidth(1) * 19,
                                                                                                                       this->tableWidget->rowHeight(1) * 19,
                                                                                                                       Qt::IgnoreAspectRatio, Qt::FastTransformation))));
        this->tableWidget->setPalette(*palette);
    } catch (ErrorGomoku const &e) {
        throw ErrorGomoku(e.what(), "GameEngine");
    }
}

void GameEngine::init() {
    std::string str;
    str = ((std::string)(this->m_arbiter->isFirstRuleEnabled() ? "1" : "0")) + " " + ((std::string)(this->m_arbiter->isSecondRuleEnabled() ? "1" : "0"));
    std::cout << std::boolalpha << "Ai: " << this->m_ai << std::endl;
    std::cout << "Difficulty: " << this->m_difficulty << std::endl;
    std::cout << std::boolalpha << "FirstRule : " << this->m_arbiter->isFirstRuleEnabled() << std::endl;
    std::cout << std::boolalpha << "SecondRule : " << this->m_arbiter->isSecondRuleEnabled() << std::endl;
    this->actionFirst_Rule->setChecked(this->m_arbiter->isFirstRuleEnabled());
    this->actionSecond_Rule->setChecked(this->m_arbiter->isSecondRuleEnabled());
    if (this->isSave && this->pathToFile != "") {
        std::cout << this->pathToFile << std::endl;
        this->save.open(this->pathToFile.c_str(), std::fstream::out);
        if (open(this->pathToFile.c_str(), O_RDWR | O_CREAT, S_IRUSR) != -1)
            this->save.is_open();
    }
    if (this->m_ai)
        this->m_artificial = new AI(this->m_arbiter);
    this->writeSave(str);
    this->actionNormal->setEnabled(this->m_ai);
    this->actionHard->setEnabled(this->m_ai);
}

void GameEngine::setAi(bool myBool) {
    this->m_ai = myBool;
};

void GameEngine::setSave(bool save){
    this->isSave = save;
}

void GameEngine::setDifficulty(t_difficulty myDifficulty) {
    if (this->m_artificial == NULL)
        this->m_artificial = new AI(this->m_arbiter, myDifficulty);
    else
        this->m_artificial->changeDifficulty(myDifficulty);
};

void GameEngine::on_quitBtn_clicked() {
    this->close();
}

void GameEngine::on_tableWidget_cellClicked(int x, int y){
    QMessageBox messageBox;
    int myCase = this->m_arbiter->playAMove(x, y);
    std::string writeTmp = ((this->m_arbiter->getCurrentPlayer() == 1) ? "B" : "W");
    this->writeSave(writeTmp + " " + this->toString(x) + " " + this->toString(y));
    this->updateMap(this->m_arbiter->getBoard()->getCellsToUpdate());
    this->updateInfoClick(x, y);
    switch(myCase) {
        case STATE_PLAYING:
            this->m_arbiter->getBoard()->cleanMapUpdate();
            if (!this->m_arbiter->isSamePlayer() && this->m_ai) this->playAI();
            break;
        case STATE_WINNER_1:
            this->m_ai = false;
            messageBox.setWindowTitle(QString::fromStdString("WE GOT A WINNER!\n"));
            messageBox.setText(QString::fromStdString("First Player won (WHITE)!"));
            messageBox.setStandardButtons(QMessageBox::Ok);
            if (messageBox.exec() == QMessageBox::Ok)
                on_newMenu_triggered();
            this->writeSave("");
            this->writeSave("Player 1 won");
            this->cleanMap();
            break;
        case STATE_WINNER_2:
            this->m_ai = false;
            messageBox.setWindowTitle(QString::fromStdString("WE GOT A WINNER!\n"));
            messageBox.setText(QString::fromStdString((this->m_ai) ? "AI won (BLACK)!" : "Second Player won (BLACK)!"));
            messageBox.setStandardButtons(QMessageBox::Ok);
            if (messageBox.exec() == QMessageBox::Ok)
                on_newMenu_triggered();
            this->writeSave("");
            this->writeSave("Player 2 won");
            this->cleanMap();
            break;
    }
}

void GameEngine::playAI() {
    QMessageBox messageBox;
    int pos = this->m_artificial->play();
    this->playerTwoStats->setTimer(this->m_artificial->getTimer() + " ms");
    int x = pos % WIDTH_BOARD;
    int y = pos / WIDTH_BOARD;
    int myCase = this->m_arbiter->playAMove(pos % WIDTH_BOARD, pos / WIDTH_BOARD);
    std::string writeTmp = ((this->m_arbiter->getCurrentPlayer() == 1) ? "B" : "W");
    this->writeSave(writeTmp + " " + this->toString(x) + " " + this->toString(y));
    this->updateMap(this->m_arbiter->getBoard()->getCellsToUpdate());
    this->updateInfoClick(x, y);
    switch(myCase){
        case STATE_PLAYING:
            this->m_arbiter->getBoard()->cleanMapUpdate();
            break;
        case STATE_WINNER_1:
            messageBox.setWindowTitle(QString::fromStdString("WE GOT A WINNER!\n"));
            messageBox.setText(QString::fromStdString("First Player won (WHITE)!"));
            messageBox.setStandardButtons(QMessageBox::Ok);
            if (messageBox.exec() == QMessageBox::Ok)
                on_newMenu_triggered();
            this->writeSave("");
            this->writeSave("Player 1 won");
            this->cleanMap();
            break;
        case STATE_WINNER_2:
            messageBox.setWindowTitle(QString::fromStdString("WE GOT A WINNER!\n"));
            messageBox.setText(QString::fromStdString((this->m_ai) ? "AI won (BLACK)!" : "Second Player won (BLACK)!"));
            messageBox.setStandardButtons(QMessageBox::Ok);
            if (messageBox.exec() == QMessageBox::Ok)
                on_newMenu_triggered();
            this->writeSave("");
            this->writeSave("Player 2 won");
            this->cleanMap();
            break;
    }
}

void GameEngine::updateInfoClick(int x, int y){
    QPixmap pixmap;
    switch (this->m_arbiter->getCurrentPlayer()){
        case CASE_WHITE:
            pixmap.load(QString("./assets/white.png"));
            break;
        case CASE_BLACK:
            pixmap.load(QString("./assets/black.png"));
            break;
    }
    if (pixmap.isNull())
        throw ErrorGomoku("QPixmap is null", "GameEngine");
    this->currentPlayer->setPixmap(pixmap.scaled(pixmap.width(),
                                                 this->currentPlayer->height(),
                                                 Qt::IgnoreAspectRatio, Qt::FastTransformation));
    this->playerOneStats->setStoneStole(this->toString(this->m_arbiter->getStonesStole(1)));
    this->playerTwoStats->setStoneStole(this->toString(this->m_arbiter->getStonesStole(2)));
    this->xValue->setText(QString::fromStdString(this->toString(x)));
    this->yValue->setText(QString::fromStdString(this->toString(y)));
}

QTableWidget &GameEngine::getTableWidget() {
    return (*this->tableWidget);
}

void GameEngine::cleanMap(){
    this->m_arbiter->resetGame();
    QPixmap  pixmap;
    pixmap.load(QString("./assets/opac.png"));
    if (pixmap.isNull())
        throw ErrorGomoku("QPixmap is null", "GameEngine");
    QBrush brush(pixmap.scaled(this->tableWidget->columnWidth(1),
                               this->tableWidget->rowHeight(1),
                               Qt::IgnoreAspectRatio, Qt::FastTransformation));
    for (int x = 0; x < 19 ; x++)
        for (int y = 0; y < 19 ; y++)
            this->tableWidget->item(x, y)->setBackground(brush);
}

void GameEngine::updateMap(std::map<t_point*, int> cells){
    QPixmap  pixmap;
    for (std::map<t_point*, int>::iterator it = cells.begin(); it != cells.end();++it){
        switch (it->second){
            case CASE_EMPTY:
                pixmap.load(QString("./assets/opac.png"));
                break;
            case CASE_WHITE:
                pixmap.load(QString("./assets/white.png"));
                break;
            case CASE_BLACK:
                pixmap.load(QString("./assets/black.png"));
                break;
        }
        if (pixmap.isNull())
            throw ErrorGomoku("QPixmap is null", "GameEngine");
        QBrush brush(pixmap.scaled(this->tableWidget->columnWidth(1),
                                   this->tableWidget->rowHeight(1),
                                   Qt::IgnoreAspectRatio, Qt::FastTransformation));
        this->tableWidget->item(it->first->x, it->first->y)->setBackground(brush);
    }
}

std::string GameEngine::toString(int number){
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

void GameEngine::on_actionFirst_Rule_triggered(){
    this->m_arbiter->setFirstRule(!this->m_arbiter->isSecondRuleEnabled());
}

void GameEngine::on_actionSecond_Rule_triggered(){
    this->m_arbiter->setSecondRule(!this->m_arbiter->isSecondRuleEnabled());
}

void GameEngine::on_newMenu_triggered() {
    IntroState *intro = new IntroState(0, this, this->m_arbiter);

    switch (intro->exec()) {
        case QDialog::Accepted:
            this->updateInfo();
            this->cleanMap();
            break;
        default:
            this->close();
            break;
    }

    intro->close();
    delete intro;
}

void GameEngine::updateInfo(){
    QPixmap  pixmap;
    pixmap.load(QString("./assets/opac.png"));
    if (pixmap.isNull())
        throw ErrorGomoku("QPixmap is null", "GameEngine");
    QBrush brush(pixmap.scaled(this->tableWidget->columnWidth(1),
                               this->tableWidget->rowHeight(1),
                               Qt::IgnoreAspectRatio, Qt::FastTransformation));
    this->actionFirst_Rule->setChecked(this->m_arbiter->isFirstRuleEnabled());
    this->actionSecond_Rule->setChecked(this->m_arbiter->isSecondRuleEnabled());
    for (int i = 0; i < 19; i++) { for (int j = 0; j < 19; j++) { this->tableWidget->item(i, j)->setBackground(brush); } }
    this->playerOneStats->setStoneStole("0");
    this->playerTwoStats->setStoneStole("0");
    this->actionNormal->setEnabled(this->m_ai);
    this->actionHard->setEnabled(this->m_ai);

}

void GameEngine::writeSave(std::string str){
    if (this->isSave && this->pathToFile != "")
        this->save << str << std::endl;
}

void GameEngine::setPathToFile(std::string str) {
    this->pathToFile = str;
}

void GameEngine::on_actionNormal_triggered() {
    this->m_artificial->changeDifficulty(DIFF_NORMAL);
}

void GameEngine::on_actionHard_triggered() {
    this->m_artificial->changeDifficulty(DIFF_HARD);
}