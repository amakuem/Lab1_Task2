#ifndef STARFIVE_H
#define STARFIVE_H

#include "base.h"

class starFive: public base
{
public:
    starFive();
    void draw(QGraphicsScene *scene, int width, int height, int &a, int &h)override;
    void getParametrs(int &side1, int &side2, int &side3, int a, bool &ok) override;
    void perSquareMasse(int width, int height, int a)override;
};

#endif // STARFIVE_H
