#include "shapeLine.h"

shapeLine::shapeLine()
{
    //形态1，水平状态
    QList<QPoint> list1;
    list1.append(QPoint(-1,0));
    list1.append(QPoint(0,0));
    list1.append(QPoint(1,0));
    list1.append(QPoint(2,0));

    //形态2，竖直状态
    QList<QPoint> list2;
    list2.append(QPoint(0,-1));
    list2.append(QPoint(0,0));
    list2.append(QPoint(0,1));
    list2.append(QPoint(0,2));

    allModels.append(list1);
    allModels.append(list2);
}
