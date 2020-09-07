#ifndef TESTSHOW_H
#define TESTSHOW_H

#include <QWidget>

namespace Ui {
class TestShow;
}

class TestShow : public QWidget
{
    Q_OBJECT

public:
    explicit TestShow(QWidget *parent = nullptr);
    ~TestShow();

private:
    Ui::TestShow *ui;
};

#endif // TESTSHOW_H
