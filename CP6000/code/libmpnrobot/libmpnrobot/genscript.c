/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "genscript.h"
#include "cmd.h"
#include "bopt.h"

int layerHeightMM=0;
tmpnBoptCoeffItem coeff;

void convert(tmpnVector *wp, int fromIdx
            ,tmpnFloat x, tmpnFloat y, tmpnFloat z, tmpnFloat v, tmpnFloat w, tmpnFloat u
            ,int toIdx, tmpnRobot *robot)
{
  wp->x = x+robot->m_frames.frame[fromIdx].x-robot->m_frames.frame[toIdx].x;
  wp->y = y+robot->m_frames.frame[fromIdx].y-robot->m_frames.frame[toIdx].y;
  wp->z = z+robot->m_frames.frame[fromIdx].z-robot->m_frames.frame[toIdx].z;
  wp->v = v+robot->m_frames.frame[fromIdx].v-robot->m_frames.frame[toIdx].v;
  wp->w = w+robot->m_frames.frame[fromIdx].w-robot->m_frames.frame[toIdx].w;
  wp->u = u+robot->m_frames.frame[fromIdx].u-robot->m_frames.frame[toIdx].u;
}


COMMANDSTRUCT *split(COMMANDSTRUCT *ptrcmd, tmpnFloat x0, tmpnFloat y0, tmpnFloat z0, tmpnFloat v0, tmpnFloat w0, tmpnFloat u0
          ,tmpnFloat x1, tmpnFloat y1, tmpnFloat z1, tmpnFloat v1, tmpnFloat w1, tmpnFloat u1
          ,int nos, int *level, const char *framename, const char *tcpname)
{
  int i,l,lnos;
  char s[256];
  tmpnFloat xp,yp,zp,vp,wp,up,t,stepsize;
  t=0.0;
  if(nos<=-1)
  {
    l=(int)sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)+(z1-z0)*(z1-z0)+(v1-v0)*(v1-v0)+(w1-w0)*(w1-w0)+(u1-u0)*(u1-u0));
    lnos=(int)(l/100.501)+1;
    if(lnos<-nos) nos=-nos; else nos=lnos;
    if(nos<1) return NULL;
    stepsize=1.0/(tmpnFloat)(nos+1);
    for(i=0;i<nos;i++)
    {                              
      t+=stepsize;
      xp=x0+(x1-x0)*t;
      yp=y0+(y1-y0)*t;
      zp=z0+(z1-z0)*t;
      vp=v0+(v1-v0)*t;
      wp=w0+(w1-w0)*t;
      up=u0+(u1-u0)*t;
      sprintf(s,"POINT %s %3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,10.0 %s",framename,xp,yp,zp,vp,wp,up,tcpname);
      ptrcmd=addCommandString(ptrcmd,s,level);
    }
  }
  else if(nos>0)
  {
    stepsize=1.0/(tmpnFloat)(nos-1);
    for(i=1;i<nos;i++)
    {
      t+=stepsize;
      xp=x0+(x1-x0)*t;
      yp=y0+(y1-y0)*t;
      zp=z0+(z1-z0)*t;
      vp=v0+(v1-v0)*t;
      wp=w0+(w1-w0)*t;
      up=u0+(u1-u0)*t;
      sprintf(s,"POINT %s %3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,10.0 %s",framename,xp,yp,zp,vp,wp,up,tcpname);
      ptrcmd=addCommandString(ptrcmd,s,level);
    }
  }
  return ptrcmd;
}

COMMANDSTRUCT *convertsplit(COMMANDSTRUCT *ptrcmd, tmpnFloat x0, tmpnFloat y0, tmpnFloat z0, tmpnFloat v0, tmpnFloat w0, tmpnFloat u0
                                  ,const char* fromFrame0, tmpnFloat x1, tmpnFloat y1, tmpnFloat z1, tmpnFloat v1, tmpnFloat w1, tmpnFloat u1
                                  ,const char* fromFrame1, tmpnRobot *robot, int nos, int *level, const char *toFrame, const char *tcpname, int endpoint)
{
  tmpnVector wp0,wp1;
  char s[256];
  
  convert(&wp0,getFrameIdx(fromFrame0,robot),x0,y0,z0,v0,w0,u0,getFrameIdx(toFrame,robot),robot);
  convert(&wp1,getFrameIdx(fromFrame1,robot),x1,y1,z1,v1,w1,u1,getFrameIdx(toFrame,robot),robot);
  ptrcmd=split(ptrcmd,wp0.x,wp0.y,wp0.z,wp0.v,wp0.w,wp0.u
               ,wp1.x,wp1.y,wp1.z,wp1.v,wp1.w,wp1.u
               ,nos,level,toFrame,tcpname);
  if(endpoint)
  {
    sprintf(s,"POINT %s %3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,10.0 %s"
        ,toFrame
        ,wp1.x
        ,wp1.y
        ,wp1.z
        ,wp1.v
        ,wp1.w
        ,wp1.u
        ,tcpname);
    ptrcmd=addCommandString(ptrcmd,s,level);
  }
  return ptrcmd;
}

///***************************************************************
///* A macro that spirals downward. Is used to make one crate    *
///* fit on top of another.                                      *
///* Parameters:                                                 *
///* robot - Pointer to our current robot                        *
///* ptrpath - Pointer to the pathstruct                         *          
///* A - Amplitude about centre                                  *
///* offsx - offset i x-direction                                *
///* offsz - offset i z-direction (along prismatic axis)         *
///* L - Length of spiral (y-component)                          *
///* f - Frequency of oscillation                                *
///* T - Total time                                              *
///* pos - position from where to start spiraling (baseframe)    *
///* nos - number of samples                                     *
///* level - ??                                                  *
///* TCPidx - TCPidx for this trajectory                         *
///* positionhint - positionhint for this part of the trajectory *           
///***************************************************************

