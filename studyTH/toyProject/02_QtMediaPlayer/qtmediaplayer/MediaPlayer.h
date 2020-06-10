#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>

class QMediaPlayer;

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    QML_ELEMENT

public:
    explicit MediaPlayer(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
signals:
    void userNameChanged();

private:
    QString m_userName;
    QMediaPlayer* m_player;
};

#endif // BACKEND_H
