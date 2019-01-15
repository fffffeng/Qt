#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsItem>
#include "gamecontroller.h"

class GameController;

class Snake : public QGraphicsItem
{
public:
    Snake(GameController& controller);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
};

#endif // SNAKE_H
