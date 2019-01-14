#include "shap.h"
#include "rect.h"

Rect::Rect()
{

}

void Rect::paint(QPainter &painter)
{
    int x = startpoint.x();
    int y = startpoint.y();
    int m = endpoint.x();
    int n = endpoint.y();
    painter.setPen(Pen);

    if(fill)
    {
        painter.setBrush(color_fill);
    }
    else
        painter.setBrush(Qt::NoBrush);
    painter.drawRect(x,y,m-x,n-y);
}
