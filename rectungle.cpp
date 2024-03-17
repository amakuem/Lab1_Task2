#include "rectungle.h"


rectungle::rectungle() {}

void rectungle::draw(QGraphicsScene *scene, int width, int height){
    QGraphicsRectItem *figure = new QGraphicsRectItem(0, 0, width, height);
    //setRect(0, 0, width, height);
    figure->setBrush(Qt::red);

    //scene->addItem(this);

    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(width/2 - 2.5, height/2 - 2.5, 3, 3);
    point->setBrush(Qt::blue);
    //scene->addItem(point);
    QGraphicsItemGroup *group = new QGraphicsItemGroup();

    group->addToGroup(figure);
    group->addToGroup(point);

    scene->addItem(group);
}

void rectungle::perSquareMasse( int width, int height){
    double perimetr = (width + height) * 2;
    double square = width *height;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}

void rectungle::centerMasse(QGraphicsScene *scene,int width, int height){

}

void rectungle::getParametrs(int &side1, int &side2, int a){
    if (a == 0)
    {
        bool ok;
        side1 = QInputDialog::getInt(this, tr("Введите ширину"), tr("Ширина:"), 100, 0, 10000, 1, &ok);
        side2 = QInputDialog::getInt(this, tr("Введите длину"), tr("Длина:"), 200, 0, 10000, 1, &ok);
    }
    else
    {
        bool ok;
        side1 = QInputDialog::getInt(this, tr("Введите длину стороны:"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
    }
}


