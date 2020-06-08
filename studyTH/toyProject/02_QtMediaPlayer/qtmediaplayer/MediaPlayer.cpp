#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QObject *parent) :
    QObject(parent)
{
}

QString MediaPlayer::userName()
{
    return m_userName;
}

void MediaPlayer::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
