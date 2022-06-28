#ifndef SHAPEMODEL_H
#define SHAPEMODEL_H
#include <QPoint>
#include <QList>
#include "mystudio.h"

class shapeModel
{
public:
    shapeModel();
    virtual ~shapeModel();
    //获得当前形态
    int getCurrentStatus();
    //上一个形态
    void upStatus();
    //下一个形态
    bool nextStatus();
    //得到指定形态位置占用
    QList<QPoint> getIndexPoints(int index);
    QList<QPoint> getIndexPoints();
    //坐标移动
    bool movePoi(int mx,int my);

protected:
    //形态副本
    QList<QList<QPoint>> allModels;
    //当前形态
    int status = 0;
    //当前位置
    QPoint nowPoi;
};

#endif // SHAPEMODEL_H
