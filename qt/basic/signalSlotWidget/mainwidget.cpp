#include "mainwidget.h"
#include "painterwidget.h"

#include <QGridLayout>
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , m_menubar(new QMenuBar(this))
    , m_mode(new QMenu("Mode Change", this))
    , m_textMode(new QAction("Text Editor mode", m_mode))
    , m_painterMode(new QAction("Painter Mode", m_mode))
    , m_editor(new QTextEdit("TEST", this))
    , m_painter(new PainterWidget(this))
{
    m_painter->setGeometry(0, 30, 300, 270);

    setUpLayout();
}

void MainWidget::setUpLayout()
{
    m_mode->addAction(m_textMode);
    m_mode->addAction(m_painterMode);
    m_menubar->addMenu(m_mode);

    connect(m_textMode, &QAction::triggered, this, &MainWidget::showEditor);
    connect(m_painterMode, &QAction::triggered, this, &MainWidget::showPainter);

    QPushButton* button1 = new QPushButton("Save");
    QPushButton* button2 = new QPushButton("Load");

    connect(button1, &QPushButton::pressed, this, &MainWidget::saveFile);
    connect(button2, &QPushButton::pressed, this, &MainWidget::openFile);

    m_layout = new QGridLayout(this);
    m_layout->setMenuBar(m_menubar);

    m_layout->addWidget(button1, 3, 0);
    m_layout->addWidget(button2, 3, 1);

    m_mode->setActiveAction(m_painterMode);
    showPainter();
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

void MainWidget::saveFile()
{
    qDebug() << "Save File";
    QString filename = QFileDialog::getSaveFileName(this);
    QFile file( filename );

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    if (m_mode->activeAction() == m_textMode)
    {
        qDebug() << "Text save";
        QTextStream out(&file);
        out << m_editor->toPlainText();
    }

    file.close();
}

void MainWidget::openFile()
{
    qDebug() << "Open File";
    QString filename = QFileDialog::getOpenFileName(this);
    QFile file( filename );

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    if (m_mode->activeAction() == m_textMode)
    {
        qDebug() << "Text open";
        QTextStream in(&file);
        m_editor->setPlainText(in.readAll());
    } else {
        qDebug() << "Image open";
        m_painter->showImage(filename);
    }

    file.close();
}
