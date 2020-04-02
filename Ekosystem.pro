TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        body/body.cpp \
        body/bodyregistry.cpp \
        main.cpp \
        organism/human.cpp \
        organism/virus.cpp \
        simulation/simulation.cpp \
        space/space.cpp \
        space/vicinity.cpp \
        space/vicinityprovider.cpp

HEADERS += \
    body/body.h \
    body/bodyregistry.h \
    organism/human.h \
    organism/organism.h \
    organism/virus.h \
    simulation/entitytype.h \
    simulation/simulation.h \
    space/bodynotinspaceexception.h \
    space/coordinates.h \
    space/direction.h \
    space/space.h \
    space/vicinity.h \
    space/vicinityprovider.h
