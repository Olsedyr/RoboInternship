VERSION=1.0a
#DIST_NAME=BOXSYSTEM.$(VERSION).tar
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
INCLUDES = -I./ -I../Bx -I../libmpnrobot/libmpnrobot
#CCFLAGS = -O2 -fomit-frame-pointer 
CCFLAGS = -Wall -pg -save-temps -g
LDFLAGS = -s -N
CC=gcc
CPP=g++
BINDIR=/sbin
DELETE=rm -f
AR=ar
LD=ld

BXOBJDIR=./
OBJDIR=./
OBJ=o
LIBEXT=a

C_SRCS   = \
  elo.c \
	kbd.c

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(BXOBJDIR)%.$(OBJ))
 
all:  $(OBJDIR)libhmi.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libhmi.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libhmi.$(LIBEXT) 
	$(AR) rcs $(OBJDIR)libhmi.$(LIBEXT) $(OBJFILES)
#	$(LD) -shared -E -o $(OBJDIR)libhmi.$(LIBEXT) $(OBJFILES)

 
#----------------------------------------------------------------------------
# Dependencies for individual files... we only specify those
# here that are not taken care of via the predefined rules
# in "rules.gnu"
#----------------------------------------------------------------------------
 
$(BXOBJDIR)elo.$(OBJ):            elo.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)kbd.$(OBJ):     				kbd.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(BXOBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
		$(OBJFILES) \
		$(OBJDIR)libhmi.$(LIBEXT) \
        *.s \
        *.o \
        *.i
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE) 
	$(DELETE) $(MAKEFILE).bak 
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
