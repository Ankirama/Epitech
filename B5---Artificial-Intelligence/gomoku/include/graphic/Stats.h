//
// Created by doT on 28/10/2015.
//

#ifndef GOMOKU_STATS_H
#define GOMOKU_STATS_H


#include "ui_stats.h"

class Stats : private Ui::Stats {
public:
    Stats(QWidget *);
    ~Stats();

    void setLabel();
    void setStoneStole(std::string);
    void setTimer(std::string);
};


#endif //GOMOKU_STATS_H
