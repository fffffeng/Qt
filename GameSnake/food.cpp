#include "food.h"
#include "constants.h"
#include <QPainter>

Food::Food(qreal x, qreal y)
{
    setPos(x,y);

    setData(GD_Type,GO_Food);
}

void Food::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shap(),Qt::red);
    painter->restore();
}

QRectF Food::boundingRect()const
{
    return QRectF(-10,-10,20,20);
}
QPainterPath Food::shap()const
{
    QPainterPath path;
    path.addEllipse(-10/2,10/2,3,3);
    return path;
}
