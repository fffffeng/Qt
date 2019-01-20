#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>

class QMediaPlayer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;
    QHBoxLayout *hbox3;

    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;

    QGridLayout *glayout;

    QLabel  *lab1;
    QLabel  *lab2;


private slots:
    void player();//播放
    void previousSong();//上一曲
    void nextSong();//下一曲


private:
    Ui::MainWindow *ui;

    QTextEdit *m_ted;   //播放界面框
    QWidget *m_centerWindow;

    QMediaPlayer *m_music;//初始化音乐
    QMediaPlaylist *m_musicList;//播放列表
    QSlider *m_seekSlider;//进度条
    QPushButton *m_btnPlayOrPause;//播放按钮
    bool m_isPlaying;
    QPushButton *m_btnPrevious;//上一曲
    QPushButton *m_btnNext;    //下一曲

};

#endif // MAINWINDOW_H
