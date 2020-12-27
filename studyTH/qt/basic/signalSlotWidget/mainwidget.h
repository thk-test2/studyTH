#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QMenu;
class QGridLayout;
class QTextEdit;
class PainterWidget;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

signals:

private:
    void setUpLayout();
    void showEditor();
    void showPainter();
    QMenu* m_mode;
    QGridLayout* m_layout;
    QAction* m_textMode;
    QAction* m_painterMode;
    QTextEdit* m_editor;
    PainterWidget* m_painter;
};

#endif // MAINWIDGET_H
