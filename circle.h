#ifndef CIRCLE_H
#define CIRCLE_H

#include "base.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

class circle: public base
{
public:
    //circle();
    void draw(QGraphicsScene *scene, int width, int height)override;
    void getParametrs(int &side1, int &side2, int a) override;
    void perSquareMasse(int width, int height)override;
};

#endif // CIRCLE_H
