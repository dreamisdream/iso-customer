#include "progressconfig.h"

#include <QDesktopServices>

#include <DLabel>
#include <DFileDialog>
#include <DLineEdit>
#include <DMessageManager>

#include <QVBoxLayout>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

ProgressConfig::ProgressConfig(QWidget *parent)
    : QWidget(parent)
    , btn(new DPushButton)
    , layout(new QVBoxLayout(this))
    , cmdlnkBtn(new DCommandLinkButton(tr("选择程序deb包")))
    , textEdit(new DTextEdit)
    , clearBtn(new DCommandLinkButton("全部清除"))
    , floatWidget(new DFloatingWidget)

{
    init();
    initConnection();

}

void ProgressConfig::init()
{
    QHBoxLayout *hLayout = new QHBoxLayout;

    hLayout->addStretch();
    DLabel *label = new DLabel("程序配置");
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

    floatWidget->hide();
    layout->addWidget(floatWidget);


    textEdit->hide();
    layout->addWidget(textEdit);
    layout->addStretch();

    DLabel *label2 = new DLabel("请选择程序");
    DFontSizeManager::instance()->bind(label2, DFontSizeManager::T2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setEnabled(false);
    layout->addWidget(label2,0,Qt::AlignTop|Qt::AlignHCenter);
    layout->addStretch();

    layout->addWidget(cmdlnkBtn,0,Qt::AlignHCenter);

    btn->setText("下一步");
    btn->setFixedWidth(width()/2);
    btn->setEnabled(false);
    layout->addWidget(btn,0,Qt::AlignCenter);

}

void ProgressConfig::initConnection()
{

    connect(cmdlnkBtn, &DCommandLinkButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->setNameFilter("*.deb");
        pDFileDialog->show();
        pDFileDialog->exec();

        floatWidget->show();
        QStringList strlistSelectedName = pDFileDialog->selectedFiles(); // 选择的文件
        QString str;
        for (QString strSelectFile : strlistSelectedName) {
            QFileInfo fileInfo(strSelectFile);
//            DFloatingMessage *floatMessage = new DFloatingMessage(DFloatingMessage::ResidentType,this);

//            floatMessage->setWidget(floatWidget);
//            DMessageManager::instance()->sendMessage(this,floatMessage);

            str.append(fileInfo.fileName()).append("\n");
        }
        textEdit->setText(str);
        textEdit->show();
        btn->setEnabled(true);
        clearBtn->show();
    });

    connect(btn,&DPushButton::clicked,[=](){
        emit signalProgressConfig(2);
    });

    connect(clearBtn,&DCommandLinkButton::clicked,[=](){
       textEdit->clear();
    });

}



