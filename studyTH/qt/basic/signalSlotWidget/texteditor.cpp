#include "texteditor.h"

#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>

TextEditor::TextEditor(QWidget *parent)
    : QWidget(parent),
      m_tEdit(new QTextEdit("TEST", this))
{
//    connect(button1, &QPushButton::pressed, this, &TextEditor::saveFile);
//    connect(button2, &QPushButton::pressed, this, &TextEditor::openFile);
    this->hide();
}

//void TextEditor::saveFile()
//{
//    qDebug() << "Save File";
//    QString filename = QFileDialog::getSaveFileName(this);
//    QFile file( filename );

//    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
//        return;

//    QTextStream out(&file);
//    out << m_tEdit->toPlainText();

//    file.close();
//}

//void TextEditor::openFile()
//{
//    qDebug() << "Open File";
//    QString filename = QFileDialog::getOpenFileName(this);
//    QFile file( filename );

//    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
//        return;

//    QTextStream in(&file);
//    m_tEdit->setPlainText(in.readAll());

//    file.close();
//}
