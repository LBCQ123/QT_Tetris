#ifndef MYGRID_H
#define MYGRID_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "mystudio.h"

class MyGrid:public QGraphicsPixmapItem
{
public:
    MyGrid();
    void setState(int mstate);
    int getState();
private:
    QPixmap mback;
    QPixmap mmove;
    QPixmap mfixed;
    int state = 0;
};

#endif // MYGRID_H
