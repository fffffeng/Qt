#ifndef PAINTSHAP_H
#define PAINTSHAP_H
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QPoint>
#include "shap.h"
#include <QVector>



//对各种的图形的统装
class Shap;

class PaintShap : public QWidget
{
    Q_OBJECT
 public:
    PaintShap(QWidget *parent = 0);
    ~PaintShap();

public slots:
    void SetCurrentShap(Shap::Number num_shap);
    void setSize(int Size);
    void setIsfill(bool b);
    void setStyle(Qt::PenStyle style);
    void setcolor1(Qt::GlobalColor color);
    void setcolor2(Qt::GlobalColor color);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool flag;
    Shap *shap;
    Shap::Number num;
    QVector<Shap*> vector;
    int begin;
    int end;

    QPixmap pix;//画布;铅笔线画的所有内容都在这里
    QPixmap tmppix;//（存放橡皮擦擦过的图像）
    bool isLinesshap;
    bool isEraser;
    bool finish;

    QPen _pen;
    int _size;//这里的粗细，颜色由槽函数设定，，之后画笔是由这里决定
    Qt::PenStyle _style;
    Qt::GlobalColor _color1;
    Qt::GlobalColor _color2;
    bool isfill;


};

#endif // PAINTSHAP_H
