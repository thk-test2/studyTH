#include "mainwidget.h"
#include "receiverwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QTextEdit>
#include <QGridLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
//      m_button(new QPushButton("&Download", this)),
      m_receiver(new ReceiverWidget())
{
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("Text Editor");

    QTextEdit* tEdit = new QTextEdit("TEST", this);

    QPushButton* button1 = new QPushButton("Save");
    QPushButton* button2 = new QPushButton("Load");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(label, 0, 0, 1, 2);
    layout->addWidget(tEdit, 1, 0, 1, 2);
    layout->addWidget(button1, 2, 0);
    layout->addWidget(button2, 2, 1);

    connect(button1, &QPushButton::pressed, [](){
        qDebug() << "Saved";
    });

//    connect(m_button, &QPushButton::pressed, this, &MainWidget::showReceiverWidget);
//    connect(this, &MainWidget::showReceiver, m_receiver, &ReceiverWidget::showWidget);

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
