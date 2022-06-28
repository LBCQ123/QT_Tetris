#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    view = ui->graphicsView;
    view->setScene(scene);
    allShaples.append(new shapeLine);
    allShaples.append(new shapeRect);
    allShaples.append(new shapeZ1);
    allShaples.append(new shapeZ2);
    allShaples.append(new shapel1);
    allShaples.append(new shapel2);
    allShaples.append(new shapeTrangle);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    smScene = new QGraphicsScene(this);
    smView = ui->graphicsView_2;
    smView->setScene(smScene);

}

MainWindow::~MainWindow()
{
    delete ui;
    foreach(shapeModel* model,allShaples)
    {
        delete model;
    }
}

//初始化界面
void MainWindow::initUi()
{
    //设置画面
    qDebug() << view->width();
    qDebug() << view->height();

    int width  = maxWidth*gridlen + 20;
    int height = maxHeight*gridlen + 20;

    view->setGeometry(0,0,width+100,height+100);
    mRect = QRect(-10,-10,width,height);
    scene->setSceneRect(mRect);
    QGraphicsRectItem* rect = new QGraphicsRectItem(mRect);
    scene->addItem(rect);

    for (int col=0;col<maxWidth;col++) {
        QVector<MyGrid*> tab;
        for (int row=0;row<maxHeight;row++) {
            MyGrid* grid = new MyGrid;
            grid->setPos(col*gridlen,row*gridlen);
            scene->addItem(grid);
            tab.append(grid);
        }
        gridTab.append(tab);
    }

    //小窗口////////////////
    int SMwidth  = smWidth*gridlen + 20;
    int SMheight = smWidth*gridlen + 20;
    smView->resize(SMwidth+40,SMheight+40);
    QRect smRect = QRect(-20,-20,SMwidth+10,SMheight+10);
    smScene->setSceneRect(smRect);
    QGraphicsRectItem* smrect = new QGraphicsRectItem(smRect);
    smScene->addItem(smrect);

    for (int col=0;col<smWidth;col++) {
        QVector<MyGrid*> tab;
        for (int row=0;row<smWidth;row++) {
            MyGrid* grid = new MyGrid;
            grid->setPos(col*gridlen-10,row*gridlen-10);
            smScene->addItem(grid);
            tab.append(grid);
        }
        smGridTab.append(tab);
    }


    //随机下一个图形
    rangeShape();
}

void MainWindow::on_actionStart_triggered()
{
   if(start == 0)
   {
       start = 1;

       shape = nextShape;
       rangeShape();

       QList<QPoint> list = shape.getIndexPoints();

       for (int col=0;col<maxWidth;col++) {
           for (int row=0;row<maxHeight;row++) {
                gridTab[col][row]->setState(0);
           }
       }

       foreach(QPoint poi,list)
       {
           gridTab[poi.x()][poi.y()]->setState(1);
       }

       scores = 0;
       ui->score->setNum(scores);

       timerId = startTimer(100);
       timerCounts = 5;
   }
}

void MainWindow::on_actionStop_triggered()
{
    if(start == 1)
    {
        start = 0;
        killTimer(timerId);
    }
}

//随机刷新图形
void MainWindow::rangeShape()
{
    int choose = qrand()%(allShaples.count());
    nextShape = *allShaples.at(choose);

    for (int col=0;col<4;col++) {
        for (int row=0;row<4;row++) {
           smGridTab[col][row]->setState(0);
        }
    }

    shapeModel abc = nextShape;
    abc.movePoi(-4,1);
    QList<QPoint> list = abc.getIndexPoints();
    foreach(QPoint poi,list){
        smGridTab[poi.x()][poi.y()]->setState(1);
    }

}