void spiralMacro(tmpnRobot *robot,tmpnPathDef *ptrpath,int* curidx, tmpnFloat A, tmpnFloat offsx, tmpnFloat offsz, tmpnFloat L, tmpnFloat f, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx,int positionhint) 
{
  tmpnVector out;
  for (int i=0;i<nos+1;i++) {
    tmpnFloat t=i*T/(1.0*nos); 
    tmpnFloat x=t/T;
    out.x=pos->x+((20/3.0)*(x-1)*(x-1)*x)*A*sin(2*PI*f*t) + offsx*10.65*((1.5*(x)*(x) - 3*x*x*x + 1.5*x*x*x*x)); 
    out.y=pos->y-(3/2.0)*(x-(1/3.0)*x*x*x)*L;
    out.z=pos->z+((-20/3.0)*(x-1)*x*x)*A*sin(2*PI*f*t+PI) + offsz*10.65*((1.5*(x)*(x) - 3*x*x*x + 1.5*x*x*x*x)); 
    out.v=pos->v;
    out.w=pos->w;
    out.u=pos->u;
    ptrpath->keypoint[*curidx].x=out.x;
    ptrpath->keypoint[*curidx].y=out.y;
    ptrpath->keypoint[*curidx].z=out.z;
    ptrpath->keypoint[*curidx].v=out.v;
    ptrpath->keypoint[*curidx].w=out.w;
    ptrpath->keypoint[*curidx].u=out.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0;
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}


///***************************************************************
///* A macro that makes an upward vertical line.                 *
///* Is used to lift one crate free from another                 *
///* Parameters:                                                 *
///* robot - Pointer to our current robot                        *          
///* ptrpath - Pointer to the pathstruct                         *
///* L - Length of line                                          *
///* T - Total time                                              *
///* pos - position from where to start the line (baseframe)     *
///* nos - number of samples                                     *
///* level - ??                                                  *
///* TCPidx - TCPidx for this trajectory                         *
///* positionhint - positionhint for this part of the trajectory *
///***************************************************************

void uplineMacro(tmpnRobot *robot,tmpnPathDef *ptrpath, int* curidx, tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx,int positionhint) 
{
  tmpnVector out;
  for (int i=0;i<nos;i++) {
    tmpnFloat t=i*T/(1.0*nos);
    tmpnFloat x=1-t/T;
    out.x=pos->x;
		out.y=pos->y-(3/2.0)*(x-(1/3.0)*x*x*x)*L;
    out.z=pos->z;
    out.v=pos->v;
    out.w=pos->w;
    out.u=pos->u;
    ptrpath->keypoint[*curidx].x=out.x;
    ptrpath->keypoint[*curidx].y=out.y;
    ptrpath->keypoint[*curidx].z=out.z;
    ptrpath->keypoint[*curidx].v=out.v;
    ptrpath->keypoint[*curidx].w=out.w;
    ptrpath->keypoint[*curidx].u=out.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0;
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }	
}


void fastUplineMacro(tmpnRobot *robot,tmpnPathDef *ptrpath, int* curidx, tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx,int positionhint) 
{
  tmpnVector out;
	tmpnFloat A=2*L/(T*T);
  for (int i=0;i<nos;i++) {
    tmpnFloat t=i*T/(1.0*nos);
    out.x=pos->x;
    out.y=pos->y-L+0.5*A*t*t;
    out.z=pos->z;
    out.v=pos->v;
    out.w=pos->w;
    out.u=pos->u;
    ptrpath->keypoint[*curidx].x=out.x;
    ptrpath->keypoint[*curidx].y=out.y;
    ptrpath->keypoint[*curidx].z=out.z;
    ptrpath->keypoint[*curidx].v=out.v;
    ptrpath->keypoint[*curidx].w=out.w;
    ptrpath->keypoint[*curidx].u=out.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0;
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}

inline tmpnFloat fastuplinespeed(tmpnFloat L, tmpnFloat T) 
{
	return 2*L/T;
}
///***************************************************************
///* A macro that makes a downward vertical line.                *
///* It is used to place a crate on conveyor.                    *
///* Parameters:                                                 *
///* robot - Pointer to our current robot                        *
///* ptrpath - Pointer to the pathstruct                         *          
///* L - Length of line                                          *
///* T - Total time                                              *
///* pos - position from where to start the line (baseframe)     *
///* nos - number of samples                                     *
///* level - ??                                                  *
///* TCPidx - TCPidx for this trajectory                         *
///* positionhint - positionhint for this part of the trajectory *
///***************************************************************

void downlineMacro(tmpnRobot *robot,tmpnPathDef *ptrpath, int* curidx,  tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx, int positionhint) 
{
  tmpnVector out;
  for (int i=0;i<nos+1;i++) {
    tmpnFloat t=i*T/(1.0*nos); 
    tmpnFloat x=t/T;
    out.x=pos->x;
    out.y=pos->y-(3/2.0)*(x-(1/3.0)*x*x*x)*L;
    out.z=pos->z;
    out.v=pos->v;
    out.w=pos->w;
    out.u=pos->u;
    ptrpath->keypoint[*curidx].x=out.x;
    ptrpath->keypoint[*curidx].y=out.y;
    ptrpath->keypoint[*curidx].z=out.z;
    ptrpath->keypoint[*curidx].v=out.v;
    ptrpath->keypoint[*curidx].w=out.w;
    ptrpath->keypoint[*curidx].u=out.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0;
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}



void fastDownlineMacro(tmpnRobot *robot,tmpnPathDef *ptrpath, int* curidx,  tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx, int positionhint) 
{
  tmpnVector out;
	tmpnFloat A=2*L/(T*T);
  for (int i=0;i<nos+1;i++) {
    tmpnFloat t=i*T/(1.0*nos);
		tmpnFloat x=T-t;
    out.x=pos->x;
		out.y=pos->y-L+0.5*A*x*x;
    out.z=pos->z;
    out.v=pos->v;
    out.w=pos->w;
    out.u=pos->u;
    ptrpath->keypoint[*curidx].x=out.x;
    ptrpath->keypoint[*curidx].y=out.y;
    ptrpath->keypoint[*curidx].z=out.z;
    ptrpath->keypoint[*curidx].v=out.v;
    ptrpath->keypoint[*curidx].w=out.w;
    ptrpath->keypoint[*curidx].u=out.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0;
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}

inline tmpnFloat fastdownlinespeed(tmpnFloat L, tmpnFloat T) 
{
	return -2*L/T;
}
///**********************************************************
///* Makes a 5th deg. hermite blend, between two points in  *
///* jointspace. Outputs trajectory in taskspace though     *
///**********************************************************

void blendquintic(tmpnPathDef *ptrpath, int* curidx, tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2, tmpnFloat ttime, int nos, int TCPidx, tmpnRobot *robot, int positionhint, int last)
{
  int i,j;
  tmpnJointsUnion c[6];
  tmpnJointsUnion bl;
  for (j=0;j<5;j++) {
    c[0].array[j]=p1->array[j];
    c[1].array[j]=v1->array[j];
    c[2].array[j]=a1->array[j]*0.5;
    c[3].array[j]=(-20*p1->array[j]+20*p2->array[j]+ttime*(-12*v1->array[j]-8*v2->array[j]-3*ttime*a1->array[j]+ttime*a2->array[j]))/(2*pow(ttime,3));
    c[4].array[j]=(30*p1->array[j]-30*p2->array[j]+ttime*(16*v1->array[j]+14*v2->array[j]+3*ttime*a1->array[j]-2*ttime*a2->array[j]))/(2*pow(ttime,4));
    c[5].array[j]=-(12*p1->array[j]-12*p2->array[j]+ttime*(6*(v1->array[j]+v2->array[j])+ttime*(a1->array[j]-a2->array[j])))/(2*pow(ttime,5));
  }
  for (i=0;i<nos+1;i++) {
    tmpnFloat st=ttime*(i)/(tmpnFloat)(nos);
    if (i==nos) {
      if (!last) break; 
    }
    for (j=0;j<5;j++) {
      bl.array[j]=c[5].array[j]*pow(st,5)+c[4].array[j]*pow(st,4)+c[3].array[j]*pow(st,3)+c[2].array[j]*pow(st,2)+c[1].array[j]*st+c[0].array[j];
    }
    tmpnComputeFKlogic(robot, bl.name.a, bl.name.b, bl.name.c, bl.name.d, bl.name.e, 0.0, TCPidx);  
    ptrpath->keypoint[*curidx].x=robot->m_worldPoint.x;
    ptrpath->keypoint[*curidx].y=robot->m_worldPoint.y;
    ptrpath->keypoint[*curidx].z=robot->m_worldPoint.z;
    ptrpath->keypoint[*curidx].v=robot->m_worldPoint.v;
    ptrpath->keypoint[*curidx].w=robot->m_worldPoint.w;
    ptrpath->keypoint[*curidx].u=robot->m_worldPoint.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0; 
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}

tmpnFloat blendquinticmaxvel(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2, tmpnFloat ttime, tmpnJointsUnion *mv)
{
  int i,j;
  int nos=100;
  tmpnJointsUnion c[5];
  tmpnJointsUnion bl;
  tmpnJointsUnion blmax={{0,0,0,0,0}};
  for (j=0;j<5;j++) {
    c[0].array[j]=v1->array[j];
    c[1].array[j]=a1->array[j];
    c[2].array[j]=3*(-20*p1->array[j]+20*p2->array[j]+ttime*(-12*v1->array[j]-8*v2->array[j]-3*ttime*a1->array[j]+ttime*a2->array[j]))/(2*pow(ttime,3));
    c[3].array[j]=2*(30*p1->array[j]-30*p2->array[j]+ttime*(16*v1->array[j]+14*v2->array[j]+3*ttime*a1->array[j]-2*ttime*a2->array[j]))/(pow(ttime,4));
    c[4].array[j]=-5*(12*p1->array[j]-12*p2->array[j]+ttime*(6*(v1->array[j]+v2->array[j])+ttime*(a1->array[j]-a2->array[j])))/(2*pow(ttime,5));
  }
  for (i=0;i<nos+1;i++) {
    tmpnFloat st=ttime*i/(tmpnFloat)(nos);
    for (j=0;j<5;j++) {
      bl.array[j]=fabs(c[4].array[j]*pow(st,4)+c[3].array[j]*pow(st,3)+c[2].array[j]*pow(st,2)+c[1].array[j]*st+c[0].array[j]);
      if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
    }  
  }
  tmpnFloat scale=0;
  for (j=0;j<5;j++) {
    bl.array[j]=blmax.array[j]/mv->array[j];
    if (bl.array[j]>scale) scale=bl.array[j];
  }  
  return scale;    
}

tmpnFloat blendquinticmaxacc(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2,tmpnFloat ttime,tmpnJointsUnion *ma)
{
  int i,j;
  int nos=60;
  int finenos=60;
  tmpnJointsUnion c[4];
  tmpnJointsUnion bl;
  tmpnJointsUnion blmax={{0,0,0,0,0}};
  //  tmpnJointsUnion oldbl={{0,0,0,0,0}};
  tmpnJointsUnion timemax={{0,0,0,0,0}};
  for (j=0;j<5;j++) {
    c[0].array[j]=a1->array[j];
    c[1].array[j]=3*(-20*p1->array[j]+20*p2->array[j]+ttime*(-12*v1->array[j]-8*v2->array[j]-3*ttime*a1->array[j]+ttime*a2->array[j]))/(pow(ttime,3));
    c[2].array[j]=6*(30*p1->array[j]-30*p2->array[j]+ttime*(16*v1->array[j]+14*v2->array[j]+3*ttime*a1->array[j]-2*ttime*a2->array[j]))/(pow(ttime,4));
    c[3].array[j]=-10*(12*p1->array[j]-12*p2->array[j]+ttime*(6*(v1->array[j]+v2->array[j])+ttime*(a1->array[j]-a2->array[j])))/(pow(ttime,5));
  }
  tmpnFloat tick=ttime/(tmpnFloat)nos;
  for (i=0;i<nos+1;i++) {
    tmpnFloat st=i*tick;
    for (j=0;j<5;j++) {
      bl.array[j]=fabs(c[3].array[j]*st*st*st+c[2].array[j]*st*st+c[1].array[j]*st+c[0].array[j]);
      if (bl.array[j]>blmax.array[j]) {
	blmax.array[j]=bl.array[j];
	timemax.array[j]=st;
      }
    }  
  }
  for (j=0;j<5;j++) {
    //  oldbl.array[j]=blmax.array[j];
    //    printf("timemax[%i] %f\n",j,timemax.array[j]);
    if (((timemax.array[j]-tick)>0.0)&&((timemax.array[j]+tick)<ttime)) {
      for (i=0;i<finenos+1;i++) {
	tmpnFloat st=(timemax.array[j]-tick) + 2*tick*i/((tmpnFloat)finenos);  
	bl.array[j]=fabs(c[3].array[j]*st*st*st+c[2].array[j]*st*st+c[1].array[j]*st+c[0].array[j]);
	if (bl.array[j]>blmax.array[j]) {
	  blmax.array[j]=bl.array[j];
	}
      }  
    }
    /*   if (j==0)
      printf("bl: %f %f\n",MMTOM(oldbl.array[j]), MMTOM(blmax.array[j])); 
    else
    printf("bl: %f %f\n",DEGTORAD(oldbl.array[j]), DEGTORAD(blmax.array[j])); */
  }
  tmpnFloat scale=0;
  for (j=0;j<5;j++) {
    
    bl.array[j]=blmax.array[j]/ma->array[j];
    if (bl.array[j]>scale) scale=bl.array[j];
  }  
  return scale;    
}


///**********************************************************
///* Makes a 3rd deg. blend between two points in           *
///* jointspace. Outputs trajectory in taskspace though     *
///**********************************************************

void blendcubic(tmpnPathDef *ptrpath, int* curidx, tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, int nos, int TCPidx, tmpnRobot *robot,int positionhint, int last)
{
  int i,j;
  tmpnJointsUnion c[4];
  tmpnJointsUnion bl;
  for (j=0;j<5;j++) {
    c[0].array[j]=p1->array[j];
    c[1].array[j]=v1->array[j];
    c[2].array[j]=-1.0*(3*p1->array[j]-3*p2->array[j]+2*v1->array[j]*ttime+v2->array[j]*ttime)/(ttime*ttime);
    c[3].array[j]=-1.0*(-v1->array[j]*ttime-v2->array[j]*ttime-2*p1->array[j]+2*p2->array[j])/(ttime*ttime*ttime);
  }
  for (i=0;i<nos+1;i++) {
    tmpnFloat st=ttime*(i)/(tmpnFloat)(nos);
		tmpnFloat st2,st3;
    if (i==nos) {
      if (!last) break; 
    }
		st2=st*st;
		st3=st2*st;
    for (j=0;j<5;j++) {
      bl.array[j]=c[3].array[j]*st3+c[2].array[j]*st2+c[1].array[j]*st+c[0].array[j];
    }
    tmpnComputeFKlogic(robot, bl.name.a, bl.name.b, bl.name.c, bl.name.d, bl.name.e, 0.0, TCPidx);    
    ptrpath->keypoint[*curidx].x=robot->m_worldPoint.x;
    ptrpath->keypoint[*curidx].y=robot->m_worldPoint.y;
    ptrpath->keypoint[*curidx].z=robot->m_worldPoint.z;
    ptrpath->keypoint[*curidx].v=robot->m_worldPoint.v;
    ptrpath->keypoint[*curidx].w=robot->m_worldPoint.w;
    ptrpath->keypoint[*curidx].u=robot->m_worldPoint.u;
    ptrpath->keypoint[*curidx].tcpidx=TCPidx;
    ptrpath->keypoint[*curidx].positionhint=positionhint;
    ptrpath->keypoint[*curidx].statehint=0; 
    ptrpath->keypoint[*curidx].dt=10;
    (*curidx)++;
  }
}


tmpnFloat blendcubicmaxvel(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, tmpnJointsUnion *mv)
{
  int j;
  tmpnJointsUnion c[4];
  tmpnJointsUnion bl;
  tmpnJointsUnion blmax={{0,0,0,0,0}};
  for (j=0;j<5;j++) {
    //c[0].array[j]=p1->array[j];
    c[1].array[j]=v1->array[j];
    c[2].array[j]=-1.0*(3*p1->array[j]-3*p2->array[j]+2*v1->array[j]*ttime+v2->array[j]*ttime)/(ttime*ttime);
    c[3].array[j]=-1.0*(-v1->array[j]*ttime-v2->array[j]*ttime-2*p1->array[j]+2*p2->array[j])/(ttime*ttime*ttime);
  }
  tmpnFloat st;
  st=0.00000;
  for (j=0;j<5;j++) {
    bl.array[j]=fabs(3*c[3].array[j]*pow(st,2)+2*c[2].array[j]*st+c[1].array[j]);
    if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
  }  
  st=ttime;
  for (j=0;j<5;j++) {
    bl.array[j]=fabs(3*c[3].array[j]*pow(st,2)+2*c[2].array[j]*st+c[1].array[j]);
    if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
  }  
  for (j=0;j<5;j++) {
    //the parabolic extremum
    tmpnFloat st=ttime*(3*p1->array[j]-3*p2->array[j]+2*v1->array[j]*ttime+v2->array[j]*ttime)/(3*(2*p1->array[j]-2*p2->array[j]+v1->array[j]*ttime+v2->array[j]*ttime));
    if ((st>=0.00)&&(st<=ttime)) {
      bl.array[j]=fabs(3*c[3].array[j]*pow(st,2)+2*c[2].array[j]*st+c[1].array[j]);
      if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
    }
  }  
  
  tmpnFloat scale=0;
  for (j=0;j<5;j++) {
    bl.array[j]=blmax.array[j]/mv->array[j];
    if (bl.array[j]>scale) scale=bl.array[j];
    //printf("blendcubicmaxvel %i: %f %f %f %f\n",j,DEGTORAD(blmax.array[j]),DEGTORAD(mv->array[j]),ttime,scale);
  } 
  return scale;    
}

tmpnFloat blendcubicmaxacc(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, tmpnJointsUnion *ma)
{
  int j;
  tmpnJointsUnion c[4];
  tmpnJointsUnion bl;
  tmpnJointsUnion blmax={{0,0,0,0,0}};
  for (j=0;j<5;j++) {
    //c[0].array[j]=p1->array[j];
    //c[1].array[j]=v1->array[j];
    c[2].array[j]=-1.0*(3*p1->array[j]-3*p2->array[j]+2*v1->array[j]*ttime+v2->array[j]*ttime)/(ttime*ttime);
    c[3].array[j]=-1.0*(-v1->array[j]*ttime-v2->array[j]*ttime-2*p1->array[j]+2*p2->array[j])/(ttime*ttime*ttime);
  }

  tmpnFloat st;
  st=0.0000000;
  for (j=0;j<5;j++) {
    bl.array[j]=fabs(6*c[3].array[j]*st+2*c[2].array[j]);
    if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
  }  
  st=ttime;
  for (j=0;j<5;j++) {
    bl.array[j]=fabs(6*c[3].array[j]*st+2*c[2].array[j]);
    if (bl.array[j]>blmax.array[j]) blmax.array[j]=bl.array[j];
  }  

  tmpnFloat scale=0;
  for (j=0;j<5;j++) {
    bl.array[j]=blmax.array[j]/ma->array[j];
    if (bl.array[j]>scale) scale=bl.array[j];
  }  
  //printf("blendcubicmaxacc: %f %f %f %f\n",DEGTORAD(blmax.array[1]),DEGTORAD(ma->array[1]),ttime,scale);
  return scale;    
}


///******************************************************************************
///*                                                                            *
///* Automatically generates optimal path from A to B.                          *
///* No check for collisions!!!                                                 *
///*                                                                            *
///* Parameters:                                                                *
///* robot - Pointer to our current robot                                       *
///* ptrcmd - Pointer to last element in the linked list of cmds                *
///* level - ??                                                                 *
///* pathidnum - identificationnumber for this path.                            *
///* loadgroup - ??                                                             *
///* trajectorytype - which type of trajectory                                  *
///* samplerate - Samples pr. second in this trajectory                         *
///* fromTCPidx,toTCPidx - TCPidx for start'n'end position for this trajectory  *
///* mv,ma - maximum velocity and acceleration (C-space)                        *
///* frompos,fromvel - Start- position and velocity (R^5 -baseframe)            *
///* topos,tovel - End- position and velocity (R^5 -baseframe)                  *
///* via1pos - Position of startviapoint (R^5 -with respect to frompos)         *
///* via1vel - Velocity of startviapoint (R^5)                                  *
///* via2pos - Position of endviapoint (R^5 - with respect to topos)            *
///* via2vel - Velocity of endviapoint (R^5)                                    *
///* startmacro,endmacro - Specifies macro types and parameters                 *
///* blendtype - 0 for cubic blend, 1 for quintic blend                         *
///*                                                                            *
///* -Note that the via velocities are bound to change during                   *
///* the optimization routine                                                   *
///*                                                                            *
///******************************************************************************

tmpnFloat trajopt(tmpnRobot *robot, tmpnPathDef *ptrpath, int pathidnum, int pathtype, int loadgroup, int trajectorytype, tmpnFloat samplerate, int fromTCPidx, int toTCPidx,tmpnJointsUnion* mv, tmpnJointsUnion* ma, tmpnVector* frompos, tmpnVector* fromvel, tmpnVector* topos, tmpnVector* tovel, tmpnDualVector* via1pos, tmpnVector* via1vel, tmpnDualVector* via2pos, tmpnVector* via2vel, macroparamstruct* startmacro, macroparamstruct* endmacro,int blendtype,float lockv) 
{
  tmpnRobot temprobot;
  memcpy(&temprobot,robot,sizeof(temprobot)); //kopier tmpnrobot strukturen
	temprobot.m_snapToGrid=FALSE;
  int curidx=1;
  int* pcuridx=&curidx;
  int positionhint=0;
  int exectime=0,blendintime=0,blendouttime=0;
  tmpnFloat retval=0.0;
  /******************* MACRO stuff *************************************/
  // It is necessary to copy vectors from parameterlist when manipulating them (some may point to the same content)
  
  tmpnVector toposloc,fromposloc;
  memcpy(&toposloc,topos,sizeof(toposloc)); 
  memcpy(&fromposloc,frompos,sizeof(fromposloc)); 
  
  tmpnVector tovelloc,fromvelloc;
  memcpy(&tovelloc,tovel,sizeof(tovelloc)); 
  memcpy(&fromvelloc,fromvel,sizeof(fromvelloc)); 

  int startmacrotime=0;
  if (startmacro->type==UPLINE) {
    startmacrotime=(int)(1000*startmacro->time);
    fromposloc.y+=startmacro->length; //add length of line to from position;
    fromvelloc.x=0;
    fromvelloc.y=uplinespeed(startmacro->length,startmacro->time);
    fromvelloc.z=0;
    fromvelloc.v=0;
    fromvelloc.w=0;
    fromvelloc.u=0;
  }
	else if (startmacro->type==FASTUPLINE) {
    startmacrotime=(int)(1000*startmacro->time);
    fromposloc.y+=startmacro->length; //add length of line to from position;
    fromvelloc.x=0;
    fromvelloc.y=fastuplinespeed(startmacro->length,startmacro->time);
    fromvelloc.z=0;
    fromvelloc.v=0;
    fromvelloc.w=0;
    fromvelloc.u=0;
  }
  int endmacrotime=0;
  if (endmacro->type==SPIRAL) {
    endmacrotime=(int)(1000*endmacro->time);
    toposloc.y+=endmacro->length; //add length of spiral to endposition;
    tovelloc.x=0;
    tovelloc.y=spiralspeed(endmacro->length,endmacro->time);
    tovelloc.z=0;
    tovelloc.v=0;
    tovelloc.w=0;
    tovelloc.u=0;
  }
  else if (endmacro->type==DOWNLINE) {
    endmacrotime=(int)(1000*endmacro->time);
    toposloc.y+=endmacro->length; //add length of line to endposition;
    tovelloc.x=0;
    tovelloc.y=downlinespeed(endmacro->length,endmacro->time);
    tovelloc.z=0;
    tovelloc.v=0;
    tovelloc.w=0;
    tovelloc.u=0;
  }
	else if (endmacro->type==FASTDOWNLINE) {
    endmacrotime=(int)(1000*endmacro->time);
    toposloc.y+=endmacro->length; //add length of line to endposition;
    tovelloc.x=0;
    tovelloc.y=fastdownlinespeed(endmacro->length,endmacro->time);
    tovelloc.z=0;
    tovelloc.v=0;
    tovelloc.w=0;
    tovelloc.u=0;
  }
  //******** Conversion of endpoints to jointspace *************************
  
  tmpnJoints fromjoints,tojoints;
  tmpnJoints fromdeltajoints,todeltajoints;
  tmpnVector fromdelta,todelta;
  tmpnJoints fromveljoint,toveljoint;

  fromdelta.x = fromposloc.x + fromvelloc.x*0.0005; 
  fromdelta.y = fromposloc.y + fromvelloc.y*0.0005;
  fromdelta.z = fromposloc.z + fromvelloc.z*0.0005;
  fromdelta.v = fromposloc.v + fromvelloc.v*0.0005;
  fromdelta.w = fromposloc.w + fromvelloc.w*0.0005;
  fromdelta.u = fromposloc.u + fromvelloc.u*0.0005;

  todelta.x = toposloc.x + tovelloc.x*0.0005;
  todelta.y = toposloc.y + tovelloc.y*0.0005;
  todelta.z = toposloc.z + tovelloc.z*0.0005;
  todelta.v = toposloc.v + tovelloc.v*0.0005;
  todelta.w = toposloc.w + tovelloc.w*0.0005;
  todelta.u = toposloc.u + tovelloc.u*0.0005;
  
  tmpnComputeIK(&temprobot,fromposloc.x,fromposloc.y,fromposloc.z,fromposloc.v,fromposloc.w,fromposloc.u,fromTCPidx);
  fromjoints=temprobot.m_joint;
  tmpnComputeIK(&temprobot,toposloc.x,toposloc.y,toposloc.z,toposloc.v,toposloc.w,toposloc.u,toTCPidx);
  tojoints=temprobot.m_joint;

  tmpnComputeIK(&temprobot,fromdelta.x,fromdelta.y,fromdelta.z,fromdelta.v,fromdelta.w,fromdelta.u,fromTCPidx);
  fromdeltajoints=temprobot.m_joint;
  tmpnComputeIK(&temprobot,todelta.x,todelta.y,todelta.z,todelta.v,todelta.w,todelta.u,toTCPidx);
  todeltajoints=temprobot.m_joint;
  
  fromveljoint.a = 2000.0*(fromdeltajoints.a-fromjoints.a); 
  fromveljoint.b = 2000.0*(fromdeltajoints.b-fromjoints.b); 
  fromveljoint.c = 2000.0*(fromdeltajoints.c-fromjoints.c); 
  fromveljoint.d = 2000.0*(fromdeltajoints.d-fromjoints.d); 
  fromveljoint.e = 2000.0*(fromdeltajoints.e-fromjoints.e); 
  fromveljoint.f = 2000.0*(fromdeltajoints.f-fromjoints.f); 
 
  toveljoint.a = 2000.0*(todeltajoints.a-tojoints.a); 
  toveljoint.b = 2000.0*(todeltajoints.b-tojoints.b); 
  toveljoint.c = 2000.0*(todeltajoints.c-tojoints.c); 
  toveljoint.d = 2000.0*(todeltajoints.d-tojoints.d); 
  toveljoint.e = 2000.0*(todeltajoints.e-tojoints.e); 
  toveljoint.f = 2000.0*(todeltajoints.f-tojoints.f); 
  
  
  //******* Conversion of viapoints to jointspace *************************

  tmpnVector via1postot; //cartesisk mm og grader
  tmpnVector via2postot; //cartesisk mm og grader
	via1postot.x=(via1pos->absx) ? via1pos->x : fromposloc.x+via1pos->x;
  via1postot.y=(via1pos->absy) ? via1pos->y : fromposloc.y+via1pos->y;
  via1postot.z=(via1pos->absz) ? via1pos->z : fromposloc.z+via1pos->z;
  via1postot.v=(via1pos->absv) ? via1pos->v : fromposloc.v+via1pos->v;
  via1postot.w=(via1pos->absw) ? via1pos->w : fromposloc.w+via1pos->w;
  via1postot.u=(via1pos->absu) ? via1pos->u : fromposloc.u+via1pos->u;
  via2postot.x=(via2pos->absx) ? via2pos->x : toposloc.x+via2pos->x;
  via2postot.y=(via2pos->absy) ? via2pos->y : toposloc.y+via2pos->y;
  via2postot.z=(via2pos->absz) ? via2pos->z : toposloc.z+via2pos->z;
  via2postot.v=(via2pos->absv) ? via2pos->v : toposloc.v+via2pos->v;
  via2postot.w=(via2pos->absw) ? via2pos->w : toposloc.w+via2pos->w;
  via2postot.u=(via2pos->absu) ? via2pos->u : toposloc.u+via2pos->u;
  
  tmpnVector via1delta,via2delta;
  tmpnJoints via1posjoint,via1posdeltajoint;
  tmpnJoints via2posjoint,via2posdeltajoint;
  tmpnJoints via1veljoint,via2veljoint;
  via1delta.x = via1postot.x + via1vel->x*0.0005;
  via1delta.y = via1postot.y + via1vel->y*0.0005;
  via1delta.z = via1postot.z + via1vel->z*0.0005;
  via1delta.v = via1postot.v + via1vel->v*0.0005;
  via1delta.w = via1postot.w + via1vel->w*0.0005;
  via1delta.u = via1postot.u + via1vel->u*0.0005;

  via2delta.x = via2postot.x + via2vel->x*0.0005;
  via2delta.y = via2postot.y + via2vel->y*0.0005;
  via2delta.z = via2postot.z + via2vel->z*0.0005;
  via2delta.v = via2postot.v + via2vel->v*0.0005;
  via2delta.w = via2postot.w + via2vel->w*0.0005;
  via2delta.u = via2postot.u + via2vel->u*0.0005;
  tmpnComputeIK(&temprobot,via1postot.x,via1postot.y,via1postot.z,via1postot.v,via1postot.w,via1postot.u,fromTCPidx);
  via1posjoint=temprobot.m_joint;
  tmpnComputeIK(&temprobot,via1delta.x,via1delta.y,via1delta.z,via1delta.v,via1delta.w,via1delta.u,fromTCPidx);
  via1posdeltajoint=temprobot.m_joint;

  tmpnComputeIK(&temprobot,via2postot.x,via2postot.y,via2postot.z,via2postot.v,via2postot.w,via2postot.u,toTCPidx);
  via2posjoint=temprobot.m_joint;
  tmpnComputeIK(&temprobot,via2delta.x,via2delta.y,via2delta.z,via2delta.v,via2delta.w,via2delta.u,toTCPidx);
  via2posdeltajoint=temprobot.m_joint;
  
  via1veljoint.a = 2000.0*(via1posdeltajoint.a-via1posjoint.a); 
  via1veljoint.b = 2000.0*(via1posdeltajoint.b-via1posjoint.b); 
  via1veljoint.c = 2000.0*(via1posdeltajoint.c-via1posjoint.c); 
  via1veljoint.d = 2000.0*(via1posdeltajoint.d-via1posjoint.d); 
  via1veljoint.e = 2000.0*(via1posdeltajoint.e-via1posjoint.e); 
  via1veljoint.f = 2000.0*(via1posdeltajoint.f-via1posjoint.f); 

  via2veljoint.a = 2000.0*(via2posdeltajoint.a-via2posjoint.a); 
  via2veljoint.b = 2000.0*(via2posdeltajoint.b-via2posjoint.b); 
  via2veljoint.c = 2000.0*(via2posdeltajoint.c-via2posjoint.c); 
  via2veljoint.d = 2000.0*(via2posdeltajoint.d-via2posjoint.d); 
  via2veljoint.e = 2000.0*(via2posdeltajoint.e-via2posjoint.e); 
  via2veljoint.f = 2000.0*(via2posdeltajoint.f-via2posjoint.f); 
  
  //  fprintf(stderr,"via2veljoint: %f %f %f %f %f\n",via2veljoint.a,via2veljoint.b,via2veljoint.c,via2veljoint.d,via2veljoint.e);

  //********************************************************************
  //* Descisions based on trajectory type                              *
  //********************************************************************

  tmpnJointsDUnion startpos= {{0.0,0.0,0.0,0.0,0.0}};       
  tmpnJointsDUnion startvel = {{0.0,0.0,0.0,0.0,0.0}};   
  tmpnJointsDUnion slutpos = {{0.0,0.0,0.0,0.0,0.0}};     
  tmpnJointsDUnion slutvel = {{0.0,0.0,0.0,0.0,0.0}};  

  tmpnJointsDUnion startposrad,startvelrad,slutposrad,slutvelrad;    

  switch(trajectorytype) {
  case NOVIA: 
    startpos.name.a = (tmpnDouble)fromjoints.a;
    startpos.name.b = (tmpnDouble)fromjoints.b;
    startpos.name.c = (tmpnDouble)fromjoints.c;
    startpos.name.d = (tmpnDouble)fromjoints.d;
    startpos.name.e = (tmpnDouble)fromjoints.e;
    
    slutpos.name.a = (tmpnDouble)tojoints.a;
    slutpos.name.b = (tmpnDouble)tojoints.b;
    slutpos.name.c = (tmpnDouble)tojoints.c;
    slutpos.name.d = (tmpnDouble)tojoints.d;
    slutpos.name.e = (tmpnDouble)tojoints.e;
    break;
  case STARTVIA:
    startpos.name.a = (tmpnDouble)via1posjoint.a;
    startpos.name.b = (tmpnDouble)via1posjoint.b;
    startpos.name.c = (tmpnDouble)via1posjoint.c;
    startpos.name.d = (tmpnDouble)via1posjoint.d;
    startpos.name.e = (tmpnDouble)via1posjoint.e;
    
    startvel.name.a = (tmpnDouble)via1veljoint.a;
    startvel.name.b = (tmpnDouble)via1veljoint.b;
    startvel.name.c = (tmpnDouble)via1veljoint.c;
    startvel.name.d = (tmpnDouble)via1veljoint.d;
    startvel.name.e = (tmpnDouble)via1veljoint.e;
    
    slutpos.name.a = (tmpnDouble)tojoints.a;
    slutpos.name.b = (tmpnDouble)tojoints.b;
    slutpos.name.c = (tmpnDouble)tojoints.c;
    slutpos.name.d = (tmpnDouble)tojoints.d;
    slutpos.name.e = (tmpnDouble)tojoints.e;
    break;
  case ENDVIA:
    startpos.name.a = (tmpnDouble)fromjoints.a;
    startpos.name.b = (tmpnDouble)fromjoints.b;
    startpos.name.c = (tmpnDouble)fromjoints.c;
    startpos.name.d = (tmpnDouble)fromjoints.d;
    startpos.name.e = (tmpnDouble)fromjoints.e;
    
    slutpos.name.a = (tmpnDouble)via2posjoint.a;
    slutpos.name.b = (tmpnDouble)via2posjoint.b;
    slutpos.name.c = (tmpnDouble)via2posjoint.c;
    slutpos.name.d = (tmpnDouble)via2posjoint.d;
    slutpos.name.e = (tmpnDouble)via2posjoint.e;

    slutvel.name.a = (tmpnDouble)via2veljoint.a;
    slutvel.name.b = (tmpnDouble)via2veljoint.b;
    slutvel.name.c = (tmpnDouble)via2veljoint.c;
    slutvel.name.d = (tmpnDouble)via2veljoint.d;
    slutvel.name.e = (tmpnDouble)via2veljoint.e;
    break;
  case BOTHVIA:
    startpos.name.a = (tmpnDouble)via1posjoint.a;
    startpos.name.b = (tmpnDouble)via1posjoint.b;
    startpos.name.c = (tmpnDouble)via1posjoint.c;
    startpos.name.d = (tmpnDouble)via1posjoint.d;
    startpos.name.e = (tmpnDouble)via1posjoint.e;
    
    startvel.name.a = (tmpnDouble)via1veljoint.a;
    startvel.name.b = (tmpnDouble)via1veljoint.b;
    startvel.name.c = (tmpnDouble)via1veljoint.c;
    startvel.name.d = (tmpnDouble)via1veljoint.d;
    startvel.name.e = (tmpnDouble)via1veljoint.e;
 
    slutpos.name.a = (tmpnDouble)via2posjoint.a;
    slutpos.name.b = (tmpnDouble)via2posjoint.b;
    slutpos.name.c = (tmpnDouble)via2posjoint.c;
    slutpos.name.d = (tmpnDouble)via2posjoint.d;
    slutpos.name.e = (tmpnDouble)via2posjoint.e;

    slutvel.name.a = (tmpnDouble)via2veljoint.a;
    slutvel.name.b = (tmpnDouble)via2veljoint.b;
    slutvel.name.c = (tmpnDouble)via2veljoint.c;
    slutvel.name.d = (tmpnDouble)via2veljoint.d;
    slutvel.name.e = (tmpnDouble)via2veljoint.e;
  }

  // Typical max vals
  // tmpnJointsDUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //rad/s
  // tmpnJointsDUnion ma = {{MTOMM(4),RADTODEG(2),RADTODEG(5),RADTODEG(7),RADTODEG(7)}};             //rad/s/s 

  tmpnJointsDUnion mvd = {{MMTOM(mv->array[0]),DEGTORAD(mv->array[1]),DEGTORAD(mv->array[2]),DEGTORAD(mv->array[3]),DEGTORAD(mv->array[4])}}; //rad/s
  tmpnJointsDUnion mad = {{MMTOM(ma->array[0]),DEGTORAD(ma->array[1]),DEGTORAD(ma->array[2]),DEGTORAD(ma->array[3]),DEGTORAD(ma->array[4])}}; //rad/s/s 

  startposrad.name.a = MMTOM(startpos.name.a);
  startposrad.name.b = DEGTORAD(startpos.name.b);
  startposrad.name.c = DEGTORAD(startpos.name.c);
  startposrad.name.d = DEGTORAD(startpos.name.d);
  startposrad.name.e = DEGTORAD(startpos.name.e);
  startvelrad.name.a = MMTOM(startvel.name.a);
  startvelrad.name.b = DEGTORAD(startvel.name.b);
  startvelrad.name.c = DEGTORAD(startvel.name.c);
  startvelrad.name.d = DEGTORAD(startvel.name.d);
  startvelrad.name.e = DEGTORAD(startvel.name.e);

  slutposrad.name.a = MMTOM(slutpos.name.a);
  slutposrad.name.b = DEGTORAD(slutpos.name.b);
  slutposrad.name.c = DEGTORAD(slutpos.name.c);
  slutposrad.name.d = DEGTORAD(slutpos.name.d);
  slutposrad.name.e = DEGTORAD(slutpos.name.e);
  slutvelrad.name.a = MMTOM(slutvel.name.a);
  slutvelrad.name.b = DEGTORAD(slutvel.name.b);
  slutvelrad.name.c = DEGTORAD(slutvel.name.c);
  slutvelrad.name.d = DEGTORAD(slutvel.name.d);
  slutvelrad.name.e = DEGTORAD(slutvel.name.e);

  bane b(startposrad,startvelrad,slutposrad,slutvelrad,mvd,mad);
  b.optimer();
  baneConf baneRes;
  tmpnDouble alpha;
  b.getResult(baneRes,alpha);
  //  printf("alpha: %f\n",alpha);
  exectime = (int)(0.5+alpha*4000);
  retval = alpha*4.0;

  tmpnJointsUnion opp,opv,opa; //startpoint of entire path
  tmpnJointsUnion tpp,tpv,tpa; //endpoint of entire path 
  
  switch(trajectorytype) {
  case ENDVIA:
    tpp.name.a=tojoints.a;
    tpp.name.b=tojoints.b;
    tpp.name.c=tojoints.c;
    tpp.name.d=tojoints.d;
    tpp.name.e=tojoints.e;
    tpv.name.a=toveljoint.a;
    tpv.name.b=toveljoint.b;
    tpv.name.c=toveljoint.c;
    tpv.name.d=toveljoint.d;
    tpv.name.e=toveljoint.e;
    tpa.name.a=0; //always constant speed through macro (or endpoint)
    tpa.name.b=0; 
    tpa.name.c=0; 
    tpa.name.d=0; 
    tpa.name.e=0; 
    break;
  case NOVIA: 
    break;
  case BOTHVIA:
    tpp.name.a=tojoints.a;
    tpp.name.b=tojoints.b;
    tpp.name.c=tojoints.c;
    tpp.name.d=tojoints.d;
    tpp.name.e=tojoints.e;
    tpv.name.a=toveljoint.a;
    tpv.name.b=toveljoint.b;
    tpv.name.c=toveljoint.c;
    tpv.name.d=toveljoint.d;
    tpv.name.e=toveljoint.e;
    tpa.name.a=0; //always constant speed through macro (or endpoint)
    tpa.name.b=0; 
    tpa.name.c=0; 
    tpa.name.d=0; 
    tpa.name.e=0; 
    //fall-through
  case STARTVIA: 
    opp.name.a=fromjoints.a;
    opp.name.b=fromjoints.b;
    opp.name.c=fromjoints.c;
    opp.name.d=fromjoints.d;
    opp.name.e=fromjoints.e;
    opv.name.a=fromveljoint.a;
    opv.name.b=fromveljoint.b;
    opv.name.c=fromveljoint.c;
    opv.name.d=fromveljoint.d;
    opv.name.e=fromveljoint.e;
    opa.name.a=0; //always constant speed through macro (or startpoint)
    opa.name.b=0; 
    opa.name.c=0; 
    opa.name.d=0; 
    opa.name.e=0; 
  }

  tmpnFloat acceldivisor=1.05; 
	tmpnFloat accelmultiplicator=1.0/acceldivisor;

  tmpnJointsUnion spp,spv,spa; //startpoint of optimized segment
  spp.name.a = startpos.name.a;
  spp.name.b = startpos.name.b;
  spp.name.c = startpos.name.c;
  spp.name.d = startpos.name.d;
  spp.name.e = startpos.name.e;
  spv.name.a=MTOMM(b.dcubicpoly(0,0.0));
  spv.name.b=RADTODEG(b.dcubicpoly(1,0.0));
  spv.name.c=RADTODEG(b.dcubicpoly(2,0.0));
  spv.name.d=RADTODEG(b.dcubicpoly(3,0.0));
  spv.name.e=RADTODEG(b.dcubicpoly(4,0.0));
  spa.name.a=spv.name.a*0.002+MTOMM(b.ddcubicpoly(0,0.0))*accelmultiplicator;
  spa.name.b=spv.name.b*0.002+RADTODEG(b.ddcubicpoly(1,0.0))*accelmultiplicator;
  spa.name.c=spv.name.c*0.002+RADTODEG(b.ddcubicpoly(2,0.0))*accelmultiplicator;
  spa.name.d=spv.name.d*0.002+RADTODEG(b.ddcubicpoly(3,0.0))*accelmultiplicator;
  spa.name.e=spv.name.e*0.002+RADTODEG(b.ddcubicpoly(4,0.0))*accelmultiplicator;
  tmpnJointsUnion epp,epv,epa; //endpoint of optimized segment  
  epp.name.a = slutpos.name.a;
  epp.name.b = slutpos.name.b;
  epp.name.c = slutpos.name.c;
  epp.name.d = slutpos.name.d;
  epp.name.e = slutpos.name.e;

	tmpnFloat attime=3.999999*alpha;

  epv.name.a=MTOMM(b.dcubicpoly(0,attime));
  epv.name.b=RADTODEG(b.dcubicpoly(1,attime));
  epv.name.c=RADTODEG(b.dcubicpoly(2,attime));
  epv.name.d=RADTODEG(b.dcubicpoly(3,attime));
  epv.name.e=RADTODEG(b.dcubicpoly(4,attime));
  epa.name.a=epv.name.a*0.002+MTOMM(b.ddcubicpoly(0,attime))*accelmultiplicator;
  epa.name.b=epv.name.b*0.002+RADTODEG(b.ddcubicpoly(1,attime))*accelmultiplicator;
  epa.name.c=epv.name.c*0.002+RADTODEG(b.ddcubicpoly(2,attime))*accelmultiplicator;
  epa.name.d=epv.name.d*0.002+RADTODEG(b.ddcubicpoly(3,attime))*accelmultiplicator;
  epa.name.e=epv.name.e*0.002+RADTODEG(b.ddcubicpoly(4,attime))*accelmultiplicator;
 

  if((trajectorytype==STARTVIA)||(trajectorytype==BOTHVIA)) {
    tmpnFloat scalein;
    tmpnFloat p1=0,p3=5;
    tmpnFloat p2=(p3+p1)*0.5;
    scalein=p2;
    tmpnFloat dscale=p3-p1;
    tmpnFloat maxinacc,maxinvel;
    while (dscale>0.0002) 
    {      
      if (blendtype==1) 
      {
				maxinacc=blendquinticmaxacc(&opp, &opv, &opa, &spp, &spv, &spa,scalein,ma);
				maxinvel=blendquinticmaxvel(&opp, &opv, &opa, &spp, &spv, &spa,scalein,mv);
      }
      else
      {
				maxinacc=blendcubicmaxacc(&opp, &opv, &spp, &spv, scalein, ma);
        maxinvel=blendcubicmaxvel(&opp, &opv, &spp, &spv, scalein, mv);
      }
      if (maxinacc<maxinvel)  {
				maxinacc=maxinvel;
      }
      if (maxinacc>1.00) { 
				p1=p2;
      }
      else if (maxinacc<1.00) { 
				p3=p2;
      }
      else break;
      p2=(p3+p1)*0.5;
      scalein=p2;
      dscale=p3-p1;
      //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!hejsain%i %f %f : %f %f %f\n",pathidnum,scalein,maxinacc,p1,p2,p3);
    }
    blendintime=(int)(0.5+1000*scalein);
    retval+=scalein;
  }

  if ((trajectorytype==ENDVIA)||(trajectorytype==BOTHVIA)) {
    tmpnFloat scaleout;
    tmpnFloat p1=0,p3=5; 
    tmpnFloat p2=(p3+p1)*0.5;
    scaleout=p2;
    tmpnFloat maxoutacc,maxoutvel;
    tmpnFloat dscale=p3-p1;
    while (dscale>0.0002) {    
      if (blendtype==1) 
      {
				maxoutacc=blendquinticmaxacc(&epp, &epv, &epa, &tpp, &tpv, &tpa,scaleout,ma);
				maxoutvel=blendquinticmaxvel(&epp, &epv, &epa, &tpp, &tpv, &tpa,scaleout,mv);
      }
      else
      {
				maxoutacc=blendcubicmaxacc(&epp, &epv, &tpp, &tpv, scaleout, ma);
				maxoutvel=blendcubicmaxvel(&epp, &epv, &tpp, &tpv, scaleout, mv);
      }
      if (maxoutacc<maxoutvel)  {
				maxoutacc=maxoutvel;
      }

      if (maxoutacc>1.00) { 
				p1=p2;
      }
      else if (maxoutacc<1.00) { 
				p3=p2;
      }
      else break;
      p2=(p3+p1)*0.5;
      scaleout=p2;
      dscale=p3-p1;
      //      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!hejsaout%i %f %f : %f %f %f\n",pathidnum,scaleout,maxoutacc,p1,p2,p3);
    }
    blendouttime=(int)(0.5+1000*scaleout);
    retval+=scaleout;
  }

  //fprintf(stderr,"blendtimes: %i %i\n",blendintime,blendouttime);

  
  if (startmacro->type!=NOMACRO) {
    exectime+=startmacrotime;
    retval+=startmacrotime*0.001;
  }
  if (endmacro->type!=NOMACRO) {
    exectime+=endmacrotime;
    retval+=endmacrotime*0.001;
  }
  if (trajectorytype==STARTVIA) {
    exectime+=blendintime;
  }
  else if (trajectorytype==ENDVIA) {
    exectime+=blendouttime;
  }
  else if (trajectorytype==BOTHVIA) {
    exectime+=(blendintime+blendouttime);
  }
  int innos = (int)(0.5+blendintime*samplerate*0.001);
  int outnos = (int)(0.5+blendouttime*samplerate*0.001);
  int startmacronos = (int)(0.5+startmacrotime*samplerate*0.001);  
  int endmacronos = (int)(0.5+endmacrotime*samplerate*0.001);
  int optsamples=(int)(0.5+4*alpha*samplerate);  
  int totnos = (innos+outnos+optsamples+startmacronos+endmacronos);
  exectime+=(int)(2.0*exectime/((double)totnos)); //take into account two extra samples
  retval+=2.0*retval/((tmpnFloat)totnos);
  
  //sprintf(s,"PATH bopt-%i id=%d,type=%d,time=%d,loadgroup=%d", trajectorytype, pathidnum, pathtype, exectime, loadgroup);
  //ptrcmd=addCommandString(ptrcmd,s,level);

  if (startmacro->type==UPLINE) {
    if (startmacro->positionhint == 2) {
     	positionhint++;
			ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
			ptrpath->poshint[ptrpath->maxpidx].time=-1;
			ptrpath->poshint[ptrpath->maxpidx].i=0;
			ptrpath->maxpidx++;
    }
    //print makro
    uplineMacro(&temprobot, ptrpath, pcuridx, startmacro->length, startmacro->time, &fromposloc, startmacronos, fromTCPidx,positionhint);
    if (startmacro->positionhint == 1) {
      positionhint++;
      ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
      ptrpath->poshint[ptrpath->maxpidx].time=-1;
      ptrpath->poshint[ptrpath->maxpidx].i=0;
      ptrpath->maxpidx++;
    }
  }
	else if (startmacro->type==FASTUPLINE) {
    if (startmacro->positionhint == 2) {
     	positionhint++;
			ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
			ptrpath->poshint[ptrpath->maxpidx].time=-1;
			ptrpath->poshint[ptrpath->maxpidx].i=0;
			ptrpath->maxpidx++;
    }
    //print macro
    fastUplineMacro(&temprobot, ptrpath, pcuridx, startmacro->length, startmacro->time, &fromposloc, startmacronos, fromTCPidx,positionhint);
    if (startmacro->positionhint == 1) {
      positionhint++;
      ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
      ptrpath->poshint[ptrpath->maxpidx].time=-1;
      ptrpath->poshint[ptrpath->maxpidx].i=0;
      ptrpath->maxpidx++;
    }
  }
  // Print "blend in" segment of PATH
  if ((trajectorytype==STARTVIA)||(trajectorytype==BOTHVIA)) {
    if (blendtype==1)
      blendquintic(ptrpath, pcuridx, &opp, &opv, &opa, &spp, &spv, &spa, (tmpnFloat)(blendintime*0.001), innos, fromTCPidx, &temprobot, positionhint, 0);
    else
      blendcubic(ptrpath, pcuridx, &opp, &opv, &spp, &spv, (tmpnFloat)(blendintime*0.001), innos, fromTCPidx, &temprobot, positionhint, 0);
    //ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 10",level);
  }
  
  tmpnJoints tj;
  // Print optimized segment of PATH

  for (int i=0;i<optsamples+1;i++) 
  { 
    double thistime=i*4.0*alpha/optsamples;
    if (i==optsamples) {
      if ((trajectorytype==ENDVIA)||(trajectorytype==BOTHVIA)) break;
      else thistime=3.9999999*alpha;
    }
    tj.a = MTOMM(b.cubicpoly(0,thistime)); 
    tj.b = RADTODEG(b.cubicpoly(1,thistime));
    tj.c = RADTODEG(b.cubicpoly(2,thistime)); 
    tj.d = RADTODEG(b.cubicpoly(3,thistime));
    tj.e = RADTODEG(b.cubicpoly(4,thistime));
    tj.f = 0.0;
    
    tmpnComputeFKlogic(&temprobot, tj.a, tj.b, tj.c, tj.d, tj.e, tj.f, fromTCPidx);       
    ptrpath->keypoint[curidx].x=temprobot.m_worldPoint.x;
    ptrpath->keypoint[curidx].y=temprobot.m_worldPoint.y;
    ptrpath->keypoint[curidx].z=temprobot.m_worldPoint.z;
    ptrpath->keypoint[curidx].v=temprobot.m_worldPoint.v;
    ptrpath->keypoint[curidx].w=temprobot.m_worldPoint.w;
    ptrpath->keypoint[curidx].u=temprobot.m_worldPoint.u;
    ptrpath->keypoint[curidx].tcpidx=fromTCPidx;
    ptrpath->keypoint[curidx].positionhint=positionhint;
    ptrpath->keypoint[curidx].statehint=0;
    ptrpath->keypoint[curidx].dt=10;
    curidx++;
    //printf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",thistime,tj.a,tj.b,tj.c,tj.d,tj.e,b.dcubicpoly(0,thistime),b.dcubicpoly(1,thistime),b.dcubicpoly(2,thistime),b.dcubicpoly(3,thistime),b.dcubicpoly(4,thistime),b.ddcubicpoly(0,thistime),b.ddcubicpoly(1,thistime),b.ddcubicpoly(2,thistime),b.ddcubicpoly(3,thistime),b.ddcubicpoly(4,thistime));
  }
  

  // Print "blend out" segment of PATH
  if ((trajectorytype==ENDVIA)||(trajectorytype==BOTHVIA)) {
    int last=0;
    if (endmacro->type==NOMACRO) last=1;
    if (blendtype == 1)
      blendquintic(ptrpath, pcuridx, &epp, &epv, &epa, &tpp, &tpv, &tpa, (tmpnFloat)(blendouttime*0.001), outnos, toTCPidx, &temprobot, positionhint, last);    
    else 
      blendcubic(ptrpath, pcuridx, &epp, &epv, &tpp, &tpv, (tmpnFloat)(blendouttime*0.001), outnos, toTCPidx, &temprobot,positionhint,last);
    
  }
  
  if (endmacro->type==SPIRAL) {
    if (endmacro->positionhint == 2) {
      positionhint++;
      ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
      ptrpath->poshint[ptrpath->maxpidx].time=-1;
      ptrpath->poshint[ptrpath->maxpidx].i=0;
      ptrpath->maxpidx++;
    }
    spiralMacro(&temprobot, ptrpath, pcuridx, endmacro->amplitude, endmacro->offsx, endmacro->offsz, endmacro->length, endmacro->frequency, endmacro->time, &toposloc, endmacronos, toTCPidx, positionhint);
  }
  else if (endmacro->type==DOWNLINE) {
    if (endmacro->positionhint == 2) {
      positionhint++;
      ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
      ptrpath->poshint[ptrpath->maxpidx].time=-1;
      ptrpath->poshint[ptrpath->maxpidx].i=0;
      ptrpath->maxpidx++;
    }
    downlineMacro(&temprobot, ptrpath, pcuridx, endmacro->length, endmacro->time, &toposloc, endmacronos, toTCPidx, positionhint);
  }
  else if (endmacro->type==FASTDOWNLINE) {
    if (endmacro->positionhint == 2) {
      positionhint++;
      ptrpath->poshint[ptrpath->maxpidx].positionhint=positionhint;
      ptrpath->poshint[ptrpath->maxpidx].time=-1;
      ptrpath->poshint[ptrpath->maxpidx].i=0;
      ptrpath->maxpidx++;
    }
    fastDownlineMacro(&temprobot, ptrpath, pcuridx, endmacro->length, endmacro->time, &toposloc, endmacronos, toTCPidx, positionhint);
  }
  /*** Dupliker sidste keypoint for at splinen stopper med v=0 ****/
  ptrpath->keypoint[curidx].x=ptrpath->keypoint[curidx-1].x;
  ptrpath->keypoint[curidx].y=ptrpath->keypoint[curidx-1].y;
  ptrpath->keypoint[curidx].z=ptrpath->keypoint[curidx-1].z;
  ptrpath->keypoint[curidx].v=ptrpath->keypoint[curidx-1].v;
  ptrpath->keypoint[curidx].w=ptrpath->keypoint[curidx-1].w;
  ptrpath->keypoint[curidx].u=ptrpath->keypoint[curidx-1].u;
  ptrpath->keypoint[curidx].tcpidx=ptrpath->keypoint[curidx-1].tcpidx;
  ptrpath->keypoint[curidx].positionhint=ptrpath->keypoint[curidx-1].positionhint;
  ptrpath->keypoint[curidx].statehint=0;
  ptrpath->keypoint[curidx].dt=10;
  curidx++;

  /*** Dupliker første keypoint for at splinen starter med v=0 ****/
  ptrpath->keypoint[0].x=ptrpath->keypoint[1].x;
  ptrpath->keypoint[0].y=ptrpath->keypoint[1].y;
  ptrpath->keypoint[0].z=ptrpath->keypoint[1].z;
  ptrpath->keypoint[0].v=ptrpath->keypoint[1].v;
  ptrpath->keypoint[0].w=ptrpath->keypoint[1].w;
  ptrpath->keypoint[0].u=ptrpath->keypoint[1].u;
  ptrpath->keypoint[0].tcpidx=ptrpath->keypoint[1].tcpidx;
  ptrpath->keypoint[0].positionhint=0;
  ptrpath->keypoint[0].statehint=0;
  ptrpath->keypoint[0].dt=10;
  
	// if wrist is locked to specific angle
	if (lockv!=1000.0)
	{
		for (int i=0;i<=curidx;i++) 
		{
			ptrpath->keypoint[i].v=lockv;
		}
	}
  ptrpath->maxTime=(tmpnFloat)exectime;
  //ptrpath->maxTime=(tmpnFloat)((int)(retval*1000.0+0.5));
  ptrpath->maxidx=curidx;
  // printf("maxidx: %i\n",ptrpath->maxidx);  
  ptrpath->spline=robot->splinehint;
  ptrpath->splineorder=robot->splineorder;
	//jerkMinimizer(&temprobot,ptrpath,fromTCPidx,10000);
  return retval;
}

tmpnDouble uniform(tmpnDouble min, tmpnDouble max)
{
  static const tmpnDouble rmax=RAND_MAX+1.0;
  return (max-min)*(rand())/rmax+min;
}

int randomindex(int max)
{
        return (int)((1.0*max*rand())/RAND_MAX);
}

void VAD(tmpnDouble x1,tmpnDouble x2,tmpnDouble x3,tmpnDouble y1,tmpnDouble y2,tmpnDouble y3,tmpnDouble* vel,tmpnDouble* acc) {
  tmpnDouble A,B;
	tmpnDouble temp1,temp2,temp3;
	temp1=y1/((x1-x2)*(x1-x3));
	temp2=y2/((x2-x1)*(x2-x3));
	temp3=y3/((x3-x1)*(x3-x2));
	A = temp1 + temp2 + temp3;
	B = -1.0*((x1+x2)*temp3+(x1+x3)*temp2+(x2+x3)*temp1);
	*acc=2*A;
	*vel=(*acc)*x2+B;	
}

void jerkMinimizer(tmpnRobot *robot, tmpnPathDef *ptrpath, int tcpidx, int jerkscale)
{
	srand((unsigned)time(NULL)); //initialiser random number generator
	printf("\n------------------before--------------------------\n");
	int i=0,j=0;
	float tvar=ptrpath->maxTime/(1000.0*ptrpath->maxidx);
	tmpnJointsDUnion pos[1000];
	tmpnJointsDUnion vel[1000];
	tmpnJointsDUnion acc[1000];
	tmpnJointsDUnion jerk[1000];
	tmpnDouble dummy;
	vel[0].name.a=0.0;
	vel[0].name.b=0.0;
	vel[0].name.c=0.0;
	vel[0].name.d=0.0;
	vel[0].name.e=0.0;
	vel[ptrpath->maxidx-1].name.a=0.0;
	vel[ptrpath->maxidx-1].name.b=0.0;
	vel[ptrpath->maxidx-1].name.c=0.0;
	vel[ptrpath->maxidx-1].name.d=0.0;
	vel[ptrpath->maxidx-1].name.e=0.0;
	for (i=0;i<ptrpath->maxidx;i++)
	{
		tmpnComputeIK(robot,ptrpath->keypoint[i].x,ptrpath->keypoint[i].y,ptrpath->keypoint[i].z,ptrpath->keypoint[i].v,ptrpath->keypoint[i].w,ptrpath->keypoint[i].u,tcpidx);
		pos[i].name.a=robot->m_joint.a;
		pos[i].name.b=robot->m_joint.b;
		pos[i].name.c=robot->m_joint.c;
		pos[i].name.d=robot->m_joint.d;
		pos[i].name.e=robot->m_joint.e;
	}
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),pos[i-1].array[j],pos[i].array[j],pos[i+1].array[j],&vel[i].array[j],&dummy);
		}
	}
	acc[0].name.a=0.0;
	acc[0].name.b=0.0;
	acc[0].name.c=0.0;
	acc[0].name.d=0.0;
	acc[0].name.e=0.0;
	acc[ptrpath->maxidx-1].name.a=0.0;
	acc[ptrpath->maxidx-1].name.b=0.0;
	acc[ptrpath->maxidx-1].name.c=0.0;
	acc[ptrpath->maxidx-1].name.d=0.0;
	acc[ptrpath->maxidx-1].name.e=0.0;
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),vel[i-1].array[j],vel[i].array[j],vel[i+1].array[j],&acc[i].array[j],&dummy);
		}
	}
	jerk[0].name.a=0.0;
	jerk[0].name.b=0.0;
	jerk[0].name.c=0.0;
	jerk[0].name.d=0.0;
	jerk[0].name.e=0.0;
	jerk[ptrpath->maxidx-1].name.a=0.0;
	jerk[ptrpath->maxidx-1].name.b=0.0;
	jerk[ptrpath->maxidx-1].name.c=0.0;
	jerk[ptrpath->maxidx-1].name.d=0.0;
	jerk[ptrpath->maxidx-1].name.e=0.0;
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),acc[i-1].array[j],acc[i].array[j],acc[i+1].array[j],&jerk[i].array[j],&dummy);
		}
	}
	for (i=0;i<ptrpath->maxidx;i++)
	{
		printf("%0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n",i*tvar,pos[i].name.a,MMTOM(vel[i].name.a),MMTOM(acc[i].name.a),MMTOM(jerk[i].name.a)*MMTOM(jerk[i].name.a),pos[i].name.b,DEGTORAD(vel[i].name.b),DEGTORAD(acc[i].name.b),DEGTORAD(jerk[i].name.b)*DEGTORAD(jerk[i].name.b),pos[i].name.c,DEGTORAD(vel[i].name.c),DEGTORAD(acc[i].name.c),DEGTORAD(jerk[i].name.c)*DEGTORAD(jerk[i].name.c),pos[i].name.d,DEGTORAD(vel[i].name.d),DEGTORAD(acc[i].name.d),DEGTORAD(jerk[i].name.d)*DEGTORAD(jerk[i].name.d),pos[i].name.e,DEGTORAD(vel[i].name.e),DEGTORAD(acc[i].name.e),DEGTORAD(jerk[i].name.e)*DEGTORAD(jerk[i].name.e));			
	}
	int t;
	int maxi=0;
	float maxjerk,minjerk;
	float totjerk;

	for (t=0;t<jerkscale;t++)
	{
		tvar=ptrpath->maxTime/(1000.0*ptrpath->maxidx);
		vel[0].name.a=0.0;vel[0].name.b=0.0;vel[0].name.c=0.0;vel[0].name.d=0.0;vel[0].name.e=0.0;
		vel[ptrpath->maxidx-1].name.a=0.0;vel[ptrpath->maxidx-1].name.b=0.0;vel[ptrpath->maxidx-1].name.c=0.0;vel[ptrpath->maxidx-1].name.d=0.0;vel[ptrpath->maxidx-1].name.e=0.0;
		for (i=1;i<ptrpath->maxidx-1;i++)
		{
			for (j=0;j<5;j++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),pos[i-1].array[j],pos[i].array[j],pos[i+1].array[j],&vel[i].array[j],&dummy);
			}
		}
		acc[0].name.a=0.0;acc[0].name.b=0.0;acc[0].name.c=0.0;acc[0].name.d=0.0;acc[0].name.e=0.0;
		acc[ptrpath->maxidx-1].name.a=0.0;acc[ptrpath->maxidx-1].name.b=0.0;acc[ptrpath->maxidx-1].name.c=0.0;acc[ptrpath->maxidx-1].name.d=0.0;acc[ptrpath->maxidx-1].name.e=0.0;
		for (i=1;i<ptrpath->maxidx-1;i++)
		{
			for (j=0;j<5;j++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),vel[i-1].array[j],vel[i].array[j],vel[i+1].array[j],&acc[i].array[j],&dummy);
			}
		}
		jerk[0].name.a=0.0;jerk[0].name.b=0.0;jerk[0].name.c=0.0;jerk[0].name.d=0.0;jerk[0].name.e=0.0;
		jerk[ptrpath->maxidx-1].name.a=0.0;jerk[ptrpath->maxidx-1].name.b=0.0;jerk[ptrpath->maxidx-1].name.c=0.0;jerk[ptrpath->maxidx-1].name.d=0.0;jerk[ptrpath->maxidx-1].name.e=0.0;
		for (i=1;i<ptrpath->maxidx-1;i++)
		{
			for (j=0;j<5;j++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),acc[i-1].array[j],acc[i].array[j],acc[i+1].array[j],&jerk[i].array[j],&dummy);
			}
		}
		tmpnJointsDUnion temp,temp2,temp3,tmp,tmp2,tmp3;
		tmpnJointsDUnion best,best2,best3;
		int q;
		for (j=0;j<5;j++)
		{
			for (i=1;i<ptrpath->maxidx-1;i++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),pos[i-1].array[j],pos[i].array[j],pos[i+1].array[j],&vel[i].array[j],&dummy);
			}
			for (i=1;i<ptrpath->maxidx-1;i++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),vel[i-1].array[j],vel[i].array[j],vel[i+1].array[j],&acc[i].array[j],&dummy);
			}
			for (i=1;i<ptrpath->maxidx-1;i++)
			{
				VAD(tvar*(i-1),tvar*i,tvar*(i+1),acc[i-1].array[j],acc[i].array[j],acc[i+1].array[j],&jerk[i].array[j],&dummy);
			}
			maxjerk=0.0;
			maxi=2;
			for (i=2;i<ptrpath->maxidx-2;i++)
			{
				totjerk=jerk[i].array[j];
				totjerk*=totjerk;
				if (totjerk>maxjerk)
				{
					maxjerk=totjerk;
					maxi=i;
				}
			}
			if (maxi>=2&&maxi<=ptrpath->maxidx-3)
			{
				if (uniform(0.0,1.0)>=0.5)
					maxi+=randomindex(2);
				else
					maxi-=randomindex(2);
			}
				//printf("maxjerk joint %i index %i jerk %f\n",j,maxi,maxjerk);
			
			totjerk=0.0;
			for (i=0;i<ptrpath->maxidx;i++)
			{
				totjerk+=jerk[i].array[j]*jerk[i].array[j];
			}
			minjerk=totjerk;
			//		printf("minjerk %0.4f\n",minjerk);
			//	sleep(5);
 			best.array[j]=pos[maxi-1].array[j];
			best2.array[j]=pos[maxi].array[j];
			best3.array[j]=pos[maxi+1].array[j];
			for (q=0;q<3;q++)
			{
				tmp.array[j]=pos[maxi-1].array[j];
				tmp2.array[j]=pos[maxi].array[j];
				tmp3.array[j]=pos[maxi+1].array[j];
				temp.array[j]=uniform(pos[maxi-1].array[j], pos[maxi-1].array[j]+(0.01+0.005/(t+1))*(pos[maxi].array[j]-pos[maxi-1].array[j]));
				temp2.array[j]=uniform(pos[maxi].array[j]*0.99, pos[maxi].array[j]*1.01);
				temp3.array[j]=uniform(pos[maxi+1].array[j], pos[maxi+1].array[j]+(0.01+0.005/(t+1))*(pos[maxi].array[j]-pos[maxi+1].array[j]));
				pos[maxi-1].array[j]=temp.array[j];
				pos[maxi].array[j]=temp2.array[j];
				pos[maxi+1].array[j]=temp3.array[j];
				//printf("try %i %0.8f %0.8f %0.8f\n",maxi,pos[maxi-1].array[j],pos[maxi].array[j],pos[maxi+1].array[j]);
				for (i=1;i<ptrpath->maxidx-1;i++)
				{
					VAD(tvar*(i-1),tvar*i,tvar*(i+1),pos[i-1].array[j],pos[i].array[j],pos[i+1].array[j],&vel[i].array[j],&dummy);
				}
				for (i=1;i<ptrpath->maxidx-1;i++)
				{
					VAD(tvar*(i-1),tvar*i,tvar*(i+1),vel[i-1].array[j],vel[i].array[j],vel[i+1].array[j],&acc[i].array[j],&dummy);
				}
				for (i=1;i<ptrpath->maxidx-1;i++)
				{
					VAD(tvar*(i-1),tvar*i,tvar*(i+1),acc[i-1].array[j],acc[i].array[j],acc[i+1].array[j],&jerk[i].array[j],&dummy);
				}
				totjerk=0.0;
				for (i=0;i<ptrpath->maxidx;i++)
				{
					totjerk+=jerk[i].array[j]*jerk[i].array[j];
				}
				if (totjerk<minjerk)
				{
					printf("BINGO!!! %i %0.4f %0.4f\n",j,minjerk,totjerk);
					minjerk=totjerk;
					best.array[j]=temp.array[j];
					best2.array[j]=temp2.array[j];
					best3.array[j]=temp3.array[j];
					//usleep(200000);
				}
				//else printf("try totjerk %0.4f %0.4f %0.4f %0.4f\n",totjerk,minjerk,pos[maxi-1].array[j],pos[maxi+1].array[j]);
				pos[maxi-1].array[j]=tmp.array[j];
				pos[maxi].array[j]=tmp2.array[j];
				pos[maxi+1].array[j]=tmp3.array[j];
			}
			//			printf("pos[maxi]\n",maxi,maxjerk);
			pos[maxi-1].array[j]=best.array[j];
			pos[maxi].array[j]=best2.array[j];
			pos[maxi+1].array[j]=best3.array[j];
