#include "shap.h"
#include "ellipse.h"

Ellipse::Ellipse()
{

}

void Ellipse::paint(QPainter &painter)
{
    int x = startpoint.x();
    int y = startpoint.y();
    int width = endpoint.x()-x;
    int heigth = endpoint.y()-y;
    painter.setPen(Pen);
    if(fill)
    {
        painter.setBrush(color_fill);
    }
    else
        painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(x,y,width,heigth);
}
