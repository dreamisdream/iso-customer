#include "tailclear.h"

#include <DLabel>
#include <DFileDialog>

#include <QTimer>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>

TailClear::TailClear()
    : btn(new DPushButton)
    , layout(new QVBoxLayout(this))
    , cmdlnkBtn(new DCommandLinkButton(tr("选择脚本")))
    , clearBtn(new DCommandLinkButton(tr("全部清除")))
    , textEdit(new DTextEdit)
{
    init();
    initConnection();
}

void TailClear::init()
{
    QHBoxLayout *hLayout = new QHBoxLayout;

    DLabel *label = new DLabel("后期清理");
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

    textEdit->hide();
    layout->addWidget(textEdit);
    layout->addStretch();

    DLabel *label2 = new DLabel("请选择后期清理");
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

void TailClear::initConnection()
{
    connect(cmdlnkBtn, &DCommandLinkButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->setNameFilter("*.job");
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        QString str;
        for (QString strSelectFile : strlistSelectedName) {
            QFileInfo fileInfo(strSelectFile);
            str.append(fileInfo.fileName()).append("\n");
        }
        textEdit->setText(str);
        textEdit->show();
        btn->setEnabled(true);
        clearBtn->show();

    });
    connect(btn,&DPushButton::clicked,[=](){
        emit signalTailClear(5);
    });
    connect(clearBtn,&DCommandLinkButton::clicked,[=](){
        textEdit->clear();
    });
}
