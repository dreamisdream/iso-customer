#include "selectkernel.h"

#include <DLabel>

SelectKernel::SelectKernel(QWidget *parent)
    : QWidget(parent)
    , btn(new DPushButton())
    , layout(new QVBoxLayout(this))
    , kernelChooser(new DFileChooserEdit)
    , initrdChooser(new DFileChooserEdit)
{
    init();
    initConnection();
}

void SelectKernel::init()
{
    DLabel *label = new DLabel("选择Kernel");
    QFont font;
    font.setFamily("Helvetica");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);
    layout->addWidget(label,0,Qt::AlignTop | Qt::AlignLeft);

    DLabel *smallTitleKernel = new DLabel("kernel");

    DLabel *smallTitleInitrd = new DLabel("initrd");

    kernelChooser->setNameFilters(QStringList("所有文件(*)"));

    initrdChooser->setNameFilters(QStringList("initrd(*.lz)"));

    btn->setText(tr("下一步"));
    btn->setEnabled(false);

    layout->addWidget(smallTitleKerne);
    layout->addWidget(kernelChooser);
    layout->addWidget(smallTitleInitrd);
    layout->addWidget(initrdChooser);
    layout->addStretch();
    btn->setFixedWidth(width()/2);
    layout->addWidget(btn,0,Qt::AlignCenter);
}

void SelectKernel::initConnection()
{

    connect(kernelChooser, &DFileChooserEdit::fileChoosed, [ = ](const QString & fileName) {
        if (!fileName.isEmpty() && !initrdChooser->text().isEmpty()) {
            btn->setEnabled(true);
        }
    });
    connect(initrdChooser, &DFileChooserEdit::fileChoosed, [ = ](const QString & fileName) {
        if (!fileName.isEmpty() && !kernelChooser->text().isEmpty()) {
            btn->setEnabled(true);
        }
    });
    connect(btn,&DPushButton::clicked,[=](){
        emit   signalSelectKernel(6);
    });
}
