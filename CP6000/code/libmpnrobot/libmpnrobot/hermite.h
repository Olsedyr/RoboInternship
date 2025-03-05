/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include "tmpnrobot.h"
#ifdef __cplusplus
extern "C" {
#endif
void CalcHemite(tmpnVector *v, tmpnVector *p1, tmpnVector *p2, tmpnVector *tan1, tmpnVector *tan2, double t);
void GenerateHermitePoints(int *maxidx
                          ,int numofsamples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3);
void generateHermitePath(tmpnPathDef *pathdef, tmpnPath *path);
#ifdef __cplusplus
}
#endif
