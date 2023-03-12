#include "mainwindow.h"
#include "loglist.h"

#include <QDebug>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_list = std::make_unique<LogList>();
    m_list->items()->push_back(LogItem());
}

QVariant MainWindow::getValue() {
    LogItem item = m_list->items()->at(0);
    return QVariant::fromValue(*(item.m_vec));
}

MainWindow::~MainWindow()
{
}

