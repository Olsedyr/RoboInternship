VERSION=1.0a
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
INCLUDES = -I./ -I../libmpnrobot/libmpnrobot -I../io -I../Bx
#CCFLAGS = -O2 -fomit-frame-pointer 
CCFLAGS = -Wall -O0 -pg -save-temps -g3
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
  workcell.c \
  stm.c \
  stmserver.c \
  stmclient.c

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(BXOBJDIR)%.$(OBJ))
 
all:  $(OBJDIR)libstm.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libstm.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libstm.$(LIBEXT) 
	$(AR) rcs $(OBJDIR)libstm.$(LIBEXT) $(OBJFILES)
#	$(LD) -shared -E -o $(OBJDIR)libstm.$(LIBEXT) $(OBJFILES)

 
#----------------------------------------------------------------------------
# Dependencies for individual files... we only specify those
# here that are not taken care of via the predefined rules
# in "rules.gnu"
#----------------------------------------------------------------------------
$(BXOBJDIR)workcell.$(OBJ): workcell.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)stm.$(OBJ):    stm.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)stmserver.$(OBJ):  stmserver.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)stmclient.$(OBJ):  stmclient.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(BXOBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
		$(OBJFILES) \
		$(OBJDIR)libstm.$(LIBEXT) \
        *.s \
        *.o \
        *.i
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE) 
	$(DELETE) $(MAKEFILE).bak 
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
