#include "Zegar.h"
#include <QPainter>

Zegar::Zegar(QWidget *parent) : QWidget(parent), m_speed(0) {
    setAttribute(Qt::WA_TranslucentBackground); // Ustawienie przezroczystego tła
}
void Zegar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Rysowanie obrazka PNG
    QPixmap backgroundImage(":/img/zegar.png"); // Ścieżka do pliku graficznego
    painter.drawPixmap(0, 0, 380, 380, backgroundImage);

    int side = qMin(width(), height());
    painter.translate(380 / 2, 380 / 2);
    painter.scale(side / 200.0, side / 200.0);



    // Rysowanie wskazówki
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.save();
    painter.rotate(-135 + 1.5 * m_speed); // 135 stopni to początek wychylenia wskazówki, 2.7 to proporcja prędkości
    painter.drawRect(-3, 0, 6, -80); // Prostokąt (szerokość 6, wysokość -80)
    painter.restore();
}

void Zegar::setSpeed(int speed) {
    if (speed >= 0 && speed <= 200) {
        m_speed = speed;
        update(); // Odświeżenie widgetu
    }
}

