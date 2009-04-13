INCLUDEPATH += ../libbitconvert
LIBS += -L../libbitconvert -lbitconvert -lpcre

# Input
SOURCES += main.cpp bitprocessor.cpp
HEADERS += bitprocessor.h
