#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./zmienne.h"
#include "./can.h"
#include "./zegar.h"
#include "qscrollbar.h"
#include <QPalette>

extern dane dane1;
int aktualneokno = 0;
Zegar *speedometer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    speedometer = new Zegar(this);
    ui->zegarlayout->addWidget(speedometer);

    timerId = startTimer(100);     //iniscjalizacja timeara na 1000 ms
}

MainWindow::~MainWindow()   //funkcja wywolywana przy zamknieciu programu
{
    killTimer(timerId);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event) //funkcja wykonywana co cykl timera
{
    ui->konsoladebugu->insertPlainText(QString::number(dane1.Speed)+"km/h\n"); //wypisywanie w konsoli debugggera
    CANodczyt();    //tu beda zbierane dane
    ui->speed->setText(QString::number(dane1.Speed)+"km/h");    //wyswietlanie tekstu predkosci na ui
    ui->error->setText(QString::fromStdString(dane1.ErrorMsg)); //wyswietlanie tekstu errora
    ui->speedbar->setValue(dane1.Speed);    //ustawianie paska predkosci
    speedometer->setSpeed(dane1.Speed); //przestawianie wskazowki
    ui->zegarpredkosc->setText(QString::number(dane1.Speed)); //predkosc w zegarze

}


void MainWindow::on_przyczmiany_clicked() //przelaczanie okien przy wciskaniu przycisku
{

    aktualneokno = (aktualneokno == 2 ? aktualneokno = 0 : aktualneokno+1);
    ui->stackedWidget->setCurrentIndex(aktualneokno);
}


void MainWindow::on_konsoladebugu_textChanged() //usatwianie scrolla na dole konsoli debugu
{
    QScrollBar *sb = ui->konsoladebugu->verticalScrollBar();
    if(sb->maximum() - sb->value() < 100){  //prog przyczepiania do dolu
        sb->setValue(sb->maximum());
    }
}


void MainWindow::on_przycdarkmode_clicked(bool checked) //ustawianie trybu ciemnego
{
    if(checked){    //ciemny
        //tla
        ui->Mdebug->setStyleSheet("background-color: rgb(22, 22, 22);");
        ui->Mdrive->setStyleSheet("background-color: rgb(22, 22, 22);");
        ui->Minfo->setStyleSheet("background-color: rgb(22, 22, 22);");
        QPalette ciemna;
        ciemna.setColor(QPalette::Base, QColor(20,20,20));
        MainWindow::setPalette(ciemna);

        //paski
        ui->batterybar->setStyleSheet("background-color: rgb(40, 40, 40);");
        ui->speedbar->setStyleSheet("background-color: rgb(40, 40, 40);");
    }else{      //jasny
        //tla
        ui->Mdebug->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->Mdrive->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->Minfo->setStyleSheet("background-color: rgb(255, 255, 255);");

        //paski
        ui->batterybar->setStyleSheet("background-color: rgb(200, 200, 200);");
        ui->speedbar->setStyleSheet("background-color: rgb(200, 200, 200);");
    }
}

