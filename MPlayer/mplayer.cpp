#include "mplayer.h"
#include "ui_mplayer.h"

MPlayer::MPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MPlayer)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer(this);

    ui->slider_Volume->setValue (40);

}

MPlayer::~MPlayer()
{
    delete ui;
}

void MPlayer::on_btn_Play_clicked()
{
    if(mediaPlayer->isAvailable ()){

        if(filePath.endsWith (".mp3")){
            playAudio ();
        } else if(filePath.endsWith (".wma")){
            playAudio ();
        } else if(filePath.endsWith (".wav")){
            playAudio ();
        } else {
            QMessageBox::information (this, "Warning !", "Nu e suportat fisierul!", QMessageBox::Ok);
        }
    }
    
}

void MPlayer::on_slider_Volume_valueChanged(int value)
{
    mediaPlayer->setVolume (value);
}

void MPlayer::on_actionOpen_triggered()
{
    filePath = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"/Audio File",tr("Audio file (*.mp3 *.wav *.)"));
}

void MPlayer::on_actionExit_triggered()
{
    this->close ();
}

void MPlayer::on_btn_Stop_clicked()
{
    mediaPlayer->stop ();
    ui->btn_Play->setEnabled (true);
    ui->btn_Stop->setEnabled (false);
    ui->btn_Pause->setEnabled (false);
}

void MPlayer::on_btn_Pause_clicked()
{
    mediaPlayer->pause ();
    ui->btn_Play->setEnabled (true);
    ui->btn_Stop->setEnabled (true);
    ui->btn_Pause->setEnabled (false);
}

void MPlayer::on_btn_Open_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"/Audio File",tr("Audio file (*.mp3 *.wav *.wma *.amr *.mp4 *.avi *.VOB *.mpeg)"));
}

void MPlayer::on_btn_Close_clicked()
{
    this->close ();
}

void MPlayer::playAudio (){
    if(!filePath.isNull ()){
        mediaPlayer->setMedia (QUrl::fromLocalFile (filePath));
        mediaPlayer->setVolume (ui->slider_Volume->value ());
        mediaPlayer->play ();
        ui->btn_Play->setEnabled (false);
        ui->btn_Stop->setEnabled (true);
        ui->btn_Pause->setEnabled (true);
    } else {
        QMessageBox::information (this, "Selectare fisier", "Selectati un fisier ...", QMessageBox::Ok);
    }
}

void MPlayer::keyPressEvent (QKeyEvent *event){
    if(event->key () == Qt::Key_Up){
        mediaPlayer->setVolume (ui->slider_Volume->value ()+5);
    } else if(event->key () == Qt::Key_Down){
        mediaPlayer->setVolume (ui->slider_Volume->value ()-5);
    }
}
