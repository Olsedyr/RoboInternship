#
#	File is generated automatically! Don't edit it!
#
# %IdeVersion:	2007
#
# %IdeAuthor:	Lars M Sandig
#
# %IdeCreationTime:	Sat Aug 10 10:29:39 2002
#
# %IdeComment:	
#
# %IdeDesc:	
#
# %FirstUniqueId:	0x40004f

# %UseWorkingDir:	/home/lms/C-ForgeWork/Bx/
#
PROJECT_DIR = .

IDE_WORKING_DIR = $(PROJECT_DIR)

MAKE = make

IDE_BLIND_INCLUDES = -I- -I./ -Iinclude -I$(PROJECT_DIR) -I$(PROJECT_DIR)/include

DEPEND_INCLUDES = -I- -I./ -Iinclude -I$(PROJECT_DIR) -I$(PROJECT_DIR)/include

ALLDEFINES = $(ALLINCLUDES)

ALLINCLUDES = $(INCLUDES)

IDE_BLIND_LIBS = -L./ -L$(PROJECT_DIR)

MAKEFLAGS = $(MAKEOPTIONS)

MAKEOPTIONS = -j1

CCLINK = $(CC)

LD = $(CC)

LDOPTIONS = $(IDE_BLIND_LDOPTIONS) $(LDFLAGS)

LDFLAGS = -L.

IDE_BLIND_LDOPTIONS = -L./ -L$(PROJECT_DIR)/

IDE_PROJECT_TOOLS = MAKE CCLINK GCC IDE_C_PARSER TAGS G++ IDE_CXX_PARSER

IDE_RCS_TYPE = none

GCC = gcc

CC = gcc

CFLAGS = $(IDE_BLIND_CFLAGS) $(INCLUDES) $(CWARNFLAGS) $(CDEBUGFLAGS) $(COPTIMIZEFLAGS) $(CLANGFLAGS) $(CCODEFLAGS)

INCLUDES = -I/usr/local/qt/include

CWARNFLAGS = 

CDEBUGFLAGS = -g

COPTIMIZEFLAGS = 

CLANGFLAGS = 

CCODEFLAGS = 

IDE_BLIND_CFLAGS = -I./ -Iinclude -I$(PROJECT_DIR)/ -I$(PROJECT_DIR)/include

IDE_C_PARSER = 

IDE_C_PARSER_FLAGS = $(IDE_C_PARSER_OPTIONS)

IDE_C_PARSER_OPTIONS = -I/usr/include -I/usr/local/include -I/usr/lib/gcc-lib/i386-redhat-linux/2.7.2.3/include -D__GNUC__=2 -D__GNUC_MINOR__=7 -Dlinux=1 -D__linux=1 -D__linux__=1 -Dunix=1 -D__unix=1 -D__unix__=1 -Di386=1 -D__i386=1 -D__i386__=1 -D__ELF__=1

TAGS = etags

TAGSFLAGS = $(TAGSOPTIONS)

TAGSOPTIONS = -t tags -t TAGS

G++ = g++

CXX = g++

CXXFLAGS = $(IDE_BLIND_CXXFLAGS) $(INCLUDES) $(CXXWARNFLAGS) $(CXXDEBUGFLAGS) $(CXXOPTIMIZEFLAGS) $(CXXCODEFLAGS) $(CXXLANGFLAGS) $(CXXSPECIFICFLAGS)

CXXWARNFLAGS = 

CXXDEBUGFLAGS = -g

CXXOPTIMIZEFLAGS = 

CXXCODEFLAGS = 

CXXLANGFLAGS = 

CXXSPECIFICFLAGS = 

IDE_BLIND_CXXFLAGS = -I./ -Iinclude -I$(PROJECT_DIR)/ -I$(PROJECT_DIR)/include

IDE_CXX_PARSER = 

IDE_CXX_PARSER_FLAGS = $(IDE_CXX_PARSER_OPTIONS)

IDE_CXX_PARSER_OPTIONS = -I/usr/include/g++ -I/usr/local/include/g++ -D__cplusplus=1 -D__GNUG__=2 -D__EXCEPTIONS=1

