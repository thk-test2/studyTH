#include "MediaPlayer.h"
#include <iostream>
#include <QMediaPlayer>
#include <QDirIterator>

MediaPlayer::MediaPlayer(QObject *parent) :
    QObject(parent),
    m_player(nullptr)
{
    m_player = new QMediaPlayer;
    connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    QDirIterator it(":/music", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        //qDebug() << it.next();
        m_mediaList = it.next();
    }
}

QString MediaPlayer::mediaName()
{
    return m_mediaName;
}

QString MediaPlayer::mediaList()
{
    return m_mediaList;
}

void MediaPlayer::setMediaName(const QString &mediaName)
{
    if (mediaName == m_mediaName)
        return;

    m_mediaName = mediaName;
    emit mediaNameChanged();
}

void MediaPlayer::start()
{
    QString mediaStr = QString("qrc:/music/"+m_mediaName);
    std::cout << mediaStr.toStdString() << std::endl;

    std::cout << m_mediaList.toStdString() << std::endl;

    m_player->setMedia(QUrl(mediaStr));
    m_player->setVolume(50);
    m_player->play();
}

void MediaPlayer::stop()
{
    std::cout << "Stop" << std::endl;
    m_player->stop();
}
