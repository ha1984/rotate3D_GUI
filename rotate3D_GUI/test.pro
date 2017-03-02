#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T17:39:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h


FORMS    += mainwindow.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/GameTutorials/test
INSTALLS += target

LIBS += -lglut
