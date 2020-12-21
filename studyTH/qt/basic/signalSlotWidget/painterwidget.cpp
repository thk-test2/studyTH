#include "painterwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

PainterWidget::PainterWidget(QWidget *parent) : QWidget(parent)
{
    this->hide();
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(0, 0, 50, 50);
    //    painter.fillRect(event->rect(), Qt::green);
    QWidget::paintEvent(event);
    painter.end();
}
