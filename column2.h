#ifndef COLUMN2_H
#define COLUMN2_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QGraphicsScene>

class Column2 :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Column2();
    void advance(int phase);
    Column2(int x_start_pos);

signals:

private:
    double speed;
    QGraphicsPixmapItem* topColumn;
    QGraphicsPixmapItem* bottomColumn;
    int nr;
};

#endif // COLUMN2_H
