#ifndef SELECTFRAME_H
#define SELECTFRAME_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DListView>

#include <QWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>

DWIDGET_USE_NAMESPACE

class SelectFrame: public QWidget
{
    Q_OBJECT
public:
    SelectFrame();
    void init();
    void initConnection();
private:

signals:
    void signalSelectFrame(int index);
private:
    DPushButton *btn;
    DPushButton *btnOpenDir;
    QVBoxLayout *layout;
    DGroupBox   *groupBox;
    DListView   *listView;
    QStandardItemModel *itemModel;
};

#endif // SELECTFRAME_H
