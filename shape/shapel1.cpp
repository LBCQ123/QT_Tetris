#include "shapel1.h"



shapel1::shapel1()
{
    //形态1
    QList<QPoint> list;
    list.append(QPoint(-1,0));
    list.append(QPoint(0,0));
    list.append(QPoint(1,0));
    list.append(QPoint(1,-1));
    allModels.append(list);

    //形态2
    list.clear();
    list.append(QPoint(-1,-1));
    list.append(QPoint(0,-1));
    list.append(QPoint(0,0));
    list.append(QPoint(0,1));
    allModels.append(list);

    //形态3
    list.clear();
    list.append(QPoint(-1,0));
    list.append(QPoint(0,0));
    list.append(QPoint(1,0));
    list.append(QPoint(-1,1));
    allModels.append(list);

    //形态4
    list.clear();
    list.append(QPoint(0,-1));
    list.append(QPoint(0,0));
    list.append(QPoint(0,1));
    list.append(QPoint(1,1));
    allModels.append(list);
}
