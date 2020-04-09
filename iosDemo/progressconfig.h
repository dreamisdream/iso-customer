#ifndef PROGRESSCONFIG_H
#define PROGRESSCONFIG_H

#include <DPushButton>
#include <DLabel>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DLineEdit>
#include <DTextEdit>


#include <QWidget>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class ProgressConfig : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressConfig(QWidget *parent = nullptr);

signals:
    void signalProgressConfig(int index);

private:
    void init();
    void initConnection();
public slots:
//    void slotOpenFile();
//    void slotDisplayUrl();
private:
    DPushButton *btn;
    QVBoxLayout *layout;
    DCommandLinkButton  *cmdlnkbtn;
    DTextEdit *textEdit;
    DCommandLinkButton *clearButton;

    QStringList *debName;

};

#endif // PROGRESSCONFIG_H
