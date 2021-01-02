#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QPainterPath>

class QPainter;
class QPoint;

class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
public slots:
signals:
private:
    QPainter* m_painter;
    QPainterPath m_path;
    QPoint m_startPoint;
    QPoint m_endPoint;
};

#endif // PAINTERWIDGET_H
