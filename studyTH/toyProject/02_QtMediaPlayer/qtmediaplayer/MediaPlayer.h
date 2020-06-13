#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>

class QMediaPlayer;

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mediaName READ mediaName WRITE setMediaName NOTIFY mediaNameChanged)
    Q_PROPERTY(QString mediaList READ mediaList NOTIFY mediaListChanged)
    QML_ELEMENT

public:
    explicit MediaPlayer(QObject *parent = nullptr);

    QString mediaName() { return m_mediaName; }
    QString mediaList() { return m_mediaList; }
    void setMediaName(const QString &mediaName);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
signals:
    void mediaNameChanged();
    void mediaListChanged();

private:
    QString m_mediaName;
    QMediaPlayer* m_player;
    QString m_mediaList;
};

#endif // BACKEND_H
