#include "output.h"

#include <DLabel>

Output::Output()
    : btn(new DPushButton)
    , timer(new QTimer(this))
    , waterProgress(new DWaterProgress)
    , layout(new QVBoxLayout(this))
{
    init();
    initConnection();
}


void Output::init()
{
    DLabel *label = new DLabel("选择ISO");
    QFont font;
    font.setFamily("Helvetica");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);
    layout->addWidget(label,0,Qt::AlignTop | Qt::AlignCenter);

    waterProgress =new DWaterProgress(this);
    waterProgress->setFixedSize(100,100);
    layout->addWidget(waterProgress,0,Qt::AlignCenter);

    timer->setInterval(10);
    connect(timer, &QTimer::timeout,this,&Output::slotWaterProgress);

    btn = new DPushButton(this);
    btn->setText("下一步");
    btn->setFixedWidth(width()/2);
  //  btn->setEnabled(false);
    layout->addWidget(btn,0,Qt::AlignCenter|Qt::AlignBottom);

}

void Output::initConnection()
{
    connect(btn, &DPushButton::clicked, [ = ]() {
        if(timer->isActive()){
              timer->stop();
        }else {
            timer->start();
            waterProgress->start();
        }
    });
}

void Output::slotWaterProgress()
{
    static int i=0;
    i++;
    if(101 == i){
        timer->stop();
        i=0;
//        emit signalOutput(7);
        //displayFailed();

    }else {
        waterProgress->setValue(i);
    }
}
