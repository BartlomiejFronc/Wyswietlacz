#ifndef ZEGAR_H
#define ZEGAR_H

#include <QWidget>

class Zegar : public QWidget {
    Q_OBJECT
public:
    explicit Zegar(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setSpeed(int speed);

private:
    int m_speed;
};

#endif // ZEGAR_H
