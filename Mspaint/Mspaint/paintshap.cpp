#include "paintshap.h"
#include "shap.h"
#include <QPaintEvent>
#include "lines.h"
#include "line.h"
#include "rect.h"
#include "eraser.h"
#include "ellipse.h"
#include "QDebug"
#include <QPicture>


PaintShap::PaintShap(QWidget *parent)
    :QWidget(parent)
{
    pix = QPixmap(800,800);
    pix.fill(Qt::white);

    flag = false;
    shap = new Lines;
    num = Shap::None;   //默认不画图形
    isLinesshap = true;
    begin = 0;
    end = 0;
    isfill = false;//默认不填充

    //设置画笔粗细、颜色
    _size = 1;
    _color1 = Qt::black;
    _color2 = Qt::black;
}

PaintShap::~PaintShap()
{

}

void PaintShap::SetCurrentShap(Shap::Number num_shap)
{
 //   qDebug()<<"setCurrentShap";
    if(num_shap != this->num)
    {
        this->num = num_shap;
    }
}

void PaintShap::setSize(int Size)
{
    _size = Size;
    qDebug()<<"size";
}

void PaintShap::setIsfill(bool b)
{
    isfill = b;
    shap->fill = b;
    qDebug()<<"paintshap: isfill="<<b;
}

void PaintShap::setStyle(Qt::PenStyle style)
{
    qDebug()<<"hhhhhhhhhhhhhhhhhhhhhh";
    _style = style;
    _pen.setStyle(style);
}

void PaintShap::setcolor1(Qt::GlobalColor color)
{
    qDebug()<<color;
    _color1 =color;
}

void PaintShap::setcolor2(Qt::GlobalColor color)
{
    qDebug()<<color;
    _color2 = color;
}


void PaintShap::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //QPen pen(color1,size);
    _pen.setColor(_color1);
    _pen.setWidth(_size);
    //pen.setStyle(_style);
    painter.setPen(_pen);

    //将pix里的所有内容复制到this中
    painter.drawPixmap(0,0, 800, 800, pix);
    qDebug()<<"begin="<<begin<<"end="<<end;

    if(isLinesshap)//接下来是画铅笔线
    {
        qDebug()<<"lines";
        for(int i = begin; i < end; ++i)//vector里存放了所有图形，复制到pix中
        {
            QPainter p(&pix);
            QPen pen(vector[i]->Pen);
            p.setPen(pen);
            vector[i]->paint(p);
        }
        shap->paint_Lines(painter,pix);//最后还是将pix的所有内容滑倒this中;
                                      //(原本在this(widget)上的内容，最后也在pix上显示。
        painter.drawPixmap(0,0,800,800,tmppix);
    }
    else if(isEraser)//橡皮擦
    {
        qDebug()<<"eraser";

       for(int i = begin; i < end; ++i)//重现之前的图形
        {
            QPainter p(&tmppix);
            QPen pen(vector[i]->Pen);
            p.setPen(pen);
            vector[i]->paint_eraser(painter,pix);
            vector[i]->paint(p);
        }

        shap->paint_eraser(painter,pix);

        QPainter temp_painter(&tmppix);
        temp_painter.drawPixmap(0,0,pix);
    }
    else
    {
        //shap->paint(painter);
        if(finish == true)
        {
            for(int i = begin; i<end; ++i)//vector里存放了所有图形，复制到pix中
            {
                QPainter p(&pix);
                QPen pen(vector[i]->Pen);
                 p.setPen(pen);
                 vector[i]->paint(p);
            }
        }
        shap->paint(painter);

        painter.drawPixmap(0,0,800,800,tmppix);
    }
}

void PaintShap::mousePressEvent(QMouseEvent *event)
{
    //选定要画的图形
    switch (num) {
    case Shap::None:
    {
        return;
    }
    case Shap::lines:
    {

        shap = new Lines;
        isLinesshap = true;
        isEraser = false;
        break;
    }
    case Shap::line:
    {
        shap = new Line;
        isLinesshap = false;
        isEraser = false;
        break;
    }
    case Shap::rect:
    {
        shap = new Rect;
        isLinesshap = false;
        isEraser = false;
        break;
    }
    case Shap::ellipse:
    {
        shap = new Ellipse;
        isLinesshap = false;
        isEraser = false;
        break;
    }
    case Shap::eraser:
    {
        shap = new Eraser;
        isLinesshap = false;
        isEraser = true;
        break;
    }
    default:
        break;
    }

    if(shap)
    {
        shap->iseraser = true;

        vector.push_back(shap);
        if(isEraser)
        {
            begin = vector.size();

        }
        shap->Pen = _pen;
        shap->fill = isfill;
        if(shap->fill == true)
            shap->color_fill = _color2;
        end = vector.size();
        flag = false;
        finish = false;

        shap->startpoint = event->pos();
        shap->endpoint = shap->startpoint;
    }
}

void PaintShap::mouseMoveEvent(QMouseEvent *event)
{
    if(num == Shap::None)
        return;
    if(shap && !flag)
    {
        shap->endpoint = event->pos();
        update();
    }

   qDebug()<<vector.size()<<endl;
}

void PaintShap::mouseReleaseEvent(QMouseEvent *event)
{
    if(num == Shap::None)
        return;
    shap->endpoint = event->pos();
    flag = true;
    finish = true;
    update();
}
