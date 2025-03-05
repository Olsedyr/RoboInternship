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


COMMANDSTRUCT *expandPath307BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
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
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 ConveyorIn ST_PAUSE",level);
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
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 ConveyorIn ST_RESUME",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}

COMMANDSTRUCT *expandPath307BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
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

//************************************************************************
//*                                                                      *
//* Automatically generates optimal path for In trajectories for 307     *
//* No check for collisions!!!                                           *
//*                                                                      *
//************************************************************************

void expandPath307BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
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

  tmpnFloat maxheight = 2150.0;
  tmpnFloat minheight = 310.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);


  thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  if (thisitem==NULL) return;
  printf("thisItem name: %s\n",thisitem->name);
  toVector.y += thisitem->my;

  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;
  
  fromVector.y += thisitem->gy + layer*thisitem->sy;    

  tmpnFloat hori=1.0;
  if (!(moveItem->idx%2)) hori=0.0;

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

  tmpnFloat macrolen = 190.0-thisitem->my;

  macroparamstruct nomacro={NOMACRO,0,0,0,0,0,0,0};
  macroparamstruct uplinemacro={UPLINE,0,0,0,50,0,0.300,1};
  macroparamstruct uplinemacro2={UPLINE,0,0,0,macrolen,0,0.005*macrolen,1};
  macroparamstruct downlinemacro={DOWNLINE,0,0,0,macrolen,0,0.006*macrolen,0};
  macroparamstruct downlinemacro2={DOWNLINE,0,0,0,80,0,0.300,0};
  
  //************************************
  
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //rad/s
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  if (ptrpath->pathtype==20) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
    
    tmpnVector viavectpos4={0,465*bar*bar,20*bar*bar,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast4={0,322*bar*bar,43*bar*bar,0,0,0}; //cartesian mm and degrees
  
    // viapoints with respect to fromFrame:
    viavectpos.x=-22;
    viavectpos.y=101+foo*foo*99+foo*foo*foo*foo*100;
    viavectpos.z=-310+foo*foo*80;
    
    viavecthast.x=12;
    viavecthast.y=-10-foo*foo*50-foo*foo*foo*foo*70;
    viavecthast.z=260-foo*foo*150;
  
   if (bar>=0.68) {
      trajopt(robot, ptrpath, moveItem->idx, 20, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &viavectpos4, &viavecthast4, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
    }
   else {
     trajopt(robot, ptrpath, moveItem->idx, 20, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
   }
  }
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  else if (ptrpath->pathtype==21) {

    //startvia for placepath
    tmpnVector viavectpos1={0,0,0,0,0,0};
    tmpnVector viavecthast1={0,0,0,0,0,0};
    
    //endvia for placepath
    tmpnVector viavectpos2={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast2={0,0,0,0,0,0}; //cartesian mm and degrees
    
    viavectpos1.x=-20;
    viavectpos1.y=152+foo*50+foo*foo*40+foo*foo*foo*foo*80;
    viavectpos1.z=-80-bar*bar*bar*250-100*hori*bar;
    
    viavecthast1.x=-12;
    viavecthast1.y=30+foo*35+foo*foo*50+foo*foo*foo*foo*50;
    viavecthast1.z=-70-bar*bar*bar*180-20*hori*bar;
    
    // viapoint with respect to toFrame:
    viavectpos2.x=-130;
    viavectpos2.y=230+bar*bar*bar*400+280*hori*bar;
    viavectpos2.z=foo*foo*foo*40;
    
    viavecthast2.x=75;
    viavecthast2.y=-120-bar*bar*bar*145-56*hori*bar;
    viavecthast2.z=-foo*foo*foo*35;
    
    tmpnJointsUnion ma = {{MTOMM(4.0),RADTODEG(2.0),RADTODEG(4.0),RADTODEG(5.0),RADTODEG(5.0)}}; //rad/s/s 
    
    trajopt(robot, ptrpath, moveItem->idx, 21, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&downlinemacro,blendtype);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==22) {
    tmpnJointsUnion ma = {{MTOMM(4.2),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}}; //rad/s/s     
    
    tmpnVector viavectpos3={-8, 60, -20, 0.000000, 0.000000, 0.00000}; //cartesian mm and degrees
    tmpnVector viavecthast3={-6, 33, -30, 0.000000, 0.000000, 0.00000}; //cartesian mm and degrees per sec.
//maxtime: 1075.000000

#ifndef BOPTTEST
    trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,blendtype);
#else
    tmpnFloat maxtime=1200; 
    tmpnFloat xdlim=3;
    tmpnFloat ydlim=15;
    tmpnFloat zdlim=10;
    tmpnFloat hastdlim=10;
    
    tmpnVector viavectopt=viavectpos3;
    tmpnVector viahastopt=viavecthast3;
    int i;
    for (i=0;i<500;i++) {
      //      viavectpos3.x=viavectopt.x+uniform(-xdlim,xdlim);
      viavectpos3.y=viavectopt.y+uniform(-ydlim,ydlim);
      viavectpos3.z=viavectopt.z+uniform(-zdlim,zdlim);
      //   viavecthast3.x=viahastopt.x+uniform(-hastdlim/2.0,hastdlim/2.0);
      viavecthast3.y=viahastopt.y+uniform(-hastdlim,hastdlim);
      viavecthast3.z=viahastopt.z+uniform(-hastdlim,hastdlim);
      trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,blendtype);
      if(ptrpath->maxTime<maxtime) {
	maxtime=ptrpath->maxTime;
	viavectopt=viavectpos3;
	viahastopt=viavecthast3;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                maxtime: %f\n",maxtime);
	printf("tmpnVector viavectpos3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees\n",viavectopt.x,viavectopt.y,viavectopt.z,viavectopt.v,viavectopt.w);
	printf("tmpnVector viavecthast3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees per sec.\n",viahastopt.x,viahastopt.y,viahastopt.z,viahastopt.v,viahastopt.w);
	printf("//maxtime: %f\n",maxtime);
      }
      if (!(i%20)) {
	xdlim*=0.89;
	ydlim*=0.89;
	zdlim*=0.89;
	hastdlim*=0.89;
      }
    }
    printf("tmpnVector viavectpos3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees\n",viavectopt.x,viavectopt.y,viavectopt.z,viavectopt.v,viavectopt.w);
    printf("tmpnVector viavecthast3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees per sec.\n",viahastopt.x,viahastopt.y,viahastopt.z,viahastopt.v,viahastopt.w);
    printf("//maxtime: %f\n",maxtime);
    trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectopt, &viahastopt, &zero, &zero,&uplinemacro2,&nomacro,blendtype);
#endif //BOPTTEST 
  }
  //*********************
}