/* 		tmpnJointsUnion temp2; */
/* 		for (j=0;j<5;j++) */
/* 		{ */
/* 			temp.array[j]=pos[maxi+1].array[j]; */
/* 			pos[maxi].array[j]=pos[maxi-1].array[j]+0.33333333*(temp.array[j]-pos[maxi-1].array[j]); */
/* 			pos[maxi+1].array[j]=pos[maxi-1].array[j]+0.66666666*(temp.array[j]-pos[maxi-1].array[j]); */
/* 			temp2.array[j]=pos[maxi+2].array[j]; */
/* 			pos[maxi+2].array[j]=temp.array[j]; */
/* 		} */
/*     ptrpath->keypoint[ptrpath->maxidx].tcpidx=ptrpath->keypoint[ptrpath->maxidx-1].tcpidx; */
/*     ptrpath->keypoint[ptrpath->maxidx].positionhint=ptrpath->keypoint[ptrpath->maxidx-1].positionhint; */
/*     ptrpath->keypoint[ptrpath->maxidx].statehint=ptrpath->keypoint[ptrpath->maxidx-1].statehint; */
/*     ptrpath->keypoint[ptrpath->maxidx].dt=10; */
/* 		ptrpath->maxidx++; */
/* 		printf("maxbefore %f\n",ptrpath->maxTime); */
/* 		ptrpath->maxTime+=1.0*(ptrpath->maxTime/(tmpnFloat)ptrpath->maxidx); */
/* 		printf("maxafter %f\n",ptrpath->maxTime); */
/* 		if (maxi+3<ptrpath->maxidx) { */
/* 			for (i=maxi+3;i<ptrpath->maxidx;i++) */
/* 			{ */
/* 				for (j=0;j<5;j++) */
/* 				{ */
/* 					temp.array[j]=temp2.array[j]; */
/* 					temp2.array[j]=pos[i].array[j]; */
/* 					pos[i].array[j]=temp.array[j];					 */
/* 				} */
/* 			} */
/* 		} */
		}
	}
	for (i=0;i<ptrpath->maxidx;i++)
	{
		tmpnComputeFKlogic(robot, pos[i].name.a, pos[i].name.b, pos[i].name.c, pos[i].name.d, pos[i].name.e, 0.0, tcpidx);    
		ptrpath->keypoint[i].x=robot->m_worldPoint.x;
    ptrpath->keypoint[i].y=robot->m_worldPoint.y;
    ptrpath->keypoint[i].z=robot->m_worldPoint.z;
    ptrpath->keypoint[i].v=robot->m_worldPoint.v;
    ptrpath->keypoint[i].w=robot->m_worldPoint.w;
    ptrpath->keypoint[i].u=robot->m_worldPoint.u;
	}
	printf("\n------------------after--------------------------\n");
	vel[0].name.a=0.0;
	vel[0].name.b=0.0;
	vel[0].name.c=0.0;
	vel[0].name.d=0.0;
	vel[0].name.e=0.0;
	vel[ptrpath->maxidx-1].name.a=0.0;
	vel[ptrpath->maxidx-1].name.b=0.0;
	vel[ptrpath->maxidx-1].name.c=0.0;
	vel[ptrpath->maxidx-1].name.d=0.0;
	vel[ptrpath->maxidx-1].name.e=0.0;
	for (i=0;i<ptrpath->maxidx;i++)
	{
		tmpnComputeIK(robot,ptrpath->keypoint[i].x,ptrpath->keypoint[i].y,ptrpath->keypoint[i].z,ptrpath->keypoint[i].v,ptrpath->keypoint[i].w,ptrpath->keypoint[i].u,tcpidx);
		pos[i].name.a=robot->m_joint.a;
		pos[i].name.b=robot->m_joint.b;
		pos[i].name.c=robot->m_joint.c;
		pos[i].name.d=robot->m_joint.d;
		pos[i].name.e=robot->m_joint.e;
	}
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),pos[i-1].array[j],pos[i].array[j],pos[i+1].array[j],&vel[i].array[j],&dummy);
		}
	}
	acc[0].name.a=0.0;
	acc[0].name.b=0.0;
	acc[0].name.c=0.0;
	acc[0].name.d=0.0;
	acc[0].name.e=0.0;
	acc[ptrpath->maxidx-1].name.a=0.0;
	acc[ptrpath->maxidx-1].name.b=0.0;
	acc[ptrpath->maxidx-1].name.c=0.0;
	acc[ptrpath->maxidx-1].name.d=0.0;
	acc[ptrpath->maxidx-1].name.e=0.0;
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),vel[i-1].array[j],vel[i].array[j],vel[i+1].array[j],&acc[i].array[j],&dummy);
		}
	}
	jerk[0].name.a=0.0;
	jerk[0].name.b=0.0;
	jerk[0].name.c=0.0;
	jerk[0].name.d=0.0;
	jerk[0].name.e=0.0;
	jerk[ptrpath->maxidx-1].name.a=0.0;
	jerk[ptrpath->maxidx-1].name.b=0.0;
	jerk[ptrpath->maxidx-1].name.c=0.0;
	jerk[ptrpath->maxidx-1].name.d=0.0;
	jerk[ptrpath->maxidx-1].name.e=0.0;
	for (i=1;i<ptrpath->maxidx-1;i++)
	{
		for (j=0;j<5;j++)
		{
			VAD(tvar*(i-1),tvar*i,tvar*(i+1),acc[i-1].array[j],acc[i].array[j],acc[i+1].array[j],&jerk[i].array[j],&dummy);
		}
	}
	for (i=0;i<ptrpath->maxidx;i++)
	{
		printf("%0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n",i*tvar,pos[i].name.a,MMTOM(vel[i].name.a),MMTOM(acc[i].name.a),MMTOM(jerk[i].name.a)*MMTOM(jerk[i].name.a),pos[i].name.b,DEGTORAD(vel[i].name.b),DEGTORAD(acc[i].name.b),DEGTORAD(jerk[i].name.b)*DEGTORAD(jerk[i].name.b),pos[i].name.c,DEGTORAD(vel[i].name.c),DEGTORAD(acc[i].name.c),DEGTORAD(jerk[i].name.c)*DEGTORAD(jerk[i].name.c),pos[i].name.d,DEGTORAD(vel[i].name.d),DEGTORAD(acc[i].name.d),DEGTORAD(jerk[i].name.d)*DEGTORAD(jerk[i].name.d),pos[i].name.e,DEGTORAD(vel[i].name.e),DEGTORAD(acc[i].name.e),DEGTORAD(jerk[i].name.e)*DEGTORAD(jerk[i].name.e));
	}
}


