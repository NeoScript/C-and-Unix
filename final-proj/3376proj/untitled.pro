QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    overlayobject.h

FORMS    += mainwindow.ui

LIBS += `pkg-config opencv --libs`

DISTFILES += \
    haarcascade_eye_tree_eyeglasses.xml \
    haarcascade_frontalface_alt.xml \
    overlays/
