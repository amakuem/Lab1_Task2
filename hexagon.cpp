#include "hexagon.h"

hexagon::hexagon() {}

void hexagon::draw(QGraphicsScene *scene, int width, int height, int &a, int &h)
{
    qreal triangleHeight = width * qSqrt(3.0) / 2.0;

    QPolygonF hexagon;
    hexagon << QPointF(0, 0)
            << QPointF(width, 0)
            << QPointF(width + width / 2.0, triangleHeight)
            << QPointF(width, 2 * triangleHeight)
            << QPointF(0, 2 * triangleHeight)
            << QPointF(-width / 2.0, triangleHeight);

    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(hexagon);

    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(figure->boundingRect().center().x(), figure->boundingRect().center().y(), 3, 3);
    point->setBrush(Qt::blue);
    scene->addItem(point);
    scene->addItem(figure);
}

void hexagon::getParametrs(int &side1, int &side2, int &side3, int a, bool &ok)
{
    ok;
    side1 = QInputDialog::getInt(this, tr("Введите сторону:"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
}

void hexagon::perSquareMasse(int width, int height, int a)
{
    double perimetr = 6 * width;
    double square = (3 * sqrt(3) * pow(width, 2)) / 2;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}
