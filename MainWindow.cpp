#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"

#include <QGraphicsProxyWidget>
#include <QTimer>
#include <QScrollBar>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUI();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QTimer::singleShot(100, this, [this] { resize(size() + QSize(1, 1)); });
    //    QTimer *t = new QTimer;
    //    connect(t, &QTimer::timeout, this, [this]() {
    //        QScrollBar *sc = ui->graphicsView->horizontalScrollBar();
    //        int max = sc->maximum();
    //        int v = sc->value();
    //        if (v + 10 <= max) {
    //            sc->setValue(v + 10);
    //        } else {
    //            sc->setValue(max);
    //        }
    //    });
    //    t->start(500);
    Controller *c = new Controller;
    c->show();
    connect(c, &Controller::LeftSignal, this, [this] {
        QScrollBar *sc = ui->graphicsView->horizontalScrollBar();
        QTimer *t = new QTimer;
        connect(t, &QTimer::timeout, this, [this, sc, t] {
            int v = sc->value();
            if (v - 20 >= 0) {
                sc->setValue(v - 20);
            } else {
                sc->setValue(0);
                t->stop();
            }
        });
        t->start(10);
    });
    connect(c, &Controller::RightSignal, this, [this] {
        QScrollBar *sc = ui->graphicsView->horizontalScrollBar();
        QTimer *t = new QTimer;
        connect(t, &QTimer::timeout, this, [this, sc, t] {
            int v = sc->value();
            if (v + 20 <= sc->maximum()) {
                sc->setValue(v + 20);
            } else {
                sc->setValue(sc->maximum());
                t->stop();
            }
        });
        t->start(10);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUI()
{
    this->resize(540, 400);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_pGraphicsScene = new CustomGraphicsScene; //自定义的场景
    //    m_pGraphicsScene
    //        ->setSceneRect(0,
    //                       0,
    //                       ui->graphicsView->width(),
    //                       ui->graphicsView->height()); //设置场景大小，占据整个QGraphicsView窗口
    ui->graphicsView->setScene(m_pGraphicsScene); //为QGraphicsView设置场景

    m_pActorWidget = new ActorWidget("black"); //自定义的ActorWidget
    w1 = new ActorWidget("green");
    pWidget = m_pGraphicsScene->addWidget(
        m_pActorWidget); //在场景中添加自定义的ActorWidget，返回一个QGraphicsProxyWidget指针
    pW1 = m_pGraphicsScene->addWidget(
        w1); //在场景中添加自定义的ActorWidget，返回一个QGraphicsProxyWidget指针
    pWidget->setPos(0, 0); //通过QGraphicsProxyWidget指针设置其位置，居中显示
    pW1->setPos(ui->graphicsView->width(), 0);
    pWidget->setFlags(
        QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable
        | QGraphicsItem::ItemIsMovable); //通过QGraphicsProxyWidget指针设置其可选、可移动、可聚焦
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
        m_pGraphicsScene
            ->setSceneRect(0,
                           0,
                           ui->graphicsView->width() * 2,
                           ui->graphicsView->height()); //设置场景大小，占据整个QGraphicsView窗口
    m_pActorWidget->resize(ui->graphicsView->width(), ui->graphicsView->height());
    pW1->resize(ui->graphicsView->width(), ui->graphicsView->height());
    pWidget->setPos(0, 0);
    pW1->setPos(ui->graphicsView->width(), 0);
    QMainWindow::resizeEvent(e);
}

