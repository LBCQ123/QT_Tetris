#include "shapeZ1.h"

shapeZ1::shapeZ1()
{
    //形态1，水平状态
    QList<QPoint> list1;
    list1.append(QPoint(0,0));
    list1.append(QPoint(1,0));
    list1.append(QPoint(0,1));
    list1.append(QPoint(-1,1));

    //形态2，竖直状态
    QList<QPoint> list2;
    list2.append(QPoint(-1,-1));
    list2.append(QPoint(-1,0));
    list2.append(QPoint(0,0));
    list2.append(QPoint(0,1));

    allModels.append(list1);
    allModels.append(list2);
}
