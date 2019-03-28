#ifndef MPLAYER_H
#define MPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMediaPlaylist>

namespace Ui {
class MPlayer;
}

class MPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MPlayer(QWidget *parent = 0);
    ~MPlayer();

private slots:
    void on_btn_Play_clicked();

    void on_slider_Volume_valueChanged(int value);

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_btn_Stop_clicked();

    void on_btn_Pause_clicked();

    void on_btn_Open_clicked();

    void on_btn_Close_clicked();

private:
    Ui::MPlayer *ui;

    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoFrame;
    QFileDialog *fileDialog;
    QString filePath;
    long lastStates;
    QMediaPlaylist *playList;

    void playAudio();
    bool isPaused();

    void keyPressEvent (QKeyEvent *event);
};

#endif // MPLAYER_H
