//
//  GameEngine.h
//  gomoku
//
//  Created by Fabien Martinez on 12/10/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

/**
 * @file: GameEngine.h
 * @brief: Core file for our game engine
 * @author: ankirama
 * @version: 0.1
 */

#ifndef __gomoku__GameEngine__
#define __gomoku__GameEngine__

# include <iostream>
# include <QMainWindow>
# include <fstream>
# include "Stats.h"
# include "Arbiter.h"
# include "AI.hh"
# include "ui_mainwindow.h"

class IGameState;

/**
 * @class: GameEngine
 * @brief: Class to check our rules and call our graphic functionc etc..
 */
class GameEngine : public QMainWindow, private Ui::MainWindow {
Q_OBJECT

public:
    GameEngine(Arbiter *arbiter);
    ~GameEngine();

    void setAi(bool);
    void setDifficulty(t_difficulty);
    void setPathToFile(std::string);
    void setSave(bool);
    void init();
    void updateMap(std::map<t_point*, int>);
    void cleanMap();
    std::string toString(int);
    void updateInfo();
    void writeSave(std::string str);
    void updateInfoClick(int, int);
    void playAI();

    QTableWidget &getTableWidget();

private slots:
    void on_quitBtn_clicked();
    void on_tableWidget_cellClicked(int x, int y);
    void on_actionFirst_Rule_triggered();
    void on_actionSecond_Rule_triggered();
    void on_actionNormal_triggered();
    void on_actionHard_triggered();
    void on_newMenu_triggered();

private:
    bool isSave;
    std::string pathToFile;
    Arbiter *m_arbiter;
    bool m_ai;
    bool m_ai_turn;
    t_difficulty m_difficulty;
    Stats *playerOneStats;
    Stats *playerTwoStats;
    std::fstream save;
    AI *m_artificial;
    void initMap();
};

#endif /* defined(__gomoku__GameEngine__) */
