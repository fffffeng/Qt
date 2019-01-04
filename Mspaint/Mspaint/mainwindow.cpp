
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QAction>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include "PaintShap.h"
#include "shap.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800,600);
    setWindowTitle("mspaint");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    //设置菜单栏
    QMenu *file = ui->menuBar->addMenu(tr("文件"));
    QActionGroup *group = new QActionGroup(this);

    QAction *openFile = group->addAction(tr("打开文件"));
    QAction *bulidFile = group->addAction(tr("新建文件"));
    QAction *saveFile = group->addAction(tr("保存文件"));
    file->addAction(openFile);
    file->addAction(bulidFile);
    file->addAction(saveFile);

    connect(openFile,SIGNAL(triggered()),this,SLOT(open_File()));
    connect(bulidFile,SIGNAL(triggered()),this,SLOT(bulid_File()));
    connect(saveFile,SIGNAL(triggered()),this,SLOT(save_File()));

    //设置工具栏
    QToolBar *tooBar = this->addToolBar(tr("Tool"));
    tooBar->setIconSize(QSize(30,30));
    tooBar->setStyleSheet("background-color:rgb(199,237,204)");//背景色

    drawlines = new QAction("Lines",tooBar);
    drawlines->setIcon(QIcon(":/image/lines.png"));
    tooBar->addAction(drawlines);

    drawline = new QAction("line",tooBar);
    drawline->setIcon(QIcon(":/image/line.png"));
    tooBar->addAction(drawline);

    drawrect = new QAction("rect",tooBar);
    drawrect->setIcon(QIcon(":/image/rect.png"));
    tooBar->addAction(drawrect);

    drawEllipse = new QAction("ellipse",tooBar);
    drawEllipse->setIcon(QIcon(":/image/ellipse.png"));
    tooBar->addAction(drawEllipse);

    //虚线
    QToolButton *linebtn = new QToolButton;
    linebtn->setText("虚线");
    QMenu *lineMenu = new QMenu;
    QActionGroup *linegroup = new QActionGroup(tooBar);
    DashLine = linegroup->addAction(QIcon(":/image/dashline.png"),"DashLine");
    DashLine->setCheckable(true);
    DotLine = linegroup->addAction(QIcon(":/image/dotline.png"),"dotline");
    DotLine->setCheckable(true);
    DashDotLine = linegroup->addAction(QIcon(":/image/dashdotline.png"),"doshdotline");
    DashDotLine->setCheckable(true);
    CustomDashLine = linegroup->addAction(QIcon(":/image/CustomDashLine.png"),"CustomDashLine");
    CustomDashLine->setCheckable(true);
    lineMenu->addAction(DashLine);
    lineMenu->addAction(DotLine);
    lineMenu->addAction(DashDotLine);
    lineMenu->addAction(CustomDashLine);
    linebtn->setMenu(lineMenu);
    linebtn->setPopupMode(QToolButton::MenuButtonPopup);
    tooBar->addWidget(linebtn);

    //橡皮擦
    eraser = new QAction("橡皮擦 ",tooBar);
    eraser->setIcon(QIcon(":image/eraser.png"));
    tooBar->addAction(eraser);


    px1 = new QAction("1px",tooBar);
    px3 = new QAction("3px",tooBar);
    px5 = new QAction("5px",tooBar);
    px8 = new QAction("8px",tooBar);
    QToolButton* sizetool = new QToolButton(tooBar);
    sizetool->setText(tr("size"));
    QMenu* sizemenu = new QMenu(tooBar);
    sizemenu->addAction(px1);
    sizemenu->addAction(px3);
    sizemenu->addAction(px5);
    sizemenu->addAction(px8);
    sizetool->setMenu(sizemenu);
    sizetool->setPopupMode(QToolButton::MenuButtonPopup);
    tooBar->addWidget(sizetool);

    //颜色
    QToolButton *color1btn = new QToolButton();
    color1btn->setText("颜色1");
    QToolButton *color2btn = new QToolButton();
    color2btn->setText("颜色2");
    QMenu *color1menu = new QMenu();
    QMenu *color2menu = new QMenu();
    QActionGroup *group1 = new QActionGroup(tooBar);
    QActionGroup *group2 = new QActionGroup(tooBar);
    color1[0] = group1->addAction(QIcon(":/image/red.png"),"red");
    color1[0]->setCheckable(true);
    color1[1] = group1->addAction(QIcon(":/image/yellow.png"),"yellow");
    color1[1]->setCheckable(true);
    color1[2] = group1->addAction(QIcon(":/image/blue.png"),"blue");
    color1[2]->setCheckable(true);
    color2[0] = group2->addAction(QIcon(":/image/red.png"),"red");
    color2[0]->setCheckable(true);
    color2[1] = group2->addAction(QIcon(":/image/green.png"),"green");
    color2[1]->setCheckable(true);
    color2[2] = group2->addAction(QIcon(":/image/blue.png"),"blue");
    color2[2]->setCheckable(true);
    color1menu->addSeparator();
    color2menu->addSeparator();
    for(int i = 0; i < 3; ++i)
    {
        color1menu->addAction(color1[i]);
        color2menu->addAction(color2[i]);
    }
    color1btn->setMenu(color1menu);
    color2btn->setMenu(color2menu);
    color1btn->setPopupMode(QToolButton::MenuButtonPopup);
    color2btn->setPopupMode(QToolButton::MenuButtonPopup);
    tooBar->addWidget(color1btn);
    tooBar->addWidget(color2btn);


    //填充
    QToolButton *fillbtn = new QToolButton(tooBar);
    fillbtn->setText(tr("填充"));
    QMenu *fillChoseMenu = new QMenu(fillbtn);
    QActionGroup *fillgroup = new QActionGroup(tooBar);
    fillYes = fillgroup->addAction(tr("yes"));
    fillYes->setCheckable(true);
    fillNo = fillgroup->addAction(tr("No"));
    fillNo->setCheckable(true);

    fillChoseMenu->addSeparator();
    fillChoseMenu->addAction(fillYes);
    fillChoseMenu->addAction(fillNo);
    fillbtn->setMenu(fillChoseMenu);
    fillbtn->setPopupMode(QToolButton::MenuButtonPopup);
    tooBar->addWidget(fillbtn);


    connect(drawlines,SIGNAL(triggered()),this,SLOT(drawLines_button()));
    connect(drawline,SIGNAL(triggered()),this,SLOT(drawLine_button()));
    connect(drawrect,SIGNAL(triggered()),this,SLOT(drawRect_button()));
    connect(drawEllipse,SIGNAL(triggered()),this,SLOT(drawEllipse_button()));

    connect(DashLine,SIGNAL(triggered()),this,SLOT(click_Dashline()));
    connect(DotLine,SIGNAL(triggered()),this,SLOT(click_DotLine()));
    connect(DashDotLine,SIGNAL(triggered()),this,SLOT(click_DashDotLine()));
    connect(CustomDashLine,SIGNAL(triggered()),this,SLOT(click_CustomDashLine()));

    connect(eraser,SIGNAL(triggered()),this,SLOT(eraser_button()));

    connect(px1,SIGNAL(triggered()),this,SLOT(setSizepx1()));
    connect(px3,SIGNAL(triggered()),this,SLOT(setSizepx3()));
    connect(px5,SIGNAL(triggered()),this,SLOT(setSizepx5()));
    connect(px8,SIGNAL(triggered()),this,SLOT(setSizepx8()));

    connect(fillYes,SIGNAL(triggered()),this,SLOT(clickfillYes()));
    connect(fillNo,SIGNAL(triggered()),this,SLOT(clickfillNo()));

    connect(color1[0],SIGNAL(triggered()),this,SLOT(clickcolor1_red()));
    connect(color1[1],SIGNAL(triggered()),this,SLOT(clickcolor1_yellow()));
    connect(color1[2],SIGNAL(triggered()),this,SLOT(clickcolor1_blue()));
    connect(color2[0],SIGNAL(triggered()),this,SLOT(clickcolor2_red()));
    connect(color2[1],SIGNAL(triggered()),this,SLOT(clickcolor2_green()));
    connect(color2[2],SIGNAL(triggered()),this,SLOT(clickcolor2_blue()));


    PaintShap *paintshap = new PaintShap(this);
    setCentralWidget(paintshap);
    connect(this,SIGNAL(sendStyle(Qt::PenStyle)),paintshap,SLOT(setStyle(Qt::PenStyle)));

    connect(this,SIGNAL(sendSize(int)),paintshap,SLOT(setSize(int)));

    connect(this,SIGNAL(drawCurrentShap(Shap::Number)),
            paintshap,SLOT(SetCurrentShap(Shap::Number)));

    connect(this,SIGNAL(sendIsfill(bool)),paintshap,SLOT(setIsfill(bool)));

    connect(this,SIGNAL(sendcolor1(Qt::GlobalColor)),paintshap,SLOT(setcolor1(Qt::GlobalColor)));
    connect(this,SIGNAL(sendcolor2(Qt::GlobalColor)),paintshap,SLOT(setcolor2(Qt::GlobalColor)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_File()
{
    qDebug()<<"打开文件";
}

void MainWindow::bulid_File()
{
    qDebug()<<"新建文件";
}

void MainWindow::save_File()
{
    qDebug()<<"保存文件";
}

void MainWindow::drawLines_button()
{
    qDebug()<<"画线";
    emit drawCurrentShap(Shap::lines);
}

void MainWindow::drawLine_button()
{
    qDebug()<<"画直线 ";

    emit drawCurrentShap(Shap::line);
}

void MainWindow::drawRect_button()
{
    qDebug()<<"画矩形 ";

    emit drawCurrentShap(Shap::rect);
}

void MainWindow::drawEllipse_button()
{
    qDebug()<<"画椭圆 ";
    emit drawCurrentShap(Shap::ellipse);
}

void MainWindow::eraser_button()
{
    emit drawCurrentShap(Shap::eraser);
}

void MainWindow::click_DashLine()
{
    emit sendStyle(Qt::DashLine);
}

void MainWindow::click_DotLine()
{
    emit sendStyle(Qt::DotLine);
}

void MainWindow::click_DashDotLine()
{
    emit sendStyle(Qt::DashDotLine);
}

void MainWindow::click_CustomDashLine()
{
    emit sendStyle(Qt::CustomDashLine);
}


//void MainWindow::drawText_button()
//{
//    qDebug()<<"文本";
//    emit drawCurrentShap(Shap::text);
//}

void MainWindow::setSizepx1()
{
    emit sendSize(1);
}

void MainWindow::setSizepx3()
{
    emit sendSize(3);
}

void MainWindow::setSizepx5()
{
    emit sendSize(5);
}

void MainWindow::setSizepx8()
{
    emit sendSize(8);
}

void MainWindow::clickfillNo()//点击no的槽函数
{
    emit sendIsfill(false);
    qDebug()<<"click no!";
}

void MainWindow::clickcolor1_red()
{
    emit sendcolor1(Qt::red);
}

void MainWindow::clickcolor1_yellow()
{
    emit sendcolor1(Qt::yellow);
}

void MainWindow::clickcolor1_blue()
{
    emit sendcolor1(Qt::blue);
}

void MainWindow::clickcolor2_red()
{
    emit sendcolor2(Qt::red);
}

void MainWindow::clickcolor2_green()
{
    emit sendcolor2(Qt::green);
}

void MainWindow::clickcolor2_blue()
{
    emit sendcolor2(Qt::blue);
}


void MainWindow::clickfillYes()//点击yes的槽函数
{
    emit sendIsfill(true);
     qDebug()<<"click yes!";
}

