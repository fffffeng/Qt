#include "snake.h"
#include "food.h"
#include "gamecontroller.h"
#include "constants.h"
#include <QPainter>
#include <QDebug>

Snake::Snake(GameController& controller)
    :m_controller(controller),
    //蛇开始位置，大小,方向
    m_head(0,0),
    m_grow(3),
    m_speed(3),
    m_direction(NoMove)
{

    qDebug()<<"snake~~~";
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug()<<"snake::paint()";

    painter->save();
    painter->fillPath(shape(), Qt::yellow);

    painter->restore();
}

QRectF Snake::boundingRect()const
{
    qDebug()<<"snalke::boundingRect()";

    qreal minX = m_head.x();
    qreal minY = m_head.y();
    qreal maxX = m_head.x();
    qreal maxY = m_head.y();

    qDebug()<<"m_tail size:"<<m_tail.size();

    for(int i = 0; i < m_tail.size(); ++i)
    {
        if(m_tail[i].x()>maxX)
            maxX = m_tail[i].x();
        if(m_tail[i].x() < minX)
            minX = m_tail[i].x();
        if(m_tail[i].y() > maxY)
            maxY = m_tail[i].y();
        if(m_tail[i].y() < minY)
            minY = m_tail[i].y();
    }

    QPointF tl = mapFromScene(QPointF(minX,minY));
    QPointF br = mapFromScene(QPointF(maxX,maxY));

    QRectF bound = QRectF(tl.x(),tl.y(),
                          br.x()-tl.x()+10,br.y()-tl.y()+10);
    return bound;
}

QPainterPath Snake::shape()const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0,0,10,10));

    foreach (QPointF p, m_tail) {
       QPointF temp = mapFromScene(p);
       path.addRect(temp.x(),temp.y(),10,10);
    }

    qDebug()<<"Snake::shap()";
    return path;
}

void Snake::advance(int phase)
{
    qDebug()<<"Snake::advance()";

    if(!phase)
    {
        return;
    }
    if(m_tickCounter % m_speed != 0)
        return;
    if(m_direction == NoMove)
        return;
    if(m_grow > 0)//吃到food的时候
    {
        QPointF tailPoint = m_head;
        m_tail.append(tailPoint);
        m_grow -= 1;
    }else{
        m_tail.removeFirst();
        m_tail.append(m_head);
    }

    switch (m_direction) {
    case MoveUp:
        moveUp();
        break;
    case MoveDown:
        moveDown();
        break;
    case MoveLeft:
        moveLeft();
        break;
    case MoveRight:
        moveRight();
        break;
    }

    setPos(m_head);
    handleCollisions();//碰撞检测
}

void Snake::setMoveDirection(Directiion d)
{
    if(m_direction == MoveLeft && d == MoveRight)
        return;
    if(m_direction == MoveRight && d == MoveLeft)
        return;
    if(m_direction == MoveUp && d == MoveDown)
        return;
    if(m_direction == MoveDown && d == MoveUp)
        return;

    m_direction = d;
}
void Snake::moveLeft()
{
    qDebug()<<"Snake::moveLeft()";
    m_head.rx() -= 10;
    if(m_head.x() < -100)
        m_head.rx() = 90;
}

void Snake::moveRight()
{
    qDebug()<<"Snake::moveRight()";

    m_head.rx() += 10;
    if(m_head.rx() > 100)
        m_head.rx() = -100;
}

void Snake::moveUp()
{
    qDebug()<<"Snake::moveUp()";

    m_head.ry() -= 10;
    if(m_head.ry() < -100)
        m_head.ry() = 90;
}

void Snake::moveDown()
{
    qDebug()<<"Snake::moveDown()";

    m_head.ry() += 10;
    if (m_head.ry() >= 100) {
        m_head.ry() = -100;
    }
}

void Snake::handleCollisions()//碰撞检测
{
    QList<QGraphicsItem*> collidingList = collidingItems();//获取所有碰撞图形项的列表
    foreach (QGraphicsItem* item, collidingList) {
        if(item->data(GD_Type) == GO_Food)
        {
            m_controller.snakeEatFood((Food*)item);
            m_grow += 1;
        }

    }

    if(m_tail.contains(m_head))
    {
        m_controller.snakeEatSelf();
    }
}
