QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iosDemo
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    selectisofile.cpp \
    progressconfig.cpp \
    prepare.cpp \
    middleinstall.cpp \
    tailclear.cpp \
    selectkernel.cpp \
    output.cpp \
    selectframe.cpp \
    fileselectdialog.cpp

RESOURCES +=    resources.qrc

HEADERS += \
    mainwindow.h \
    selectisofile.h \
    progressconfig.h \
    prepare.h \
    middleinstall.h \
    tailclear.h \
    selectkernel.h \
    output.h \
    selectframe.h \
    fileselectdialog.h