//***********************************************************************
//*                                                                     *
//* Automatically generates optimal path for Out trajectories of 307    *
//* No check for collisions!!!                                          *
//*                                                                     *
//***********************************************************************

void expandPath307BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
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
  
  tmpnFloat maxheight=1850.0;
  tmpnFloat minheight=320.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);

  thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  if (thisitem==NULL) return;
  printf("thisItem name: %s\n",thisitem->name);
  
  fromVector.y += thisitem->gy;

  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;

  toVector.y += thisitem->my + layer*thisitem->sy;

    
  //tmpnFloat bar = barscale*layer/(1.0*(maxlayers-1)); //0.0 at bottom layer, 1.0 at top layer.
  tmpnFloat bar = (toVector.y-minheight)/(maxheight-minheight);
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
  
  
  tmpnFloat macrolen = 175.0-thisitem->gy;
  
  macroparamstruct nomacro={NOMACRO,0,0,0,0,0,0,0};
  macroparamstruct uplinemacro={UPLINE,0,0,0,macrolen,0,0.005*macrolen,1};
  macroparamstruct uplinemacro2={UPLINE,0,0,0,50,0,0.3,2};
  macroparamstruct downlinemacro={DOWNLINE,0,0,0,macrolen,0,0.005*macrolen,0};
  
  tmpnFloat offset=0.0;
  if (!(moveItem->idx%2)) offset=-1.6;
  else offset=1.6;
  macroparamstruct spiralmacro={SPIRAL,12*(1-foo*foo*foo*foo),0,offset*bar,12.0,2.0,1.450*(1-foo*foo*foo)+0.4,0};
  

  //************************************
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}};  //rad/s
 
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************

  if (ptrpath->pathtype==23) {  
    tmpnJointsUnion ma = {{MTOMM(4.2),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s   
    
    
    tmpnVector viavectpos={6.276662, 51.698673, 11.537301, 0.000000, 0.000000, 0.000000}; //cartesian mm and degrees
    tmpnVector viavecthast={-12.279048, -63.591763, -3.418611, 0.000000, 0.000000, 0.000000}; //cartesian mm and degrees per sec.
    //maxtime: 1.133245
  

#ifndef BOPTTEST
    trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro,blendtype);
#else
    tmpnFloat maxtime=1500; 
    tmpnFloat ydlim=15;
    tmpnFloat zdlim=10;
    tmpnFloat xdlim=3;
    tmpnFloat hastdlim=6;
    
    tmpnVector viavectopt=viavectpos;
    tmpnVector viahastopt=viavecthast;
    int i;
    int change=0;
    for (i=0;i<700;i++) {
     viavectpos.x=viavectopt.x+uniform(-xdlim,xdlim); 
     viavectpos.y=viavectopt.y+uniform(-ydlim,ydlim);
     viavectpos.z=viavectopt.z+uniform(-zdlim,zdlim);
     
     viavecthast.x=viahastopt.x+uniform(-hastdlim/2.0,hastdlim/2.0);
     viavecthast.y=viahastopt.y+uniform(-hastdlim,hastdlim);
     viavecthast.z=viahastopt.z+uniform(-hastdlim,hastdlim);
     
     float trajtime=trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro,blendtype);
      if(trajtime<maxtime) {
	maxtime=trajtime;
	viavectopt=viavectpos;
	viahastopt=viavecthast;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                maxtime: %f\n",maxtime);
	change++;
      }
      if (!(i%25)) {
	if (!change) {
	  xdlim*=0.81;
	  ydlim*=0.81;
	  zdlim*=0.81;
	  hastdlim*=0.81;
	}
	else
	  change=0;
      }
    }
    printf("tmpnVector viavectpos={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees\n",viavectopt.x,viavectopt.y,viavectopt.z,viavectopt.v,viavectopt.w);
    printf("tmpnVector viavecthast={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees per sec.\n",viahastopt.x,viahastopt.y,viahastopt.z,viahastopt.v,viahastopt.w);
    printf("maxtime: %f, xdlim=%f,ydlim=%f,zdlim=%f,hastdlim=%f\n",maxtime,xdlim,ydlim,zdlim,hastdlim);
    trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectopt, &viahastopt,&nomacro,&downlinemacro,blendtype);
