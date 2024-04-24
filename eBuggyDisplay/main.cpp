#include "mainwindow.h"

#include <QApplication>
#include "./zmienne.h"
#include <QtSvg>
#include <QtQuickWidgets/QtQuickWidgets>
dane dane1; //deklaracja danych



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //w.setWindowState(Qt::WindowFullScreen);   //ustawiene fullscreena (na kompie polecam to wylaczyc)
    w.show();
    return a.exec();
}

