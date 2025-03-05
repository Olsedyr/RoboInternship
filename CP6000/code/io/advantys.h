//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#ifdef __cplusplus
extern "C" void openAdvantys(tmpnDIO *dio);
extern "C" void readAdvantys(tmpnDIO *dio);
extern "C" void readAdvantys1(tmpnDIO *dio);
extern "C" void readAdvantys2(tmpnDIO *dio);
extern "C" void writeAdvantys(tmpnDIO *dio);
extern "C" void writeAdvantys1(tmpnDIO *dio);
extern "C" void writeAdvantys2(tmpnDIO *dio);
extern "C" void closeAdvantys(tmpnDIO *dio);
extern "C" void clearErrorAdvantys(tmpnDIO *dio);
#else
extern void openAdvantys(tmpnDIO *dio);
extern void readAdvantys(tmpnDIO *dio);
extern void readAdvantys1(tmpnDIO *dio);
extern void readAdvantys2(tmpnDIO *dio);
extern void writeAdvantys(tmpnDIO *dio);
extern void writeAdvantys1(tmpnDIO *dio);
extern void writeAdvantys2(tmpnDIO *dio);
extern void closeAdvantys(tmpnDIO *dio);
extern void clearErrorAdvantys(tmpnDIO *dio);
#endif
