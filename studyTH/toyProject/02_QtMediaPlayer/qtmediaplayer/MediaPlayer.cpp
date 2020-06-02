#include "MediaPlayer.h"

#include <QMessageLogger>
#include <iostream>
#include <cstdio>

MediaPlayer::MediaPlayer(QObject *parent) :
    QObject(parent)
{
    std::cout << "TEST: THK" << std::endl;
    printf("THKTHKTHKTHK\n");
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

    std::cout << "TEST: " << m_videoURI.toStdString() << std::endl;
    printf("THKTHKTHKTHK\n");
    emit videoURIChanged();
}
