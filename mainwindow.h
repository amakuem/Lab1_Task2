#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QTimer>
#include "rectungle.h"
#include "base.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void plusZoom();

    void minusZoom();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void showPerimetr(double perimetr);

    void showSquare(double square);


private:
    base *basa;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    rectungle *rectangle;
    QTimer *plus;
    QTimer *minus;
    int x;
    int y;
};
#endif // MAINWINDOW_H
