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

COMMANDSTRUCT *generateProgramAlfredIn(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int forceLayer, int forceItem, const char *ppscriptname)
{
  return NULL;
}

COMMANDSTRUCT *generateProgramAlfredOut(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int forceLayer, int forceItem, const char *ppscriptname)
{
  return NULL;
}

COMMANDSTRUCT *expandSubPathAlfredOut(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup)
{
  return NULL;
}

COMMANDSTRUCT *expandSubPathAlfredIn(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup)
{
  return NULL;
} 

COMMANDSTRUCT *expandPathAlfredBoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
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
  
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,20,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);  
  ptrcmd=addCommandString(ptrcmd,"END",level);
    
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,21,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  ptrcmd=addCommandString(ptrcmd,"COUNTER cAItems += 1",level);
       
  //********************************************************************
  //* Home                                                             *
  //********************************************************************

  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,22,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 Sektor20 ST_RESET",level);  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}

COMMANDSTRUCT *expandPathAlfredBoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
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
  
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,23,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);  
  ptrcmd=addCommandString(ptrcmd,"END",level);
    
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,24,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems += 1",level);
  //  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 Sektor36 ST_RESET",level);        
  //********************************************************************
  //* Home                                                             *
  //********************************************************************

  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,25,0,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}


//************************************************************************
//*                                                                      *
//* Automatically generates optimal path for In trajectories for Alfred  *
//* No check for collisions!!!                                           *
//*                                                                      *
//************************************************************************

void expandPathAlfredBoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
#ifdef BOPTTEST
  srand((unsigned)time(NULL)); //initialiser random number generator
#endif
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int maxlayers;
  int itemsPrLayer; 
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
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);

  tmpnFloat hori=1.0;
  if (!(moveItem->idx%2)) hori=0.0;

  int layer = (maxlayers-1) - (moveItem->idx/itemsPrLayer);
  tmpnFloat bar = layer/(1.0*(maxlayers-1)); //0.0 at bottom layer, 1.0 at top layer.
  tmpnFloat foo = 1.0-bar; //1.0 at bottom layer, 0.0 at top layer.

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
  macroparamstruct uplinemacro={UPLINE,0,0,0,50,0,0.300,1};
  macroparamstruct uplinemacro2={UPLINE,0,0,0,50,0,0.250,1};
  macroparamstruct downlinemacro={DOWNLINE,0,0,0,10,0,0.100,0};
  macroparamstruct downlinemacro2={DOWNLINE,0,0,0,80,0,0.300,0};
  
  //************************************
  
  float samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //rad/s
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  if (ptrpath->pathtype==20) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 

    //startvia for pickpath
    tmpnVector viavectpos4={0,0,0,0,0,0}; 
    tmpnVector viavecthast4={0,0,0,0,0,0}; 
    
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
    
    if (bar>0.5) {
      viavectpos4.y=150*bar*bar;
      viavectpos4.z=15*bar+100*foo*foo*foo;
      
      viavecthast4.y=120*bar*bar;
      viavecthast4.z=25*bar*bar+15*hori+100*foo*foo*foo+10;
    }

    // viapoints with respect to fromFrame:
    viavectpos.y=100+600*foo*foo;
    viavectpos.z=-280*bar-50*hori;
    
    viavecthast.y=-20-180*foo*foo;
    viavecthast.z=150*bar+40*hori*bar+50+20*hori;
  
    trajopt(robot, ptrpath, moveItem->idx, 20, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &viavectpos4, &viavecthast4, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,1);
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
    
    viavectpos1.y=150+foo*foo*foo*500;
    viavectpos1.z=-30-80*bar-40*bar*bar*bar*bar-30*hori*bar-30*hori-30*foo*foo*foo;
    
    viavecthast1.y=60+15*hori+20*bar*bar*bar*bar*hori+foo*foo*foo*100;
    viavecthast1.z=-40-bar*70-30*hori*bar-50*bar*bar*bar*bar*hori-35*hori;
    
    // viapoint with respect to toFrame:
    viavectpos2.y=220+140*bar*bar*bar*bar;
    viavectpos2.z=10+10*foo*foo;
    
    viavecthast2.y=-90-100*bar*bar*bar*bar+80*foo*foo;
    viavecthast2.z=-25-15*hori-40*foo*foo;

    tmpnJointsUnion ma = {{MTOMM(3.6),RADTODEG(1.8),RADTODEG(4),RADTODEG(5),RADTODEG(5)}};             //rad/s/s   
    
    trajopt(robot, ptrpath, moveItem->idx, 21, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&downlinemacro,1);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==22) {
    tmpnJointsUnion ma = {{MTOMM(4.2),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}}; //rad/s/s     
    
    tmpnVector viavectpos3={0.000000, 50.837223, -20.979675, 0.000000, 0.000000, 0.00000}; //cartesian mm and degrees
    tmpnVector viavecthast3={0.000000, 20.703159, -20.623161, 0.000000, 0.000000, 0.00000}; //cartesian mm and degrees per sec.
    //maxtime: 902.000000
    
#ifndef BOPTTEST
    trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,1);
