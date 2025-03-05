//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
#define TOUCH_NONE              0
#define TOUCH_ELO               1
#define TOUCH_EGLX              2
#define TOUCH_DFD               3
#define TOUCH_SDL               4

extern void SetTouchCalibration(float xcal, float ycal);
extern void SetTouchCalibrationOffset(int xoff, int yoff);

int GetTouchXOffset(void);
int GetTouchYOffset(void);
float GetTouchXFactor(void);
float GetTouchYFactor(void);
void SetRawX(int x);
void SetRawY(int y);
void SetRawZ(int z);
int GetCalcX(void);
int GetCalcY(void);
