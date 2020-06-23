#include "mainwindow.h"

#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    QPen pen(Qt::red);
    painter.begin(this);

    painter.setPen(Qt::blue);
    painter.drawLine(10, 10, 100, 40);
    painter.drawLine(120, 10, 80, 80);

    qDebug() << "TEST";

    painter.end();
}
