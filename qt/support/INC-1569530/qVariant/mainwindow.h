#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class LogList;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVariant getValue();
private:
    std::unique_ptr<LogList> m_list;
//    LogList* m_list = nullptr;
};
#endif // MAINWINDOW_H
