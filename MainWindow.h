#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "actorwidget.h"
#include "customgraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    void InitUI();

private:
    Ui::MainWindow *ui;

private:
    CustomGraphicsScene *m_pGraphicsScene;
    ActorWidget *m_pActorWidget;
    ActorWidget *w1;
    QGraphicsProxyWidget *pWidget;
    QGraphicsProxyWidget *pW1;
};

#endif // MAINWINDOW_H
