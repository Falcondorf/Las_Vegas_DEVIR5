#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "game.h"

class gameWindow : public QWidget
{

public:
    explicit gameWindow(Game *myGame, QWidget *parent = 0);
};

#endif // GAMEWINDOW_H
