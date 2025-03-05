VERSION=1.0a
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
INCLUDES = -I./ -I../libmpnrobot/libmpnrobot -I../rs/ -I../stm/
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
  advantys.c \
	trio.c \
	modbus_tcp.c \
	comsk.c \
	loadcell.c \
	mac.c \
	icpcon.c

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(BXOBJDIR)%.$(OBJ))
 
all:  $(OBJDIR)libio.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libio.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libio.$(LIBEXT) 
	$(AR) rcs $(OBJDIR)libio.$(LIBEXT) $(OBJFILES)
#	$(LD) -shared -E -o $(OBJDIR)libio.$(LIBEXT) $(OBJFILES)

 
#----------------------------------------------------------------------------
# Dependencies for individual files... we only specify those
# here that are not taken care of via the predefined rules
# in "rules.gnu"
#----------------------------------------------------------------------------
 
$(BXOBJDIR)advantys.$(OBJ): advantys.c advantys.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)comsk.$(OBJ): comsk.c comsk.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)loadcell.$(OBJ): loadcell.c loadcell.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)mac.$(OBJ): mac.c mac.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)icpcon.$(OBJ): icpcon.c icpcon.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)trio.$(OBJ):	trio.c 
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)modbus_tcp.$(OBJ):	modbus_tcp.c modbus_tcp.h
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(BXOBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
		$(OBJFILES) \
		$(OBJDIR)libio.$(LIBEXT) \
        *.s \
        *.o \
        *.i
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE) 
	$(DELETE) $(MAKEFILE).bak 
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
