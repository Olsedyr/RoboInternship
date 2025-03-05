####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = bxbuilder

## INCLUDES were found outside kdevelop specific part

bxbuilder_SOURCES = bxdialoglistview.cpp generadlg.cpp main.cpp generate.ui bxbuilderview.cpp bxbuilderdoc.cpp bxbuilder.cpp 
SOURCES = bxdialoglistview.cpp generadlg.cpp main.cpp bxbuilderview.cpp bxbuilderdoc.cpp bxbuilder.cpp 
INTERFACES = generate.ui 
TRANSLATIONS = 
KDE_OPTIONS = qtonly
bxbuilder_LDADD   = $(LIB_QPE) -lqui $(LIB_QT) -lX11 $(LIBSOCKET)

SUBDIRS = docs 

EXTRA_DIST = lo32-app-bxbuilder.png lo16-app-bxbuilder.png filenew.xpm filesave.xpm fileopen.xpm bxbuilder.cpp bxbuilderdoc.cpp bxbuilderdoc.h bxbuilder.h bxbuilderview.cpp bxbuilderview.h generate.ui main.cpp generadlg.cpp generadlg.h bxdialoglistview.cpp bxdialoglistview.h 

####### kdevelop will overwrite this part!!! (end)############


# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

bxbuilder_METASOURCES = AUTO

# the library search path. 
bxbuilder_LDFLAGS = $(all_libraries) 

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(bxbuilder_METASOURCES)

