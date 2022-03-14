#include "gamecontroller.h"
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QtGlobal>

GameController::GameController(QGraphicsScene& scene,QObject* parent)
    :QObject(parent)
    ,m_scene(scene)
    ,m_snake(new Snake(*this))
    ,m_isPause(false)
{
    int static i = 0;
    m_timer.start(1000/10);//游戏循环的定时器，
    qDebug()<<"i:"<<i++;

    Food *startFood = new Food(0,-30);//将第一个食物和蛇添加到场景中
    scene.addItem(startFood);
    scene.addItem(m_snake);
    scene.installEventFilter(this);

    qDebug()<<":game beging!";

    resume();
}

GameController::~GameController()
{

}

void GameController::snakeEatFood(Food *food)
{

 //当前食物消失，产生新的食物
    m_scene.removeItem(food);
    addNewFood();
}

void GameController::addNewFood()
{
    qDebug()<<"add food";

    int x,y;

    do
    {
        x = (rand()%200)/10-10;
        y = (rand()%200)/10-10;
        x *=10;
        y *=10;

    }while(m_snake->shape().contains(m_snake->mapFromScene(QPointF(x + 15, y + 15))));

    Food *food = new Food(x,y);
    m_scene.addItem(food);

}

void GameController::snakeEatSelf()
{
    QTimer::singleShot(0,this,SLOT(gameOver()));
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        handleKeyPressed((QKeyEvent*)event);
        return true;
    }else
    {
        return QObject::eventFilter(object,event);
    }
}

void GameController::pause()
{
    qDebug()<<"GameController::pause";

    disconnect(&m_timer,SIGNAL(timeout()),&m_scene,SLOT(advance()));
    m_isPause = true;
}

void GameController::resume()
{
    qDebug()<<"GameContraller::resue()";

    connect(&m_timer,SIGNAL(timeout()),&m_scene,SLOT(advance()));
    m_isPause = false;
}

void GameController::gameOver()//处理游戏结束
{
    qDebug()<<"game over";

    //断开和定时器和advance的链接
    disconnect(&m_timer,SIGNAL(timeout()),&m_scene,SLOT(advance()));
    //弹出一个窗口，是否选择”重开游戏“或者”退出“
    if(QMessageBox::Yes == QMessageBox::information(NULL,"Gane Over!","Play Again?",
                                                    QMessageBox::Yes|QMessageBox::No,
                                                    QMessageBox::Yes))
    {
        connect(&m_timer,SIGNAL(timeout()),&m_scene,SLOT(advance()));
        m_scene.clear();
        
        m_snake = new Snake(*this); 
        m_scene.addItem(m_snake);
        
        addNewFood();
    }else
    {
        exit(0);
    }
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
    if(m_isPause == 0)
    {
        switch (event->key()) {
        case Qt::Key_Left:
        {

            m_snake->setMoveDirection(Snake::MoveLeft);
            qDebug()<<"按下左 ";
            break;
        }
        case Qt::Key_Up:
        {
            qDebug()<<"按下上 ";
            m_snake->setMoveDirection(Snake::MoveUp);
            break;
        }
        case Qt::Key_Right:
        {
            qDebug()<<"按下右 ";
            m_snake->setMoveDirection(Snake::MoveRight);
            break;
        }
        case Qt::Key_Down:
        {
            qDebug()<<"按下下 ";
            m_snake->setMoveDirection(Snake::MoveDown);
            break;
        }
        case Qt::Key_Space:
            qDebug()<<"按下空格 ";
            pause();
            break;
        }
    }
     else{
            resume();
        }

}

