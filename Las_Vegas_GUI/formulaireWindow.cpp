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

    gbRadioExtension_ = new QGroupBox(tr("Extensions"));
    lNbJ_->setText("Nb joueurs");
    sbNbJ_->setRange(2,8);
    hbLayoutNbJ_->addWidget(lNbJ_);
    hbLayoutNbJ_->addWidget(sbNbJ_);

    cbExtension_->setText("Voir les extensions");

    rNoExtension_->setText("Pas d'extension");
    rNoExtension_->setChecked(true);
    rExtension1_->setText("Ext1");
    rExtension2_->setText("Ext2");
    vbExtensionForRadio_->addWidget(rNoExtension_);
    vbExtensionForRadio_->addWidget(rExtension1_);
    vbExtensionForRadio_->addWidget(rExtension2_);
    gbRadioExtension_->setLayout(vbExtensionForRadio_);
    gbRadioExtension_->hide();

    buttonStart_ = new QPushButton(tr("Start"));
    buttonStart_->setMaximumSize(100, 50);

    superRoot_->addLayout(hbLayoutNbJ_);
    superRoot_->addWidget(cbExtension_);
    superRoot_->addWidget(gbRadioExtension_);
    superRoot_->addWidget(buttonStart_);


    QObject::connect(buttonStart_, SIGNAL(clicked()),this, SLOT(startGame()));
    QObject::connect(cbExtension_, SIGNAL(stateChanged(int)),this, SLOT(hideShowExt()));
}

void formulaireWindow::startGame(){

    theGame_ = new Game(sbNbJ_->value());
    theGameWindow_ = new gameWindow(theGame_);
    theGameWindow_->show();

    this->deleteLater();

}

void formulaireWindow::hideShowExt(){
    if (cbExtension_->isChecked()){
        gbRadioExtension_->show();
    }else {
        gbRadioExtension_->hide();
    }
}
