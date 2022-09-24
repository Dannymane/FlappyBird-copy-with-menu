#include "bird.h"
#include "QKeyEvent"
#include "math.h"
#include "QDebug"
#include "QEasingCurve"
#include "QTransform"


void bird::relaxBird(){
    setPixmap(QPixmap(":/pictures/pictures/bird_up_wings2.png"));
    setSpeed(12);
    setY(200);
    current_rotation = 0;
    jump = 4;
}
void bird::madBird(){
    setPixmap(QPixmap(":/pictures/pictures/mad_bird.png"));
    setSpeed(20);
    setY(200);
    current_rotation = 0;
    jump = 5;

}
void bird::crazyBird(){
    setPixmap(QPixmap(":/pictures/pictures/strange_bird.png"));
    setSpeed(-12);
    setY(200);
    current_rotation = 0;
    jump = -4;

}
bird::bird(QGraphicsItem*  parent):
    QGraphicsPixmapItem(parent)
{
    speed = 12;
    setPixmap(QPixmap(":/pictures/pictures/bird_up_wings2.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setX(0);
    setY(200);
}
void bird::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Space)
    {
        if(game_over){
            emit new_game(2);
            game_over = false;
        }
        timeFromLastJump = 0;
        setX(x);
    }
}
void bird::setRotation(qreal rotation)
{
//    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(407/20,288/20);
    t.rotate(rotation);
    t.translate(-407/20,-288/20);
    setTransform(t);

}

void bird::advance(int phase)
{
    if(phase)
    {
        timeFromLastJump += 0.015;
        moveBy(0, speed*timeFromLastJump-jump); //wzdłuż osi x i y
        if(speed > 0){
            current_rotation = 150*(timeFromLastJump-0.265);
            if (current_rotation<90){
                setRotation(150*(timeFromLastJump-0.265));
            }
        } else{
            current_rotation = -150*(timeFromLastJump-0.265);
            if (current_rotation>-90){
                setRotation(-150*(timeFromLastJump-0.265));
            }
        }
        //-45 do 90

    }else{
        if(!collidingItems().isEmpty()){
            emit valueChanged(1);
            game_over = true;
            }
        }


}
void bird::setSpeed(double speed_){
    speed = speed_;
}
