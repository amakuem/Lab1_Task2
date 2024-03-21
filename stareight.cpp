#include "stareight.h"

starEight::starEight() {}

void starEight::draw(QGraphicsScene *scene, int width, int height, int &a, int &h)
{
    QPolygonF star;
    double innerRadius = width * sin(M_PI / 8) / sin((2 * 8 - 1) * M_PI / (2 * 8));
    for (int i = 0; i < 2 * 8; ++i) {
        double radius = (i % 2 == 0) ? width : innerRadius;
        double angle = i * M_PI / 8;
        star << QPointF(radius * cos(angle), radius * sin(angle));
    }


    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(star);
    scene->addItem(figure);
}
