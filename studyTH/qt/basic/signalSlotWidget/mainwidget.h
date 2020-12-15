#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QPushButton;
class ReceiverWidget;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void paintEvent(QPaintEvent* event) override;
signals:
    void showReceiver();
private:
    QPushButton* m_button;
    ReceiverWidget* m_receiver;
};
#endif // MAINWINDOW_H
