#include "Controller.h"
#include "ui_Controller.h"
#include <QDebug>

Controller::Controller(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::Controller)
{
    ui->setupUi(this);
}

Controller::~Controller()
{
    delete ui;
}
//<
void Controller::on_pushButton_clicked()
{
    emit LeftSignal();
    qDebug() << "l";
}
//>
void Controller::on_pushButton_2_clicked()
{
    emit RightSignal();
    qDebug() << "r";
}
