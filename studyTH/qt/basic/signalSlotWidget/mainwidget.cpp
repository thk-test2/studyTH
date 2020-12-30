#include "mainwidget.h"
#include "texteditor.h"
#include "painterwidget.h"

#include <QGridLayout>
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , m_mode(new QMenu("Mode Change", this))
    , m_textMode(new QAction("Text Editor mode", m_mode))
    , m_painterMode(new QAction("Painter Mode", m_mode))
    , m_painter(new PainterWidget(this))
{
    m_painter->setGeometry(0, 30, 300, 270);

    setUpLayout();
    showEditor();
}

void MainWidget::setUpLayout()
{
    QMenuBar* menuBar = new QMenuBar(this);
    m_mode->addAction(m_textMode);
    m_mode->addAction(m_painterMode);
    menuBar->addMenu(m_mode);

    connect(m_textMode, &QAction::triggered, this, &MainWidget::showEditor);
    connect(m_painterMode, &QAction::triggered, this, &MainWidget::showPainter);

    m_editor = new QTextEdit("TEST", this);

    QPushButton* button1 = new QPushButton("Save");
    QPushButton* button2 = new QPushButton("Load");

    m_layout = new QGridLayout(this);
    m_layout->setMenuBar(menuBar);

    m_layout->addWidget(button1, 3, 0);
    m_layout->addWidget(button2, 3, 1);
}

void MainWidget::showEditor()
{
    m_layout->addWidget(m_editor, 2, 0, 1, 2);
    m_editor->show();
    m_painter->hide();
}

void MainWidget::showPainter()
{
    m_layout->addWidget(m_painter, 2, 0, 1, 2);
    m_editor->hide();
    m_painter->show();
}
