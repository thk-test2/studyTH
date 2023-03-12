#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QLabel>
#include <QPainterPath>

class QPainter;
class QPoint;

class PainterWidget : public QLabel
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
public slots:
    void showImage(QString);
    void saveImage(QString);
signals:
private:
    QPainter* m_painter;
    QPainterPath m_path;
    QPixmap* m_pixmap;
};

#endif // PAINTERWIDGET_H
