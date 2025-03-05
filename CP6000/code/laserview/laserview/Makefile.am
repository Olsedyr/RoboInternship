####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = laserview

## INCLUDES were found outside kdevelop specific part

laserview_SOURCES = servermain.c savedib.c cammain.c webmain.c upldForm.c main.c 
laserview_LDADD   = libwebs.a -lpthread -lraw1394 -ldc1394_control -lm


EXTRA_DIST = main.c upldForm.c webmain.c libwebs.a cammain.c lv.h savedib.c servermain.c 

####### kdevelop will overwrite this part!!! (end)############
# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
laserview_LDFLAGS = $(all_libraries) 
                                                                                
