#include "painterwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

PainterWidget::PainterWidget(QWidget *parent)
    : QWidget(parent)
    , m_painter(new QPainter())
    , m_startPoint(QPoint())
    , m_endPoint(QPoint())
{
    this->hide();
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);
    m_painter->setRenderHints(QPainter::Antialiasing, true);
    m_painter->setPen(Qt::SolidLine);
    m_painter->drawLine(m_startPoint, m_endPoint);
    m_painter->end();
    QWidget::paintEvent(event);
}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Pressed:" << event->x() <<  event->y();
    m_startPoint = QPoint(event->x(), event->y());
}

void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug() << "Moving:" << event->x() <<  event->y();
}

void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Released:" << event->x() <<  event->y();
    m_endPoint = QPoint(event->x(), event->y());
    this->repaint();
}
