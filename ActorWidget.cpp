#include "ActorWidget.h"
#include "ui_ActorWidget.h"
#include <QPainter>
#include <QtDebug>

ActorWidget::ActorWidget(QString color, QWidget *parent) : QWidget(parent), ui(new Ui::ActorWidget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    mInfo = color;
}

void ActorWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(Qt::blue);
    p.drawText(rect(), Qt::AlignCenter, mInfo);
//    p.fillRect(rect().adjusted(-10, -10, 10, 10), QBrush());
}

void ActorWidget::on_pushButton_clicked()
{
    qDebug() << mInfo;
}