void convertToFrame(tmpnVector *wp, int fromIdx, tmpnKeyPoint *p, int toIdx, tmpnRobot *robot)
{
  wp->x = p->x+robot->m_frames.frame[fromIdx].x-robot->m_frames.frame[toIdx].x;
  wp->y = p->y+robot->m_frames.frame[fromIdx].y-robot->m_frames.frame[toIdx].y;
  wp->z = p->z+robot->m_frames.frame[fromIdx].z-robot->m_frames.frame[toIdx].z;
  wp->v = p->v+robot->m_frames.frame[fromIdx].v-robot->m_frames.frame[toIdx].v;
  wp->w = p->w+robot->m_frames.frame[fromIdx].w-robot->m_frames.frame[toIdx].w;
  wp->u = p->u+robot->m_frames.frame[fromIdx].u-robot->m_frames.frame[toIdx].u;
}

void convertToFrame_vectorstyle(tmpnVector *wp, tmpnFrame *fromF, tmpnVector *p, tmpnFrame *toF)
{
  wp->x = p->x+fromF->x-toF->x;
  wp->y = p->y+fromF->y-toF->y;
  wp->z = p->z+fromF->z-toF->z;
  wp->v = p->v+fromF->v-toF->v;
  wp->w = p->w+fromF->w-toF->w;
  wp->u = p->u+fromF->u-toF->u;
}