# %UniqueId:	0x400002
# %TargetType:	DLL
# %TreeIndex:	0x1
# %IDEFlags:	0x8
# %ComplexTarget
# %SrcDir:	
# %IncDir:	
# %ObjsDir:	
libBx.so ::	Arial_5.o\
	Arial_6.o\
	Arial_7.o\
	Arial_8.o\
	Bx.o\
	BxBitmap.o\
	BxBox.o\
	BxBoxApp.o\
	BxButton.o\
	BxCheckBox.o\
	BxCreate.o\
	BxDC.o\
	BxDialog.o\
	BxEvent.o\
	BxFileDialog.o\
	BxGdi.o\
	BxGfxQtDrv.o\
	BxGfxFBDrv.o\
	BxGfxSVGADrv.o\
	BxGui.o\
	BxIcon.o\
	BxLayout.o\
	BxList.o\
	BxMemoryGfxDrv.o\
	BxMsgBox.o\
	BxPBar.o\
	BxResElement.o\
	BxResMan.o\
	BxResource.o\
	BxScrollBar.o\
	BxStatic.o\
	BxSysBoxList.o\
	BxText.o\
	BxUser.o\
	BxVKeyTab.o\
	Times_10.o\
	arial14.o\
	fftfont.o\
	gdi_grlib.o\
	gdi_line.o\
	sysres.o\
	qt_grlib.o
	rm -f $@
	$(LD) -shared -o $@ $^ $(LDOPTIONS)

# %ObjectFilesLinking
# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400003
Arial_5.o : Arial_5.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400004
Arial_6.o : Arial_6.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400005
Arial_7.o : Arial_7.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400006
Arial_8.o : Arial_8.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400007
Bx.o : Bx.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400008
BxBitmap.o : BxBitmap.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400009
BxBox.o : BxBox.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000a
BxBoxApp.o : BxBoxApp.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000b
BxButton.o : BxButton.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000c
BxCheckBox.o : BxCheckBox.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000d
BxCreate.o : BxCreate.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000e
BxDC.o : BxDC.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40000f
BxDialog.o : BxDialog.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400010
BxEvent.o : BxEvent.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400011
BxFileDialog.o : BxFileDialog.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400012
BxGdi.o : BxGdi.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400013
BxGfxFBDrv.o : BxGfxFBDrv.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400014
BxGfxSVGADrv.o : BxGfxSVGADrv.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400015
BxGui.o : BxGui.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400016
BxIcon.o : BxIcon.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400017
BxLayout.o : BxLayout.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400018
BxList.o : BxList.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400019
BxMemoryGfxDrv.o : BxMemoryGfxDrv.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001a
BxMsgBox.o : BxMsgBox.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001b
BxPBar.o : BxPBar.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001c
BxResElement.o : BxResElement.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001d
BxResMan.o : BxResMan.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001e
BxResource.o : BxResource.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40001f
BxScrollBar.o : BxScrollBar.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400020
BxStatic.o : BxStatic.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400021
BxSysBoxList.o : BxSysBoxList.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400022
BxText.o : BxText.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400023
BxUser.o : BxUser.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400024
BxVKeyTab.o : BxVKeyTab.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400025
Times_10.o : Times_10.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400027
arial14.o : arial14.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400028
fftfont.o : fftfont.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x400029
gdi_grlib.o : gdi_grlib.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40002a
gdi_line.o : gdi_line.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40002b
sysres.o : sysres.c
	$(CC) -c -o $@ $< $(CFLAGS)


# %TargetType:	C++_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40004c
qt_grlib.o : qt_grlib.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)


# %TargetType:	C_OBJ
# %ParentTarget:	0x400002
# %SourceTarget:	0x40004d
BxGfxQtDrv.o : BxGfxQtDrv.c
	$(CC) -c -o $@ $< $(CFLAGS)


# DO NOT DELETE

