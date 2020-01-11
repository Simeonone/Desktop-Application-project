#-------------------------------------------------
#
# Project created by QtCreator 2019-03-07T18:49:50
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Project001
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    mainpage.cpp \
    signup.cpp \
    admin.cpp \
    optionselection.cpp \
    cashflows2.cpp \
    balancesheet.cpp \
    incomestatement.cpp \
    calculator.cpp \
    cashflowsfinals.cpp \
    qcustomplot.cpp \
    incomesec.cpp \
    last.cpp \
    lastoflast.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    mainpage.h \
    signup.h \
    admin.h \
    optionselection.h \
    cashflows2.h \
    balancesheet.h \
    incomestatement.h \
    calculator.h \
    cashflowsfinals.h \
    qcustomplot.h \
    incomesec.h \
    last.h \
    lastoflast.h

FORMS += \
        mainwindow.ui \
    login.ui \
    mainpage.ui \
    signup.ui \
    admin.ui \
    optionselection.ui \
    cashflows2.ui \
    balancesheet.ui \
    incomestatement.ui \
    calculator.ui \
    cashflowsfinals.ui \
    incomesec.ui \
    last.ui \
    lastoflast.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    appresources.qrc
