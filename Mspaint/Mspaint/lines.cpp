
#include "lines.h"
#include <QDebug>
Lines::Lines()
{
    isfinish = false;
}


void Lines::paint(QPainter &painter)
{

}

void Lines::paint_Lines(QPainter &painter, QPixmap& pix)
{
    QPainter p(&pix);
    p.setPen(Pen);
    p.drawLine(startpoint,endpoint);
    startpoint = endpoint;

    painter.drawPixmap(0,0,pix);


}

