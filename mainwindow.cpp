#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this); // Создайте новую сцену
    rectangle = new rectungle(); // Создайте новый прямоугольник
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
        //basa = new rectungle();
        rectangle = new rectungle();
        //rectungle *rec = dynamic_cast<rectungle*>(basa);
        int width;// = QInputDialog::getInt(this, tr("Введите ширину"), tr("Ширина:"), 100, 0, 10000, 1, &ok);
        int height;// = QInputDialog::getInt(this, tr("Введите длину"), tr("Длина:"), 200, 0, 10000, 1, &ok);
        rectangle->getParametrs(width, height);
        //basa->getParametrs(width, height);
        //basa->draw(scene, width, height);
        rectangle->draw(scene, width, height);
        //rectangle->centerMasse(scene, width, height);

        //connect(basa, *re)
        connect(rectangle, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(rectangle, &rectungle::sendSquare, this, &MainWindow::showSquare);

        rectangle->perSquareMasse(width, height);
        x = width/2;
        y = height/2;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));

    }
    else if(ui->comboBox->currentText() == "Квадрат"){
        //scene->clear();
        rectangle = new rectungle();
        bool ok;
        int side = QInputDialog::getInt(this, tr("Введите длину стороны:"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
        rectangle->draw(scene, side, side);
        //rectangle->centerMasse(scene, side, side);

        connect(rectangle, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(rectangle, &rectungle::sendSquare, this, &MainWindow::showSquare);

        rectangle->perSquareMasse(side, side);
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
