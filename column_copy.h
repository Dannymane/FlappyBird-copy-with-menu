#ifndef COLUMN_COPY_H
#define COLUMN_COPY_H

#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QObject>

class Column_copy :public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
   void classicMap();
   void ExtremeMap();
signals:
   void valueChanged(int newValue);
public:
    Column_copy(QGraphicsItem* parent = 0, int start_position = 263+240+240);
    void advance(int phase);
    bool columnPassedBird = false;

private:
    double speed;


};

#endif // COLUMN_COPY_H
