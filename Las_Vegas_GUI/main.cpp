#include "mainwindow.h"
#include <QApplication>
#include "titleWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    titleWindow tw;
    tw.setWindowTitle("Bienvenue");
    tw.show();

    return a.exec();
}
