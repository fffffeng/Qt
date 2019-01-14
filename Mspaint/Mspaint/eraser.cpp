#include "eraser.h"
#include "shap.h"
#include "QDebug"

Eraser::Eraser()
{
    ppix = QPixmap(800,800);
}

void Eraser::paint(QPainter &painter)
{
//    QRect rect=QRect(startpoint,QPoint(endpoint.x()+10,endpoint.y()+10));  //姗＄毊鎿﹀ぇ灏?
//    painter.eraseRect(rect);
//    startpoint = endpoint;
}

void Eraser::paint_eraser(QPainter &painter, QPixmap& pix)
{
    qDebug()<<"this is eraser";

    QPainter newpainter(&ppix);
    newpainter.drawPixmap(0,0,pix);
    newpainter.setCompositionMode(QPainter::CompositionMode_Clear);
    QPen newpen = Pen;
    newpen.setColor(Qt::red);
    newpainter.setPen(newpen);
    newpainter.drawLine(startpoint,endpoint);
    startpoint = endpoint;

    QPainter p(&pix);
    p.drawPixmap(0,0,ppix);
    pix = ppix;
    painter.drawPixmap(0,0,pix);
}
