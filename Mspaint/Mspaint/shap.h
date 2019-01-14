#ifndef SHAP_H
#define SHAP_H
#include <QPoint>
#include <QPainter>
//#include "paintshap.h"

class Shap:public QObject{
    Q_OBJECT
public:

    Shap();

    enum Number{    //给图形编号
        None,
        lines,
        line,
        rect,
        ellipse,
        text,
        eraser,
    };

   void virtual paint(QPainter &painter) = 0;
   void virtual paint_Lines(QPainter &painter,QPixmap &pix);
   void virtual paint_eraser(QPainter &painter, QPixmap& pix);

public:
   QPoint startpoint; //起点
   QPoint endpoint;   //终点
//   QColor color;
   QPen Pen;    //设置画（颜色，连线风格）
   QColor color_fill;   //填充的颜色
   bool fill;  //是否需要填充
   bool iseraser;

};

#endif // SHAP_H
