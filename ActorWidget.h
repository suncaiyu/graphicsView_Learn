#ifndef ACTORWIDGET_H
#define ACTORWIDGET_H

#include <QWidget>

namespace Ui {
class ActorWidget;
}
class ActorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ActorWidget(QString color, QWidget *parent = nullptr);
    ~ActorWidget(){};

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ActorWidget *ui;
    QString mInfo;
};

#endif // ACTORWIDGET_H
