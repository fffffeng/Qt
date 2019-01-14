#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QAction>
#include "shap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    //发出信号和paint类通信,在paint类画图形。参数是要画的图形编号
    void drawCurrentShap(Shap::Number num);
    void sendSize(int Size);
    void sendStyle(Qt::PenStyle style);
    void sendIsfill(bool b);
    void sendcolor1(Qt::GlobalColor color);
    void sendcolor2(Qt::GlobalColor color);

private slots:
    void open_File();//暂时未实现
    void bulid_File();
    void save_File();

    void drawLines_button();//图形形状
    void drawLine_button();
    void drawRect_button();
    void drawEllipse_button();
    void eraser_button();

    void click_DashLine();//虚线
    void click_DotLine();
    void click_DashDotLine();
    void click_CustomDashLine();
//    void drawText_button();

    void setSizepx1();//粗细
    void setSizepx3();
    void setSizepx5();
    void setSizepx8();

    void clickfillYes();//是否填充
    void clickfillNo();

    void clickcolor1_red();//颜色
    void clickcolor1_yellow();
    void clickcolor1_blue();
    void clickcolor2_red();
    void clickcolor2_green();
    void clickcolor2_blue();


private:
    Ui::MainWindow *ui;
    //工具栏的事件标志
    QAction *drawlines;//线条
    QAction *drawline;//直线
    QAction *drawrect;//矩形
    QAction *drawEllipse;//椭圆
    QAction *eraser;    //橡皮擦
    QAction *text;//文本

    QAction *px1;//粗细
    QAction *px3;
    QAction *px5;
    QAction *px8;

    QAction *DashLine;
    QAction *DotLine;
    QAction *DashDotLine;
    QAction *CustomDashLine;

    QAction *color1[3];
    QAction *color2[3];

    QAction *fillYes;
    QAction *fillNo;

//    QColor color_array[2];//color_array[0]存放画笔(轮廓)的颜色,color_array[1]填充的颜色
};

#endif // MAINWINDOW_H
