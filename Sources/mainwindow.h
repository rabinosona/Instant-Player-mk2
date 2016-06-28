#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtDebug>
#include <QGraphicsVideoItem>
#include "videowindow.h"
#include "QDialog"
#include <iostream>
#include <cstddef>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OpenFile_triggered();

    void on_actionActionPlay_triggered();

    void on_PauseVideo_triggered();
    void on_actionExit_triggered();

    void on_StopVideo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