#endif //BOPTTEST
  }  
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  else if (ptrpath->pathtype==24) {
    
    tmpnJointsUnion ma = {{MTOMM(3.6),RADTODEG(1.8),RADTODEG(4),RADTODEG(5),RADTODEG(5)}};             //rad/s/s   
    
    //startvia for placepath
    tmpnVector viavectpos1={0,0,0,0,0,0};
    tmpnVector viavecthast1={0,0,0,0,0,0};
    
    //endvia for placepath
    tmpnVector viavectpos2={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast2={0,0,0,0,0,0}; //cartesian mm and degrees
    
    // viapoints with respect to fromFrame:
    viavectpos1.x=-260;
    viavectpos1.y=190+550*bar*bar*bar+180*bar*bar;
    viavectpos1.z=-30;

    viavecthast1.x=-160;   
    viavecthast1.y=95+80*bar*bar*bar+20*bar*bar+15*foo*foo*foo*foo;
    viavecthast1.z=-25+20*bar*bar*bar*bar;
 
    // viapoint with respect to toFrame:
    viavectpos2.x=-30;
    viavectpos2.y=200+bar*bar*bar*100+100*foo*foo*foo*foo;
    viavectpos2.z=50+bar*bar*130;
    
    viavecthast2.x=17;
    viavecthast2.y=-100-bar*bar*bar*50-40*foo*foo*foo*foo;
    viavecthast2.z=-9-55*bar*bar;
    
    trajopt(robot, ptrpath, moveItem->idx, 24, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&spiralmacro,blendtype);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==25) {
    
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};  //rad/s/s   
    
    //startvia for homepath
    tmpnVector viavectpos3={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast3={0,0,0,0,0,0}; //cartesian mm and degrees

    tmpnVector viavectpos4={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast4={0,0,0,0,0,0}; //cartesian mm and degrees
    
    viavectpos3.x=-80;
    viavectpos3.y=210+foo*foo*foo*120+bar*bar*bar*bar*40;
    viavectpos3.z=90+bar*bar*bar*bar*150;
    
    viavecthast3.x=-45;
    viavecthast3.y=80+foo*foo*80+bar*bar*bar*bar*70;
    viavecthast3.z=80+bar*bar*bar*bar*100;

    viavectpos4.x=-60;
    viavecthast4.x=34;
    viavectpos4.z=-8;
    viavecthast4.z=6;

    if (bar>=0.65) 
    {  
      viavectpos4.y=250;    
      viavecthast4.y=-140;
    }
      trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &viavectpos4, &viavecthast4,&uplinemacro2,&nomacro,blendtype);
      /*  }
    else {
      trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,blendtype);
      }*/
  }
  //*********************
}

