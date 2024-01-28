#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./zmienne.h"
#include "./can.h"

extern dane dane1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timerId = startTimer(1000);     //iniscjalizacja timeara na 1000 ms
}

MainWindow::~MainWindow()   //funkcja wywolywana przy zamknieciu programu
{
    killTimer(timerId);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event) //funkcja wykonywana co cykl timera
{
    CANodczyt();    //tu beda zbierane dane
    ui->speed->setText(QString::number(dane1.Speed)+"km/h");    //wyswietlanie tekstu predkosci na ui
    ui->error->setText(QString::fromStdString(dane1.ErrorMsg)); //wyswietlanie tekstu errora
    ui->speedbar->setValue(dane1.Speed);    //ustawianie paska predkosci
}

