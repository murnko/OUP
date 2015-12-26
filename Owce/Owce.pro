#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T11:39:47
#
#-------------------------------------------------

QT       += core
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Owce
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clean.cpp
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_features2d -lopencv_imgproc


HEADERS  += mainwindow.h \
    clean.h

FORMS    += mainwindow.ui
