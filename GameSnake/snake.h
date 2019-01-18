#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsItem>
#include "gamecontroller.h"

class GameController;

class Snake : public QGraphicsItem
{
public:
    enum Directiion
    {
        NoMove,
        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight
    };

    Snake(GameController& controller);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape()const;
    QRectF boundingRect()const;

    void setMoveDirection(Directiion d);

protected:
    void advance(int phase);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void handleCollisions();//碰撞检测

    GameController &m_controller;
    QPointF m_head;
    QList<QPointF> m_tail;
    int m_speed;//蛇移动速度
    int m_tickCounter;//相当于一个定时器,
    //m_tickCountertickCounter% peed != 0 的次数响应越多，刷新的次数就会越少，蛇运动得越慢。
    int m_grow;//蛇的大小
    Directiion m_direction;//蛇要移动的方向

};

#endif // SNAKE_H
