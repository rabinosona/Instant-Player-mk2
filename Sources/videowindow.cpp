#include "videowindow.h"
#include "mainwindow.h"

int i = 1;

videoWindow::videoWindow()
{
    count = new int;
    *count = 1;
}

videoWindow::~videoWindow()
{
     delete player;
     delete playlist;
     delete videoWid;
     delete filename;
}

void videoWindow::video_enable(const QString &path)
{

    playlist->addMedia(QUrl::fromLocalFile(path)); // add user's media and play it.
    playlist->next();
    player->play();


}

void videoWindow::video_enable(QVideoWidget *output)
{
    player = new QMediaPlayer; // set up the basic variables

    playlist = new QMediaPlaylist;
    player->setPlaylist(playlist);
    playlist->setCurrentIndex(1); // start from a first video in the playlist
    player->setVideoOutput(output);
    player->play();
    count++;
}

void videoWindow::handlePlay()
{
    player->play();
}

void videoWindow::handleStop()
{
    player->pause();
}

void videoWindow::handleForward()
{
    player->setPosition(player->position() + 30000);
}

void videoWindow::handleBackward()
{
    player->setPosition(player->position() - 10000);
}

void videoWindow::handleFile()
{
    if (i != 1)
    {
    player->stop();
    playlist->removeMedia(1);
    }
    *filename = QFileDialog::getOpenFileName();
    qDebug() << *filename;
    qDebug() << i;
    video_enable(*filename);
    i++;
}
