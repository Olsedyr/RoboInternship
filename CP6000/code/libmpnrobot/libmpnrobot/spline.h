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
void generatePath(tmpnRobot *tmpnrobot, tmpnPathDef *pathdef, tmpnPath *path);
int bspline(int n,int k,int p1,tmpnKeyPoint *b, tmpnPosition *p, int multi);
int bsplineu(int n,int k,int p1,tmpnKeyPoint *b, tmpnPosition *p, int multi);
void GenerateSplinePoints(int *maxidx
                          ,int numofsamples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3);
int generateSplinePath(int maxidx
                      ,int numofsamples
                      ,tmpnKeyPoint *keypoint
                      ,tmpnPosition *position);
//http://hyperphysics.phy-astr.gsu.edu/hbase/hframe.html
#ifdef __cplusplus
}
#endif
