#include "ground.h"


Ground::Ground(QGraphicsItem* parent) :
    QGraphicsPixmapItem(parent),
    speed(-1.8)
{
    setPixmap(QPixmap(":/pictures/pictures/ground.png"));
    setFlag(QGraphicsItem::ItemIsMovable);

    setX(-240);
    setY(500);
}
void Ground::advance(int phase)
{
    if(phase)
    {
        moveBy(speed, 0); //wzdłuż osi x i y

    }
    if(x() < -480-240)
    {
        setX(-237);
        setY(500);
    }

}

