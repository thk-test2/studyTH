#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QString>
#include <qqml.h>

#include <QMediaPlayer>

#include <cstdio>
#include <memory>

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString videoURI READ videoURI WRITE setVideoURI NOTIFY videoURIChanged)
    QML_ELEMENT

public:
    explicit MediaPlayer(QObject *parent = nullptr);

    QString videoURI();
    void setVideoURI(const QString &videoURI);
    void play();
    void stop();

signals:
    void videoURIChanged();

private:
    QString m_videoURI;
    std::unique_ptr<QMediaPlayer> player;
};

#endif // MEDIAPLAYER_H
