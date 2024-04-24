#include "./speedometer.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPainter>

class Speedometer : public QWidget {
public:
    Speedometer(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        speedLabel = new QLabel("0 km/h", this);
        speedLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(speedLabel);

        speedSlider = new QSlider(Qt::Horizontal, this);
        speedSlider->setRange(0, 200); // Ustaw zakres prędkości od 0 do 200 km/h
        speedSlider->setValue(0); // Początkowa wartość prędkości
        connect(speedSlider, &QSlider::valueChanged, this, &Speedometer::updateSpeed);
        layout->addWidget(speedSlider);

        setLayout(layout);
        setWindowTitle("Speedometer");
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        int side = qMin(width(), height());
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 200.0, side / 200.0);

        drawSpeedometer(&painter);
    }

private slots:
    void updateSpeed(int value) {
        currentSpeed = value;
        speedLabel->setText(QString::number(value) + " km/h");
        update();
    }

private:
    QLabel *speedLabel;
    QSlider *speedSlider;
    int currentSpeed = 0;

    void drawSpeedometer(QPainter *painter) {
        // Rysowanie tarczy zegara
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::white);
        painter->drawEllipse(-90, -90, 180, 180);

        // Rysowanie wskazówki
        painter->setPen(Qt::black);
        painter->setBrush(Qt::black);
        painter->save();
        painter->rotate(-135 + 2.7 * currentSpeed); // 135 stopni to początek wychylenia wskazówki, 2.7 to proporcja prędkości
        QPolygonF hand;
        hand << QPointF(0, 0) << QPointF(5, -80) << QPointF(-5, -80);
        painter->drawConvexPolygon(hand);
        painter->restore();
    }
};

