#include "receiverwidget.h"

#include <QDebug>

ReceiverWidget::ReceiverWidget(QWidget *parent) : QWidget(parent)
{

}

void ReceiverWidget::showWidget()
{
    qDebug() << Q_FUNC_INFO;
}
