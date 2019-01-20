#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_scene(new QGraphicsScene(this)),
    m_view(new QGraphicsView(m_scene,this)),
    m_game(new GameController(*m_scene,this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

    this->statusBar()->hide();//隐藏状态栏
    this->resize(600,600);
    setWindowTitle("七彩吞天莽蛇");
    setWindowIcon(QIcon(":/images/1.jpg"));
    setCentralWidget(m_view);

    initScene();
    setSceneBackground();
    //时刻调整Item处于方格子中心
    QTimer::singleShot(0,this,SLOT(adjustItem()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    m_scene->setSceneRect(-100,-100,200,200);
}

void MainWindow::setSceneBackground()
{
    QPixmap bg(10,10);
    QPainter painter(&bg);
    QBrush brush(Qt::gray);
    painter.setBrush(brush);
    painter.drawRect(0,0,10,10);

    m_scene->setBackgroundBrush(QBrush(bg));
}

void MainWindow::adjustItem()
{
    m_view->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}
