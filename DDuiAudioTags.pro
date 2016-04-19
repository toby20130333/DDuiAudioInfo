#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T15:42:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DDuiAudioTagsXX
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibtag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibtag

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
