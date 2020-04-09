#include "mainwindow.h"
#include "selectisofile.h"

#include <DListView>
#include <DApplicationHelper>
#include <DFrame>
#include <DMainWindow>

#include <QHBoxLayout>
#include <QStackedWidget>
#include <QString>
#include <QMainWindow>
#include <QWidget>
#include <QIcon>



MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
    , m_view(new DListView(this))
    , m_stackWidget(new QStackedWidget())
    , m_pCentralWidget(new QWidget())
    , m_selectIosFile(new SelectIsoFile)
    , m_selectFrame(new SelectFrame)
    , m_programConfig(new ProgressConfig)
    , m_prepare(new Prepare)
    , m_middleInstall(new MiddleInstall)
    , m_tailClear(new TailClear)
    , m_selectKernel(new SelectKernel)
    , m_output(new Output)
    , m_pHBoxLayout(new QHBoxLayout(this))
{
    m_titlebar = this->titlebar();
    m_titlebar->setIcon(QIcon::fromTheme("iso_image6"));

    setWindowIcon(QIcon::fromTheme("iso_image8"));

    init();
    initConnection();

}

void MainWindow::init()
{

    m_ItemModel = new QStandardItemModel(m_view);

    DFrame *leftFrame = new DFrame();
    DFrame *rightFrame = new DFrame();

    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;

    leftFrame->setLayout(leftLayout);
    leftLayout->addWidget(m_view);

    rightFrame->setLayout(rightLayout);
    rightLayout->addWidget(m_stackWidget);

    m_pHBoxLayout->addWidget(leftFrame, 1);
    m_pHBoxLayout->addWidget(rightFrame, 3);

    m_pCentralWidget->setLayout(m_pHBoxLayout);
    setCentralWidget(m_pCentralWidget);

    QStandardItem *pItemSelectIosFile = new QStandardItem(QIcon::fromTheme("NO_active1"),"选择ISO");
    m_stackWidget->addWidget(m_selectIosFile);
    m_has_ItemName_ItemWiget.insert("选择ISO",m_selectIosFile);
    m_ItemModel->appendRow(pItemSelectIosFile);

    QStandardItem *pItemSelectFrame = new QStandardItem(QIcon::fromTheme("NO_active2"),"选择架构");
    pItemSelectFrame->setEnabled(false);
    m_stackWidget->addWidget(m_selectFrame);
    m_has_ItemName_ItemWiget.insert("选择架构",m_selectFrame);
    m_ItemModel->appendRow(pItemSelectFrame);

    QStandardItem *pItemProgressConfig = new QStandardItem(QIcon::fromTheme("NO_active3"),"程序配置");
    pItemProgressConfig->setEnabled(false);
    m_stackWidget->addWidget(m_programConfig);
    m_has_ItemName_ItemWiget.insert("程序配置",m_programConfig);
    m_ItemModel->appendRow(pItemProgressConfig);

    QStandardItem *pItemPrepare = new QStandardItem(QIcon::fromTheme("NO_active4"),"前期准备");
    pItemPrepare->setEnabled(false);
    m_stackWidget->addWidget(m_prepare);
    m_has_ItemName_ItemWiget.insert("前期准备",m_prepare);
    m_ItemModel->appendRow(pItemPrepare);

    QStandardItem *pItemMiddleInstall = new QStandardItem(QIcon::fromTheme("NO_active5"),"中期安装");
    pItemMiddleInstall->setEnabled(false);
    m_stackWidget->addWidget(m_middleInstall);
    m_has_ItemName_ItemWiget.insert("中期安装",m_middleInstall);
    m_ItemModel->appendRow(pItemMiddleInstall);

    QStandardItem *pItemTailClear = new QStandardItem(QIcon::fromTheme("NO_active6"),"后期清理");
    pItemTailClear->setEnabled(false);
    m_stackWidget->addWidget(m_tailClear);
    m_has_ItemName_ItemWiget.insert("后期清理",m_tailClear);
    m_ItemModel->appendRow(pItemTailClear);

    QStandardItem *pItemSelectKernel = new QStandardItem(QIcon::fromTheme("NO_active7"),"选择Kernel");
    pItemSelectKernel->setEnabled(false);
    m_stackWidget->addWidget(m_selectKernel);
    m_has_ItemName_ItemWiget.insert("选择Kernel",m_selectKernel);
    m_ItemModel->appendRow(pItemSelectKernel);

    QStandardItem *pItemOutput = new QStandardItem(QIcon::fromTheme("NO_active8"),"输出");
    pItemOutput->setEnabled(false);
    m_stackWidget->addWidget(m_output);
    m_has_ItemName_ItemWiget.insert("输出",m_output);
    m_ItemModel->appendRow(pItemOutput);

    m_view->setModel(m_ItemModel);

    m_stackWidget->setCurrentWidget(m_selectIosFile);



}

void MainWindow::initConnection()
{

//    connect(m_selectIosFile,&SelectIsoFile::signalSelectIsoFileBtn(,this,[=](){
//         int nowlist=1;
//         QModelIndex indexFromList = m_ItemModel->index(nowlist, 0);
//         m_view->clicked(indexFromList);
//         m_view->setCurrentIndex(indexFromList);
//    });

    connect(m_view, &DListView::clicked, this, &MainWindow::showClicked);

    connect(m_selectIosFile,&SelectIsoFile::signalSelectIsoFileBtn,this,&MainWindow::nextPage);
    connect(m_selectFrame,&SelectFrame::signalSelectFrame,this,&MainWindow::nextPage);
    connect(m_programConfig,&ProgressConfig::signalProgressConfig,this,&MainWindow::nextPage);
    connect(m_prepare,&Prepare::signalPrepare,this,&MainWindow::nextPage);
    connect(m_middleInstall,&MiddleInstall::signalMiddleInstall,this,&MainWindow::nextPage);
    connect(m_tailClear,&TailClear::signalTailClear,this,&MainWindow::nextPage);
    connect(m_selectKernel,&SelectKernel::signalSelectKernel,this,&MainWindow::nextPage);
    connect(m_output,&Output::signalOutput,this,&MainWindow::nextPage);

}

void MainWindow::showClicked(const QModelIndex &index)
{
    QString strName;
    strName = index.data().toString();
    if (m_ItemModel->item(index.row(),0)->isEnabled())
        m_stackWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strName));
}

void MainWindow::nextPage(int num)
{
    QStandardItemModel *itemModel = m_ItemModel;
    itemModel->item(num)->setCheckState(Qt::Checked);
    itemModel->item(num + 1, 0)->setEnabled(true);
    m_view->setCurrentIndex(itemModel->indexFromItem(itemModel->item(num + 1, 0)));
    m_stackWidget->setCurrentIndex(num + 1);

}


