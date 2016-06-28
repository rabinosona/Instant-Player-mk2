#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videowindow.h"
#include "setofbuttons.h"

videoWindow *ptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    videoWindow *video = new videoWindow;
    QVideoWidget *video_wid = new QVideoWidget;
    QSlider *timeline = new QSlider;
    video ->filename = new QString;

    this->setCentralWidget(video_wid);
    video->video_enable(video_wid); // enable video
    ui->statusBar->addPermanentWidget(timeline);
    timeline->setOrientation(Qt::Horizontal);

    connect(video->player, &QMediaPlayer::durationChanged, timeline, &QSlider::setMaximum);
    connect(video->player, &QMediaPlayer::positionChanged, timeline, &QSlider::setValue);
    connect(timeline, &QSlider::sliderMoved, video->player, &QMediaPlayer::setPosition);

    ptr = video; // assign video's address to the global pointer.
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenFile_triggered()
{

    ptr->handleFile();
}

void MainWindow::on_actionActionPlay_triggered()
{
    if (ptr != 0)
        ptr->player->play();
}

void MainWindow::on_PauseVideo_triggered()
{
    if (ptr != 0)
        ptr->player->pause();
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::exit();
}

void MainWindow::on_StopVideo_triggered()
{
    if (ptr != 0)
        ptr->player->stop();
}
