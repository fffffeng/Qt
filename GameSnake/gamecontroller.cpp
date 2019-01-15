#include "gamecontroller.h"
#include <QMessageBox>

GameController::GameController(QGraphicsScene& scene,QObject* parent)
    :QObject(parent)
    ,m_snake(new Snake(*this))
    ,m_scene(&scene)
    ,m_isPause(false)
{
    m_timer.start(1000/10);//游戏循环的定时器，

    Food *startFood = new Food(0,50);//将第一个食物和蛇添加到场景中
    scene.addItem(startFood);
    scene.addItem(m_snake);
    scene.installEventFilter(this);
    resume();
}

GameController::~GameController()
{

}

void GameController::snakeEatFood(Food *food)
{

 //当前食物消失，产生新的食物
    m_scene->removeItem(food);
    addNewFood();
}

void GameController::addNewFood()
{
    int x,y;

    do
    {
        x = (qrand()%300)/10-10;
        y = (qrand()%300)/10-10;
        x *=10;
        y *=10;

    }while(m_snake->shape().contains(m_snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x,y);
    m_scene->addItem(food);

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
    disconnect(&m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));
    m_isPause = true;
}

void GameController::resume()
{
    disconnect(&m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));
    m_isPause = false;
}

void GameController::gameOver()//处理游戏结束
{
    //断开和定时器和advance的链接
    disconnect(&m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));
    //弹出一个窗口，是否选择”重开游戏“或者”退出“
    if(QMessageBox::Yes == QMessageBox::information(NULL,"Gane Over!","Play Again?",
                                                    QMessageBox::Yes|QMessageBox::No,
                                                    QMessageBox::Yes))
    {
        connect(&m_timer,SIGNAL(timeout()),m_scene,SLOT(advance()));
        m_scene->clear();
        
        m_snake = new Snake(*this); 
        m_scene->addItem(m_snake);
        
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

            break;
        }
        case Qt::Key_Up:
        {
            break;
        }
        case Qt::Key_Right:
        {

        }
        case Qt::Key_Down:
        {

        }
        case Qt::Key_Space:
            pause();
            break;
        }
    }
     else{
            resume();
        }

}

