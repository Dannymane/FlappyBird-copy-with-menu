#ifndef BIRD_H
#define BIRD_H

#include "QGraphicsPixmapItem"
#include <QObject>

class bird :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
   void relaxBird();
   void madBird();
   void crazyBird();
signals:
   void valueChanged(int newValue);
   void new_game(int newValue);
public:
    bird(QGraphicsItem*  parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void advance(int phase);;
    void setRotation(qreal rotation);
    void setSpeed(double speed_);
    void ddd();



private:
    double timeFromLastJump = 0;
    double speed;
    qreal x;
    qreal y;
    qreal current_rotation;
    bool game_over = false;
    double jump = 4;

};

#endif // BIRD_H
