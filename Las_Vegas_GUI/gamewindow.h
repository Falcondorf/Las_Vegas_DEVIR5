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

#include "observer.h"

class gameWindow : public QWidget, nvs::Observer
{
    Q_OBJECT

    QHBoxLayout *superRoot_;
    QGridLayout *casinoDisp_;
    QVBoxLayout *rightPannel_;
    QGroupBox *playerInfos_;
    QVBoxLayout *vbPlayerInfos_;
    QPushButton *rollButton_;
    QGridLayout *dicesDisp_;
    QHBoxLayout *betSBLayout_;
    QSpinBox *sbBet_;
    QLabel *lBet_;
    QPushButton *buttonBet_;

    QLabel *noCurrPlay_;
    QLabel *moneyCurrPlay_;
    QLabel *dicesLeftCurrPlay_;

    QGroupBox *gbCasino1_;
    QVBoxLayout *c1Layout_;
    QLabel *lTList1_;
    QLabel *lBList1_;
    QGroupBox *gbCasino2_;
    QVBoxLayout *c2Layout_;
    QLabel *lTList2_;
    QLabel *lBList2_;
    QGroupBox *gbCasino3_;
    QVBoxLayout *c3Layout_;
    QLabel *lTList3_;
    QLabel *lBList3_;
    QGroupBox *gbCasino4_;
    QVBoxLayout *c4Layout_;
    QLabel *lTList4_;
    QLabel *lBList4_;
    QGroupBox *gbCasino5_;
    QVBoxLayout *c5Layout_;
    QLabel *lTList5_;
    QLabel *lBList5_;
    QGroupBox *gbCasino6_;
    QVBoxLayout *c6Layout_;
    QLabel *lTList6_;
    QLabel *lBList6_;

    Game *theGame_;


private slots:
    void rolling();


public:
    explicit gameWindow(Game *myGame, QWidget *parent = 0);
    virtual void update(const nvs::Subject *subject) override;
};

#endif // GAMEWINDOW_H
