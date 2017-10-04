//
// Created by doT on 15/10/2015.
//

#ifndef GOMOKU_INTROSTATE_H
#define GOMOKU_INTROSTATE_H

#include <QWidget>
#include "GameEngine.h"
#include "Error.hpp"
#include "ui_dialog.h"

class IntroState : public QDialog, private Ui::Dialog {
    Q_OBJECT

public:
    IntroState(QWidget * parent = 0, GameEngine *engine = 0, Arbiter *arbiter = 0);
    ~IntroState();

private slots:
    void on_buttonBox_accepted();
    void on_aiBox_clicked(bool);
    void on_secondRules_clicked();
    void on_firstRules_clicked();
    void on_sauvegarde_clicked();
    void on_pathToFile_textEdited();

private:
    QWidget *m_parent;
    GameEngine *m_engine;
    Arbiter *m_arbiter;
};

#endif //GOMOKU_INTROSTATE_H
