#-------------------------------------------------
#
# Project created by QtCreator 2016-05-31T19:50:02
#
#-------------------------------------------------

QT       += core gui \
            multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UTComputerQt
TEMPLATE = app

#CONFIG += console \

SOURCES += main.cpp\
        mainwindow.cpp \
    licomplexe.cpp \
    lientiere.cpp \
    lirationnelle.cpp \
    lireelle.cpp \
    liexpression.cpp \
    pile.cpp \
    calculatrice.cpp

HEADERS  += mainwindow.h \
    litterale.h \
    fetchThread.h \
    liexception.h \
    linumerique.h \
    lientiere.h \
    lirationnelle.h \
    licomplexe.h \
    liexpression.h \
    lireelle.h \
    pile.h \
    calculatrice.h
    operateur.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
