#ifndef PROGRESSCONFIG_H
#define PROGRESSCONFIG_H

#include <DPushButton>
#include <DLabel>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DTextEdit>
#include <DBackgroundGroup>
#include <DGroupBox>
#include <DFloatingMessage>
#include <DFloatingWidget>

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
private:
    DPushButton *btn;
    QVBoxLayout *layout;
    DCommandLinkButton  *cmdlnkBtn;
    DTextEdit *textEdit;
    DCommandLinkButton *clearBtn;
    QWidget *widgetBox;
    QVBoxLayout *boxLayout;
};

#endif // PROGRESSCONFIG_H
