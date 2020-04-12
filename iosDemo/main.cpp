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
    a.loadTranslator();     //中文
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setOrganizationName(u8"deepin");

    a.setApplicationName(u8"ISO定制工具");
    a.setApplicationVersion("1.0.4");
    a.setProductIcon(QIcon::fromTheme("iso_image6"));
    a.setApplicationDescription("ISO定制工具是统信提供给装机厂商的一款系统镜像定制工具");
    DApplicationSettings saveTheme;

    MainWindow w;
    w.setFixedSize(800,600);
    w.setWindowFlag(Qt::WindowMaximizeButtonHint);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