#else
    tmpnFloat maxtime=1200; 
    tmpnFloat xdlim=5;
    tmpnFloat ydlim=15;
    tmpnFloat zdlim=10;
    tmpnFloat hastdlim=10;
    
    tmpnVector viavectopt=viavectpos3;
    tmpnVector viahastopt=viavecthast3;
    int i;
    for (i=0;i<500;i++) {
      viavectpos3.x=viavectopt.x+uniform(-xdlim,xdlim);
      viavectpos3.y=viavectopt.y+uniform(-ydlim,ydlim);
      viavectpos3.z=viavectopt.z+uniform(-zdlim,zdlim);
      viavecthast3.x=viahastopt.x+uniform(-hastdlim/10.0,hastdlim/10.0);
      viavecthast3.y=viahastopt.y+uniform(-hastdlim,hastdlim);
      viavecthast3.z=viahastopt.z+uniform(-hastdlim,hastdlim);
      trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,1);
      if(ptrpath->maxTime<maxtime) {
	maxtime=ptrpath->maxTime;
	viavectopt=viavectpos3;
	viahastopt=viavecthast3;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                maxtime: %f\n",maxtime);
	printf("tmpnVector viavectpos3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees\n",viavectopt.x,viavectopt.y,viavectopt.z,viavectopt.v,viavectopt.w);
	printf("tmpnVector viavecthast3={%f, %f, %f, %f, %f, 0.00000}; //cartesian mm and degrees per sec.\n",viahastopt.x,viahastopt.y,viahastopt.z,viahastopt.v,viahastopt.w);
	printf("maxtime: %f\n",maxtime);
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
    printf("maxtime: %f\n",maxtime);
    trajopt(robot, ptrpath, moveItem->idx, 22, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectopt, &viahastopt, &zero, &zero,&uplinemacro2,&nomacro,1);
#endif //BOPTTEST 
  }
  //*********************
}



//***********************************************************************
//*                                                                     *
//* Automatically generates optimal path for Out trajectories of Alfred *
//* No check for collisions!!!                                          *
//*                                                                     *
//***********************************************************************

void expandPathAlfredBoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
#ifdef BOPTTEST
  srand((unsigned)time(NULL)); //initialiser random number generator
