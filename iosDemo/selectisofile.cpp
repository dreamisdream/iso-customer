#include "selectisofile.h"
#include <dfilechooseredit.h>

#include <DLabel>


#include <QVBoxLayout>
#include <QString>
#include <QDebug>

DWIDGET_USE_NAMESPACE

SelectIsoFile::SelectIsoFile(QWidget *parent)
    : QWidget (parent)
    , fileChooserEdit(new DFileChooserEdit)
    , btn(new DPushButton)
    , layout(new QVBoxLayout(this))
{
    init();
    initConnection();
}

void SelectIsoFile::init()
{
    DLabel *label = new DLabel("选择ISO");
    QFont font;
    font.setFamily("Helvetica");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);
    layout->addWidget(label,0,Qt::AlignTop | Qt::AlignLeft);

    fileChooserEdit->setNameFilters(QStringList("ISO(*.iso)"));
    layout->addWidget(fileChooserEdit);
    layout->addStretch();

    btn->setText("下一步");
    btn->setFixedWidth(width()/2);
    btn->setEnabled(false);
 //   btn->setStyleSheet("QPushButton{border:none;}");
    layout->addWidget(btn,0,Qt::AlignCenter);
}

void SelectIsoFile::initConnection()
{
    // open iso file
    connect(fileChooserEdit,&DFileChooserEdit::dialogOpened,this,&SelectIsoFile::checkBtnStatus);

    // next page
    connect(btn, &DPushButton::clicked, this,[=](){
        emit signalSelectIsoFileBtn(0);
    });
}

void SelectIsoFile::checkBtnStatus()
{
//    QString str = fileChooserEdit->directoryUrl().toString();
    QString str = fileChooserEdit->text();
    QString suffix =".iso";
    if(!(str.right(4)==".iso"))
        btn->setEnabled(true);
}

