#include "middleinstall.h"

#include <DLabel>

#include <QVBoxLayout>
#include <QTimer>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>

MiddleInstall::MiddleInstall(QWidget *parent)
    : QWidget(parent)
    , btn(new DPushButton)
    , layout(new QVBoxLayout(this))
    , cmdlnkBtn(new DCommandLinkButton(tr("选择脚本")))
    , clearBtn(new DCommandLinkButton(tr("全部清除")))
    , lineEdit(new DLineEdit)
{
    init();
    initConnection();
}


void MiddleInstall::init()
{
    QHBoxLayout *hLayout = new QHBoxLayout;

    DLabel *label = new DLabel("中期安装");
    QFont font;
    font.setFamily("Helvetica");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);
    hLayout->addWidget(label, Qt::AlignLeft);
    hLayout->addStretch(5);

    clearBtn->hide();
    hLayout->addWidget(clearBtn,Qt::AlignRight);

    layout->addLayout(hLayout);

    lineEdit->hide();
    layout->addWidget(lineEdit);
    layout->addStretch();


    DLabel *label2 = new DLabel("请选择中期安装");
    DFontSizeManager::instance()->bind(label2, DFontSizeManager::T2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setEnabled(false);
    layout->addWidget(label2,0,Qt::AlignTop|Qt::AlignHCenter);
    layout->addStretch();

    layout->addWidget(cmdlnkBtn,0,Qt::AlignHCenter);

    btn = new DPushButton(this);
    btn->setText("下一步");
    btn->setFixedWidth(width()/2);
    btn->setEnabled(false);
    layout->addWidget(btn,0,Qt::AlignCenter|Qt::AlignBottom);
}

void MiddleInstall::initConnection()
{
    connect(cmdlnkBtn,&DCommandLinkButton::clicked,[=](){
        QString url = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                              QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
                                                              tr("deb (*.deb)"));
         QDesktopServices::openUrl(QUrl(url));
         QTimer::singleShot(1000, [=](){
//             if(".deb" == lineEdit->text().right(4))
                 btn->setEnabled(true);
         });
         lineEdit->clear();
         lineEdit->setText(url);
         lineEdit->show();
         clearBtn->show();
    });

    connect(btn,&DPushButton::clicked,[=](){
        emit signalMiddleInstall(4);
    });

    connect(clearBtn,&DCommandLinkButton::clicked,[=](){
        lineEdit->clear();
    });
}

