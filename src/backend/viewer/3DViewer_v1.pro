QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../operations/s21_arithmetic.c \
    ../operations/s21_common.c \
    ../parser/s21_parser.c \
    glwidget.cpp \
    main.cpp \
    mainviewer.cpp

HEADERS += \
    ../operations/s21_arithmetic.h \
    ../operations/s21_common.h \
    ../parser/s21_parser.h \
    glwidget.h \
    mainviewer.h

FORMS += \
    ../../frontend/mainviewer.ui

LIBS += -lglut -lGLU

DESTDIR = ../../build

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target