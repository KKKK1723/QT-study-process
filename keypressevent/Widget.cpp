#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QDebug>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);//设置聚焦协议 不然按键动不了
    // id1=startTimer(1000);//开启定时器，中间是以毫秒为单位 1000就是1秒 会返回一个定时器的id
    // id2=startTimer(1000);
    // id3=startTimer(1000);
    //初始化
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::slot_update_led);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
    // killTimer(id1);
    // killTimer(id2);
    // killTimer(id3);
}

void Widget::keyPressEvent(QKeyEvent *event)
{                              //ctrl键
    if(event->modifiers()==Qt::ControlModifier)//这个modifiers可以判断鼠标按键也可以判断键盘按键
    {
        if(event->key()==Qt::Key_M&&windowState()!=Qt::WindowFullScreen)//按下m 并且此时不是全屏 那就变成全屏
        {
            setWindowState(Qt::WindowFullScreen);
            return;
        }
        return ;
    }

    if(event->key()==Qt::Key_Escape&&windowState()==Qt::WindowFullScreen)
    {
        setWindowState(Qt::WindowNoState);//退出全屏
        return;
    }

    bool bup=false;
    bool bdw=false;
    bool lf=false;
    bool ri=false;


    //向上
    if(event->key()==Qt::Key_Up)
    {             //返回true
        if(event->isAutoRepeat())//查看是不是一直按住不动
        {
            auto curpos=ui->pushButton->pos();
            curpos.setY(curpos.y()-5);
            ui->pushButton->move(curpos);
            return;//结束
        }
        else
        {
            bup=true;
        }
    }
    //向下
    if(event->key()==Qt::Key_Down)
    {             //返回true
        if(event->isAutoRepeat())//查看是不是一直按住不动
        {
            auto curpos=ui->pushButton->pos();
            curpos.setY(curpos.y()+5);
            ui->pushButton->move(curpos);
            return;//结束
        }
        else
        {
            bdw=true;
        }
    }
    //向左
    if(event->key()==Qt::Key_Left)
    {             //返回true
        if(event->isAutoRepeat())//查看是不是一直按住不动
        {
            auto curpos=ui->pushButton->pos();
            curpos.setX(curpos.x()-5);
            ui->pushButton->move(curpos);
            return;//结束
        }
        else
        {
            lf=true;
        }
    }
    //向右
    if(event->key()==Qt::Key_Right)
    {             //返回true
        if(event->isAutoRepeat())//查看是不是一直按住不动
        {
            auto curpos=ui->pushButton->pos();
            curpos.setX(curpos.x()+5);
            ui->pushButton->move(curpos);
            return;//结束
        }
        else
        {
            ri=true;
        }
    }

    auto curpos=ui->pushButton->pos();//获取位置
    if(bup)
    {
        curpos.setY(curpos.y()-5);
    }
    if(bdw)
    {
        curpos.setY(curpos.y()+5);
    }
    if(lf)
    {
        curpos.setX(curpos.x()-5);
    }
    if(ri)
    {
        curpos.setX(curpos.x()+5);
    }
    ui->pushButton->move(curpos);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        qDebug()<<"id1 timer triggred";
    }
    if(event->timerId() == id2)
    {
        qDebug()<<"id2 timer triggred";
    }
    if(event->timerId() == id3)
    {
        qDebug()<<"id3 timer triggred";
    }
}

void Widget::slot_update_led()
{
    //获取当前时间
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm:ss");//格式化
    //qDebug()<<"current time is "<<text;
    ui->lcdNumber->setDigitCount(text.length());//显示长度
    ui->lcdNumber->display(text);
}

