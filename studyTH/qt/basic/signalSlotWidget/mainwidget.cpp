#include "mainwidget.h"
#include "receiverwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QTimer>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      m_button(new QPushButton("&Download", this)),
      m_receiver(new ReceiverWidget())
{
    connect(m_button, SIGNAL(pressed()), m_receiver, SLOT(showWidget()));
    connect(this, SIGNAL(showReceiver()), m_receiver, SLOT(showWidget()));

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SIGNAL(showReceiver()));
    timer->start(1);
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
