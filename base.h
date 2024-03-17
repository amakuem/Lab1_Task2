#ifndef BASE_H
#define BASE_H

#include <QWidget>
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsRotation>
#include <QGraphicsItemGroup>


class base: public QWidget, public QGraphicsRectItem
{
    Q_OBJECT
public:
    base();
    virtual void draw(QGraphicsScene *scene, int width, int height);
    virtual void centerMasse(QGraphicsScene *scene, int width, int height);
    virtual void perSquareMasse(int width, int height);
    virtual void getParametrs(int &side1, int &side2, int a);

    void up(QGraphicsScene *scene, int &x, int &y);
    void down(QGraphicsScene *scene, int &x, int &y);
    void left(QGraphicsScene *scene, int &x);
    void right(QGraphicsScene *scene, int &x, int &y);
    void rotateLeft(QGraphicsScene *scene,int x, int y);
    void rotateRight(QGraphicsScene *scene, int x, int y);
signals:
    void sendPerimetr(double perimetr);
    void sendSquare(double square);
};

#endif // BASE_H
