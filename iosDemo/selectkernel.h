#ifndef SELECTKERNEL_H
#define SELECTKERNEL_H

#include <dfilechooseredit.h>

#include <DPushButton>
#include <DFontSizeManager>


#include <QWidget>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class SelectKernel: public QWidget
{
    Q_OBJECT
public:
    SelectKernel(QWidget *parent =nullptr);
signals:
    void signalSelectKernel(int index);
private:
    void init();
    void initConnection();
private:
    DFileChooserEdit *fileChooserEdit;
    DPushButton *btn;
    QVBoxLayout *layout;
    DFileChooserEdit *kernelChooser;
    DFileChooserEdit *initrdChooser;
};

#endif // SELECTKERNEL_H
