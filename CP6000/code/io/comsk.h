//*****************************************************************************
//* Copyright (C) 2006 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#ifndef __COMSK_H
#define __COMSK_H

#ifdef __cplusplus
extern "C" int readmultiple_CTreg(int slave, int X, int Y, short *dest, int destsize, int fd);
extern "C" int writesingle_CTreg(int slave, int X, int Y, int value, int fd);
extern "C" int writemultiple_CTreg(int slave, int adr, short* array, int count, int fd);
extern "C" int openComSK(tmpnComSK *comsk);
extern "C" void closeComSK(tmpnComSK *comsk);
extern "C" void initComskTasks(tmpnWorkCell *workcell);
extern "C" void *comskWonlyTask(void * arg );
#else
extern int readmultiple_CTreg(int slave, int X, int Y, short *dest, int destsize, int fd);
extern int writesingle_CTreg(int slave, int X, int Y, int value, int fd);
extern int writemultiple_CTreg(int slave, int adr, short* array, int count, int fd);
extern int openComSK(tmpnComSK *comsk);
extern void closeComSK(tmpnComSK *comsk);
extern void initComskTasks(tmpnWorkcell *workcell);
extern void *comskWonlyTask(void * arg );
#endif

#endif /* __COMSK_H */
