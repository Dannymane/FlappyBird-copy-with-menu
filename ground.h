#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class Ground :  public QGraphicsPixmapItem
{
public:
    Ground(QGraphicsItem* parent = 0);
    void advance(int phase);

private:
    double speed;
};

#endif // GROUND_H
