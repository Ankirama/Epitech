//
// Created by doT on 21/10/2015.
//

#include <iostream>
#include "Wallpaper.h"

Wallpaper::Wallpaper(QWidget *parent, GameEngine *engine) : QDialog(parent), m_engine(engine){
    setupUi(this);
    new QListWidgetItem("1", this->listWidget);
    new QListWidgetItem("2", this->listWidget);
    new QListWidgetItem("3", this->listWidget);
}

Wallpaper::~Wallpaper() {
}

void Wallpaper::on_listWidget_itemClicked(QListWidgetItem *item){
    this->mImage->setPixmap(QPixmap("D:/Programmation/Git/Gomoku/assets/w" + item->text() + ".png").scaled(180, 155,
                                                                                                           Qt::IgnoreAspectRatio,
                                                                                                           Qt::FastTransformation));
}

void Wallpaper::on_buttonBox_accepted(){
    QPalette *palette = new QPalette();
   // std::cout << "Test 1" << std::endl;
    palette->setBrush(QPalette::Base, *(new QBrush(QPixmap("D:/Programmation/Git/Gomoku/assets/w" + this->listWidget->currentItem()->text() +".png"))));
    //std::cout << "Test 2" << std::endl;
    //this->m_engine->getTableWidget().setPalette(*palette); TODO Crash when is set
    //std::cout << "Test 3" << std::endl;
    this->close();
}