#endif
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int maxlayers;
  int itemsPrLayer;
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
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);


  int layer = moveItem->idx/itemsPrLayer;
  tmpnFloat bar = layer/(1.0*(maxlayers-1)); //0.0 at bottom layer, 1.0 at top layer.
  tmpnFloat foo = 1.0-bar; //1.0 at bottom layer, 0.0 at top layer.

  tmpnFloat hori=1.0;
  if (!(moveItem->idx%2)) hori=0.0;
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
  macroparamstruct uplinemacro={UPLINE,0,0,0,50,0,0.3,1};
  macroparamstruct uplinemacro2={UPLINE,0,0,0,50,0,0.3,2};
  macroparamstruct downlinemacro={DOWNLINE,0,0,0,50,0,0.28,0};
  
  tmpnFloat offset=0.0;
  if (!(moveItem->idx%2)) offset=-1.6;
  else offset=1.6;
  macroparamstruct spiralmacro={SPIRAL,12*(1-foo*foo*foo*foo),0,offset*bar,12.0,2.0,1.450*(1-foo*foo*foo)+0.4,0};
  

  //************************************
  float samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}};  //rad/s
 
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************

  if (ptrpath->pathtype==23) {  
    tmpnJointsUnion ma = {{MTOMM(4.2),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s   
    
    tmpnVector viavectpos={0.00, 45.928532, 16.616906, 0.000000, 0.000000, 0.000000}; //cartesian mm and degrees
    tmpnVector viavecthast={0.00, -20.962490, -5.480989, 0.000000, 0.000000, 0.000000}; //cartesian mm and degrees per sec.
    //maxtime: 999.000000

#ifndef BOPTTEST
    trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro,1);
#else
    tmpnFloat maxtime=1230; 
    tmpnFloat ydlim=15;
    tmpnFloat zdlim=10;
    tmpnFloat xdlim=4;
    tmpnFloat hastdlim=10;
    
    tmpnVector viavectopt=viavectpos;
    tmpnVector viahastopt=viavecthast;
    int i;
    for (i=0;i<500;i++) 
    {
      viavectpos.x=viavectopt.x+uniform(-xdlim,xdlim); 
      viavectpos.y=viavectopt.y+uniform(-ydlim,ydlim);
      viavectpos.z=viavectopt.z+uniform(-zdlim,zdlim);
      
      viavecthast.x=viahastopt.x+uniform(-hastdlim/10.0,hastdlim/10.0);
      viavecthast.y=viahastopt.y+uniform(-hastdlim,hastdlim);
      viavecthast.z=viahastopt.z+uniform(-hastdlim,hastdlim);
      
      trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro,1);
      if(ptrpath->maxTime<maxtime) {
	maxtime=ptrpath->maxTime;
	viavectopt=viavectpos;
	viahastopt=viavecthast;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                maxtime: %f\n",maxtime);
      }
      if (!(i%20)) {
	xdlim*=0.89;
	ydlim*=0.89;
	zdlim*=0.89;
	hastdlim*=0.89;
      }
    }
    printf("tmpnVector viavectpos={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees\n",viavectopt.x,viavectopt.y,viavectopt.z,viavectopt.v,viavectopt.w);
    printf("tmpnVector viavecthast={%f, %f, %f, %f, %f, 0.000000}; //cartesian mm and degrees per sec.\n",viahastopt.x,viahastopt.y,viahastopt.z,viahastopt.v,viahastopt.w);
    printf("maxtime: %f\n",maxtime);
    trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectopt, &viahastopt,&nomacro,&downlinemacro,1);
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
    viavectpos1.y=200+300*bar*bar*bar;
    viavectpos1.z=-80-70*foo*foo*foo*foo;

    viavecthast1.y=85+80*bar*bar*bar+15*foo*foo*foo*foo;
    viavecthast1.z=-110-100*foo*foo*foo*foo+45*bar*bar*bar*bar;
 
    // viapoint with respect to toFrame:
    viavectpos2.y=220+bar*bar*bar*80+180*foo*foo*foo*foo;
    viavectpos2.z=50+bar*bar*80+80*(1-hori);
    
    viavecthast2.y=-80-bar*bar*bar*30-80*foo*foo*foo*foo-100*hori*foo*foo*foo*foo;
    viavecthast2.z=-10-30*bar*bar-80*(1-hori);
    
    trajopt(robot, ptrpath, moveItem->idx, 24, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&spiralmacro,1);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==25) {
    
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};  //rad/s/s   
    //startvia for homepath
    tmpnVector viavectpos3={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast3={0,0,0,0,0,0}; //cartesian mm and degrees
    
    viavectpos3.y=140+foo*foo*foo*foo*410+100*(1-hori)+foo*foo*foo*200*hori;
    viavectpos3.z=50+bar*bar*bar*bar*120+90*(1-hori)+bar*bar*100;
    
    viavecthast3.y=20+foo*foo*foo*130+bar*bar*bar*bar*60+60*(1-hori);
    viavecthast3.z=60+bar*bar*bar*bar*100+130*(1-hori)+hori*bar*130;

     trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos3, &viavecthast3, &zero, &zero,&uplinemacro2,&nomacro,1);
  }
  //*********************
}
