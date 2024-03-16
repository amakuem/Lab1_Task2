#ifndef BASE_H
#define BASE_H

#include <QWidget>
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>

class base: public QWidget, public QGraphicsRectItem
{
    Q_OBJECT
public:
    base();
    virtual void draw(QGraphicsScene *scene, int width, int height);
    virtual void centerMasse(QGraphicsScene *scene, int width, int height);
    virtual void perSquareMasse(int width, int height);
    virtual void getParametrs(int &side1, int &side2);
signals:
    void sendPerimetr(double perimetr);
    void sendSquare(double square);
};

#endif // BASE_H
