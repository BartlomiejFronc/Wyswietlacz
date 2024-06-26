#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int timerId;
protected:
    void timerEvent(QTimerEvent *event);
private slots:
    void on_przyczmiany_clicked();
    void on_konsoladebugu_textChanged();
    void on_przycdarkmode_clicked(bool checked);
};
#endif // MAINWINDOW_H
