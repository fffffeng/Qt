#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

//游戏控制处理：
//1,控制游戏循环
//2,处理蛇吃到食物的情况
//3，蛇吃到自己的情况
#include <QObject>
#include <QGraphicsScene>
#include "food.h"
#include "snake.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

class Snake;
class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene& scene,QObject*parent = 0);
    ~GameController();

    void snakeEatFood(Food *food);
    void snakeEatSelf();

public slots:
    void pause();//暂停
    void resume();//重新开始
    void gameOver();//游戏结束

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();//新增食物

private:
    Snake* m_snake;
    QGraphicsScene* m_scene;
    bool m_isPause;

    QTimer m_timer;

};

#endif // GAMECONTROLLER_H
