# Manuel Makefile for bxbuilder 

INCLUDES =  -I/usr/lib/qt-3.3/include -I/usr/X11R6/include -I./ 

CCFLAGS = -Wall -O0 -pg -save-temps -g3 
OTHERFLAGS = -DQT_THREAD_SUPPORT  -D_REENTRANT
LDFLAGS = -L/usr/X11R6/lib -L/usr/lib/qt-3.3/lib -lqui -lGL -lGLU -lqt-mt -lm -lXext -lX11  -lpthread
CC=gcc
CPP=g++
MOC=moc
RM=rm -f


%.moc.cpp: %.h %.cpp
	$(MOC) $< -o $@

%.moc.o: %.moc.cpp %.h
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp %.h
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) $(INCLUDES) -c $< -o $@


bxbuilder: bxbuilder.o bxbuilderdoc.o bxbuilderview.o bxdialoglistview.o generadlg.o main.o generate.o generate.moc.o bxbuilder.moc.o bxbuilderdoc.moc.o bxbuilderview.moc.o bxdialoglistview.moc.o generadlg.moc.o 
	$(CPP) $(CCFLAGS) $(OTHERFLAGS) -o $@ $(LDFLAGS) $^

.PHONY: clean
clean:
	- $(RM) *.o *.moc.cpp *.s *.ii
	- $(RM) *~
	- $(RM) bxbuilder 

