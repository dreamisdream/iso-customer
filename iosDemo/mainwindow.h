#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "selectisofile.h"
#include "selectframe.h"
#include "progressconfig.h"
#include "prepare.h"
#include "middleinstall.h"
#include "tailclear.h"
#include "selectkernel.h"
#include "output.h"

#include <DListView>
#include <DMainWindow>
#include <DApplication>
#include <DTitlebar>

#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>
#include <QStackedWidget>

DWIDGET_USE_NAMESPACE

class MainWindow  : public DMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    void init();
    void initConnection();


signals:

public slots:
    void showClicked(const QModelIndex &index);
    void nextPage(int index);

private:
    QList<QString>      m_modules;
    DListView           *m_view;
    QStackedWidget      *m_stackWidget;
//    QHash<QString, QWidget*> m_has_ItemName_ItemWiget;
    QWidget             *m_pCentralWidget;

    SelectIsoFile       *m_selectIosFile;
    SelectFrame         *m_selectFrame;
    ProgressConfig      *m_programConfig;
    Prepare             *m_prepare;
    MiddleInstall       *m_middleInstall;
    TailClear           *m_tailClear;
    SelectKernel        *m_selectKernel;
    Output              *m_output;

    QHBoxLayout         *m_pHBoxLayout;
    DTitlebar           *m_titlebar;
    QStandardItemModel  *m_ItemModel;

};

#endif // MAINWINDOW_H
