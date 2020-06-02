#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QtMultimedia>
#include <QObject>
#include <QString>
#include <qqml.h>
#include <cstdio>

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString videoURI READ videoURI WRITE setVideoURI NOTIFY videoURIChanged)
    QML_ELEMENT

public:
    explicit MediaPlayer(QObject *parent = nullptr);

    QString videoURI();
    void setVideoURI(const QString &videoURI);
    void print() { printf("print TEST\n"); }

signals:
    void videoURIChanged();

private:
    QString m_videoURI;
};

#endif // MEDIAPLAYER_H
