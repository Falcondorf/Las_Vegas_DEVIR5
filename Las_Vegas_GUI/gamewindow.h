#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>
#include <QPixmap>
#include "game.h"

class gameWindow : public QWidget
{
    QHBoxLayout *superRoot_;
    QGridLayout *casinoDisp_;
    QVBoxLayout *rightPannel_;
    QGroupBox *playerInfos_;
    QPushButton *rollButton_;
    QGridLayout *dicesDisp_;
    QHBoxLayout *sbBet_;
    QLabel *lBet_;
    QPushButton *buttonBet_;

    Game *theGame_;

public:
    explicit gameWindow(Game *myGame, QWidget *parent = 0);
};

#endif // GAMEWINDOW_H
