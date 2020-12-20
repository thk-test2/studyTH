#include "mainwidget.h"
#include "receiverwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QTextEdit>
#include <QGridLayout>
#include <QFileDialog>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      //      m_button(new QPushButton("&Download", this)),
      m_receiver(new ReceiverWidget()),
      m_tEdit(new QTextEdit("TEST", this))
{
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("Text Editor");

    QPushButton* button1 = new QPushButton("Save");
    QPushButton* button2 = new QPushButton("Load");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(label, 0, 0, 1, 2);
    layout->addWidget(m_tEdit, 1, 0, 1, 2);
    layout->addWidget(button1, 2, 0);
    layout->addWidget(button2, 2, 1);

    connect(button1, &QPushButton::pressed, this, &MainWidget::saveFile);
    connect(button2, &QPushButton::pressed, this, &MainWidget::openFile);

    //    connect(m_button, &QPushButton::pressed, this, &MainWidget::showReceiverWidget);
    //    connect(this, &MainWidget::showReceiver, m_receiver, &ReceiverWidget::showWidget);

    //    QTimer *timer = new QTimer(this);
    //    connect(timer, SIGNAL(timeout()), this, SIGNAL(showReceiver()));
    //    timer->start(1);
}

void MainWidget::saveFile()
{
    qDebug() << "Save File";
    QString filename = QFileDialog::getSaveFileName(this);
    QFile file( filename );

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << m_tEdit->toPlainText();

    file.close();
}

void MainWidget::openFile()
{
    qDebug() << "Open File";
    QString filename = QFileDialog::getOpenFileName(this);
    QFile file( filename );

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream in(&file);
    m_tEdit->setPlainText(in.readAll());

    file.close();
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