void MainWindow::timerEvent(QTimerEvent *event)
{
    static int tm = 0;
    if(event->timerId() != timerId)
        return;

    //是否新建一个
    bool isnew = false;

    tm++;
    if(tm<timerCounts)
    {
        return;
    }
    else {
        tm = 0;
    }

    QList<QPoint> list = shape.getIndexPoints();
    foreach(QPoint poi,list)
    {
        gridTab[poi.x()][poi.y()]->setState(0);
    }
    //如果碰到底部了
    if (shape.movePoi(0,1) == false)
    {
        QList<QPoint> list = shape.getIndexPoints();
        foreach(QPoint poi,list)
        {
            gridTab[poi.x()][poi.y()]->setState(2);
        }
        isnew = true;
    }
    else
    {
        list = shape.getIndexPoints();
        //如果遇到重叠了
        foreach(QPoint poi,list)
        {
            if(gridTab[poi.x()][poi.y()]->getState() == 2)
            {
                isnew = true;
            }
        }
        //刷新显示
        if(isnew == false)
        {
            foreach(QPoint poi,list)
            {
                gridTab[poi.x()][poi.y()]->setState(1);
            }
        }
        else {
            shape.movePoi(0,-1);
            QList<QPoint> list = shape.getIndexPoints();
            foreach(QPoint poi,list)
            {
                gridTab[poi.x()][poi.y()]->setState(2);
            }
        }
    }

    if(isnew == true)
    {
        //检查是否发生了堆满料的情况
        QList<QPoint> list = shape.getIndexPoints();
        QList<int> xiaochu;
        foreach(QPoint poi,list)
        {
            int row = poi.y();
            int col=0;
            if(xiaochu.indexOf(row)>=0)
                continue;
            for (;col<maxWidth;col++)
            {
                if(gridTab[col][row]->getState() != 2)
                {
                    break;
                }
            }
            if(col == maxWidth)
            {
                xiaochu.append(row);
            }
        }

        foreach(int row,xiaochu)
        {

            for (int col=0;col<maxWidth;col++) {
                gridTab[col][row]->setState(0);
            }

            for (int mrow=row;mrow>0;mrow--) {
                for (int col=0;col<maxWidth;col++) {
                    gridTab[col][mrow]->setState(
                            gridTab[col][mrow-1]->getState());
                }
            }
            for (int col=0;col<maxWidth;col++) {
                gridTab[col][0]->setState(0);
            }
            //统计分数
            scores += 10;
        }
        ui->score->setNum(scores);

        shape = nextShape;
        rangeShape();
        list = shape.getIndexPoints();
        foreach(QPoint poi,list)
        {
            if(gridTab[poi.x()][poi.y()]->getState() == 2)
            {
                on_actionStop_triggered();
                QMessageBox::information(this,"提示","您输了");
                return;
            }
            gridTab[poi.x()][poi.y()]->setState(1);
        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(start == false)
        return;
    QList<QPoint> currentList = shape.getIndexPoints();
    QList<QPoint> nextList;

    //确认下一个位置
    switch (event->key()) {
        case Qt::Key_W:
            if(shape.nextStatus() == true)
            {
                nextList = shape.getIndexPoints();
            }
            else {
                shape.upStatus();
                return;
            }
            break;
        case Qt::Key_S:
            timerCounts = 1;
            return ;
        case Qt::Key_A:
            if(shape.movePoi(-1,0) == false)
                return;
            nextList = shape.getIndexPoints();
            break;
        case Qt::Key_D:
            if(shape.movePoi(1,0) == false)
                return;
            nextList = shape.getIndexPoints();
            break;
    }
    bool isTran = true;
    foreach (QPoint poi, nextList) {
        if(gridTab[poi.x()][poi.y()]->getState() == 2)
        {
            isTran = false;
            break;
        }
    }
    //如果可以移动
    if(isTran == true)
    {
        foreach(QPoint poi,currentList)
        {
            gridTab[poi.x()][poi.y()]->setState(0);
        }
        foreach(QPoint poi,nextList)
        {
            gridTab[poi.x()][poi.y()]->setState(1);
        }
    }
    else {
        //回档
        switch (event->key()) {
            case Qt::Key_W:
                shape.upStatus();
                    break;
            case Qt::Key_S: break;
            case Qt::Key_A:
                shape.movePoi(1,0);
                break;
            case Qt::Key_D:
                shape.movePoi(-1,0);
                break;
        }
    }



}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {

        case Qt::Key_S:
            timerCounts = 5;
            return ;
    }
}
