#ifndef HEXAGON_H
#define HEXAGON_H

#include "base.h"

class hexagon: public base
{
public:
    hexagon();
    void draw(QGraphicsScene *scene, int width, int height, int &a, int &h)override;
    void getParametrs(int &side1, int &side2, int &side3, int a, bool &ok) override;
    void perSquareMasse(int width, int height, int a)override;
};

#endif // HEXAGON_H
