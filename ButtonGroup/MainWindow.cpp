#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <ButtonGroup.h>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ButtonGroup *bg = new ButtonGroup(this);
    for (int i = 0; i < 3; i++) {
        QPushButton *btn = new QPushButton(QString::number(i));
        bg->addButton(btn, i);
    }
    bg->SetHeight(35);
    bg->setLinePosition(ButtonGroup::LinePosition_Bottom);
    ui->verticalLayout->insertWidget(0, bg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

