#include "painterwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

PainterWidget::PainterWidget(QWidget *parent)
    : QLabel(parent)
    , m_painter(new QPainter())
{
    QPixmap image(480,320);
    image.fill(Qt::red);
    this->setPixmap(image);
    qDebug() << this->size();
    this->hide();
}

//void PainterWidget::paintEvent(QPaintEvent *event)
//{
//    m_painter->begin(this);
//    m_painter->setRenderHints(QPainter::Antialiasing, true);
//    m_painter->setPen(Qt::SolidLine);
//    m_painter->drawPath(m_path);
//    m_painter->end();
//}

void PainterWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Pressed:" << event->x() <<  event->y();
    m_path = QPainterPath(QPoint(event->x(), event->y()));
}

void PainterWidget::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug() << "Moving:" << event->x() <<  event->y();
    m_path.lineTo(event->x(), event->y());
}

void PainterWidget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Released:" << event->x() <<  event->y();
    m_path.lineTo(event->x(), event->y());
    this->update();
}
