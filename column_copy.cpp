#include "column_copy.h"
#include "QKeyEvent"

void Column_copy::classicMap(){
    setX(240);
    speed = -1.8;
    setPixmap(QPixmap(":/pictures/pictures/double_column.png"));
}
void Column_copy::ExtremeMap(){
    setX(240);
    speed = -2.6;
    setPixmap(QPixmap(":/pictures/pictures/extreme_double_column.png"));
}
Column_copy::Column_copy(QGraphicsItem* parent, int start_position) :
    QGraphicsPixmapItem(parent),
    speed(-1.8)
{

    setPixmap(QPixmap(":/pictures/pictures/double_column.png"));
    setFlag(QGraphicsItem::ItemIsMovable);

    setX(start_position);
    setY(QRandomGenerator::global()->bounded(320)-360);
}

void Column_copy::advance(int phase)
{
    if(phase)
    {
        moveBy(speed, 0); //wzdłuż osi x i y
        if (x() < 0 && !columnPassedBird){
            emit valueChanged(1);
            columnPassedBird = true;
        }
    }else{

        if(x() < -240)
        {
            setX(240);
            //160 -160
            setY(QRandomGenerator::global()->bounded(320)-360);
            columnPassedBird = false;

        }

    }
}
