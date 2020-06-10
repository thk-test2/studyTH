#include "MediaPlayer.h"
#include <iostream>
#include <QMediaPlayer>

MediaPlayer::MediaPlayer(QObject *parent) :
    QObject(parent),
    m_player(nullptr)
{
    m_player = new QMediaPlayer;
    connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
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

void MediaPlayer::start()
{
    std::cout << "Start" << std::endl;
    m_player->setMedia(QUrl("qrc:/music/5mg.mp3"));
    m_player->setVolume(50);
    m_player->play();
}

void MediaPlayer::stop()
{
    std::cout << "Stop" << std::endl;
    m_player->stop();
}
