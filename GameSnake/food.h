#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>


class Food : public QGraphicsItem
{
public:
    Food(qreal x,qreal y);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
};

#endif // FOOD_H
