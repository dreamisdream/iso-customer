#ifndef SELECTISOFILE_H
#define SELECTISOFILE_H

#include <dfilechooseredit.h>
#include <DPushButton>
#include <DFontSizeManager>

#include <QWidget>

DWIDGET_USE_NAMESPACE

class SelectIsoFile: public QWidget
{
    Q_OBJECT
public:
    SelectIsoFile(QWidget *parent = nullptr);
protected slots:
    void checkBtnStatus();
//    void next();
signals:
    void signalSelectIsoFileBtn(int index);
private:
    void init();
    void initConnection();

private:
    DFileChooserEdit *fileChooserEdit;
    DPushButton *btn;
    QVBoxLayout *layout;
};

#endif // SELECTISOFILE_H
