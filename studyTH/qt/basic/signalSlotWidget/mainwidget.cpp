#include "mainwidget.h"
#include "receiverwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QTimer>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      m_button(new QPushButton("&Download", this)),
      m_receiver(new ReceiverWidget())
{
    connect(m_button, SIGNAL(pressed()), this, SLOT(showReceiverWidget()));
    connect(this, SIGNAL(showReceiver(QWidget*)), m_receiver, SLOT(showWidget(QWidget*)));

//    QLabel *label = new QLabel(this);
//    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    label->setText("first line\nsecond line");
//    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
//    label->move(this->geometry().center());

//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SIGNAL(showReceiver()));
//    timer->start(1);
}

void MainWidget::showReceiverWidget()
{
    emit showReceiver(this);
}

void MainWidget::paintEvent(QPaintEvent *event)
{
}

MainWidget::~MainWidget()
{
}
