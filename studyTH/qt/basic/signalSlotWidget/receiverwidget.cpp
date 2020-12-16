#include "receiverwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

ReceiverWidget::ReceiverWidget(QWidget *parent) : QWidget(parent)
{

}

void ReceiverWidget::showWidget(QWidget* parent)
{
    qDebug() << Q_FUNC_INFO << parent;
    this->setParent(parent);
    this->show();
}

void ReceiverWidget::paintEvent(QPaintEvent *event)
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
