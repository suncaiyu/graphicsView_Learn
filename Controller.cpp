#include "Controller.h"
#include "ui_Controller.h"

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
}
//>
void Controller::on_pushButton_2_clicked()
{
    emit RightSignal();
}
