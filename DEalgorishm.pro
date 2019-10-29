TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gene.cpp \
    simplegene.cpp \
    simpleperson.cpp \
    populationforbasicdealgo.cpp \
    person.cpp \
    population.cpp

HEADERS += \
    gene.h \
    simplegene.h \
    person.h \
    simpleperson.h \
    population.h \
    populationforbasicdealgo.h
