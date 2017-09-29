TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    autre.c \
    arbres.c \
    liste_chainees.c \
    table_hash.c \
    fichier.c \
    dictionnaire.c \
    interface.c

HEADERS += \
    autre.h \
    arbres.h \
    table_hash.h \
    liste_chainees.h \
    fichier.h \
    dictionnaire.h \
    interface.h

#TEMPLATE=vcapp
