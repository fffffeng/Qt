#include "shap.h"
#include "line.h"

Line::Line()
{

}

void Line::paint(QPainter &painter)
{
    painter.setPen(Pen);
    painter.drawLine(startpoint,endpoint);


}

//void Line::newpaint(QPainter &painter, QPixmap &pix)
//{
//    QPainter p(&pix);
//    p.drawLine(startpoint,endpoint);
//    painter.drawPixmap(0,0,pix);
//}
