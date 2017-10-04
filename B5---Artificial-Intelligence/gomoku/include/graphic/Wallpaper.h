//
// Created by doT on 21/10/2015.
//

#ifndef GOMOKU_WALLPAPER_H
#define GOMOKU_WALLPAPER_H


#include <QtWidgets/qwidget.h>
#include "ui_wallpaper.h"
#include "GameEngine.h"

class Wallpaper : public QDialog, private Ui::WallPaper{
    Q_OBJECT
public:
    Wallpaper(QWidget *parent = 0, GameEngine *engine = 0);
    ~Wallpaper();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem*);
    void on_buttonBox_accepted();

private:
    GameEngine *m_engine;
};


#endif //GOMOKU_WALLPAPER_H
