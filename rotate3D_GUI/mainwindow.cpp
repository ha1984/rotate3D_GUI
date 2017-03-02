#include "mainwindow.h"
#include "..\build-test-Desktop_Qt_5_6_1_MSVC2013_64bit2-Debug\ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    // Connect button signal to appropriate slot
   connect(ui->checkBox, SIGNAL (stateChanged(int)), this, SLOT (wiredmesh()));
   connect(ui->checkBox_2, SIGNAL (stateChanged(int)), this, SLOT (rotate()));
   connect(ui->X, SIGNAL(valueChanged(double)), this, SLOT(setxVal()));
   connect(ui->Y, SIGNAL(valueChanged(double)), this, SLOT(setyVal()));
   connect(ui->Z, SIGNAL(valueChanged(double)), this, SLOT(setzVal()));
}


void MainWindow::wiredmesh()
{

    ui->widget->Wire = !ui->widget->Wire;
    //repaint();
}

void MainWindow::rotate()
{
    ui->widget->Rotate = !ui->widget->Rotate;
}

void MainWindow::setxVal()
{
    ui->widget->x = static_cast<GLfloat>(ui->X->value());
    //move object
    ui->widget->xmove = true;
    //ui->lineEdit->setText("x value set");
    ui->widget->update();
}

void MainWindow::setyVal()
{
    ui->widget->y = static_cast<GLfloat>(ui->Y->value());
    //move object
    ui->widget->ymove = true;
    //ui->lineEdit->setText("x value set");
    ui->widget->update();
}

void MainWindow::setzVal()
{
    ui->widget->z = static_cast<GLfloat>(ui->Z->value());
    //move object
    ui->widget->zmove = true;
    //ui->lineEdit->setText("x value set");
    ui->widget->update();
}



MainWindow::~MainWindow()
{
    delete ui;
}




