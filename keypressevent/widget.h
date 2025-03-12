#ifndef WIDGET_H
#define WIDGET_H
#include<QTime>
#include <QWidget>
#include<QTimerEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent *event);//按键事件
    virtual void timerEvent(QTimerEvent *event);//定时器事件
    void slot_update_led();
private:
    Ui::Widget *ui;
    int id1;
    int id2;
    int id3;
};
#endif // WIDGET_H
