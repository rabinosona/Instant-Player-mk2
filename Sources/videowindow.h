#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include "mainwindow.h"
#include <ui_mainwindow.h>

class videoWindow: public QObject
{
    Q_OBJECT

private slots:
   void handlePlay();
   void handleStop();
   void handleForward();
   void handleBackward();
private:
    QMediaPlaylist *playlist;
    QVideoWidget *videoWid;
public:
    videoWindow();
    ~videoWindow();

    void video_enable(const QString &path); // ask for widget as an output and for a QString path
    void video_enable(QVideoWidget *output);
       void handleFile();

    QString *filename;
    QMediaPlayer *player;
    int *count;
};

#endif // VIDEOWINDOW_H
