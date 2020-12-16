#ifndef RECEIVERWIDGET_H
#define RECEIVERWIDGET_H

#include <QWidget>

class ReceiverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiverWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
public slots:
    void showWidget(QWidget* parent = nullptr);
signals:
};

#endif // RECEIVERWIDGET_H
