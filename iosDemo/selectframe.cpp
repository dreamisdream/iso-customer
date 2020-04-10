#include "selectframe.h"

#include <DLabel>
#include <DGroupBox>
#include <QIcon>
#include <DIconButton>
#include <DListWidget>



DWIDGET_USE_NAMESPACE

SelectFrame::SelectFrame()
    : btn(new DPushButton)
    , btnOpenDir(new DPushButton)
    , layout(new QVBoxLayout(this))
    , groupBox(new DGroupBox)
{
    init();

    initConnection();

}

void SelectFrame::init()
{
    DLabel *label = new DLabel("选择架构");
    QFont font;
    font.setFamily("Helvetica");
    font.setBold(true);
    label->setFont(font);
    layout->addWidget(label,0,Qt::AlignTop | Qt::AlignLeft);

    QStandardItemModel *itemModel = new QStandardItemModel;

    QStandardItem *arm = new QStandardItem(tr("ARM"));
    QStandardItem *x86 = new QStandardItem(tr("X86"));
    QStandardItem *mips = new QStandardItem(tr("MIPS"));

    listView = new DListView(this);

    itemModel->appendRow(arm);
    itemModel->appendRow(x86);
    itemModel->appendRow(mips);
    listView->setModel(itemModel);

    layout->addWidget(listView);
    layout->addStretch();

    QHBoxLayout * hBoxLayout = new QHBoxLayout;

    btn = new DPushButton("下一步");
    btn->setEnabled(false);
    btn->setFixedWidth(width()/2);
    hBoxLayout->addWidget(btn,Qt::AlignCenter);

    layout->addLayout(hBoxLayout);


    connect(listView, &DListView::clicked, [ = ](const QModelIndex & index) {
        for(int i=0;i<3;i++)
        {
            QModelIndex indexFromList = itemModel->index(i, 0);
            itemModel->item(indexFromList.row(), 0)->setCheckState(Qt::Unchecked);
        }
        itemModel->item(index.row(), 0)->setCheckState(Qt::Checked);
        itemModel->item(index.row(),0)->setSelectable(false);
        btn->setEnabled(true);
    });
}

void SelectFrame::initConnection()
{
    connect(btn,&DPushButton::clicked,[=]{
       emit  signalSelectFrame(1);
    });

}


