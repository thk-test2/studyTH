#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>

class QPushButton;
class QTextEdit;

class TextEditor : public QWidget
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
public slots:
    void saveFile();
    void openFile();
    void showWidget() { show(); }
    void hideWidget() { hide(); }
signals:
private:
    QTextEdit* m_tEdit;
};
#endif // TEXTEDITOR_H
