#include "MediaPlayer.h"

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
    emit mediaListChanged();
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
    qDebug() << mediaStr;
    qDebug() << m_mediaList;

    m_player->setMedia(QUrl(mediaStr));
    m_player->setVolume(50);
    m_player->play();
}

void MediaPlayer::stop()
{
    qDebug() << "Stop";
    m_player->stop();
}
