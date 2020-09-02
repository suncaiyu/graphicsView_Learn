#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

namespace Ui {
class Controller;
}

class Controller : public QWidget
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Controller *ui;
signals:
    void LeftSignal();
    void RightSignal();
};

#endif // CONTROLLER_H
