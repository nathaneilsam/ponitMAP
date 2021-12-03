#-------------------------------------------------
#
# Project created by QtCreator 2021-07-16T22:00:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HDMAP
TEMPLATE = app
QT += opengl
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += link_pkgconfig
PKGCONFIG += openscenegraph
SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h
CONFIG += C++11
#Eigen
INCLUDEPATH += /usr/include/eigen3

#Boost
INCLUDEPATH += /usr/include/boost
LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so


#Vtk
INCLUDEPATH += /usr/local/include/vtk-8.2
LIBS +=/usr/local/lib/libvtk*.so

#PCL Header
#INCLUDEPATH += /usr/local/include/pcl-1.8
INCLUDEPATH += /usr/include/pcl-1.12/
#PCL Lib
#LIBS        += /usr/local/lib/libpcl_*.so \
LIBS        +=/usr/lib/libpcl_*.so

CONFIG +=C++11
LIBS += -L/home/nathaneil/Qt5.9.5/5.9.5/gcc_64/lib
# ld -rpath /home/nathaneil/Qt5.9.5/5.9.5/gcc_64/lib/libQt5X11Extras.so.5

FORMS +=

RESOURCES += \
    resources.qrc
