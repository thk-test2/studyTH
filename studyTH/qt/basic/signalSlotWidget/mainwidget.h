#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void paintEvent(QPaintEvent* event) override;
};
#endif // MAINWINDOW_H
