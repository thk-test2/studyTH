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
        m_mediaName = it.next();
    }
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
    QString mediaStr = QString("qrc"+m_mediaName);
    qDebug() << mediaStr;

    m_player->setMedia(QUrl(mediaStr));
    m_player->setVolume(50);
    m_player->play();
}

void MediaPlayer::stop()
{
    qDebug() << "Stop";
    m_player->stop();
}
