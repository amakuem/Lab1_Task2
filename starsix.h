#ifndef STARSIX_H
#define STARSIX_H

#include "starfive.h"

class starSix: public starFive
{
public:
    starSix();
    void draw(QGraphicsScene *scene, int width, int height, int &a, int &h) override;
};

#endif // STARSIX_H
