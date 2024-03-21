#ifndef STAREIGHT_H
#define STAREIGHT_H

#include "starfive.h"

class starEight: public starFive
{
public:
    starEight();
    void draw(QGraphicsScene *scene, int width, int height, int &a, int &h);
};

#endif // STAREIGHT_H
