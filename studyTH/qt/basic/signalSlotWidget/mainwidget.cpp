#include "mainwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QLabel>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label = new QLabel(this);
//    m_label = new QLabel(QString("TEST"), this, Qt::Widget);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(0, 0, 100, 100);
//    painter.fillRect(event->rect(), Qt::green);
    QWidget::paintEvent(event);
    painter.end();
}

MainWidget::~MainWidget()
{
}
