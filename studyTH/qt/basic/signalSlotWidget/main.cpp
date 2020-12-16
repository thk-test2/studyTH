#include "mainwidget.h"

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsAnchorLayout>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow mW;
    MainWidget* w = new MainWidget(&mW);

    w->setGeometry(0,0,100, 100);
    w->setStyleSheet("border: 1px solid red");
    mW.setMinimumSize(300, 300);

//    w.move(mW.geometry().center());
    qDebug() << w->sizeHint();
    mW.show();
    return a.exec();
}
