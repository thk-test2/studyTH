#include "mainwidget.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;

    QMainWindow mW;
    mW.setCentralWidget(&w);
    mW.setMinimumSize(200, 200);
    mW.show();
//    w.show();
    return a.exec();
}
