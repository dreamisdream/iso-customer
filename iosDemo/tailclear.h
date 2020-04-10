#ifndef TAILCLEAR_H
#define TAILCLEAR_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DTextEdit>

#include <QVBoxLayout>
#include <QWidget>

DWIDGET_USE_NAMESPACE

class TailClear: public QWidget
{
    Q_OBJECT
public:
    TailClear();
private:
    void init();
    void initConnection();
signals:
    void signalTailClear(int index);
private:
    DPushButton *btn;
    QVBoxLayout *layout;
    DCommandLinkButton  *cmdlnkBtn;
    DCommandLinkButton  *clearBtn;
    DTextEdit  *textEdit;
};

#endif // TAILCLEAR_H
