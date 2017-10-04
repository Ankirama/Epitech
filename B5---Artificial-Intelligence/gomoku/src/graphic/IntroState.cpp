//
// Created by doT on 15/10/2015.
//

#include <QtWidgets/qmessagebox.h>
#include "IntroState.h"

IntroState::IntroState(QWidget * parent, GameEngine *engine, Arbiter *arbiter) : QDialog(parent),
                                                               m_engine(engine),
                                                               m_arbiter(arbiter){
    setupUi(this);

    this->windowBox->addItem(QString::fromStdString("Fenetre"));
    this->windowBox->addItem(QString::fromStdString("Fenetre Pleine Ecran"));
    this->windowBox->addItem(QString::fromStdString("Pleine Ecran"));

    this->aiSpinner->addItem(QString::fromStdString("Normal"));
    this->aiSpinner->addItem(QString::fromStdString("Hard"));

    this->firstRules->setChecked(this->m_arbiter->isFirstRuleEnabled());
    this->secondRules->setChecked(this->m_arbiter->isSecondRuleEnabled());
}

IntroState::~IntroState() {
}

void IntroState::on_buttonBox_accepted(){
    this->m_engine->setAi(this->aiBox->isChecked());
    this->m_engine->setPathToFile(this->pathToFile->text().toStdString());
    this->m_engine->setSave(this->sauvegarde->isChecked());
    switch (this->windowBox->currentIndex()){
        case 0:
            break;
        case 1:
        case 2:
            this->m_engine->setWindowState(this->m_engine->windowState() ^ Qt::WindowFullScreen);
            break;
    }

    if (this->aiBox->isChecked())
        switch (this->aiSpinner->currentIndex()){
            case 0:
                this->m_engine->setDifficulty(DIFF_NORMAL);
                break;
            case 1:
                this->m_engine->setDifficulty(DIFF_HARD);
                break;
        }
}

void IntroState::on_aiBox_clicked(bool enable){
    this->aiSpinner->setEnabled(enable);
}

void IntroState::on_secondRules_clicked(){
    this->m_arbiter->setSecondRule(!this->m_arbiter->isSecondRuleEnabled());
    this->secondRules->setChecked(this->m_arbiter->isSecondRuleEnabled());
}

void IntroState::on_firstRules_clicked(){
    this->m_arbiter->setFirstRule(!this->m_arbiter->isFirstRuleEnabled());
    this->firstRules->setChecked(this->m_arbiter->isFirstRuleEnabled());
}

void IntroState::on_sauvegarde_clicked(){
    this->pathToFile->setEnabled(this->sauvegarde->isChecked());
    if (this->pathToFile->text() == "")
        this->buttonBox->setEnabled(false);
}

void IntroState::on_pathToFile_textEdited(){
    if (this->pathToFile->text() == "")
        this->buttonBox->setEnabled(false);
    else
        this->buttonBox->setEnabled(true);
}