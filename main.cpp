#include "MainWindow.h"

#include <QApplication>
#include <TestShow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestShow w;
    w.show();
    return a.exec();
}
