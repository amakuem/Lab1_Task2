#include "rectungle.h"


rectungle::rectungle() {}

void rectungle::draw(QGraphicsScene *scene, int width, int height){
    setRect(0, 0, width, height); // Задайте размер прямоугольника
    setBrush(Qt::red);
    scene->addItem(this); // Добавьте прямоугольник на сцену

    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(width/2 - 2.5, height/2 - 2.5, 5, 5);
    point->setBrush(Qt::blue);
    scene->addItem(point);
}

void rectungle::perSquareMasse( int width, int height){
    double perimetr = (width + height) * 2;
    double square = width *height;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}

void rectungle::centerMasse(QGraphicsScene *scene,int width, int height){

}

void rectungle::getParametrs(int &side1, int &side2){
    bool ok;
    side1 = QInputDialog::getInt(this, tr("Введите ширину"), tr("Ширина:"), 100, 0, 10000, 1, &ok);
    side2 = QInputDialog::getInt(this, tr("Введите длину"), tr("Длина:"), 200, 0, 10000, 1, &ok);
}

