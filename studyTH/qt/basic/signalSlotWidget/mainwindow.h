#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TextEditor;
class PainterWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
    void setUpMenuBar();
    void setUpMode();
    QMenu* m_mode;
    QAction* m_textMode;
    QAction* m_painterMode;
    TextEditor* m_texteditor;
    PainterWidget* m_painter;
};

#endif // MAINWINDOW_H
