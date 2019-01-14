#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gamecontroller.h"

//游戏主要有四部分：地图，食物food，蛇snake，游戏逻辑控制部分
//地图的设置在ManinWindows类，
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initScene();
    void setSceneBackground();

private slots:
    void adjustItem();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
    GameController *m_game;

};

#endif // MAINWINDOW_H
