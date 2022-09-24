#include "column2.h"

Column2::Column2(int x_start_pos) :
    speed(-2),
    topColumn(new QGraphicsPixmapItem(QPixmap(":/pictures/pictures/column.png"))),
    bottomColumn(new QGraphicsPixmapItem(QPixmap(":/pictures/pictures/column.png")))
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    bottomColumn->setPos(QPointF(x_start_pos,290));
    topColumn->setPos(QPointF(0,0) - QPointF(-x_start_pos,topColumn->boundingRect().height() - 210));


    addToGroup(topColumn);
    addToGroup(bottomColumn);
}
void Column2::advance(int phase)
{
    if(phase)
    {
        moveBy(speed, 0); //wzdłuż osi x i y
    }else{
//        if(!collidingItems().isEmpty()){
//            setX(QRandomGenerator::global()->bounded(1350));
//            setY(0);
//        }
        if(x() == -240)
        {
            setX(240);
            //160 -160
            setY(QRandomGenerator::global()->bounded(320)-160);
//            QGraphicsTextItem *text = scene()->addText("YOU LOST YOUR APPLES", QFont("Fantasy", 50,40,true));
//            text->setDefaultTextColor(Qt::white);
//            text->setPos(250, 200);
        }
    }
}
