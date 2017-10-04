//
// Created by doT on 28/10/2015.
//

#include "Stats.h"

Stats::Stats(QWidget *widget) {
    setupUi(widget);
}

Stats::~Stats() {
}

void Stats::setLabel(){
    this->player->setText("Player 2");
}

void Stats::setStoneStole(std::string number){
    this->stoneStole->setText(QString::fromStdString(number));
}

void Stats::setTimer(std::string time) {
    this->label_4->setText(QString::fromStdString(time));
}