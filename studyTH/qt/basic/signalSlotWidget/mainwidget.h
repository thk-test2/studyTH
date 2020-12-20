#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QPushButton;
class PainterWidget;
class QTextEdit;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void paintEvent(QPaintEvent* event) override;
public slots:
    void saveFile();
    void openFile();
    void showPainterWidget();
signals:
    void showPainter(QWidget*);
private:
    QPushButton* m_changeButton;
    PainterWidget* m_painter;
    QTextEdit* m_tEdit;
};
#endif // MAINWIDGET_H
