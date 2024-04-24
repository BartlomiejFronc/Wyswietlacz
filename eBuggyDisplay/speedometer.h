#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QLabel>
#include <QSlider>

class Speedometer : public QWidget {
    Q_OBJECT
public:
    explicit Speedometer(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateSpeed(int value);

private:
    QLabel *speedLabel;
    QSlider *speedSlider;
    int currentSpeed = 0;

    void drawSpeedometer(QPainter *painter);
};

#endif // SPEEDOMETER_H
