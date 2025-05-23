QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additionofbook.cpp \
    allissuers.cpp \
    book.cpp \
    informationWareHouse.cpp \
    issuebook.cpp \
    main.cpp \
    mainwindow.cpp \
    members.cpp \
    registerdialog.cpp \
    returnbook.cpp

HEADERS += \
    additionofbook.h \
    allissuers.h \
    issuebook.h \
    mainwindow.h \
    book.h \
    informationWareHouse.h \
    inLibrary.h \
    members.h \
    registerdialog.h \
    returnbook.h

FORMS += \
    additionofbook.ui \
    allissuers.ui \
    issuebook.ui \
    mainwindow.ui \
    registerdialog.ui \
    returnbook.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
