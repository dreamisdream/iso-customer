#ifndef PREPARE_H
#define PREPARE_H

#include <DPushButton>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DLineEdit>

#include <QWidget>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class Prepare : public QWidget
{
    Q_OBJECT
public:
    explicit Prepare(QWidget *parent = nullptr);

signals:
    void signalPrepare(int index);
private:
    void init();
    void initConnection();

public slots:
private:
     DPushButton *btn;
     QVBoxLayout *layout;
     DCommandLinkButton  *cmdlnkBtn;
     DCommandLinkButton  *clearBtn;
     DLineEdit *lineEdit;

};

#endif // PREPARE_H