void blendCorner3(tmpnRobot *robot, COMMANDSTRUCT *corner)
{
  int frameIdx;
  tmpnVector wp0,wp1,wp2,wp3,wp4,wp5,wp6;
  tmpnVector distanceBetweenPoints;
  tmpnVector acc,V0,V1,f1,f2,f3;
  POINTSTRUCT *p0,*p1,*p2,*p3,*p4,*p5,*p6;
  tmpnFloat arczy4;

  p0=getPoint(corner,-3);
  p1=getPoint(corner,-2);
  p2=getPoint(corner,-1);
  p3=getPoint(corner,0);
  p4=getPoint(corner,1);
  p5=getPoint(corner,2);
  p6=getPoint(corner,3);

  frameIdx=getFrameIdx("base",robot);
  convertToFrame(&wp0,p0->frameidx,&p0->fp,frameIdx,robot);
  convertToFrame(&wp1,p1->frameidx,&p1->fp,frameIdx,robot);
  convertToFrame(&wp2,p2->frameidx,&p2->fp,frameIdx,robot);
  convertToFrame(&wp3,p3->frameidx,&p3->fp,frameIdx,robot);
  convertToFrame(&wp4,p4->frameidx,&p4->fp,frameIdx,robot);
  convertToFrame(&wp5,p5->frameidx,&p5->fp,frameIdx,robot);
  convertToFrame(&wp6,p6->frameidx,&p6->fp,frameIdx,robot);
  V0.x=wp1.x-wp0.x; //Speed0
  V0.y=wp1.y-wp0.y; //
  V0.z=wp1.z-wp0.z; //
  V0.w=wp1.w-wp0.w; //sFrom
//  alfazy0=atan2(V0.y,V0.z); //Vector0 in zy-plane angle
  V1.y=wp6.y-wp5.y; //Speed1
  V1.x=wp6.x-wp5.x; //
  V1.z=wp6.z-wp5.z; //
  V1.w=wp6.w-wp5.w; //
//  alfazy1=atan2(V1.y,V1.z); //Vector1 in zy-plane angle
  acc.x=0; if(fabs(V0.x)<=fabs(V1.x)) acc.x=1; //are we acc or dec
  acc.y=0; if(fabs(V0.y)<=fabs(V1.y)) acc.y=1; //are we acc or dec
  acc.z=0; if(fabs(V0.z)<=fabs(V1.z)) acc.z=1; //are we acc or dec
  acc.w=0; if(fabs(V0.w)<=fabs(V1.w)) acc.w=1; //are we acc or dec
//  arczy4=fabs(alfazy0-alfazy1)*0.25;
//  if(arczy4>PI/8) arczy4=PI/8;
  
  arczy4=PI/8;
  //calgualte blend values x
  if(acc.x==1)
  {
    f1.x=1-sin(arczy4*3);
    f2.x=1-sin(arczy4*2);
    f3.x=1-sin(arczy4*1);
  }
  else
  {
    f1.x=sin(arczy4*1);
    f2.x=sin(arczy4*2);
    f3.x=sin(arczy4*3);
  }
  //calgualte blend values y
  if(acc.y==1)
  {
    f1.y=1-sin(arczy4*3);
    f2.y=1-sin(arczy4*2);
    f3.y=1-sin(arczy4*1);
  }
  else
  {
    f1.y=sin(arczy4*1);
    f2.y=sin(arczy4*2);
    f3.y=sin(arczy4*3);
  }

  //calgualte blend values z
  if(acc.z==1)
  {
    f1.z=1-sin(arczy4*3);
    f2.z=1-sin(arczy4*2);
    f3.z=1-sin(arczy4*1);
  }
  else
  {
    f1.z=sin(arczy4*1);
    f2.z=sin(arczy4*2);
    f3.z=sin(arczy4*3);
  }
  //calgualte blend values w
  if(acc.w==1)
  {
    f1.w=1-sin(arczy4*3);
    f2.w=1-sin(arczy4*2);
    f3.w=1-sin(arczy4*1);
  }
  else
  {
    f1.w=sin(arczy4*1);
    f2.w=sin(arczy4*2);
    f3.w=sin(arczy4*3);
  }
  //direction and total distance to blend is found here
  distanceBetweenPoints.x=wp5.x-wp1.x;
  distanceBetweenPoints.y=wp5.y-wp1.y;
  distanceBetweenPoints.z=wp5.z-wp1.z;
  distanceBetweenPoints.w=wp5.w-wp1.w;
  
  p2->fp.x=wp1.x+f1.x*distanceBetweenPoints.x-robot->m_frames.frame[p2->frameidx].x;
  p3->fp.x=wp1.x+f2.x*distanceBetweenPoints.x-robot->m_frames.frame[p3->frameidx].x;
  p4->fp.x=wp1.x+f3.x*distanceBetweenPoints.x-robot->m_frames.frame[p4->frameidx].x;
  
  p2->fp.y=wp1.y+f1.y*distanceBetweenPoints.y-robot->m_frames.frame[p2->frameidx].y;
  p3->fp.y=wp1.y+f2.y*distanceBetweenPoints.y-robot->m_frames.frame[p3->frameidx].y;
  p4->fp.y=wp1.y+f3.y*distanceBetweenPoints.y-robot->m_frames.frame[p4->frameidx].y;

  p2->fp.z=wp1.z+f1.z*distanceBetweenPoints.z-robot->m_frames.frame[p2->frameidx].z;
  p3->fp.z=wp1.z+f2.z*distanceBetweenPoints.z-robot->m_frames.frame[p3->frameidx].z;
  p4->fp.z=wp1.z+f3.z*distanceBetweenPoints.z-robot->m_frames.frame[p4->frameidx].z;

  p2->fp.w=wp1.w+f1.w*distanceBetweenPoints.w-robot->m_frames.frame[p2->frameidx].w;
  p3->fp.w=wp1.w+f2.w*distanceBetweenPoints.w-robot->m_frames.frame[p3->frameidx].w;
  p4->fp.w=wp1.w+f3.w*distanceBetweenPoints.w-robot->m_frames.frame[p4->frameidx].w;
}

