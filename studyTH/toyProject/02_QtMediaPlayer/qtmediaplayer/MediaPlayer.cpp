#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QObject *parent) :
    QObject(parent),
    player(std::unique_ptr<QMediaPlayer>(new QMediaPlayer()))
{
}

QString MediaPlayer::videoURI()
{
    return m_videoURI;
}

void MediaPlayer::setVideoURI(const QString &videoURI)
{
    if (videoURI == m_videoURI)
        return;

    m_videoURI = videoURI;
    QMessageLogger().debug() << m_videoURI;
    emit videoURIChanged();
}

void MediaPlayer::play()
{
    printf("THK play\n");
}

void MediaPlayer::stop()
{
    printf("THK stop\n");
}
