/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <math.h>
#include "spline.h"
void tknot(int n, int k, tmpnFloat *x);
void tbasis(int c,tmpnFloat t,int npts,tmpnFloat *x,tmpnFloat n[]);
/****************************************************************************
*                                                                           *
*   Subroutine to generate a B-spline open uniform knot vector              *
*   with multiplicity equal to the order at the ends.                       *
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
****************************************************************************/
void tknot(int numberofkeypoints, int splineorder, tmpnFloat *knotTable)
{
  int i;
  for (i = 0; i < splineorder; i++)
    knotTable[i] = 0;
  for (i = splineorder; i < numberofkeypoints; i++)
    knotTable[i] = i-splineorder+1;
  for (i = numberofkeypoints; i < numberofkeypoints+splineorder; i++)
    knotTable[i] = numberofkeypoints-splineorder+1;
}
/****************************************************************************
*                                                                           *
*   Subroutine to generate B-spline basis functions for open knot vectors   *
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
*   c      = order of the B-spline basis function                           *
*   d      = first term of the basis function recursion relation            *
*   e      = second term of the basis function recursion relation           *
*   npts   = number of defining polygon vertices                            *
*   n[]    = array containing the basis functions                           *
*            n[1] contains the basis function associated with B1 etc.       *
*   nplusc = constant -- npts + c -- maximum number of knot values          *
*   t      = parameter value                                                *
*   temp[] = temporary array                                                *
*   x[]    = knot vector                                                    *
*                                                                           *
****************************************************************************/
void tbasis(int c,tmpnFloat t,int npts,tmpnFloat *x,tmpnFloat n[])
{
  int nplusc;
  int i,k,tidx=0;
  tmpnFloat d,e,temp[MAXKEYPOINTS+20];
  nplusc = npts + c;
/* calculate the first order basis functions n[i][1]	*/
  for (i = 0; i < nplusc-2; i++)
  {
    if (( t >= x[i]) && (t < x[i+1]))
    {
      temp[i] = 1;
      tidx=i;
    }
    else
      temp[i] = 0;
  }
/* calculate the higher order basis functions */
  for (k = 2; k <= c; k++)
  {
    for (i = 0; i < nplusc-k-1; i++)
    {
      if (temp[i] != 0)
        d = ((t-x[i])*temp[i])/(x[i+k-1]-x[i]);
      else
        d = 0;
      if (temp[i+1] != 0)
        e = ((x[i+k]-t)*temp[i+1])/(x[i+k]-x[i+1]);
      else
        e = 0;
      temp[i] = d + e;
    }
  }
/* put in n array	*/
  for (i = 0; i < k; i++)
  {
    n[i] = temp[tidx-c+1+i];
  }
}
/****************************************************************************
*                                                                           *
*   Subroutine to generate static tables with knot values and basis         *
*   function for a B-spline if the number of keypionts or number of samples *
*   or splineorder changed since last call                                  *
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
****************************************************************************/
void tableInit(int numberofkeypoints, int splineorder, int numberofsamples
              ,tmpnFloat *knotTable, tmpnFloat *basisTable, int force)
{
  static int oldnumberofkeypoints=-1;
  static int oldnumberofsamples=-1;
  static int oldsplineorder=-1;
  int i,icount,k;
  tmpnFloat stepsize,t;
  //call only if splineorder or numofkeypoints have changed
  if(force
   ||splineorder!=oldsplineorder
   ||numberofkeypoints!=oldnumberofkeypoints)
  {
    for(i = 0; i < numberofkeypoints + splineorder+10; i++)  knotTable[i] = 0.0;
    /* generate the open uniform knot values */
    tknot(numberofkeypoints,splineorder,knotTable);
  }
  //call only if splineorder or numberofsamples or numberofkeypoints have changed
  if(force
   ||splineorder!=oldsplineorder
   ||numberofkeypoints!=oldnumberofkeypoints
   ||numberofsamples!=oldnumberofsamples)
  {
    for(i = 0; i < numberofsamples*splineorder+10; i++) basisTable[i] = 0.0;
    t = 0.0;
  	stepsize = ((tmpnFloat)knotTable[numberofkeypoints+splineorder-1])/((tmpnFloat)(numberofsamples-1));
    for (icount = 0; icount< numberofsamples; icount++)
    {
      /* basis function for this value of t */
      tbasis(splineorder,t,numberofkeypoints,knotTable,&basisTable[icount*splineorder]);
      t = t + stepsize;
    }
    //pick up last point
    for(k=0;k<splineorder;k++)
    {
      basisTable[numberofsamples*splineorder-k-1]=0.0;
    }
    basisTable[numberofsamples*splineorder-1]=1.0;
  }
  splineorder=oldsplineorder;
  numberofkeypoints=oldnumberofkeypoints;
  numberofsamples=oldnumberofsamples;
}
/****************************************************************************
*                                                                           *
*   Subroutine to generate a B-spline curve using an uniform open knot vector *
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
****************************************************************************/
#define MAXBASISTABLESIZE 40000
int tbspline(int numberofkeypoints, int splineorder, int numberofsamples, tmpnFloat *b, tmpnFloat *p)
{
static tmpnFloat basisTable[MAXBASISTABLESIZE]; //max is numberofsamples * splineorder
static tmpnFloat knotTable[MAXKEYPOINTS+20];
  int i,icount,tidx,basisIdx;
  tmpnFloat max;
  int nplusc;
  tmpnFloat stepsize,t;
  if(numberofsamples*splineorder>MAXBASISTABLESIZE) return 0;
  nplusc = numberofkeypoints + splineorder;
  tableInit(numberofkeypoints, splineorder, numberofsamples, knotTable, basisTable, TRUE);
  t=0.0;
	stepsize = ((tmpnFloat)knotTable[nplusc-1])/((tmpnFloat)(numberofsamples-1));
  for (icount = 0; icount< numberofsamples; icount++)
  {
    p[icount] = 0.0;
    max=0.0;
    for (i = 0; i < splineorder; i++)
    {
      tidx=i+(int)t;
      basisIdx=icount*splineorder+i;
      if(tidx>numberofkeypoints-1) tidx=numberofkeypoints-1;
      p[icount] += basisTable[basisIdx]*b[tidx];
    }
    t = t + stepsize;
  }
  return numberofsamples;
}
/****************************************************************************
*                                                                           *
*   Same as tbspline                                                        *
*   Subroutine to generate a B-spline curve using an uniform open knot vector *
*   execpt it operates on the hole position (not just a float table)        *
*   and can add start and stop points according to the parameter multi      *
*                                                                           *
*   by Thomas Noerby. thn@mpn.nu                                            *
*   Copyright (C) 2004 MPN A/S - Guided by vision(R)                        *
*   All rights reserved.                                                    *
*                                                                           *
*   np     = number of defining polygon vertices                            *
*   k      = order of the \bsp basis function                               *
*   b      = array containing the defining polygon vertices                 *
*   nbasis = array containing the basis functions for a single value of t   *
*   nplusc = number of knot values                                          *
*   p      = array containing the curve points                              *
*   numofsamples = number of points to be calculated on the curve           *
*   t      = parameter value 0 <= t <= 1                                    *
*   x[]    = array containing the knot vector                               *
*                                                                           *
****************************************************************************/
int bspline(int numberofkeypoints, int splineorder, int numberofsamples
           ,tmpnKeyPoint *b, tmpnPosition *p, int multi)
{
static tmpnFloat basisTable[MAXBASISTABLESIZE]; //max is numberofsamples * splineorder
static tmpnFloat knotTable[MAXKEYPOINTS+20];
  int i,icount,basisIdx;
  tmpnFloat max;
  int nplusc,tidx,ptidx;
  tmpnFloat stepsize,t;


//  printf("before numberofkeypoints=%d splineorder=%d numberofsamples=%d\n"
//        ,numberofkeypoints,splineorder,numberofsamples);

  if(numberofsamples*splineorder>MAXBASISTABLESIZE) return 0;
  nplusc = numberofkeypoints + splineorder;
  tableInit(numberofkeypoints, splineorder, numberofsamples, knotTable, basisTable, TRUE);
  stepsize = ((tmpnFloat)knotTable[nplusc-1])/((tmpnFloat)(numberofsamples-1));
  t = 0.0;
  basisIdx=0;
  for (icount = 0; icount< numberofsamples; icount++)
  {
    p[icount].taskSpace.x = 0.;
    p[icount].taskSpace.y = 0.;
    p[icount].taskSpace.z = 0.;
    p[icount].taskSpace.v = 0.;
    p[icount].taskSpace.w = 0.;
    p[icount].taskSpace.u = 0.;
    p[icount].t = 0.;
    p[icount].keypoint = &b[0];
    p[icount].tcpidx = b[0].tcpidx;
    p[icount].statehint = b[0].statehint;
    p[icount].positionhint = b[0].positionhint;
    max=0.0;
    tidx=(int)t;
    ptidx=tidx+1;
    if(tidx>numberofkeypoints-splineorder) tidx=numberofkeypoints-splineorder;
    for (i = 0; i < splineorder; i++)
    {
      p[icount].taskSpace.x += basisTable[basisIdx]*b[tidx].x;
      p[icount].taskSpace.y += basisTable[basisIdx]*b[tidx].y;
      p[icount].taskSpace.z += basisTable[basisIdx]*b[tidx].z;
      p[icount].taskSpace.v += basisTable[basisIdx]*b[tidx].v;
      p[icount].taskSpace.w += basisTable[basisIdx]*b[tidx].w;
      p[icount].taskSpace.u += basisTable[basisIdx]*b[tidx].u;
      p[icount].t           += basisTable[basisIdx]*b[tidx].t;
      p[icount].positionhint += basisTable[basisIdx]*b[tidx].positionhint;
      if(basisTable[basisIdx]>=max)
      {
        max=basisTable[basisIdx];
        p[icount].keypoint = &b[tidx];
        p[icount].tcpidx = b[tidx].tcpidx;
        p[icount].statehint = b[tidx].statehint;
      }
      basisIdx++;
      tidx++;
    }
    t = t + stepsize;
  }
//  printf("after numberofkeypoints=%d splineorder=%d numberofsamples=%d\n"
//        ,numberofkeypoints,splineorder,numberofsamples);

  return numberofsamples;
}
