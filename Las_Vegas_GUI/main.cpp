#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "titleWindow.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    titleWindow tw;
    tw.setWindowTitle("Bienvenue");
    tw.setFixedSize(0,0);
    tw.move(QPoint(400,100));
    tw.show();

    return a.exec();

}
