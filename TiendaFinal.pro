#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T19:52:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TiendaFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cliente.cpp \
    normal.cpp \
    gold.cpp \
    platinum.cpp \
    juego.cpp \
    crear_cliente.cpp \
    iniciar_sesion.cpp \
    comprar_juego.cpp \
    crear_juego.cpp \
    modificar_juego.cpp

HEADERS  += mainwindow.h \
    cliente.h \
    normal.h \
    gold.h \
    platinum.h \
    juego.h \
    crear_cliente.h \
    iniciar_sesion.h \
    comprar_juego.h \
    crear_juego.h \
    modificar_juego.h

FORMS    += mainwindow.ui \
    crear_cliente.ui \
    iniciar_sesion.ui \
    comprar_juego.ui \
    crear_juego.ui \
    modificar_juego.ui
