#include "mainwindow.h"

#include <QDebug>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    m_list = std::make_unique<LogList>();
}

QVariant MainWindow::getValue() {
    return QVariant();
}

MainWindow::~MainWindow()
{
}

