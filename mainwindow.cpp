#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    rectangle = new rectungle();
    ui->graphicsView->setScene(scene);
    //connect(rectangle, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
    //connect(rectangle, &rectungle::sendSquare, this, &MainWindow::showSquare);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    scene->clear();

    if(ui->comboBox->currentText() == "Прямоугольник")
    {
        scene->clear();
        basa = new rectungle();
            //rectangle = new rectungle();
        rectungle *rec = dynamic_cast<rectungle*>(basa);
        int width;// = QInputDialog::getInt(this, tr("Введите ширину"), tr("Ширина:"), 100, 0, 10000, 1, &ok);
        int height;// = QInputDialog::getInt(this, tr("Введите длину"), tr("Длина:"), 200, 0, 10000, 1, &ok);
            //rectangle->getParametrs(width, height);
        int a = 0;
        //basa->getPara

        basa->getParametrs(width, height, a);
        basa->draw(scene, width, height);
            //rectangle->draw(scene, width, height);
            //rectangle->centerMasse(scene, width, height);

            //connect(basa, *re)
        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);
        basa->perSquareMasse(width, height);
        //rectangle->perSquareMasse(width, height);
        x = width/2;
        y = height/2;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));

    }
    else if(ui->comboBox->currentText() == "Квадрат"){
        scene->clear();
        basa = new rectungle();
        rectungle *rec = dynamic_cast<rectungle*>(basa);
            //rectangle = new rectungle();
        bool ok;

        int side;
        int a = 1;
        basa->getParametrs(side, side, a);
            //int side = QInputDialog::getInt(this, tr("Введите длину стороны:"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
        basa->draw(scene, side, side);
            //rectangle->draw(scene, side, side);
            //rectangle->centerMasse(scene, side, side);

        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);

        basa->perSquareMasse(side, side);
            //rectangle->perSquareMasse(side, side);
        x = side/2;
        y = side/2;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));
        //rectangle->
    }
}


void MainWindow::on_pushButton_2_pressed()
{
    plus = new QTimer(this);
    plus->start(65);
    connect(plus, &QTimer::timeout, this, &MainWindow::plusZoom);
}



void MainWindow::on_pushButton_3_pressed()
{
    minus = new QTimer(this);
    minus->start(65);
    connect(minus, &QTimer::timeout, this, &MainWindow::minusZoom);

}

void MainWindow::plusZoom(){
    ui->graphicsView->scale(1.2, 1.2);
}

void MainWindow::minusZoom(){
    ui->graphicsView->scale(1/1.2, 1/1.2);
}


void MainWindow::on_pushButton_2_released()
{
    plus->stop();
}


void MainWindow::on_pushButton_3_released()
{
    minus->stop();
}

void MainWindow::showPerimetr(double perimetr){
    ui->label_4->setText(QString::number(perimetr));
}

void MainWindow::showSquare(double square){
    ui->label_5->setText(QString::number(square));
}



void MainWindow::on_pushButton_4_pressed()
{
    up = new QTimer(this);
    up->start(65);
    connect(up, &QTimer::timeout, this, &MainWindow::mUp);
}

void MainWindow::mUp()
{
    basa->up(scene, x ,y);
}

void MainWindow::on_pushButton_4_released()
{
    up->stop();
}

void MainWindow::on_pushButton_5_pressed()
{
    down = new QTimer(this);
    down->start(65);
    connect(down, &QTimer::timeout, this, &MainWindow::mDown);
}

void MainWindow::mDown()
{
    basa->down(scene, x, y);
}

void MainWindow::on_pushButton_5_released()
{
    down->stop();
}


void MainWindow::on_pushButton_6_pressed()
{
    left = new QTimer(this);
    left->start(65);
    connect(left, &QTimer::timeout, this, &MainWindow::mLeft);
}

void MainWindow::mLeft()
{
    basa->left(scene, x);
}

void MainWindow::on_pushButton_6_released()
{
    left->stop();
}


void MainWindow::on_pushButton_7_pressed()
{
    right = new QTimer(this);
    right->start(65);
    connect(right, &QTimer::timeout, this, &MainWindow::mRight);
}

void MainWindow::mRight()
{
    basa->right(scene, x ,y);
}

void MainWindow::on_pushButton_7_released()
{
    right->stop();
}



void MainWindow::on_pushButton_8_pressed()
{
    rotateLef = new QTimer(this);
    rotateLef->start(65);
    connect(rotateLef, &QTimer::timeout, this, &MainWindow::rotateL);
}

void MainWindow::rotateL()
{
    basa->rotateLeft(scene, x, y);
}

void MainWindow::on_pushButton_8_released()
{
    rotateLef->stop();
}



void MainWindow::on_pushButton_9_pressed()
{
    rotateRig = new QTimer(this);
    rotateRig->start(65);
    connect(rotateRig, &QTimer::timeout, this, &MainWindow::rotateR);
}

void MainWindow::rotateR()
{
    basa->rotateRight(scene, x, y);
}


void MainWindow::on_pushButton_9_released()
{
    rotateRig->stop();
}

