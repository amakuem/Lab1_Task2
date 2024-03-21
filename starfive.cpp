#include "starfive.h"

starFive::starFive() {}

void starFive::draw(QGraphicsScene *scene, int width, int height, int &a, int &h)
{
    // Создаем точки для пятиконечной звезды
    // QPolygonF star;
    // for (int i = 0; i < 5; ++i) {
    //     qreal angle = 2 * M_PI * i / 5;
    //     star << QPointF(width * qCos(angle), width * qSin(angle));
    // }


    QPolygonF star;
    //double radius = 100.0;
    double innerRadius = width * sin(M_PI / 10) / sin(7 * M_PI / 10);
    for (int i = 0; i < 10; ++i) {
        double radius = (i % 2 == 0) ? width : innerRadius;
        double angle = i * M_PI / 5;
        star << QPointF(radius * cos(angle), radius * sin(angle));
    }


    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(star);

    scene->addItem(figure);
}

void starFive::getParametrs(int &side1, int &side2, int &side3, int a, bool &ok)
{
    ok;
    side1 = QInputDialog::getInt(this, tr("Введите радиус:"), tr("Радиус:"), 100, 0, 10000, 1, &ok);
}

void starFive::perSquareMasse(int width, int height, int a)
{
    double perimetr = 2 * a * sqrt(pow(width, 2) + pow(width * sin(M_PI / a), 2));
    double square = 0.5 * perimetr * width * sin(M_PI / a);
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}
