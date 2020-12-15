#ifndef RECEIVERWIDGET_H
#define RECEIVERWIDGET_H

#include <QWidget>

class ReceiverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiverWidget(QWidget *parent = nullptr);

public slots:
    void showWidget();
signals:
};

#endif // RECEIVERWIDGET_H
