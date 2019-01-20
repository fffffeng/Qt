#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/Images/3.jpg");
    pixmap.scaled(QSize(600,400),Qt::KeepAspectRatio);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);

//      setAttribute(Qt::WA_TranslucentBackground, true);
//    this->setStyleSheet("background:url(:/Images/3.jpg)");

    setWindowTitle("优听音乐");
    setWindowIcon(QIcon(":/Images/4.jpg"));
    this->resize(600,400);

//    m_centerWindow = new QWidget;
//    setCentralWidget(m_centerWindow);

    hbox1 = new QHBoxLayout;    //水平布局
    hbox2 = new QHBoxLayout;

    vbox1 = new QVBoxLayout;    //垂直布局
    vbox2 = new QVBoxLayout;

    glayout = new QGridLayout;

    m_seekSlider = new QSlider(Qt::Horizontal,this);
    m_seekSlider->setGeometry(100,345,300,15);
    m_seekSlider->setObjectName(tr("seekSlider"));
    m_seekSlider->setCursor(QCursor(Qt::PointingHandCursor));//设置光标形状为食指

    m_btnPlayOrPause = new QPushButton;    //播放
    m_btnPlayOrPause->setIcon(QIcon(":/Images/7.png"));
    m_btnPlayOrPause->setIconSize(QSize(30,30));
    m_btnPlayOrPause->setFixedSize(QSize(35,30));//设置按钮大小
    m_isPlaying = true;

    m_btnPrevious = new QPushButton;
    m_btnPrevious->setIcon(QIcon(":/Images/5.png"));
    m_btnPrevious->setIconSize(QSize(30,30));
    m_btnPrevious->setFixedSize(QSize(35,30));

    m_btnNext = new QPushButton;
    m_btnNext->setIcon(QIcon(":/Images/6.png"));
    m_btnNext->setIconSize(QSize(30,30));
    m_btnNext->setFixedSize(QSize(35,30));

    m_ted = new QTextEdit(this);  //播放列表
    QPalette p;
    p.setColor(QPalette::Base,QColor(255,0,0,0));
    m_ted->setPalette(p);
    m_ted->move(5,5);
    m_ted->setFixedSize(200,300);

    //m_ted->setStyleSheet("./Images/2.jpg");


    hbox1->addWidget(m_ted);
    hbox1->addWidget(m_seekSlider);

//    hbox2->addWidget(m_seekSlider);

//    hbox3->addWidget(m_btnPlayOrPause);
//    hbox3->addWidget(m_btnPrevious);
//    hbox3->addWidget(m_btnNext);

//    vbox1->addWidget(m_ted);
//    vbox1->addWidget(m_seekSlider);
    vbox1->addLayout(hbox1);

    this->setLayout(vbox1);

   // m_centerWindow->setLayout(hbox2);
   // m_centerWindow->setLayout(hbox3);


   // m_centerWindow->show();

    connect(m_btnPlayOrPause,SIGNAL(clicked()),this,SLOT(player()));
    //connect(m_btnPause,SIGNAL(clicked()),this,SLOT(pause()));
    connect(m_btnNext,SIGNAL(clicked()),this,SLOT(nextSong()));
    connect(m_btnPrevious,SIGNAL(clicked()),this,SLOT(previousSong()));

    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::player()
{
    if(m_isPlaying)
    {
        qDebug()<<"播放";
        m_isPlaying = false;
    }
    else
    {
        qDebug()<<"暂停";
        m_isPlaying = true;
    }

}


void MainWindow::previousSong()
{
    qDebug()<<"上一曲歌";
}

void MainWindow::nextSong()
{
    qDebug()<<"下一曲歌";
}
