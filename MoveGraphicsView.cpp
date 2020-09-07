#include "MoveGraphicsView.h"
#include <Qdebug>
MoveGraphicsView::MoveGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    mScene = new QGraphicsScene(this);
    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setScene(mScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mAnimation = new QPropertyAnimation(this, "scrollPosition");
    mAnimation->setDuration(interval);
    connect(horizontalScrollBar(), &QScrollBar::valueChanged, this, [](int v) { qDebug() << v; });
}

MoveGraphicsView::~MoveGraphicsView()
{
    for (QGraphicsProxyWidget *v : mWidget) {
        delete v;
        v = nullptr;
    }
}

void MoveGraphicsView::showEvent(QShowEvent *event)
{
    int count = 0 ? 1 : mWidgetCount;
    mScene->setSceneRect(0, 0, width() * count, height());
    QGraphicsView::showEvent(event);
}

void MoveGraphicsView::AddWidget(QWidget *widget)
{
    mWidgetCount++;
    QGraphicsProxyWidget *w = mScene->addWidget(widget);
    mWidget.push_back(w);
    mScene->setSceneRect(0, 0, width() * mWidgetCount, height());
    for (int i = 0; i < mWidget.size(); i++) {
        mWidget[i]->resize(width(), height());
        mWidget[i]->setPos(width() * i, 0);
    }
}

void MoveGraphicsView::resizeEvent(QResizeEvent *event)
{
    mScene->setSceneRect(0, 0, width() * mWidgetCount, height());
    for (int i = 0; i < mWidget.size(); i++) {
        mWidget[i]->resize(width(), height());
        mWidget[i]->setPos(width() * i, 0);
    }
    float pre = (float) (horizontalScrollBar()->maximum()) / (float) (mWidgetCount - 1);
    horizontalScrollBar()->setValue(pre * (mCurrentIndex - 1));
    QGraphicsView::resizeEvent(event);
}

void MoveGraphicsView::ChangeIndex(int index)
{
    // 从1开始
    if (index > mWidgetCount) {
        return;
    }
    if (index < 1) {
        return;
    }
    mCurrentIndex = index;
    if (mAnimation->state() == QPropertyAnimation::Running) {
        mAnimation->stop();
    }
    float pre = (float) (horizontalScrollBar()->maximum()) / (float) (mWidgetCount - 1);
    mAnimation->setStartValue(GetCurrentPosition());

    mAnimation->setEndValue((float) (pre * (index - 1)));
    mAnimation->start();
}

void MoveGraphicsView::ChangeIndexNxt()
{
    int index = mCurrentIndex + 1;
    if (index > mWidgetCount) {
        return;
    }
    mCurrentIndex = index;
    if (mAnimation->state() == QPropertyAnimation::Running) {
        mAnimation->stop();
    }
    float pre = (float) (horizontalScrollBar()->maximum()) / (float) (mWidgetCount - 1);
    mAnimation->setStartValue(GetCurrentPosition());

    mAnimation->setEndValue((float) (pre * (index - 1)));
    mAnimation->start();
}

void MoveGraphicsView::ChangeIndexPre()
{
    int index = mCurrentIndex - 1;
    if (index < 1) {
        return;
    }
    mCurrentIndex = index;
    if (mAnimation->state() == QPropertyAnimation::Running) {
        mAnimation->stop();
    }
    float pre = (float) (horizontalScrollBar()->maximum()) / (float) (mWidgetCount - 1);
    mAnimation->setStartValue(GetCurrentPosition());

    mAnimation->setEndValue((float) (pre * (index - 1)));
    mAnimation->start();
}

void MoveGraphicsView::SetInterval(int i)
{
    interval = i;
    mAnimation->setDuration(interval);
}

int MoveGraphicsView::GetCurrentPosition()
{
    return horizontalScrollBar()->value();
}

int MoveGraphicsView::GetCurrentIndex()
{
    return mCurrentIndex;
}

int MoveGraphicsView::GetMaxIndex()
{
    return mWidgetCount;
}

void MoveGraphicsView::SetScrollPosition(int i)
{
    mScrollPosition = i;
    horizontalScrollBar()->setValue(i);
    update();
}

int MoveGraphicsView::GetScrollPosition()
{
    return mScrollPosition;
}
