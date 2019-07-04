#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDebug>
#include<QGraphicsLineItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto myLine = new QGraphicsLineItem(0,0,45,45);
    myLine->setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scene->addItem(myLine);
    this->item.append(myLine);
    auto myLine2 = new QGraphicsLineItem(0,0,90,0);
    myLine2->setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scene->addItem(myLine2);
    this->item.append(myLine2);
    QVector<QPair<int,QPair<float,float>>> idx;
    idx.append(qMakePair(0,qMakePair(60,60)));
    idx.append(qMakePair(1,qMakePair(300,0)));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
         advance(idx);
    });
    timer->start(100);

}
void MainWindow::advance(QVector<QPair<int,QPair<float,float>>> vect)
{
    int flag=0;
for(int idx=0;idx<vect.size();idx++)
{
  if(this->item[idx]->line().p2().x()!=vect[idx].second.first)
  {

    scene->removeItem(this->item[idx]);
    int x1=this->item[idx]->line().p1().x();
    int y1=this->item[idx]->line().p1().y();
    int x2=this->item[idx]->line().p2().x();
    int y2=this->item[idx]->line().p2().y();
    float slope=(y2-y1)/(x2-x1);
    int dx=1;
    int dy=dx*slope;
    auto myLine = new QGraphicsLineItem(this->item[idx]->line().p1().x(),this->item[idx]->line().p1().y(),this->item[idx]->line().p2().x()+dx,this->item[idx]->line().p2().y()+dy);
    myLine->setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    this->item[idx]=myLine;
    scene->addItem(myLine);
    flag=1;
   }
 }
    if(flag==0)
    timer->stop();
}
