#include "progressconfig.h"

#include <QDesktopServices>

#include <DLabel>
#include <DFileDialog>
#include <DLineEdit>


#include <QVBoxLayout>
#include <QUrl>
#include <QFileDialog>
#include <QTimer>

ProgressConfig::ProgressConfig(QWidget *parent)
    : QWidget(parent)
    , btn(new DPushButton)
    , layout(new QVBoxLayout(this))
    , cmdlnkbtn(new DCommandLinkButton(tr("选择程序deb包")))
    , textEdit(new DTextEdit)
    , clearButton(new DCommandLinkButton("全部清除"))
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


    clearButton->hide();
    hLayout->addWidget(clearButton,Qt::AlignRight);

    layout->addLayout(hLayout);

    textEdit->hide();
    layout->addWidget(textEdit);
    layout->addStretch();

    DLabel *label2 = new DLabel("请选择程序");
    DFontSizeManager::instance()->bind(label2, DFontSizeManager::T2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setEnabled(false);
    layout->addWidget(label2,0,Qt::AlignTop|Qt::AlignHCenter);
    layout->addStretch();

    layout->addWidget(cmdlnkbtn,0,Qt::AlignHCenter);

    btn->setText("下一步");
    btn->setFixedWidth(width()/2);
    btn->setEnabled(false);
    layout->addWidget(btn,0,Qt::AlignCenter);

}

void ProgressConfig::initConnection()
{
//    connect(cmdlnkbtn, &DCommandLinkButton::clicked, this,[=](){
//        QString url = QFileDialog::getOpenFileName(this, tr("Open File"), QStandardPaths::writableLocation(QStandardPaths::HomeLocation), tr("job (*.job)"));
        
//        QDesktopServices::openUrl(QUrl(url));
//        QTimer::singleShot(1000, [=](){
//             btn->setEnabled(true);
//         });
//        lineEdit->clear();

//        lineEdit->setText(url);
//        lineEdit->show();
//        clearButton->show();
//    });

    connect(cmdlnkbtn, &DCommandLinkButton::clicked, [ = ]() {
        DFileDialog *fileDialog = new DFileDialog();
        fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        fileDialog->setNameFilter("*.deb");
        if (fileDialog->exec() == QDialog::Accepted) {
            clearButton->show();
            QStringList strSelectedName = fileDialog->selectedFiles();
            QString str;
            for (int i = 0; i < strSelectedName.size(); i++) {
                str.append(strSelectedName[i]);
                str.append('\n');
            }
            textEdit->setText(str);
        }
        textEdit->show();
        btn->setEnabled(true);
    });

    connect(btn,&DPushButton::clicked,[=](){
        emit signalProgressConfig(2);
    });

    connect(clearButton,&DCommandLinkButton::clicked,[=](){
       textEdit->clear();
    });

}



