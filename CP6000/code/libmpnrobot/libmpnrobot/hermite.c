/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <math.h>
#include "hermite.h"
/********************************************************
 *     Hemite curve					*
 *							*
 * x(t) = x1*(2*t^3-3*t^2+1)+x2*(-2*t^3+2*t^2)+		*
 *	dx1*(t^3-2*t^2+t)+dx2*(t^3-t^2)			*
 *							*
 * y(t) = y1*(2*t^3-3*t^2+1)+y2*(-2*t^3+2*t^2)+		*
 *	dy1*(t^3-2*t^2+t)+dy2*(t^3-t^2)			*
 *							*
 * p1 = (x1, y1)					*
 * p2 = (x2, y2)					*
 * tan1 = (dx1, dy1)					*
 * tan2 = (dx2, dy2)					*
 *							*
 ********************************************************/
void CalcHemite(tmpnVector *v, tmpnVector *p1, tmpnVector *p2, tmpnVector *tan1, tmpnVector *tan2, double t)
{
 double t3, t2, A, B, C, D;

  t2 = t * t;
  t3 = t * t2;
  A = 2 * t3 - 3 * t2 + 1;
  B = -2 * t3 + 3 * t2;
  C = t3 - 2 * t2 + t;
  D = t3 - t2;
  v->x = p1->x * A + p2->x * B + tan1->x * C + tan2->x * D;
  v->y = p1->y * A + p2->y * B + tan1->y * C + tan2->y * D;
  v->z = p1->z * A + p2->z * B + tan1->z * C + tan2->z * D;
  v->v = p1->v * A + p2->v * B + tan1->v * C + tan2->v * D;
  v->w = p1->w * A + p2->w * B + tan1->w * C + tan2->w * D;
}

void GenerateHermitePoints(int *maxidx
                          ,int samples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3)
{
  tmpnVector vt1;
  tmpnVector vt2;
  tmpnVector vp1;
  tmpnVector vp2;
//  tmpnFloat pathlength,nos;
  tmpnFloat nos;
  tmpnFloat stepsize,t;
  tmpnFloat vt1length,vt2length;

  nos=(tmpnFloat)samples;
//  pathlength=sqrt((p2->x-p1->x)*(p2->x-p1->x)+(p2->y-p1->y)*(p2->y-p1->y)+(p2->z-p1->z)*(p2->z-p1->z)/*+(p2->v-p1->v)*(p2->v-p1->v)+(p2->w-p1->w)*(p2->w-p1->w)*/);
//  nos=(pathlength+2000.0)/samples;
//  nos=pathlength;
  if(nos<2) nos=2;
  vt1.x=(p2->x-p0->x);
  vt1.y=(p2->y-p0->y);
  vt1.z=(p2->z-p0->z);
  vt1.v=(p2->v-p0->v);
  vt1.w=(p2->w-p0->w);
  vt2.x=(p3->x-p1->x);
  vt2.y=(p3->y-p1->y);
  vt2.z=(p3->z-p1->z);
  vt2.v=(p3->v-p1->v);
  vt2.w=(p3->w-p1->w);
  vt1length=sqrt(vt1.x*vt1.x+vt1.y*vt1.y+vt1.z*vt1.z/*+vt1.v*vt1.v+vt1.w*vt1.w*/);
  vt2length=sqrt(vt2.x*vt2.x+vt2.y*vt2.y+vt2.z*vt2.z/*+vt2.v*vt2.v+vt2.w*vt2.w*/);

  if(vt1length==0.0) vt1length=1.0;
  if(vt2length==0.0) vt2length=1.0;

/*  vt1.x=vt1.x*(tmpnFloat)p1->tanxyz*0.01;
  vt1.y=vt1.y*(tmpnFloat)p1->tanxyz*0.01;
  vt1.z=vt1.z*(tmpnFloat)p1->tanxyz*0.01;

  vt1.v=vt1.v*(tmpnFloat)p1->tanv*0.01;
  vt1.w=vt1.w*(tmpnFloat)p1->tanw*0.01;

  vt2.x=vt2.x*(tmpnFloat)p2->tanxyz*0.01;
  vt2.y=vt2.y*(tmpnFloat)p2->tanxyz*0.01;
  vt2.z=vt2.z*(tmpnFloat)p2->tanxyz*0.01;

  vt2.v=vt2.v*(tmpnFloat)p2->tanv*0.01;
  vt2.w=vt2.w*(tmpnFloat)p2->tanw*0.01;

  */
  /*if(vt1length>vt2length)
    vt1length=vt2length;
  else
    vt2length=vt1length;
*/
/*  vt1.x=vt1.x*(tmpnFloat)p1->tanxyz*TANSCALE/vt1length;
  vt1.y=vt1.y*(tmpnFloat)p1->tanxyz*TANSCALE/vt1length;
  vt1.z=vt1.z*(tmpnFloat)p1->tanxyz*TANSCALE/vt1length;

  vt1.v=vt1.v*(tmpnFloat)p1->tanv*TANSCALE/vt1length;
  vt1.w=vt1.w*(tmpnFloat)p1->tanw*TANSCALE/vt1length;

  vt2.x=vt2.x*(tmpnFloat)p2->tanxyz*TANSCALE/vt2length;
  vt2.y=vt2.y*(tmpnFloat)p2->tanxyz*TANSCALE/vt2length;
  vt2.z=vt2.z*(tmpnFloat)p2->tanxyz*TANSCALE/vt2length;

  vt2.v=vt2.v*(tmpnFloat)p2->tanv*TANSCALE/vt2length;
  vt2.w=vt2.w*(tmpnFloat)p2->tanw*TANSCALE/vt2length;          */

  vp1.x = p1->x; vp1.y = p1->y; vp1.z = p1->z; vp1.v = p1->v; vp1.w = p1->w;
  vp2.x = p2->x; vp2.y = p2->y; vp2.z = p2->z; vp2.v = p2->v; vp2.w = p2->w;

  stepsize=1.0/(tmpnFloat)(nos);
  for(t=stepsize*0.5;t<1.0;t+=stepsize)
  {
    if(*maxidx>=MAXPOSITIONS) *maxidx=MAXPOSITIONS-1;
    //TODO test for min/max af (x,y,z)
    CalcHemite(&position[*maxidx].taskSpace, &vp1, &vp2, &vt1, &vt2,t);
    (*maxidx)++;
  }
}

