/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "genscript.h"
#include "cmd.h"


//#define BOPTTEST

#ifdef BOPTTEST
inline tmpnDouble uniform(tmpnDouble min, tmpnDouble max)
{
        static const tmpnDouble rmax=RAND_MAX+1.0;
        return (max-min)*(rand())/rmax+min;
}
#endif


COMMANDSTRUCT *expandPath401BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
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
  ptrcmd=addCommandString(ptrcmd,"END",level);
      
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}


//************************************************************************
//*                                                                      *
//* Automatically generates optimal path for In trajectories for Alfred  *
//* No check for collisions!!!                                           *
//*                                                                      *
//************************************************************************

void expandPath401BoptIn(tmpnRobot *robot, PATHSTRUCT *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
  int i;
#ifdef BOPTTEST
  srand((unsigned)time(NULL)); //initialiser random number generator
#endif
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int maxlayers;
  int itemsPrLayer; 
  tmpnItem* thisitem;
  tmpnFrame *toFrame,*fromFrame,*homeFrame,*baseFrame;
  tmpnVector toVector,fromVector,homeVector;
  tmpnVector zero = {0,0,0,0,0,0};
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  maxlayers = ppscriptA->layers;
  itemsPrLayer = ppscriptA->itemsPrLayer;
  moveItem=&ppscriptA->item[forceItem];
  fromFrame=&robot->m_frames.frame[getFrameIdx(moveItem->from,robot)];
  toFrame=&robot->m_frames.frame[getFrameIdx(moveItem->to,robot)];
  homeFrame=&robot->m_frames.frame[getFrameIdx("home",robot)];
  baseFrame=&robot->m_frames.frame[getFrameIdx("base",robot)];
  
  int blendtype=0;

  tmpnFloat maxheight = 500.0;
  tmpnFloat minheight = -500.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);


  thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  if (thisitem==NULL) return;
  printf("thisItem name: %s\n",thisitem->name);
  toVector.y += thisitem->my;

  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;
  
  fromVector.y += thisitem->gy + layer*thisitem->sy;    

  tmpnFloat bar = (fromVector.y-minheight)/(maxheight-minheight);
  tmpnFloat foo = (1.0-bar); //1.0 at bottom layer, 0.0 at top layer.
  
  printf("PPScript is %s. Height adjusting with fb(%f,%f)\n",ppscriptA->name,bar,foo);
  
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


  macroparamstruct nomacro={NOMACRO,0,0,0,0,0,0,0};
  
  //************************************

  
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.5),RADTODEG(3.5),RADTODEG(3.2),RADTODEG(5.236)}}; //rad/s

  tmpnJointsUnion ma = {{MTOMM(6.0),RADTODEG(24.44),RADTODEG(24.96),RADTODEG(18),RADTODEG(10)}};             //rad/s/s 
  
  tmpnVector viavectpos1={0,0,0,0,0,0};
  tmpnVector viavecthast1={0,0,0,0,0,0};
  
  tmpnVector viavectpos2={0,0,0,0,0,0};
  tmpnVector viavecthast2={0,0,0,0,0,0};
 
#ifdef BOPTTEST
  float maxtime=4500;
  tmpnVector opt={0,0,0,0,0,0};
  for (i=0;i<500;i++)
  {
#endif
    
#ifndef BOPTTEST
    fromVector.x=278;
    fromVector.y=-115;
#else
    fromVector.x=uniform(100.0,350.0);
    fromVector.y=uniform(-160.0,0.0);
#endif
    fromVector.z=1000.0;
    fromVector.v=90.0;
    fromVector.w=0.0;
    fromVector.u=0.0;
    
    toVector.x=fromVector.x+650;
    toVector.y=fromVector.y+750;
    toVector.z=fromVector.z;
    toVector.v=fromVector.v;
    toVector.w=0.0;
    toVector.u=0.0;

    /*******************/
    viavectpos1.x =0.0; 
    viavectpos1.y =600;
    viavectpos1.z =0.0; 
    
    viavecthast1.x=24.0; 
    viavecthast1.y=100; 
    viavecthast1.z=0.0; 
    /*******************/
    viavectpos2.x =-50; 
    viavectpos2.y =100; 
    viavectpos2.z =0.0; 
    
    viavecthast2.x=100; 
    viavecthast2.y=-200; 
    viavecthast2.z=0.0; 
    /*******************/
  printf("tmpnVector fromVector={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees\n",fromVector.x,fromVector.y,fromVector.z,fromVector.v,fromVector.w);
  printf("tmpnVector toVector={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees\n",toVector.x,toVector.y,toVector.z,toVector.v,toVector.w);
#ifdef BOPTTEST
    trajopt(robot, ptrpath, moveItem->idx, 20, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&nomacro,&nomacro,blendtype);
    /*********************/
    if(ptrpath->tpathdef.maxTime<maxtime) {
      maxtime=ptrpath->tpathdef.maxTime;
      opt=fromVector;
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                maxtime: %f\n",maxtime);
    }
  }

 printf("tmpnVector opt={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees\n",opt.x,opt.y,opt.z,opt.v,opt.w); 
 printf("//maxtime: %f\n",maxtime);
 fromVector=opt;
   toVector.x=fromVector.x+650;
    toVector.y=fromVector.y;
    toVector.z=fromVector.z;
    toVector.v=fromVector.v;
    toVector.w=0.0;
    toVector.u=0.0;

    /*******************/
    viavectpos1.x =10; 
    viavectpos1.y =70;
    viavectpos1.z =0.0; 
    
    viavecthast1.x=30; 
    viavecthast1.y=140; 
    viavecthast1.z=0.0; 
    /*******************/
    viavectpos2.x =-10; 
    viavectpos2.y =70; 
    viavectpos2.z =0.0; 
    
    viavecthast2.x=30; 
    viavecthast2.y=-140; 
    viavecthast2.z=0.0; 
    /*******************/
    exit(0);
#endif
    trajopt(robot, ptrpath, moveItem->idx, 20, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&nomacro,&nomacro,blendtype);
}


