#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineF>
#include<utility>
#include <QMainWindow>
#include<QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QGraphicsScene* scene;
      QVector<QGraphicsLineItem *> item;
      QTimer* timer,*timer2;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void advance(QVector<QPair<int,QPair<float,float>>>);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