void generateHermitePath(tmpnPathDef *pathdef, tmpnPath *path)
{
  int numofcurves,i;
  tmpnKeyPoint *p0;
  tmpnKeyPoint *p1;
  tmpnKeyPoint *p2;
  tmpnKeyPoint *p3;
  pathdef->samplesBetweenKeyPoints=250;
//*************************************************************
//* solve firstPoint                                          *
//*************************************************************
  p0 = &pathdef->keypoint[0];
  path->position[0].taskSpace.x = p0->x;
  path->position[0].taskSpace.y = p0->y;
  path->position[0].taskSpace.z = p0->z;
  path->position[0].taskSpace.v = p0->v;
  path->position[0].taskSpace.w = p0->w;
  path->maxidx=1;
  numofcurves=(pathdef->maxidx-1);
  if(numofcurves==0) return;
  //first hermitecurve
  {
    p0 = &pathdef->keypoint[0];
    p1 = &pathdef->keypoint[0];
    p2 = &pathdef->keypoint[1];
    p3 = &pathdef->keypoint[1];
    if(pathdef->maxidx>2)
    {
      p3 = &pathdef->keypoint[2];
    }
    GenerateHermitePoints(&path->maxidx,pathdef->samplesBetweenKeypoints,path->position,p0,p1,p2,p3);
  }
  for ( i=2; i < (int)pathdef->maxidx-1; i++)
  {
    p0 = &pathdef->keypoint[i-2];
    p1 = &pathdef->keypoint[i-1];
    p2 = &pathdef->keypoint[i];
    p3 = &pathdef->keypoint[i+1];
    GenerateHermitePoints(&path->maxidx,pathdef->samplesBetweenKeypoints,path->position,p0,p1,p2,p3);
  }
  //last hermitecurve
  if(pathdef->maxidx>2)
  {
    p0 = &pathdef->keypoint[pathdef->maxidx-3];
    p1 = &pathdef->keypoint[pathdef->maxidx-2];
    p2 = &pathdef->keypoint[pathdef->maxidx-1];
    p3 = &pathdef->keypoint[pathdef->maxidx-1];
    GenerateHermitePoints(&path->maxidx,pathdef->samplesBetweenKeypoints,path->position,p0,p1,p2,p3);
  }
  p0 = &pathdef->keypoint[pathdef->maxidx-1];
  path->position[path->maxidx].taskSpace.x = p0->x;
  path->position[path->maxidx].taskSpace.y = p0->y;
  path->position[path->maxidx].taskSpace.z = p0->z;
  path->position[path->maxidx].taskSpace.v = p0->v;
  path->position[path->maxidx].taskSpace.w = p0->w;
  path->maxidx++;
}


