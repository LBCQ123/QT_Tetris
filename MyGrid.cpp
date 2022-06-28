#include "MyGrid.h"

MyGrid::MyGrid():QGraphicsPixmapItem()
{
    mback = QPixmap(":/Pixmap/background.png");
    mmove = QPixmap(":/Pixmap/move.png");
    mfixed = QPixmap(":/Pixmap/fixed.png");
    setState(0);
    setScale(gridlen/10.0);
}

void MyGrid::setState(int mstate)
{
    switch(mstate)
    {
        case 0:setPixmap(mback);
        break;
        case 1:setPixmap(mmove);
        break;
        case 2:setPixmap(mfixed);
        break;
    }
    state = mstate;
}

int MyGrid::getState()
{
    return state;
}

