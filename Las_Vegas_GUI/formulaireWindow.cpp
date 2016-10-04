#include "formulaireWindow.h"


formulaireWindow::formulaireWindow(QWidget *parent) :QWidget(parent){
    superRoot_ = new QVBoxLayout(this);
    vbExtensionForRadio_ = new QVBoxLayout(this);
    hbLayoutNbJ_ = new QHBoxLayout(this);
    cbExtension_ = new QCheckBox (this);
    lNbJ_ = new QLabel(this);
    sbNbJ_ = new QSpinBox(this);
    rNoExtension_ = new QRadioButton(this);
    rExtension1_ = new QRadioButton(this);
    rExtension2_ = new QRadioButton(this);
    rExtension3_ = new QRadioButton(this);

    gbRadioExtension_ = new QGroupBox(tr("Extensions"));
    lNbJ_->setText("Nb joueurs");
    sbNbJ_->setRange(2,8);

    cbExtension_->setText("Voir les extensions");

    rNoExtension_->setText("Pas d'extension");
    rExtension1_->setText("Ext1");
    rExtension2_->setText("Ext2");
    rExtension3_->setText("Ext3");

    buttonStart_ = new QPushButton(tr("Start"));
    buttonStart_->setMaximumSize(100, 50);


    /*QVBoxLayout *vb2J = new QVBoxLayout(this);
    vb2J->addWidget(leName1_);
    vb2J->addWidget(leName2_);
    QVBoxLayout *vb4J = new QVBoxLayout(this);
    vb4J->addWidget(leName3_);
    vb4J->addWidget(leName4_);

    fourPlayerGameBox_->setLayout(vb4J);
    fourPlayerGameBox_->hide();

    groupParam_->addWidget(lNbJ_);
    groupParam_->addWidget(sbNbJ_);
    groupParam_->addWidget(lSize_);
    groupParam_->addWidget(sbSize_);

    root_->addLayout(groupParam_);
    root_->addLayout(vb2J);
    root_->addWidget(fourPlayerGameBox_);
    startB_ = new QPushButton(tr("START"));
    startB_->setMaximumSize(100, 50);
    superRoot_->addLayout(root_);
    superRoot_->addWidget(startB_);*/

    QObject::connect(buttonStart_, SIGNAL(clicked()),this, SLOT(startGame()));
    //QObject::connect(sbNbJ_, SIGNAL(valueChanged(int)),this, SLOT(fourPlayerGame()));
}

void formulaireWindow::startGame(){
    /*if(sbNbJ_->value()==2){
        theGame_ = new Game(leName1_->text().toStdString(),leName2_->text().toStdString(),sbSize_->value(),true);
    }else{
         theGame_ = new Game(leName1_->text().toStdString(),leName2_->text().toStdString(),
                            leName3_->text().toStdString(),leName4_->text().toStdString(),
                            sbSize_->value());
    }

    theGameWindow_ = new gameWindow(theGame_);
    theGameWindow_->show();*/
    this->close();

}
/*
void formulaireWindow::fourPlayerGame(){
    if (sbNbJ_->value()!=4){
        fourPlayerGameBox_->hide();
    } else {
        fourPlayerGameBox_->show();
    }
}
*/
