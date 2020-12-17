#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QPushButton;
class ReceiverWidget;
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
    void loadFile();
    void showReceiverWidget();
signals:
    void showReceiver(QWidget*);
private:
    QPushButton* m_button;
    ReceiverWidget* m_receiver;
    QTextEdit* m_tEdit;
};
#endif // MAINWINDOW_H
