QT += core  \
    widgets
CONFIG += c++11


TARGET = SeminarWeek9
TEMPLATE = app

HEADERS += \
    persistenceengine.h \
    plant.h \
    plantscontroller.h \
    plantsgui.h

SOURCES += \
    main.cpp \
    plant.cpp \
    plantscontroller.cpp \
    plantsgui.cpp
