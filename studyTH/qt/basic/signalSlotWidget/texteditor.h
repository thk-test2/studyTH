#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>

class QPushButton;
class PainterWidget;
class QTextEdit;

class TextEditor : public QWidget
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();
public slots:
    void saveFile();
    void openFile();
    void showPainterWidget();
signals:
    void showPainter(QWidget*);
private:
    QTextEdit* m_tEdit;
};
#endif // TEXTEDITOR_H
