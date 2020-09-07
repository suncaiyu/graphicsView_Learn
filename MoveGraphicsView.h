#ifndef MOVEGRAPHICSVIEW_H
#define MOVEGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QScrollBar>
#include <QGraphicsProxyWidget>
#include <QPropertyAnimation>

class MoveGraphicsView : public QGraphicsView
{
    Q_OBJECT
    Q_PROPERTY(int scrollPosition READ GetScrollPosition WRITE SetScrollPosition)
public:
    MoveGraphicsView(QWidget *parent);
    ~MoveGraphicsView();
    void AddWidget(QWidget *);
    float mCurrentScrollPosition = 0;
    void SetInterval(int);
    int GetCurrentIndex();
    int GetMaxIndex();

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *mScene = nullptr;
    int mWidgetCount = 0;
    QList<QGraphicsProxyWidget *> mWidget;
    QPropertyAnimation *mAnimation = nullptr;
    // 动画时间
    int interval = 300;
    int GetCurrentPosition();
    // 当前的位置是第几个，默认从1开始
    int mCurrentIndex = 1;

    int GetScrollPosition();
    void SetScrollPosition(int);
    int mScrollPosition = 0;
public slots:
    // 第几个
    void ChangeIndex(int index);
    //上一个
    void ChangeIndexPre();
    //下一个
    void ChangeIndexNxt();
};

#endif // MOVEGRAPHICSVIEW_H
