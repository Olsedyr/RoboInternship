VERSION=1.0a
DIST_NAME=robostacker.$(VERSION).tar
export LANG="da_DK.ISO8859-1" 
# -------------------------------------------------
# Append local cc flags here for only this Makefile
# -------------------------------------------------
TOPDIR = ../
INCLUDES = -I./ -I$(TOPDIR)Bx -I$(TOPDIR)hmi -I$(TOPDIR)io -I$(TOPDIR)stm -I$(TOPDIR)libmpnrobot/libmpnrobot
CFLAGS = -Wall -Wstrict-prototypes -O0 -pg -save-temps -g3 -m32
CCFLAGS = -Wall -Wstrict-prototypes -O0 -pg -save-temps -g3 -m32
#CCFLAGS = -O2 -fomit-frame-pointer
LDFLAGS = -L$(TOPDIR)Bx  -L$(TOPDIR)hmi -L$(TOPDIR)io -L$(TOPDIR)stm -L/usr/X11R6/lib -L$(TOPDIR)libmpnrobot/libmpnrobot -lstdc++ -m32

#CC=gcc
CPP=g++
BINDIR=/sbin
DELETE=rm -f
AR=ar
LD=ld

OBJDIR=./
OBJ=o

#SYSTEM=DFD
SYSTEM=SDL
#SYSTEM=X11
USEFFT=NO

C_SRCS   = \
	main.c \
	mc.c \
	loader.c \
	version.c \
	formEditBoxPattern.c \
	formEditBoxPatternCode.c \
	formEditBoxPatternUser.c \
	formTest.c \
	formTestCode.c \
	formTestUser.c \
	formCP.c \
	formCPCode.c \
	formCPUser.c \
	formCW.c \
	formCWCode.c \
	formCWUser.c \
	formCWdata.c \
	formCWdataCode.c \
	formCWdataUser.c \
	form2pCal.c \
	form2pCalCode.c \
	form2pCalUser.c \
	formAxisParm.c \
	formAxisParmCode.c \
	formAxisParmUser.c \
	formEditFrame.c \
	formEditFrameCode.c \
	formEditFrameUser.c \
	formEditPPP.c \
	formEditPPPCode.c \
	formEditPPPUser.c \
	formEditSysParam.c \
	formEditSysParamCode.c \
	formEditSysParamUser.c \
	formEditTcp.c \
	formEditTcpCode.c \
	formEditTcpUser.c \
	formEditCPPattern.c \
	formEditCPPatternCode.c \
	formEditCPPatternUser.c \
	formFixPoints.c \
	formFixPointsCode.c \
	formFixPointsUser.c \
	formHome.c \
	formHomeCode.c \
	formHomeUser.c \
	formJogAxis.c \
	formJogAxisCode.c \
	formJogAxisUser.c \
	formJogIk.c \
	formJogIkCode.c \
	formJogIkUser.c \
	formJogTool.c \
	formJogToolCode.c \
	formJogToolUser.c \
	formJogLift.c \
	formJogLiftCode.c \
	formJogLiftUser.c \
	formLogger.c \
	formLoggerCode.c \
	formLoggerUser.c \
	formNumKeyboard.c \
	formNumKeyboardCode.c \
	formNumKeyboardUser.c \
	formKeyboard.c \
	formKeyboardCode.c \
	formKeyboardUser.c \
	formSetIO.c \
	formSetIOCode.c \
	formSetIOUser.c \
	formDistIO.c \
	formDistIOCode.c \
	formDistIOUser.c \
	formDDI3725Mod.c \
	formDDI3725ModCode.c \
	formDDI3725ModUser.c \
	formEHCMod.c \
	formEHCModCode.c \
	formEHCModUser.c \
	formEPIMod.c \
	formEPIModCode.c \
	formEPIModUser.c \
	formAVIMod.c \
	formAVIModCode.c \
	formAVIModUser.c \
	formAVOMod.c \
	formAVOModCode.c \
	formAVOModUser.c \
	formSysParam.c \
	formSysParamCode.c \
	formSysParamUser.c \
	formSetDebug.c \
	formSetDebugCode.c \
	formSetDebugUser.c \
	formStatus.c \
	formStatusCode.c \
	formStatusUser.c \
	formSTMCtrl.c \
	formSTMCtrlCode.c \
	formSTMCtrlUser.c \
	formSTMList.c \
	formSTMListCode.c \
	formSTMListUser.c \
	formScopeData.c \
	formScopeDataCode.c \
	formScopeDataUser.c \
	formProgram.c \
	formProgramCode.c \
	formProgramUser.c \
	formStdRun.c \
	formStdRunCode.c \
	formStdRunUser.c \
	formDemo.c \
	formDemoCode.c \
	formDemoUser.c \
	formLoadCell.c \
	formLoadCellCode.c \
	formLoadCellUser.c \
	formComSK.c \
	formComSKCode.c \
	formComSKUser.c \
	formMac.c \
	formMacCode.c \
	formMacUser.c \
	formICPcon.c \
	formICPconCode.c \
	formICPconUser.c \
	formCM.c \
	formCMCode.c \
	formCMUser.c \
	form900.c \
	form900Code.c \
	form900User.c \
	formItem.c \
	formItemCode.c \
	formItemUser.c \
  formItemEdit.c \
	formItemEditCode.c \
	formItemEditUser.c \
	formCPPattern.c \
	formCPPatternCode.c \
	formCPPatternUser.c \
	formProgramCtrl.c \
	formProgramCtrlCode.c \
	formProgramCtrlUser.c \
	formLanguage.c \
	formLanguageCode.c \
	formLanguageUser.c \
	manual.c \
	formManual319.c \
	formManual319Code.c \
	formManual319User.c \
	formManual320.c \
	formManual320Code.c \
	formManual320User.c \
	formManual321.c \
	formManual321Code.c \
	formManual321User.c 

