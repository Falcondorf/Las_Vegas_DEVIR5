#include "gamewindow.h"

gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent), theGame_(myGame){
    superRoot_ = new QHBoxLayout(this);
    casinoDisp_ = new QGridLayout(this);
    rightPannel_ = new QVBoxLayout(this);
    playerInfos_ = new QGroupBox(this);
    rollButton_ = new QPushButton("Lancer");
    dicesDisp_ = new QGridLayout;
    sbBet_ = new QSpinBox;
    lBet_ = new QLabel("Valeur a déposer");
    buttonBet_ = new QPushButton("Parier");

}
