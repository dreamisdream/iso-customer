#include "mainwindow.h"

#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include <DTitlebar>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
//    a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("iso 定制工具");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a dtk template application.");

    DApplicationSettings saveTheme;


    MainWindow w;
    w.setFixedSize(900,600);
    w.setWindowFlag(Qt::WindowMaximizeButtonHint);
    w.show();

//    DMainWindow w;
//    w.setMinimumSize(900, 600);
//    w.show();
//   w.setWindowFlags(Qt::WindowMaximizeButtonHint);

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
