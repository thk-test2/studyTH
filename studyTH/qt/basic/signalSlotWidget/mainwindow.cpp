#include "mainwindow.h"
#include "texteditor.h"
#include "painterwidget.h"

#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_mode(new QMenu("Mode Change", this))
    , m_textMode(new QAction("Text Editor mode", m_mode))
    , m_painterMode(new QAction("Painter Mode", m_mode))
    , m_texteditor(new TextEditor(this))
    , m_painter(new PainterWidget(this))
{
    m_texteditor->setGeometry(0, 30, 300, 270);
    m_texteditor->setStyleSheet("border: 1px solid red");
    qDebug() << m_texteditor->sizeHint();
    m_painter->setGeometry(0, 30, 300, 270);

    setUpMenuBar();
    setUpMode();
}

void MainWindow::setUpMenuBar()
{
    m_mode->addAction(m_textMode);
    m_mode->addAction(m_painterMode);
    menuBar()->addMenu(m_mode);

    connect(m_textMode, &QAction::triggered, m_texteditor, &TextEditor::show);
    connect(m_textMode, &QAction::triggered, m_painter, &PainterWidget::hide);

    connect(m_painterMode, &QAction::triggered, m_texteditor, &TextEditor::hide);
    connect(m_painterMode, &QAction::triggered, m_painter, &PainterWidget::show);
}

void MainWindow::setUpMode()
{
    m_painter->show();
}