void seekCorner(tmpnRobot *robot, COMMANDSTRUCT *corner, tmpnFloat rx, tmpnFloat rz)
{
  POINTSTRUCT *p0;
  p0=getPoint(corner,-1);
  p0->fp.z+=rz*0.5;
  p0=getPoint(corner,-2);
  p0->fp.z+=rz;
  p0=getPoint(corner,-3);
  p0->fp.x+=rx*0.5;
  p0->fp.z+=rz;
  p0=getPoint(corner,-4);
  p0->fp.x+=rx;
  p0->fp.z+=rz;
  p0=getPoint(corner,-5);
  p0->fp.z+=rz*0.5;
  p0->fp.x+=rx;
  p0=getPoint(corner,-6);
  p0->fp.x+=rx;
  p0=getPoint(corner,-7);
  p0->fp.x+=rx;
  p0->fp.z-=rz*0.5;
  p0=getPoint(corner,-8);
  p0->fp.x+=rx;
  p0->fp.z-=rz;
  p0=getPoint(corner,-9);
  p0->fp.x+=rx*0.5;
  p0->fp.z-=rz;
  p0=getPoint(corner,-10);
  p0->fp.z-=rz;
  p0=getPoint(corner,-11);
  p0->fp.x-=rx*0.5;
  p0->fp.z-=rz;
  p0=getPoint(corner,-12);
  p0->fp.x-=rx;
  p0->fp.z-=rz;
  p0=getPoint(corner,-13);
  p0->fp.x-=rx;
  p0->fp.z-=rz*0.5;
  p0=getPoint(corner,-14);
  p0->fp.x-=rx;
  p0=getPoint(corner,-15);
  p0->fp.x-=rx;
  p0->fp.z+=rz*0.5;
  p0=getPoint(corner,-16);
  p0->fp.x-=rx;
  p0->fp.z+=rz;
  p0=getPoint(corner,-17);
  p0->fp.x-=rx*0.5;
  p0->fp.z+=rz;
  p0=getPoint(corner,-18);
  p0->fp.z+=rz;
  p0=getPoint(corner,-19);
  p0->fp.z+=rz*0.5;
}

