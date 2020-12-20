#include "mainwindow.h"
#include "mainwidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    MainWidget* w = new MainWidget(this);

    w->setGeometry(0,0,300, 300);
    w->setStyleSheet("border: 1px solid red");
    qDebug() << w->sizeHint();
}
