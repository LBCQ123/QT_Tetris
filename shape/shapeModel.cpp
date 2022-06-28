#include "shapeModel.h"

shapeModel::shapeModel()
{
    nowPoi.setX(maxWidth/2);
    nowPoi.setY(0);
}

shapeModel::~shapeModel()
{

}

int shapeModel::getCurrentStatus()
{
    return status;
}

//上一个形态
void shapeModel::upStatus()
{
    int counts = allModels.count();
    status--;
    if(status<0)
        status = counts - 1;
}

//下一个形态
bool shapeModel::nextStatus()
{
    int counts = allModels.count();
    status++;
    if(status>=counts)
        status = 0;
    int numbers = getIndexPoints().count();
    if(numbers  == allModels.at(0).count())
        return true;
    else {
        return false;
    }
}

QList<QPoint> shapeModel::getIndexPoints(int index)
{
    int counts = allModels.count();
    if((index>=0)&&(index<counts))
    {
        QList<QPoint> ret;
        int x = nowPoi.x();
        int y = nowPoi.y();
        foreach(QPoint point,allModels.at(index))
        {
            int ix = x + point.x();
            int iy = y + point.y();
            if((ix>=0)&&(ix<maxWidth)&&(iy>=0)&&(iy<maxHeight))
            {
                ret.append(QPoint(ix,iy));
            }
        }
        return ret;
    }
    else {
        return QList<QPoint>();
    }
}


QList<QPoint> shapeModel::getIndexPoints()
{
    int index = status;
    int counts = allModels.count();
    if((index>=0)&&(index<counts))
    {
        QList<QPoint> ret;
        int x = nowPoi.x();
        int y = nowPoi.y();
        foreach(QPoint point,allModels.at(index))
        {
            int ix = x + point.x();
            int iy = y + point.y();
            if((ix>=0)&&(ix<maxWidth)&&(iy>=0)&&(iy<maxHeight))
            {
                ret.append(QPoint(ix,iy));
            }
        }
        return ret;
    }
    else {
        return QList<QPoint>();
    }
}


//坐标移动
bool shapeModel::movePoi(int mx, int my)
{
    int x = nowPoi.x() + mx;
    int y = nowPoi.y() + my;

    bool ret = true;
    foreach(QPoint poi,getIndexPoints())
    {
        int ix = mx + poi.x();
        int iy = my + poi.y();
        if((ix>=0)&&(ix<maxWidth)&&(iy>=0)&&(iy<maxHeight))
        {

        }
        else {
            ret = false;
        }
    }
    if(ret == true)
    {
        nowPoi.setX(x);
        nowPoi.setY(y);
        return true;
    }
    else {
        return false;
    }
}
