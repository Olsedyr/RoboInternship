VERSION=1.0a
DIST_NAME=BOXSYSTEM.$(VERSION).tar
 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
INCLUDES = -I./ -I/usr/src/linux-headers-2.6.31-23/include
#CCFLAGS = -O2 -fomit-frame-pointer -fPIC -DLINUX
CCFLAGS = -c -fPIC -DLINUX -Wall -O0 -pg -save-temps -g3 -m32
LDFLAGS = -s -N -m32
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
#LIBEXT=so

#GFXDRV=SVGA
#GFXDRV=FRAMEBUFFER
#GFXDRV=X11
GFXDRV=SDL
#GFXDRV=DFB

DRIVER_SRCS = \
  gdi_grlib.c \
	gdi_line.c

ifeq "$(GFXDRV)" "X11"
DRIVER_SRCS += BxGfxX11Drv.c
CCFLAGS += -g -DX11
endif

ifeq "$(GFXDRV)" "SVGA"
DRIVER_SRCS += BxGfxSVGADrv.c
endif

ifeq "$(GFXDRV)" "FRAMEBUFFER"
DRIVER_SRCS += BxGfxFBDrv.c
CCFLAGS += -DFBDRV
endif

ifeq "$(GFXDRV)" "DFB"
DRIVER_SRCS += BxGfxDFBDrv.c
INCLUDES += -I/usr/local/include/directfb
CCFLAGS += -DDFBDRV
endif

ifeq "$(GFXDRV)" "SDL"
DRIVER_SRCS += BxGfxSDLDrv.c
INCLUDES += -I/usr/include/SDL
CCFLAGS += -DSDLDRV
endif

ifeq "$(GFXDRV)" "MEM"
CCFLAGS += -DMEMDRV
endif

USER_LIB = \
  formFileDialog.c \
  formFileDialogCode.c \
  formFileDialogUser.c \
  formMsgBox.c \
  formMsgBoxCode.c \
  formMsgBoxUser.c

ifneq "$(GFXDRV)" "DFB"
STATIC_FONT = \
  nimbus14.c \
	arial14.c \
	Arial_8.c \
	Arial_7.c \
	Times_10.c \

endif

C_SRCS   = \
	$(DRIVER_SRCS) \
	$(STATIC_FONT) \
	Bx.c \
	BxMemoryGfxDrv.c \
	BxBoxApp.c \
	BxEvent.c \
	BxBox.c \
	BxButton.c \
	BxStatic.c \
	BxCheckBox.c \
	BxText.c \
	BxMenu.c \
	BxDC.c \
	BxCreate.c \
	BxDialog.c \
	BxGui.c \
	BxGdi.c \
	BxBitmap.c \
	BxIcon.c \
	BxUser.c \
	BxResElement.c \
	BxResMan.c \
	BxResource.c \
	BxVKeyTab.c \
	BxSysBoxList.c \
	fftfont.c \
	sysres.c \
	BxPBar.c \
	BxScrollBar.c \
	BxList.c \
	BxLayout.c \
	BxValue.c \
	BxTranslator.c \
	$(USER_LIB) 
#	BxFileDialog.c

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(BXOBJDIR)%.$(OBJ))
 
all:  $(OBJDIR)libbx.$(LIBEXT)
 
#----------------
 
$(OBJDIR)libbx.$(LIBEXT): $(OBJFILES)
	$(DELETE) -f $(OBJDIR)libbx.$(LIBEXT) 
	$(AR) rcs $(OBJDIR)libbx.$(LIBEXT) $(OBJFILES)
#	$(LD) -shared -E -o $(OBJDIR)libbx.$(LIBEXT) $(OBJFILES)

 
#----------------------------------------------------------------------------
# Dependencies for individual files... we only specify those
# here that are not taken care of via the predefined rules
# in "rules.gnu"
#----------------------------------------------------------------------------
 
$(BXOBJDIR)BxGfxDrv.$(OBJ):            BxGfxDrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)BxGfxSVGADrv.$(OBJ):            BxGfxSVGADrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)BxGfxFBDrv.$(OBJ):            BxGfxFBDrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxGfxDFBDrv.$(OBJ):            BxGfxDFBDrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxGfxSDLDrv.$(OBJ):            BxGfxSDLDrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxGfxX11Drv.$(OBJ):            BxGfxX11Drv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxMemoryGfxDrv.$(OBJ):            BxMemoryGfxDrv.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)gdi_line.$(OBJ):            gdi_line.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)gdi_grlib.$(OBJ):            gdi_grlib.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)ftfont.$(OBJ):            ftfont.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<
 
$(BXOBJDIR)Bx.$(OBJ):            Bx.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)arial14.$(OBJ):            arial14.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)nimbus14.$(OBJ):            nimbus14.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)Arial_8.$(OBJ):            Arial_8.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)Arial_7.$(OBJ):            Arial_7.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)Times_10.$(OBJ):            Times_10.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxBoxApp.$(OBJ):            BxBoxApp.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxBox.$(OBJ):            BxBox.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxUser.$(OBJ):            BxUser.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxCreate.$(OBJ):            BxCreate.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxButton.$(OBJ):            BxButton.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxStatic.$(OBJ):            BxStatic.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxCheckBox.$(OBJ):            BxCheckBox.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxText.$(OBJ):            BxText.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxMenu.$(OBJ):            BxMenu.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxDC.$(OBJ):            BxDC.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxDialog.$(OBJ):            BxDialog.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxGui.$(OBJ):            BxGui.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxGdi.$(OBJ):            BxGdi.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxBitmap.$(OBJ):            BxBitmap.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxIcon.$(OBJ):            BxIcon.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxEvent.$(OBJ):            BxEvent.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxResElement.$(OBJ):            BxResElement.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxResMan.$(OBJ):            BxResMan.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxResource.$(OBJ):            BxResource.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxVKeyTab.$(OBJ):            BxVKeyTab.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxSysBoxList.$(OBJ):            BxSysBoxList.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxPBar.$(OBJ):            BxPBar.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxScrollBar.$(OBJ):            BxScrollBar.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxList.$(OBJ):            BxList.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxLayout.$(OBJ):		BxLayout.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxValue.$(OBJ):		BxValue.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxTranslator.$(OBJ):		BxTranslator.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)BxFileDialog.$(OBJ):		BxFileDialog.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)fftfont.$(OBJ):            fftfont.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)sysres.$(OBJ):            sysres.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)splash.$(OBJ):            splash.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)qt_grlib.$(OBJ):            qt_grlib.cpp
	$(CPP) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formMsgBox.$(OBJ):		formMsgBox.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formMsgBoxCode.$(OBJ):		formMsgBoxCode.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formMsgBoxUser.$(OBJ):		formMsgBoxUser.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formFileDialog.$(OBJ):		formFileDialog.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formFileDialogCode.$(OBJ):		formFileDialogCode.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

$(BXOBJDIR)formFileDialogUser.$(OBJ):		formFileDialogUser.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

#----------------------------------------------------------------------------
 
depend: $(C_SRCS)
	$(MAKEDEPEND) -p'$$(BXOBJDIR)' -- $(DEPENDFLAGS) -- \
	$(C_SRCS)
 
clean:
	$(DELETE) \
		$(OBJFILES) \
		$(OBJDIR)libbx.$(LIBEXT) \
        *.s \
        *.o \
        *.i \
		*.ii
	$(CLEAN)
 
distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE) 
	$(DELETE) $(MAKEFILE).bak 
 
#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
 
