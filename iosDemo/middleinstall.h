#ifndef MIDDLEINSTALL_H
#define MIDDLEINSTALL_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DTextEdit>

#include <QStringList>
#include <QWidget>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class MiddleInstall : public QWidget
{
    Q_OBJECT
public:
    explicit MiddleInstall(QWidget *parent = nullptr);
signals:
    void signalMiddleInstall(int index);
public slots:
private:
    void init();
    void initConnection();
private:
    DPushButton *btn;
    QVBoxLayout *layout;
    DCommandLinkButton  *cmdlnkBtn;
    DCommandLinkButton *clearBtn;
    DTextEdit *textEdit;
};

#endif // MIDDLEINSTALL_H
