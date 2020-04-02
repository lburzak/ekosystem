TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        body/body.cpp \
        body/bodyregistry.cpp \
        main.cpp \
        space/space.cpp \
        space/vicinity.cpp \
        space/vicinityprovider.cpp

HEADERS += \
    body/body.h \
    body/bodyregistry.h \
    space/coordinates.h \
    space/direction.h \
    space/space.h \
    space/vicinity.h \
    space/vicinityprovider.h
