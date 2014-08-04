#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    comboTime=new QSpinBox;
    editMsg=new QLineEdit;
    editClickMsg=new QLineEdit;
    btnShow=new QPushButton(tr("显示"));

    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setVisible(true);
    trayIcon->setIcon(QIcon(":/sunny"));
    trayIcon->setToolTip(tr("测试"));//

    QGridLayout *gridLayout=new QGridLayout;
    gridLayout->addWidget(new QLabel(tr("显示时间")),0,0);
    gridLayout->addWidget(comboTime,0,1);
    gridLayout->addWidget(new QLabel(tr("消息内容")),1,0);
    gridLayout->addWidget(editMsg,1,1);
    gridLayout->addWidget(new QLabel(tr("点击显示")),2,0);
    gridLayout->addWidget(editClickMsg,2,1);
    gridLayout->addWidget(btnShow,3,1);
    setLayout(gridLayout);

    comboTime->setSuffix(tr("秒"));//添加后缀
    comboTime->setRange(5,15);
    comboTime->setValue(10);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showMsg()));
    connect(btnShow,SIGNAL(clicked()),this,SLOT(showMsg()));
    connect(trayIcon,SIGNAL(messageClicked()),this,SLOT(showClickMsg()));
}



void Widget::showMsg()
{
    trayIcon->showMessage(tr("弹出消息测试"),editMsg->text(),QSystemTrayIcon::Information,comboTime->value()*1000);
}

void Widget::showClickMsg()
{
    QMessageBox::information(this,tr("托盘消息点击测试"),editClickMsg->text());
}

