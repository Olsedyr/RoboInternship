VERSION=1.0a
DIST_NAME=LIBMPNROBOT.$(VERSION).tar
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------

INCLUDES = -I./
CCFLAGS =  -Wall -pg -save-temps -g#3 -O0
#CCFLAGS = -O2 -fomit-frame-pointer
CPPFLAGS = -Wall -pg -save-temps -g3 -O0
#CPPFLAGS = -Wall -O2  -fomit-frame-pointer 
LDFLAGS = -s -N
CC=gcc
CPP=g++
BINDIR=/sbin
DELETE=rm -f
AR=ar

OBJDIR=./
OBJ=o
LIBEXT=a

C_SRCS   = \
  scene.c \
  cmd.c \
  rs306.c \
  logger.c \
  spline.c \
  dynomads.c \
  genscript.c \
  tmpnrobot.c \

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(OBJDIR)%.$(OBJ)) bopt.o
  

all:  $(OBJDIR)libmpnrobot.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libmpnrobot.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libmpnrobot.$(LIBEXT)
	$(AR) rcs $(OBJDIR)libmpnrobot.$(LIBEXT) $(OBJFILES)

#----------------------------------------------------------------------------
# Dependencies for individual files... we only specify those
# here that are not taken care of via the predefined rules
# in "rules.gnu"
#----------------------------------------------------------------------------
 
$(OBJDIR)logger.$(OBJ):            logger.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(OBJDIR)cmd.$(OBJ):            cmd.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(OBJDIR)rs306.$(OBJ):            rs306.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)scene.$(OBJ):            scene.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)tmpnrobot.$(OBJ):            tmpnrobot.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)dynomads.$(OBJ): dynomads.c tau.c fric.c 
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)spline.$(OBJ):            spline.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)hermite.$(OBJ):            hermite.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)genscript.$(OBJ):            genscript.c
	$(CC) $(CCFLAGS) -xc++ -o $@ -c $(INCLUDES) $<

$(OBJDIR)bopt.$(OBJ):		  bopt.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

runbopt: bopt.o
	$(CC) -lm -lstdc++ $(CCFLAGS) bopt.o -o runbopt

runmain: libmpnrobot.a
	$(CC) -lm -lstdc++ $(CCFLAGS) libmpnrobot.a -o runmain 

#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(OBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
	  *.[ois] \
		$(OBJFILES) \
		$(OBJDIR)libmpnrobot.$(LIBEXT)
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE)
	$(DELETE) $(MAKEFILE).bak
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
