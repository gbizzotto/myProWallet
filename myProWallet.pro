QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chooseutxosdialog.cpp \
    feeeditorwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    txoutputwidget.cpp \
    utxospendwidget.cpp \
    utxowidget.cpp

HEADERS += \
    chooseutxosdialog.h \
    feeeditorwidget.h \
    mainwindow.h \
    tx.hpp \
    txoutputwidget.h \
    utxospendwidget.h \
    utxowidget.h

FORMS += \
    chooseutxosdialog.ui \
    feeeditorwidget.ui \
    mainwindow.ui \
    txoutputwidget.ui \
    utxospendwidget.ui \
    utxowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
