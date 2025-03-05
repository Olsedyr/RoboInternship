VERSION=1.0a
DIST_NAME=TRIOLNX.$(VERSION).tar
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
INCLUDE = -I./ 
CFLAGS	= -Wall -Wstrict-prototypes -O6 -fomit-frame-pointer -m486 
CCFLAGS = -Wall -Wstrict-prototypes -O0 -pg -save-temps -g3
#CCFLAGS = -O3 -fomit-frame-pointer
LDFLAGS = -s -N
CC=gcc
CPP=g++
BINDIR=/sbin
DELETE=rm
AR=ar

OBJDIR=./
OBJ=o
LIBEXT=a

C_SRCS   = \
  tmclnx.c \
  tmcsup.c \
  tmceth.c \
  tmcser.c

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(OBJDIR)%.$(OBJ))
 
all:  $(OBJDIR)libtmclnx.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libtmclnx.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libtmclnx.$(LIBEXT)
	$(AR) rcs $(OBJDIR)libtmclnx.$(LIBEXT) $(OBJFILES)

$(OBJDIR)tmclnx.$(OBJ):            tmclnx.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)tmcsup.$(OBJ):            tmcsup.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)tmceth.$(OBJ):            tmceth.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(OBJDIR)tmcser.$(OBJ):            tmcser.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(OBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
		$(OBJFILES) \
		$(OBJDIR)libtmclnx.$(LIBEXT)
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE)
	$(DELETE) $(MAKEFILE).bak
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
