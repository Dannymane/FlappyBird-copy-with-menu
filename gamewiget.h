#ifndef GAMEWIGET_H
#define GAMEWIGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include <bird.h>
#include <column_copy.h>

#include <QTimer>

namespace Ui {
class GameWiget;
}

class GameWiget : public QWidget
{
    Q_OBJECT

public slots:
   void stop_game();
   void start_game();
   void plusPoint2();

signals:
   void valueChanged(int newValue);
   void setRelaxBird();
   void setMadBird();
   void setCrazyBird();
   void setClassicMap();
   void setExtremeMap();
public:
    explicit GameWiget(QWidget *parent = nullptr);
       bird* bi;
   void setRelaxBird_method();
   void setMadBird_method();
   void setCrazyBird_method();
   void setClassicMap_method();
   void setExtremeMap_method();

    ~GameWiget();

private:
    Ui::GameWiget *ui;
    QGraphicsScene* scene;
    QTimer* timer;
    QGraphicsPixmapItem* gameOver;

    Column_copy* col;
    Column_copy* col2;
    int score = 0;
    QGraphicsTextItem* text;

};

#endif // GAMEWIGET_H
