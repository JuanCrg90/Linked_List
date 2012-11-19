TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCE = ./src
DESTDIR= ./bin
HEADER = ./include


SOURCES += \    
    src/main.c \
    src/linkList.c

HEADERS += \
    $$HEADER/linklist.h

