#include "gamewiget.h"
#include "ui_gamewiget.h"
#include "column_copy.h"
#include "bird.h"
#include "ground.h"


#include <QTimer>

void GameWiget::setRelaxBird_method(){
      emit setRelaxBird();
    scene->addItem(gameOver);
      start_game();
}
void GameWiget::setMadBird_method(){
    emit setMadBird();
    scene->addItem(gameOver);
    start_game();
}

void GameWiget::setCrazyBird_method(){
    emit setCrazyBird();
    scene->addItem(gameOver);
    start_game();
}
void GameWiget::setExtremeMap_method(){
    emit setExtremeMap();
    scene->addItem(gameOver);
    start_game();
}
void GameWiget::setClassicMap_method(){
    emit setClassicMap();
    scene->addItem(gameOver);
    start_game();
}


void GameWiget::plusPoint2(){
    score+=1;
    scene->removeItem(text);
    text = new QGraphicsTextItem(QString::number(score, 'f', 0),nullptr);
    text->setX(-100);
    text->setScale(2);
    scene->addItem(text);
}
void GameWiget::stop_game(){
   timer->stop();
   gameOver = new QGraphicsPixmapItem();
   gameOver->setPixmap(QPixmap(":/pictures/pictures/game_over.png"));
   gameOver->setScale(0.2);
   gameOver->setX(-50);
   gameOver->setY(-50);

   scene->addItem(gameOver);
}
void GameWiget::start_game(){
    scene->removeItem(gameOver);
    col->columnPassedBird = false;
    col2->columnPassedBird = false;
    col->setX(263+240);
    col2->setX(263+240+240);
    score = 0;
    scene->removeItem(text);
    text = new QGraphicsTextItem(QString::number(score, 'f', 0),nullptr);
    text->setX(-100);
    text->setScale(2);
    scene->addItem(text);
    timer->start(15);

}
//bird_type,bird_speed,column_type,column_speed_
GameWiget::GameWiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWiget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,120,600,this);
    scene->setBackgroundBrush(QPixmap(":/pictures/pictures/background.png"));

    col = new Column_copy(0, 263+240);
    scene->addItem(col);

    col2 = new Column_copy();
    scene->addItem(col2);
    bird* bi = new bird();
    bi->setScale(0.10);
    scene->addItem(bi);

    text = new QGraphicsTextItem(QString::number(score, 'f', 0),nullptr);
    text->setX(-100);
    text->setScale(2);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(15);

    QObject::connect(bi, SIGNAL(valueChanged(int)),this, SLOT(stop_game()));
    QObject::connect(bi, SIGNAL(new_game(int)),this, SLOT(start_game()));
    QObject::connect(col, SIGNAL(valueChanged(int)),this, SLOT(plusPoint2()));
    QObject::connect(col2, SIGNAL(valueChanged(int)),this, SLOT(plusPoint2()));


    Ground* gr = new Ground();
    scene->addItem(gr);
    QObject::connect(this, SIGNAL(setRelaxBird()),bi, SLOT(relaxBird()));
    QObject::connect(this, SIGNAL(setMadBird()),bi, SLOT(madBird()));
    QObject::connect(this, SIGNAL(setCrazyBird()),bi, SLOT(crazyBird()));

    QObject::connect(this, SIGNAL(setClassicMap()),col, SLOT(classicMap()));
    QObject::connect(this, SIGNAL(setClassicMap()),col2, SLOT(classicMap()));
    QObject::connect(this, SIGNAL(setExtremeMap()),col, SLOT(ExtremeMap()));
    QObject::connect(this, SIGNAL(setExtremeMap()),col2, SLOT(ExtremeMap()));
}

GameWiget::~GameWiget()
{
    delete ui;
}
