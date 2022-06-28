#include "shapeRect.h"

shapeRect::shapeRect()
{
    //方块只有一个形态
    QList<QPoint> list1;
    list1.append(QPoint(0,-1));
    list1.append(QPoint(1,-1));
    list1.append(QPoint(0,0));
    list1.append(QPoint(1,0));

    allModels.append(list1);
}