# %TargetInfo Arial_5.c	SourceOrHeader,	UniqueId=0x400003,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Arial_6.c	SourceOrHeader,	UniqueId=0x400004,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Arial_7.c	SourceOrHeader,	UniqueId=0x400005,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Arial_8.c	SourceOrHeader,	UniqueId=0x400006,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Bx.c	SourceOrHeader,	UniqueId=0x400007,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxBitmap.c	SourceOrHeader,	UniqueId=0x400008,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxBox.c	SourceOrHeader,	UniqueId=0x400009,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxBoxApp.c	SourceOrHeader,	UniqueId=0x40000a,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxButton.c	SourceOrHeader,	UniqueId=0x40000b,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxCheckBox.c	SourceOrHeader,	UniqueId=0x40000c,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxCreate.c	SourceOrHeader,	UniqueId=0x40000d,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxDC.c	SourceOrHeader,	UniqueId=0x40000e,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxDialog.c	SourceOrHeader,	UniqueId=0x40000f,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxEvent.c	SourceOrHeader,	UniqueId=0x400010,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxFileDialog.c	SourceOrHeader,	UniqueId=0x400011,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxGdi.c	SourceOrHeader,	UniqueId=0x400012,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxGfxFBDrv.c	SourceOrHeader,	UniqueId=0x400013,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxGfxSVGADrv.c	SourceOrHeader,	UniqueId=0x400014,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxGui.c	SourceOrHeader,	UniqueId=0x400015,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxIcon.c	SourceOrHeader,	UniqueId=0x400016,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxLayout.c	SourceOrHeader,	UniqueId=0x400017,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxList.c	SourceOrHeader,	UniqueId=0x400018,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxMemoryGfxDrv.c	SourceOrHeader,	UniqueId=0x400019,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxMsgBox.c	SourceOrHeader,	UniqueId=0x40001a,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxPBar.c	SourceOrHeader,	UniqueId=0x40001b,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxResElement.c	SourceOrHeader,	UniqueId=0x40001c,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxResMan.c	SourceOrHeader,	UniqueId=0x40001d,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxResource.c	SourceOrHeader,	UniqueId=0x40001e,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxScrollBar.c	SourceOrHeader,	UniqueId=0x40001f,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxStatic.c	SourceOrHeader,	UniqueId=0x400020,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxSysBoxList.c	SourceOrHeader,	UniqueId=0x400021,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxText.c	SourceOrHeader,	UniqueId=0x400022,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxUser.c	SourceOrHeader,	UniqueId=0x400023,	TargetType=C,	IDEFlags=0x4
# %TargetInfo BxVKeyTab.c	SourceOrHeader,	UniqueId=0x400024,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Times_10.c	SourceOrHeader,	UniqueId=0x400025,	TargetType=C,	IDEFlags=0x4
# %TargetInfo arial14.c	SourceOrHeader,	UniqueId=0x400027,	TargetType=C,	IDEFlags=0x4
# %TargetInfo fftfont.c	SourceOrHeader,	UniqueId=0x400028,	TargetType=C,	IDEFlags=0x4
# %TargetInfo gdi_grlib.c	SourceOrHeader,	UniqueId=0x400029,	TargetType=C,	IDEFlags=0x4
# %TargetInfo gdi_line.c	SourceOrHeader,	UniqueId=0x40002a,	TargetType=C,	IDEFlags=0x4
# %TargetInfo sysres.c	SourceOrHeader,	UniqueId=0x40002b,	TargetType=C,	IDEFlags=0x4
# %TargetInfo qt_grlib.cpp	SourceOrHeader,	UniqueId=0x40004c,	TargetType=C++,	IDEFlags=0xc
# %TargetInfo BxGfxQtDrv.c	SourceOrHeader,	UniqueId=0x40004d,	TargetType=C,	IDEFlags=0x4
# %TargetInfo Bx.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40002c,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxBitmap.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40002d,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxBox.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40002e,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxBoxSx.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40002f,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxDC.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400030,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxDrivers.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400031,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxEvent.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400032,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxFileDialog.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400033,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxFont.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400034,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxGdi.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400035,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxGfxDrv.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400036,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxGlue.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400037,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxIcon.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400038,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxLayout.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400039,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxList.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003a,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxPBar.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003b,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxPrivate.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003c,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxResElement.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003d,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxResMan.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003e,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxResource.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40003f,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxScrollBar.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400040,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxSysBoxList.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400041,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxTypes.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400042,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxUser.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400043,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo BxVKeys.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400044,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo def.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400045,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo font.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400046,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo freetype.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400047,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo gdi_header.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400048,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo inlstring.h	SourceOrHeader,	IncludeFile,	UniqueId=0x400049,	TargetType=INC,	IDEFlags=0x4
# %TargetInfo vgakeyboard.h	SourceOrHeader,	IncludeFile,	UniqueId=0x40004a,	TargetType=INC,	IDEFlags=0x4


# %UniqueId:	0x400001
# %TreeIndex:	0x2
# %IncludesFolder
# %Folder
# "*** Includes ***" : 
#
