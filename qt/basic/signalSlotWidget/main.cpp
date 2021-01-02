#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget mW;
    mW.setMinimumSize(300, 300);
    mW.show();
    return a.exec();
}