# For GNU make
OBJFILES = $(C_SRCS:%.c=$(OBJDIR)%.$(OBJ))

all:  $(OBJDIR)robostacker

ifeq "$(SYSTEM)" "DFD"
LIBS= -ldirectfb
INCLUDES += -I/usr/local/include/directfb 
CCFLAGS += -DDFD
endif

ifeq "$(SYSTEM)" "SDL"
LIBS= -lSDL -lSGE -lSDL_image
CCFLAGS += -DSDL
endif


ifeq "$(SYSTEM)" "X11"
LIBS= -lX11 -lXext -lXv
CCFLAGS += -DX11
endif

ifeq "$(USEFFT)" "YES"
LIBS += -lfftw3
CCFLAGS += -DUSEFFT
endif

#----------------
 
$(OBJDIR)robostacker: $(OBJFILES) $(TOPDIR)libmpnrobot/libmpnrobot/libmpnrobot.a $(TOPDIR)Bx/libbx.a  $(TOPDIR)stm/libstm.a $(TOPDIR)io/libio.a $(TOPDIR)hmi/libhmi.a
	$(DELETE) -f $(OBJDIR)robostacker 
	$(CC) $(LDFLAGS) -o $(OBJDIR)robostacker $(OBJFILES) -lc -lbx \
        -lhmi -lstm -lio -lpthread -lmpnrobot -lm $(LIBS)

$(OBJDIR)%.$(OBJ): %.c
	$(CC) $(CCFLAGS) -o $@ -c $(INCLUDES) $<

#----------------------------------------------------------------------------

#depend: $(C_SRCS)
#	$(MAKEDEPEND) -p'$$(OBJDIR)' -- $(DEPENDFLAGS) -- \
#	$(C_SRCS)

clean:
	$(DELETE) \
		*.$(OBJ) \
		*~ \
		$(OBJDIR)robostacker \
		*.s \
		*.i \
		*.ii
	$(CLEAN)

distclean:	clean
	$(MAKEDEPEND) -f $(MAKEFILE)
	$(DELETE) $(MAKEFILE).bak

#----------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
