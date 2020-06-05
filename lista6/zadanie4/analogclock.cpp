#include "analogclock.h"

#include <QPainter>
#include <QTime>
#include <QTimer>


AnalogClock::AnalogClock(QWidget *parent)

        : QWidget(parent) {

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));

    timer->start(1000);


    setToolTip("Instrukcje");
    setAutoFillBackground(true);
    setWindowTitle(tr("MojTytul"));//zmiana tytulu
    resize(400, 400);//zmiana rozmiaru zegarka


}


void AnalogClock::paintEvent(QPaintEvent *) {
    static const QPoint secondHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -90)
    };
    static const QPoint hourHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -70)
    };

    QColor secondColor(127, 127, 191);
    QColor hourColor(0, 127, 127);//zmiana koloru wskazowek
    QColor minuteColor(127, 127, 191);
    QColor circleColor(0,0,0); //zmiana koloru zegara

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();


    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);

    painter.scale(side / 200.0, side / 200.0);


    painter.setPen(Qt::NoPen);

    painter.setBrush(hourColor);


    painter.save();

    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();


    painter.setPen(hourColor);


    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }


    painter.setPen(Qt::NoPen);

    painter.setBrush(minuteColor);


    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();


    painter.setPen(minuteColor);


    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();
    painter.rotate(time.second()*6.0);//time second wartosc 0-60 * 6  pelny obrot
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
void AnalogClock::leaveEvent(QEvent *event) {
    setBackgroundRole(QPalette::Dark);
}
//funkcje zmieniajace kolor
void AnalogClock::enterEvent(QEvent *event) {
    setBackgroundRole(QPalette::Light);
}



