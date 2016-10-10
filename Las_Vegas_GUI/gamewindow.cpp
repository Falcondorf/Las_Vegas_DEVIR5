#include "gamewindow.h"

gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent), theGame_(myGame){
    /*Déclaration générale des layouts et widgets*/
    superRoot_ = new QHBoxLayout(this);
    casinoDisp_ = new QGridLayout;
    rightPannel_ = new QVBoxLayout;
    playerInfos_ = new QGroupBox("Infos joueur");
    vbPlayerInfos_ = new QVBoxLayout;
    rollButton_ = new QPushButton("Lancer");
    dicesDisp_ = new QGridLayout;
    betSBLayout_ = new QHBoxLayout;
    sbBet_ = new QSpinBox;
    lBet_ = new QLabel("Valeur a déposer");
    buttonBet_ = new QPushButton("Parier");

    /*Paramétrage des widgets en générale*/
    sbBet_->setRange(1,6);
    rollButton_->setMaximumWidth(120);
    buttonBet_->setMaximumWidth(120);

    /*Déclaration, configuration et intégration des Casinos*/
    gbCasino1_ = new QGroupBox("Casino 1");
    c1Layout_ = new QVBoxLayout;
    lTList1_ = new QLabel("Billets: ");
    lBList1_ = new QLabel("Paris des joueurs: ");
    c1Layout_->addWidget(lTList1_);
    c1Layout_->addWidget(lBList1_);
    gbCasino1_->setLayout(c1Layout_);

    gbCasino2_ = new QGroupBox("Casino 2");
    c2Layout_ = new QVBoxLayout;
    lTList2_ = new QLabel("Billets: ");
    lBList2_ = new QLabel("Paris des joueurs: ");
    c2Layout_->addWidget(lTList2_);
    c2Layout_->addWidget(lBList2_);
    gbCasino2_->setLayout(c2Layout_);

    gbCasino3_ = new QGroupBox("Casino 3");
    c3Layout_ = new QVBoxLayout;
    lTList3_ = new QLabel("Billets: ");
    lBList3_ = new QLabel("Paris des joueurs: ");
    c3Layout_->addWidget(lTList3_);
    c3Layout_->addWidget(lBList3_);
    gbCasino3_->setLayout(c3Layout_);

    gbCasino4_ = new QGroupBox("Casino 4");
    c4Layout_ = new QVBoxLayout;
    lTList4_ = new QLabel("Billets: ");
    lBList4_ = new QLabel("Paris des joueurs: ");
    c4Layout_->addWidget(lTList4_);
    c4Layout_->addWidget(lBList4_);
    gbCasino4_->setLayout(c4Layout_);

    gbCasino5_ = new QGroupBox("Casino 5");
    c5Layout_ = new QVBoxLayout;
    lTList5_ = new QLabel("Billets: ");
    lBList5_ = new QLabel("Paris des joueurs: ");
    c5Layout_->addWidget(lTList5_);
    c5Layout_->addWidget(lBList5_);
    gbCasino5_->setLayout(c5Layout_);

    gbCasino6_ = new QGroupBox("Casino 6");
    c6Layout_ = new QVBoxLayout;
    lTList6_ = new QLabel("Billets: ");
    lBList6_ = new QLabel("Paris des joueurs: ");
    c6Layout_->addWidget(lTList6_);
    c6Layout_->addWidget(lBList6_);
    gbCasino6_->setLayout(c6Layout_);

    casinoDisp_->addWidget(gbCasino1_,0,0);
    casinoDisp_->addWidget(gbCasino2_,0,1);
    casinoDisp_->addWidget(gbCasino3_,1,0);
    casinoDisp_->addWidget(gbCasino4_,1,1);
    casinoDisp_->addWidget(gbCasino5_,2,0);
    casinoDisp_->addWidget(gbCasino6_,2,1);

    /*Déclaration des infos joueurs courant et intégration*/
    noCurrPlay_ = new QLabel("Joueur courant: "+QString::number(theGame_->getCurrPlay()));
    moneyCurrPlay_ = new QLabel("Argent gagné: "+QString::number(theGame_->getPlayer(theGame_->getCurrPlay()).getSumAccount()));
    dicesLeftCurrPlay_ = new QLabel("Nombre de dé restant: "+QString::number(theGame_->getPlayer(theGame_->getCurrPlay()).getDiceStock()));
    vbPlayerInfos_->addWidget(noCurrPlay_);
    vbPlayerInfos_->addWidget(moneyCurrPlay_);
    vbPlayerInfos_->addWidget(dicesLeftCurrPlay_);
    playerInfos_->setLayout(vbPlayerInfos_);

    /*Intégration des widgets et layout généraux*/
    betSBLayout_->addWidget(sbBet_);
    betSBLayout_->addWidget(lBet_);
    rightPannel_->addWidget(playerInfos_);
    rightPannel_->addWidget(rollButton_);
    rightPannel_->addLayout(dicesDisp_);
    rightPannel_->addLayout(betSBLayout_);
    rightPannel_->addWidget(buttonBet_);
    superRoot_->addLayout(casinoDisp_);
    superRoot_->addLayout(rightPannel_);
}
