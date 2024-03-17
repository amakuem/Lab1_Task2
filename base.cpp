#include "base.h"

base::base() {}

void base::draw(QGraphicsScene *scene, int width, int height){}

void base::centerMasse(QGraphicsScene *scene, int width, int height){}

void base::perSquareMasse(int width, int height){}

void base::getParametrs(int &side1, int &side2, int a){}

void base::up(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x(), item->pos().y() - 3);
        y -= 3;
    }
    //this->setPos(this->QGraphicsItem::x(), this->QGraphicsItem::y() - 3);
}

void base::down(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x(), item->pos().y() + 3);
        y += 3;
    }
    //group()->setPos(group()->QGraphicsItem::x(), group()->QGraphicsItem::y() + 3);
}

void base::left(QGraphicsScene *scene, int &x)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x() - 3, item->pos().y());
        x -= 3;
    }


    //this->setPos(this->QGraphicsItem::x() - 3, this->QGraphicsItem::y());
}

void base::right(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x() + 3, item->pos().y());
        x += 3;
    }
    //this->setPos(this->QGraphicsItem::x() + 3, this->QGraphicsItem::y());
}

void base::rotateLeft(QGraphicsScene *scene, int x, int y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setTransformOriginPoint(x, y);
        item->setRotation(item->rotation()-1);
    }

    //group->setTransformOriginPoint();
}

void base::rotateRight(QGraphicsScene *scene, int x, int y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setTransformOriginPoint(x, y);
        item->setRotation(item->rotation()+1);
    }
}


