# Manuel Makefile for mpnguide

INCLUDES =  -I/usr/lib/qt3/include -I/usr/include -I/usr/X11R6/include -I ../../libmpnrobot/libmpnrobot
CCFLAGS = -Wall -O0 -pg -save-temps -g3 
#CCFLAGS = -O2 -fomit-frame-pointer
OTHERFLAGS = -DQT_THREAD_SUPPORT  -D_REENTRANT
LDFLAGS = -L/usr/lib -L/usr/X11R6/lib -L/usr/lib/qt3 -L../../libmpnrobot/libmpnrobot/ -lmpnrobot -lGL -lGLU -lqt-mt -lm -lXext -lX11  -lpthread
CC=gcc
CPP=g++
MOC=moc
RM=rm -f
#CPP_FILES=$(shell find . -name '*.cpp' -and -not -name 'hemite.cpp')
CPP_FILES=main.cpp \
	mpncommand.cpp \
	mpnguide.cpp \
	mpnscript.cpp \
	mpntrackball.cpp \
	mpnview3d.cpp \
	mpnviewdata.cpp
MOC_OBJ_FILES=mpnguide.moc.o \
	mpnview3d.moc.o \
	mpnscript.moc.o \
	mpnviewdata.moc.o
OBJ_FILES=$(CPP_FILES:%.cpp=%.o)

all: mpnguide

mpnguide: $(OBJ_FILES) $(MOC_OBJ_FILES) ../../libmpnrobot/libmpnrobot/libmpnrobot.a
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) -o $@ $(LDFLAGS) $^

%.moc.cpp: %.h %.cpp
	$(MOC) $< -o $@

%.moc.o: %.moc.cpp %.h
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp %.h
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@

../../libmpnrobot/libmpnrobot/libmpnrobot.a:
	cd ../../libmpnrobot/libmpnrobot/;make


doc:
	doxygen Doxyfile

.PHONY: clean
clean:
	$(RM) $(OBJ_FILES) $(MOC_OBJ_FILES) *.moc.cpp *.s *.ii *~ mpnguide