void seekCornerX(tmpnRobot *robot, COMMANDSTRUCT *corner, tmpnFloat rzminus, tmpnFloat rzplus, tmpnFloat rxminus, tmpnFloat rxplus)
{
  POINTSTRUCT *p0;
 
  p0=getPoint(corner,-1);
  p0->fp.z-=rzminus*0.5;
  p0=getPoint(corner,-2);
  p0->fp.z-=rzminus;
  p0=getPoint(corner,-3);
  p0->fp.z-=rzminus*0.5;
 
  p0=getPoint(corner,-5);
  p0->fp.z+=rzplus*0.5;
  p0=getPoint(corner,-6);
  p0->fp.z+=rzplus;
  p0=getPoint(corner,-7);
  p0->fp.z+=rzplus*0.5;

  p0=getPoint(corner,-9);
  p0->fp.x-=rxminus*0.5;
  p0=getPoint(corner,-10);
  p0->fp.x-=rxminus;
  p0=getPoint(corner,-11);
  p0->fp.x-=rxminus*0.5;

  p0=getPoint(corner,-13);
  p0->fp.x+=rxplus*0.5;
  p0=getPoint(corner,-14);
  p0->fp.x+=rxplus;
  p0=getPoint(corner,-15);
  p0->fp.x+=rxplus*0.5;

}

COMMANDSTRUCT *expandPath(COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  tmpnPPScript *ppscript;
  ppscript = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  if (ppscript==NULL) {
   fprintf(stderr,"error: ppscript (%s) not found!\n",ppscriptname);
   exit(1);
  }
  if(ppscript->type==6) 
    return expandSubPathKatrineIn((tmpnRobot*)trobot,ptrcmd,level,forceItem, ppscriptname,loadgroup);
  if(ppscript->type==7) 
    return expandSubPathKatrineOut((tmpnRobot*)trobot,ptrcmd,level,forceItem, ppscriptname,loadgroup);


	if (ppscript->type%2==0)
	{
		return expandPathGeneralBoptInHeader((tmpnRobot*)trobot,ptrcmd,level,forceItem,ppscriptname,loadgroup); 
	}
	else
	{
		return expandPathGeneralBoptOutHeader((tmpnRobot*)trobot,ptrcmd,level,forceItem,ppscriptname,loadgroup); 
	}
	return NULL;
}

//type=1 Nyhuus10Kg,Nyhuus5Kg
//type=4 AlfredIn 
//type=5 AlfredOut 
//type=6 KatrineIn
//type=7 KatrineOut
//type=8 Automatisk baneoptimering AlfredIn
//type=9 Automatisk baneoptimering AlfredOut
//type=10 Automatisk baneoptimering 307In
//type=11 Automatisk baneoptimering 307Out

void expandBopt(tmpnRobot *robot, COMMANDSTRUCT* ptrcmd) {
  COMMANDSTRUCT* ppcmd=NULL;
  const char *ppscriptname;
  tmpnPPScript *ppscript;
  int forceItem;
  int loadgroup;
	tmpnBoptCoeff* BoptCoeffs;
  PATHSTRUCT* ptrpath;
  
  ptrpath=(PATHSTRUCT*)ptrcmd->data;
  
  ppcmd = getPrevPPScriptCommand(ptrcmd);
  ppscriptname=((PPSCRIPTSTRUCT*)ppcmd->data)->name;
  //printf("hejsaname: %s\n",ppscriptname);
  forceItem = ((PPSCRIPTSTRUCT*)ppcmd->data)->idx;
  loadgroup = ((PPSCRIPTSTRUCT*)ppcmd->data)->loadgroup;
  ppscript = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  //printf("hejsatype: %i\n",ppscript->type);
	BoptCoeffs = getBoptCoeff((tmpnWorkcell*)tworkcell);
	if (BoptCoeffs == NULL)
		printf("wrong type ppscript for runbopt!!\n");
	else
		expandPathBoptGeneral(robot,&ptrpath->tpathdef,forceItem,ppscriptname,loadgroup,BoptCoeffs); 	
} 

COMMANDSTRUCT *generateProgram(COMMANDSTRUCT *ptrcmd
                              ,tmpnRobot *robot
                              ,int *level
                              ,int layerHeightMM
                              ,int forceLayer
                              ,const char *ppscriptname)
{
  tmpnPPScript *ppscript;
  ppscript = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  return NULL;
}

COMMANDSTRUCT *expandPathGeneralBoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  moveItem=&ppscriptA->item[forceItem];

  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,20,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level); 
  /* ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);
      
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,21,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  /*  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);


  ptrcmd=addCommandString(ptrcmd,"COUNTER cAItems += 1",level);
      
  //********************************************************************
  //* Home                                                             *
  //********************************************************************

  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,22,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  /*  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}

COMMANDSTRUCT *expandPathGeneralBoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  moveItem=&ppscriptA->item[forceItem];

  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,23,1000,loadgroup);
	ptrcmd=addCommandString(ptrcmd,s,level);  
    /* ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);

  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,24,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  /*  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);

  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems += 1",level);

  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  
  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,25,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  /*  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT base 0,0,0,0,0,0,10 case",level);*/
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}


//***********************************************************************
//*                                                                     *
//* Automatically generates optimal path for trajectories of whatever   *
//* No check for collisions!!!                                          *
//*                                                                     *
//***********************************************************************




