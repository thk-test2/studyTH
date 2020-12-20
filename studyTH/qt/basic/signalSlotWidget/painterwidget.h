#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>

class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
public slots:
    void showWidget(QWidget* parent = nullptr);
signals:
};

#endif // PAINTERWIDGET_H
