#ifndef OUTPUT_H
#define OUTPUT_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DWaterProgress>
#include <DWaterProgress>

#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>

DWIDGET_USE_NAMESPACE

class Output: public QWidget
{
    Q_OBJECT
public:
    Output();
protected slots:
    void slotWaterProgress();
signals:
    void signalOutput(int index);
private:
    void init();
    void initConnection();
private:
    DPushButton *btn;
    QTimer *timer;
    DWaterProgress *waterProgress;
    QVBoxLayout *layout;
};

#endif // OUTPUT_H