void expandPathBoptGeneral(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup, tmpnBoptCoeff* BoptCoeffs)
{
  tmpnFrame *toFrame,*fromFrame,*homeFrame;
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int maxlayers;
  int itemsPrLayer;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  maxlayers = ppscriptA->layers;
  itemsPrLayer = ppscriptA->itemsPrLayer;
  moveItem=&ppscriptA->item[forceItem];
	int layer = moveItem->layer;
	int pathidx = moveItem->idx;
	fromFrame=&robot->m_frames.frame[getFrameIdx(moveItem->from,robot)];
  toFrame=&robot->m_frames.frame[getFrameIdx(moveItem->to,robot)];
  homeFrame=&robot->m_frames.frame[getFrameIdx("home",robot)];

	if (ptrpath->pathtype==20) 
	{  
		expandPathBoptGeneric(robot,ptrpath,-1,layer,pathidx,homeFrame,fromFrame,NULL,moveItem->item,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
	else if (ptrpath->pathtype==21) 
	{  
		expandPathBoptGeneric(robot,ptrpath,layer,-1,pathidx,fromFrame,toFrame,moveItem->item,moveItem->item,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
	else if (ptrpath->pathtype==22) 
	{  
		expandPathBoptGeneric(robot,ptrpath,-1,-1,pathidx,toFrame,homeFrame,moveItem->item,NULL,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
	else if (ptrpath->pathtype==23) 
	{  
		expandPathBoptGeneric(robot,ptrpath,-1,-1,pathidx,homeFrame,fromFrame,NULL,moveItem->item,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
	else if (ptrpath->pathtype==24) 
	{  
		expandPathBoptGeneric(robot,ptrpath,-1,layer,pathidx,fromFrame,toFrame,moveItem->item,moveItem->item,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
	else if (ptrpath->pathtype==25) 
	{  
		expandPathBoptGeneric(robot,ptrpath,layer,-1,pathidx,toFrame,homeFrame,moveItem->item,NULL,loadgroup,ppscriptA->type,ptrpath->pathtype,BoptCoeffs);
	}
}

tmpnDualVector viavectpos1={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
tmpnVector viavecthast1={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
tmpnDualVector viavectpos2={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
tmpnVector viavecthast2={0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
int viavectabs1[]={0, 0, 0, 0, 0, 0};
int viavectabs2[]={0, 0, 0, 0, 0, 0};
tmpnVector toVector,fromVector;
macroparamstruct startmacro;
macroparamstruct endmacro;

int expandPathBoptGeneric(
     tmpnRobot *robot
    ,tmpnPathDef *ptrpath
    ,int cALayer
    ,int cBLayer
    ,int pathidx
    ,tmpnFrame *fromFrame
    ,tmpnFrame *toFrame
    ,const char *startItem
    ,const char *endItem
    ,int loadgroup
    ,int boptMode
    ,int pathtype
    ,tmpnBoptCoeff* BoptCoeffs)
{
  tmpnItem *thisitemstart, *thisitemend;
	tmpnFrame baseFrame={"base",0.00,0.00,0.00,0.00,0.00,0.00};
  tmpnVector zero = {0,0,0,0,0,0};
	tmpnBoptCoeffItem* boptcoeff;
  if (fromFrame == NULL || toFrame == NULL) return FALSE;
	boptcoeff = getBoptCoeffItem(BoptCoeffs, boptMode, pathtype);
	if (boptcoeff==NULL) return FALSE;
	ptrpath->pathtype=pathtype;
	
  int blendtype=boptcoeff->params.integer[1];
 
	tmpnFloat maxlength=boptcoeff->params.floating[4];
  tmpnFloat maxheight=boptcoeff->params.floating[0];
  tmpnFloat minheight=boptcoeff->params.floating[1];
	tmpnFloat lockv=boptcoeff->params.floating[5];

  convertToFrame_vectorstyle(&fromVector,fromFrame,&zero,&baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,&baseFrame);


	thisitemstart = getItem(startItem,(tmpnWorkcell*)tworkcell);
	thisitemend = getItem(endItem,(tmpnWorkcell*)tworkcell);
	
 	tmpnFloat b,f,p,g,l,h,t,r;
	
	if (thisitemstart!=NULL)
	{
		if (pathtype==22||pathtype==25||pathtype==44)
			fromVector.y += thisitemstart->my;
		else
			fromVector.y += thisitemstart->gy;
		if (cALayer!=-1)
		{
			fromVector.y += cALayer*thisitemstart->sy;    		
		}
		if (pathtype==24||pathtype==43)
			fromVector.x -= thisitemstart->gx; 
	}
	else
	{
		fromVector.y += cALayer;
	}
	if (thisitemend!=NULL)
	{
		if (pathtype==20||pathtype==23)
			toVector.y += thisitemend->gy;
		else
			toVector.y += thisitemend->my;
		if (cBLayer !=-1)
		{
			toVector.y +=	cBLayer*thisitemend->sy;
		}
		if (pathtype==23||pathtype==44)
			toVector.x -=	 thisitemend->gx;
	}
	else
	{
		toVector.y += cBLayer;
	}
	b = (fromVector.y-minheight)/(maxheight-minheight); //fromVector absolute normalized height
	f = (1.0-b); //1.0 at bottom layer, 0.0 at top layer.
	g = (toVector.y-minheight)/(maxheight-minheight); //toVector absolute normalized height
	p = (1.0-g); //1.0 at bottom layer, 0.0 at top layer.
	l = fabs(fromVector.z - toVector.z)/maxlength;
	h = fabs(toVector.y - fromVector.y)/(maxheight-minheight);
	t = fabs(toVector.v - fromVector.v)/180.0;
	r = (toVector.w - fromVector.w)/360.0;
	char noitemname[]="nothing";
	char *sitem;
	char *eitem;
	if (thisitemstart==NULL)
		sitem=noitemname;
	else
		sitem=thisitemstart->name;
	if (thisitemend==NULL)
		eitem=noitemname;
	else
		eitem=thisitemend->name;
  if(rs_param.path_debug>0) printf("Item is (%s , %s). adjusting with bfgplhtr(%f %f %f %f %f %f %f %f)\n",sitem,eitem,b,f,g,p,l,h,t,r);
	
  //************ Setting up macro parameters ***************
  

  /*typedef struct macroparamstruct
    {
    int type;
    tmpnFloat amplitude; //mm
    tmpnFloat offsx; //mm 
    tmpnFloat offsz;   //mm
    tmpnFloat length; //mm
    tmpnFloat frequency; //Hz
    tmpnFloat time;  //sec
    int positionhint;  
    } macroparamstruct;*/
  

	if (boptcoeff->macro[0].integer[0]==NOMACRO)
	{
		startmacro.type=NOMACRO;
	}
	else if (boptcoeff->macro[0].integer[0]==SPIRAL)
	{
		startmacro.type=SPIRAL;
		startmacro.positionhint=boptcoeff->macro[0].integer[1];
		startmacro.length=boptcoeff->macro[0].floating[0];
		startmacro.time=boptcoeff->macro[0].floating[1]*(1-f*f*f)+0.4;
		startmacro.amplitude=boptcoeff->macro[0].floating[2]*(1-f*f*f*f);
		startmacro.offsx=boptcoeff->macro[0].floating[3];
		startmacro.offsz=b*boptcoeff->macro[0].floating[4];
		startmacro.frequency=boptcoeff->macro[0].floating[5];
	}
	else if (boptcoeff->macro[0].integer[0]==UPLINE)
	{
		startmacro.type=UPLINE;
		startmacro.positionhint=boptcoeff->macro[0].integer[1];	
		startmacro.length=boptcoeff->macro[0].floating[0];
		startmacro.time=boptcoeff->macro[0].floating[1];
	}
	else if (boptcoeff->macro[0].integer[0]==FASTUPLINE)
	{
		startmacro.type=FASTUPLINE;
		startmacro.positionhint=boptcoeff->macro[0].integer[1];	
		startmacro.length=boptcoeff->macro[0].floating[0];
		startmacro.time=boptcoeff->macro[0].floating[1];
	}
	else if (boptcoeff->macro[0].integer[0]==DOWNLINE)
	{
		startmacro.type=DOWNLINE;
		startmacro.positionhint=boptcoeff->macro[0].integer[1];	
		startmacro.length=boptcoeff->macro[0].floating[0];
		startmacro.time=boptcoeff->macro[0].floating[1];
	}	
	else if (boptcoeff->macro[0].integer[0]==FASTDOWNLINE)
	{
		startmacro.type=FASTDOWNLINE;
		startmacro.positionhint=boptcoeff->macro[0].integer[1];	
		startmacro.length=boptcoeff->macro[0].floating[0];
		startmacro.time=boptcoeff->macro[0].floating[1];
	}
	if (boptcoeff->macro[1].integer[0]==NOMACRO)
	{
		endmacro.type=NOMACRO;
	}
	else if (boptcoeff->macro[1].integer[0]==SPIRAL)
	{
		endmacro.type=SPIRAL;
		endmacro.positionhint=boptcoeff->macro[1].integer[1];
		endmacro.length=boptcoeff->macro[1].floating[0];
		endmacro.time=boptcoeff->macro[1].floating[1]*(1-p*p*p)+0.4;
		endmacro.amplitude=boptcoeff->macro[1].floating[2]*(1-p*p*p*p);
		endmacro.offsx=boptcoeff->macro[1].floating[3];
		endmacro.offsz=g*boptcoeff->macro[1].floating[4];
		endmacro.frequency=boptcoeff->macro[1].floating[5];
	}
	else if (boptcoeff->macro[1].integer[0]==UPLINE)
	{
		endmacro.type=UPLINE;
		endmacro.positionhint=boptcoeff->macro[1].integer[1];	
		endmacro.length=boptcoeff->macro[1].floating[0];
		endmacro.time=boptcoeff->macro[1].floating[1];
	}
	else if (boptcoeff->macro[1].integer[0]==FASTUPLINE)
	{
		endmacro.type=FASTUPLINE;
		endmacro.positionhint=boptcoeff->macro[1].integer[1];	
		endmacro.length=boptcoeff->macro[1].floating[0];
		endmacro.time=boptcoeff->macro[1].floating[1];
	}
	else if (boptcoeff->macro[1].integer[0]==DOWNLINE)
	{
		endmacro.type=DOWNLINE;
		endmacro.positionhint=boptcoeff->macro[1].integer[1];	
		endmacro.length=boptcoeff->macro[1].floating[0];
		endmacro.time=boptcoeff->macro[1].floating[1];
	}
	else if (boptcoeff->macro[1].integer[0]==FASTDOWNLINE)
	{
		endmacro.type=FASTDOWNLINE;
		endmacro.positionhint=boptcoeff->macro[1].integer[1];	
		endmacro.length=boptcoeff->macro[1].floating[0];
		endmacro.time=boptcoeff->macro[1].floating[1];
	}
  //************************************
  tmpnFloat samplerate=boptcoeff->params.floating[2]; //Hz
  
  tmpnJointsUnion mv; 
	mv.name.a=MTOMM(boptcoeff->mv[0]);
	mv.name.b=RADTODEG(boptcoeff->mv[1]);
	mv.name.c=RADTODEG(boptcoeff->mv[2]);
	mv.name.d=RADTODEG(boptcoeff->mv[3]);
	mv.name.e=RADTODEG(boptcoeff->mv[4]);  //rad/s
	tmpnJointsUnion ma; 
	ma.name.a=MTOMM(boptcoeff->ma[0]);
	ma.name.b=RADTODEG(boptcoeff->ma[1]);
	ma.name.c=RADTODEG(boptcoeff->ma[2]);
	ma.name.d=RADTODEG(boptcoeff->ma[3]);
	ma.name.e=RADTODEG(boptcoeff->ma[4]);  //rad/s/s   

	
	tmpnBoptParamStruct *pvia[20];
	tmpnFloat valvia[20];
	tmpnFloat sum,factor;
	int i,j,k;

	pvia[0]=boptcoeff->viapos[0].x;
	pvia[1]=boptcoeff->viapos[0].y;
	pvia[2]=boptcoeff->viapos[0].z;
	pvia[3]=boptcoeff->viapos[0].v;
	pvia[4]=boptcoeff->viapos[0].w;
	pvia[5]=boptcoeff->viapos[1].x;
	pvia[6]=boptcoeff->viapos[1].y;
	pvia[7]=boptcoeff->viapos[1].z;
	pvia[8]=boptcoeff->viapos[1].v;
	pvia[9]=boptcoeff->viapos[1].w;
	pvia[10]=boptcoeff->viavel[0].x;
	pvia[11]=boptcoeff->viavel[0].y;
	pvia[12]=boptcoeff->viavel[0].z;
	pvia[13]=boptcoeff->viavel[0].v;
	pvia[14]=boptcoeff->viavel[0].w;
	pvia[15]=boptcoeff->viavel[1].x;
	pvia[16]=boptcoeff->viavel[1].y;
	pvia[17]=boptcoeff->viavel[1].z;
	pvia[18]=boptcoeff->viavel[1].v;
	pvia[19]=boptcoeff->viavel[1].w;

	for (k=0;k<20;k++)
	{
		sum=0.0;
		for (i=0;i<16;i++)
		{
			factor=pvia[k][i].value;
			if (factor!=0.0000)
			{
				for (j=0;j<pvia[k][i].numofparams;j++)
				{
					char tab = pvia[k][i].table[j];
					switch (tab) 
					{
					case 'f':
						factor *= f;
						break;
					case 'b':
						factor *= b;
						break;
					case 'p':
						factor *= p;
						break;
					case 'g':
						factor *= g;
						break;
					case 'l':
						factor *= l;
						break;
					case 'h':
						factor *= h;
						break;
					case 't':
						factor *= t;
						break;
					case 'r':
						factor *= r;
						break;
					case 'c':
					default:
						break;
					}
				}
				sum += factor;
			}
		}
		valvia[k]=sum;
	}
	viavectpos1.x=valvia[0];
	viavectpos1.absx=boptcoeff->viapos[0].x[0].ABS;
	viavectpos1.y=valvia[1];
	viavectpos1.absy=boptcoeff->viapos[0].y[0].ABS;
	viavectpos1.z=valvia[2];
	viavectpos1.absz=boptcoeff->viapos[0].z[0].ABS;
	viavectpos1.v=valvia[3];
	viavectpos1.absv=boptcoeff->viapos[0].v[0].ABS;
	viavectpos1.w=valvia[4];
	viavectpos1.absw=boptcoeff->viapos[0].w[0].ABS;
	viavectpos2.x=valvia[5];
	viavectpos2.absx=boptcoeff->viapos[1].x[0].ABS;
	viavectpos2.y=valvia[6];
	viavectpos2.absy=boptcoeff->viapos[1].y[0].ABS;
	viavectpos2.z=valvia[7];
	viavectpos2.absz=boptcoeff->viapos[1].z[0].ABS;
	viavectpos2.v=valvia[8];
	viavectpos2.absv=boptcoeff->viapos[1].v[0].ABS;
	viavectpos2.w=valvia[9];
	viavectpos2.absw=boptcoeff->viapos[1].w[0].ABS;
	viavecthast1.x=valvia[10];
	viavecthast1.y=valvia[11];
	viavecthast1.z=valvia[12];
	viavecthast1.v=valvia[13];
	viavecthast1.w=valvia[14];
	viavecthast2.x=valvia[15];
	viavecthast2.y=valvia[16];
	viavecthast2.z=valvia[17];
	viavecthast2.v=valvia[18];
	viavecthast2.w=valvia[19];
	
	trajopt(robot, ptrpath, pathidx, pathtype, loadgroup, boptcoeff->viatype, samplerate, boptcoeff->params.integer[0], boptcoeff->params.integer[0] , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1 , &viavectpos2, &viavecthast2, &startmacro, &endmacro, blendtype,lockv);
	ptrpath->maxTime*=boptcoeff->params.floating[3];
	return TRUE;
}

int expandBoptLoader(tmpnRobot *robot, tmpnPathItem *path) 
{
  tmpnPatternItem *fromPatternItem=NULL;
  tmpnPatternItem *toPatternItem=NULL;
  
  tmpnFrame *fromFrame=&path->handle.key.from.frame;
  tmpnFrame *toFrame=&path->handle.key.to.frame;

	// char *fromItem=path->handle.key.from.itemName;
	// char *toItem=path->handle.key.to.itemName;
  
  int fromLayer=-1;
  int toLayer=-1;
	
  if(path->handle.key.from.pattern!=NULL)
  {
    fromPatternItem=&path->handle.key.from.pattern->item[path->handle.key.from.cItem];
    fromLayer=fromPatternItem->layer; 
  }

  if(path->handle.key.to.pattern!=NULL)
  {
    toPatternItem=&path->handle.key.to.pattern->item[path->handle.key.to.cItem];
    toLayer=toPatternItem->layer; 
  }
	
  return expandPathBoptGeneric(robot
                       ,&path->pathdef
                       ,-1
                       ,-1
                       ,0
                       ,fromFrame
                       ,toFrame
                       ,NULL
                       ,NULL
                       ,0
                       ,path->handle.key.mode
                       ,path->handle.key.type
                       ,getBoptCoeff((tmpnWorkcell*)tworkcell));
  
  /*expandPathBoptGeneric(robot
                       ,&path->pathdef
                       ,fromLayer //encoder i mm
                       ,toLayer //encoder i mm
                       ,0
                       ,fromFrame
                       ,toFrame
                       ,fromItem //1 mm heigh
                       ,toItem //1 mm heigh
                       ,0
                       ,path->handle.key.mode
                       ,path->handle.key.type
                       ,getBoptCoeff((tmpnWorkcell*)tworkcell));*/
}

//********************************************************************
//*                                                                  *
//* handmade and can only be used to generate path's that moves      *
//* a bag from conveyorA to palletA in workcell 304 (Nyhuus)         *
//* bags can be Nyhuus10Kg and Nyhuus5Kg                             *
//********************************************************************
void copyFramesFromSTMtoRobot(void);
COMMANDSTRUCT *generateProgramNS(COMMANDSTRUCT *ptrcmd
                                ,tmpnRobot *robot
                                ,int *level
                                ,int layerHeightMM
                                ,int forceLayer
                                ,const char *ppscriptnameA)
{
  //         |C|
  //         |o|
  //         |n|
  //==gantry============
  //         |A| palletA
  //             -----
  //             |1|0|
  //             -----
  //             |3|2|
  //             -----
  char s[1024];
  int i,id=5100,iA,bagsPrLayer=7;
  tmpnFloat towerHight=400,difw;
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int toFrameIdx,fromFrameIdx;
  tmpnFrame *toFrame,*fromFrame;
  int exectime;
  COMMANDSTRUCT *start0,*stop0,*corner0,*corner1,*corner2,*corner3,*corner4,*corner5;

//  printf("*********  testMM=%d\n",testMM);
   
  ppscriptA = getPPScript(ppscriptnameA,(tmpnWorkcell*)tworkcell);
  bagsPrLayer=ppscriptA->itemsPrLayer;

  sprintf(s,"SUB %s",ppscriptnameA);
  ptrcmd=addCommandString(ptrcmd,s,level);
  
  copyFramesFromSTMtoRobot();

  iA=forceLayer*bagsPrLayer;
  for(i=0;i<bagsPrLayer;i++)
  {
    moveItem=&ppscriptA->item[iA++];
    moveItem->wcp.y=layerHeightMM;
    fromFrameIdx=getFrameIdx(moveItem->from,robot);
    fromFrame=&robot->m_frames.frame[fromFrameIdx];
    toFrameIdx=getFrameIdx(moveItem->to,robot);
    toFrame=&robot->m_frames.frame[toFrameIdx];
    exectime = 3500 + layerHeightMM;
    if(moveItem->wcp.z<=400.0) exectime+=500;
    if(exectime<3500) exectime=3500;
    sprintf(s,"PATH %s-%s-%d-%d id=%d,type=%d,time=%d,loadgroup=2,runbopt=0",moveItem->from,moveItem->to,forceLayer,moveItem->idx,id++,13,exectime);
    ptrcmd=addCommandString(ptrcmd,s,level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      start0=ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
//      ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 1",level);
      //UP
      corner0=ptrcmd=convertsplit(ptrcmd,0,0,0,0,0,0,moveItem->from
                          ,500,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+200,fromFrameIdx,toFrameIdx)),0,0,moveItem->wcp.w*0.5,0,moveItem->from
                          ,robot,-1,level,moveItem->from,"case",TRUE);
      //OVER/OUT + ROTATE
      corner1=ptrcmd=convertsplit(ptrcmd,500,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+200,fromFrameIdx,toFrameIdx)),0,0,moveItem->wcp.w*0.5,0,moveItem->from
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //PLACE 3xTCP
      corner2=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                            ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                            ,robot,3,level,moveItem->to,"case",TRUE);
      ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 2",level);
      //PLACE 3xTCP
      corner3=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,robot,3,level,moveItem->to,"case",TRUE);
      //UP
      corner4=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+300,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //BACK/IN + ROTATE
      corner5=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+300,moveItem->wcp.z,0,moveItem->wcp.w,0,moveItem->to
                  ,550,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+300,fromFrameIdx,toFrameIdx)),0,0,moveItem->wcp.w*0.5,0,moveItem->from
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //DOWN/IN
      stop0=ptrcmd=convertsplit(ptrcmd,550,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+300,fromFrameIdx,toFrameIdx)),0,0,moveItem->wcp.w*0.5,0,moveItem->from
                  ,0,0,0,0,0,0,moveItem->from
                  ,robot,-1,level,moveItem->from,"case",FALSE);
      stop0=ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorB 0,0,0,0,0,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"END",level);
//for at stoppe midt i loopet
    //blend corners
    blendCorner3(robot,start0);
    blendCorner3(robot,corner0);
    blendCorner3(robot,corner1);
    blendCorner3(robot,corner3->next);
    blendCorner3(robot,corner4);
    blendCorner3(robot,corner5);
    blendCorner3(robot,stop0->prev);


    ((POINTSTRUCT*)start0->data)->fp.w+=(((POINTSTRUCT*)start0->next->data)->fp.w-((POINTSTRUCT*)start0->data)->fp.w)*0.33;

    difw=(((POINTSTRUCT*)corner0->next->data)->fp.w-((POINTSTRUCT*)corner0->data)->fp.w);
    ((POINTSTRUCT*)corner0->prev->data)->fp.w+=difw*0.15;
    ((POINTSTRUCT*)corner0->data)->fp.w+=difw*0.37;
    ((POINTSTRUCT*)corner0->next->data)->fp.w+=difw*0.15;

    difw=(((POINTSTRUCT*)corner1->prev->data)->fp.w-((POINTSTRUCT*)corner1->data)->fp.w);
    ((POINTSTRUCT*)corner1->prev->data)->fp.w+=difw*0.15;
    ((POINTSTRUCT*)corner1->data)->fp.w+=difw*0.57;
    ((POINTSTRUCT*)corner1->next->data)->fp.w+=difw*0.15;
  
    difw=(((POINTSTRUCT*)corner4->next->data)->fp.w-((POINTSTRUCT*)corner4->data)->fp.w);
    ((POINTSTRUCT*)corner4->prev->data)->fp.w+=difw*0.15;
    ((POINTSTRUCT*)corner4->data)->fp.w+=difw*0.57;
    ((POINTSTRUCT*)corner4->next->data)->fp.w+=difw*0.15;

    difw=(((POINTSTRUCT*)corner5->prev->data)->fp.w-((POINTSTRUCT*)corner5->data)->fp.w);
    ((POINTSTRUCT*)corner5->prev->data)->fp.w+=difw*0.15;
    ((POINTSTRUCT*)corner5->data)->fp.w+=difw*0.37;
    ((POINTSTRUCT*)corner5->next->data)->fp.w+=difw*0.15;

   ((POINTSTRUCT*)stop0->data)->fp.w+=(((POINTSTRUCT*)stop0->prev->data)->fp.w-((POINTSTRUCT*)stop0->data)->fp.w)*0.33;

   ((POINTSTRUCT*)stop0->prev->data)->fp.y+=10.0;
   ((POINTSTRUCT*)stop0->data)->fp.y+=20.0;
   ((POINTSTRUCT*)stop0->next->data)->fp.y+=10.0;
  }
  ptrcmd=addCommandString(ptrcmd,"END",level);
  return ptrcmd;
}

