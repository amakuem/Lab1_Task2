#include "starsix.h"

starSix::starSix() {}

void starSix::draw(QGraphicsScene *scene, int width, int height, int &a, int &h)
{
    QPolygonF star;
    double innerRadius = width * sin(M_PI / 6) / sin((2 * 6 - 1) * M_PI / (2 * 6));
    for (int i = 0; i < 2 * 6; ++i) {
        double radius = (i % 2 == 0) ? width : innerRadius;
        double angle = i * M_PI / 6;
        star << QPointF(radius * cos(angle), radius * sin(angle));
    }


    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(star);
    scene->addItem(figure);
}
