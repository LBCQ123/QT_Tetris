#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include <QTime>
#include "mystudio.h"
#include <QGraphicsRectItem>
#include "MyGrid.h"
#include <QMessageBox>


#include "shape/shapeModel.h"
#include "shape/shapeLine.h"
#include "shape/shapeRect.h"
#include "shape/shapeZ1.h"
#include "shape/shapeZ2.h"
#include "shape/shapel1.h"
#include "shape/shapel2.h"
#include "shape/shapeTrangle.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUi();

private slots:
    void on_actionStart_triggered();

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;
    //大窗口
    QGraphicsScene* scene;
    QGraphicsView* view;
    QRect mRect;
    //地图矩阵
    QVector<QVector<MyGrid*>> gridTab;//x,y

    //小窗口显示下一个图形
    QGraphicsScene* smScene;
    QGraphicsView* smView;
    QVector<QVector<MyGrid*>> smGridTab;//x,y
    int smWidth = 5;

    //图形
    shapeModel shape;
    shapeModel nextShape;
    QList<shapeModel*> allShaples;
    void rangeShape();

    int start = 0;
    int timerId;
    int timerCounts;
    int scores = 0;

protected:
    void timerEvent(QTimerEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // MAINWINDOW_H
