#include "TestShow.h"
#include "ui_TestShow.h"
#include <MoveGraphicsView.h>
#include <ActorWidget.h>
#include <QHBoxLayout>
#include <Controller.h>
#include <QDebug>

TestShow::TestShow(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::TestShow)
{
    ui->setupUi(this);
    QHBoxLayout *main = new QHBoxLayout(this);
    setLayout(main);

    MoveGraphicsView *mview = new MoveGraphicsView(this);
    ActorWidget *a1 = new ActorWidget("blue");
    ActorWidget *a2 = new ActorWidget("yellow");
    ActorWidget *a3 = new ActorWidget("white");
    ActorWidget *a4 = new ActorWidget("red");
    main->addWidget(mview);
    mview->AddWidget(a1);
    mview->AddWidget(a2);
    mview->AddWidget(a3);
    mview->AddWidget(a4);
    Controller *c = new Controller;
    connect(c, &Controller::LeftSignal, this, [mview] {
        mview->ChangeIndexPre();
    });
    connect(c, &Controller::RightSignal, this, [mview] {
        mview->ChangeIndexNxt();
    });
    c->show();
}

TestShow::~TestShow()
{
    delete ui;
}
