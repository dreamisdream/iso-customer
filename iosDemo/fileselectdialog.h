#ifndef FILESELECTDIALOG_H
#define FILESELECTDIALOG_H

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

#include <QWidget>

DWIDGET_USE_NAMESPACE

class FileSelectDialog : public QWidget
{
    Q_OBJECT
public:
    explicit FileSelectDialog(QWidget *parent = nullptr);

signals:


public slots:
private:
    DPushButton			 *btn;
    QVBoxLayout 	  	 *layout;
    DCommandLinkButton   *cmdlnkBtn;
    DTextEdit 		     *textEdit;
    DCommandLinkButton   *clearBtn;
    QWidget 		     *widgetBox;
    QVBoxLayout 		 *boxLayout;
};

#endif // FILESELECTDIALOG_H
