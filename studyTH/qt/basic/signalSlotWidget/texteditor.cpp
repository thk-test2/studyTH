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
    this->hide();
}
