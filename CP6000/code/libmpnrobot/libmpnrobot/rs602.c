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


COMMANDSTRUCT *expandPath602BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  moveItem=&ppscriptA->item[forceItem];
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 WaitTime ST_BEGINWAIT",level);
  ptrcmd=addCommandString(ptrcmd,"WAITEVENT 1 WaitTime ST_READY",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,23,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level); 
  ptrcmd=addCommandString(ptrcmd,"END",level);
      
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,24,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  ptrcmd=addCommandString(ptrcmd,"COUNTER cAItems += 1",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems -= 1",level);
      
  //********************************************************************
  //* Home                                                             *
  //********************************************************************

  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,25,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}

COMMANDSTRUCT *expandPath602BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  moveItem=&ppscriptA->item[forceItem];

  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 WaitTime ST_BEGINWAIT",level);
  ptrcmd=addCommandString(ptrcmd,"WAITEVENT 1 WaitTime ST_READY",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  sprintf(s,"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1",moveItem->from,moveItem->idx,moveItem->idx,23,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);  
   ptrcmd=addCommandString(ptrcmd,"END",level);

  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,24,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER cAItems -= 1",level);
  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems += 1",level);

  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  
  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,25,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}

//************************************************************************
//*                                                                      *
//* Automatically generates optimal path for In trajectories for 602     *
//* No check for collisions!!!                                           *
//*                                                                      *
//************************************************************************

void expandPath602BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
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

  tmpnFloat maxheight = 2200.0;
  tmpnFloat minheight = 300.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);


  thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  if (thisitem==NULL) return;
  printf("thisItem name: %s\n",thisitem->name);

  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;
  
  fromVector.y += thisitem->gy + layer*thisitem->sy;    
  toVector.y += thisitem->my + (maxlayers-layer-1)*thisitem->sy; 
  tmpnFloat hori=1.0;
  if (!(moveItem->idx%2)) hori=0.0;

  tmpnFloat hori2=0.0;
  if (!(moveItem->idx%2)) hori2=1.0;
  
  tmpnFloat bar = (fromVector.y-minheight)/(maxheight-minheight);
  tmpnFloat foo = (1.0-bar); //1.0 at bottom layer, 0.0 at top layer.

  tmpnFloat bar2 = (toVector.y-minheight)/(maxheight-minheight);
  tmpnFloat foo2 = (1.0-bar2); //1.0 at bottom layer, 0.0 at top layer.

  printf("PPScript is %s. Height adjusting with fb(%f,%f) and fb2(%f,%f)\n",ppscriptA->name,bar,foo,bar2,foo2);
  
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
  macroparamstruct uplinemacro3={UPLINE,0,0,0,80,0,0.300,0};
  macroparamstruct downlinemacro2={DOWNLINE,0,0,0,80,0,0.300,0};


  tmpnFloat offset=0.0;
  if (!(moveItem->idx%2)) offset=-1.6;
  else offset=1.6;
  macroparamstruct spiralmacro={SPIRAL,12*(1-foo2*foo2*foo2*foo2),0,offset*bar2,12.0,2.0,1.450*(1-foo2*foo2*foo2)+0.4,0};
  //************************************
  
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //rad/s
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  if (ptrpath->pathtype==23) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
  
    tmpnVector viavectpos4={0,0,0,0,0,0};
    tmpnVector viavecthast4={0,0,0,0,0,0};

    viavectpos4.y = 400*bar*bar+200*hori*bar;
    viavectpos4.z = 10+20*bar*bar; 
    
    viavecthast4.y= 200*bar*bar+100*hori*bar;
    viavecthast4.z= 10+40*bar*bar+20*hori*bar; 
  
    // viapoints with respect to fromFrame:
    //viavectpos.x=-22;
    viavectpos.y=100+foo*foo*70+foo*foo*foo*foo*220;
    viavectpos.z=-310+foo*foo*60;
    
    //viavecthast.x=12;
    viavecthast.y=-foo*foo*45-foo*foo*foo*foo*80;
    viavecthast.z=200-foo*foo*40+60*hori;
    
   if (bar>=0.58) {
     trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &viavectpos4, &viavecthast4, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
   }
   else {
     trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
   }
  }
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  else if (ptrpath->pathtype==24) {

    //startvia for placepath
    tmpnVector viavectpos1={0,0,0,0,0,0};
    tmpnVector viavecthast1={0,0,0,0,0,0};
    
    //endvia for placepath
    tmpnVector viavectpos2={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast2={0,0,0,0,0,0}; //cartesian mm and degrees
        
    //viavectpos1.x=-20;
    viavectpos1.y=152+foo*50+foo*foo*40+foo*foo*foo*foo*150;
    viavectpos1.z=-80-bar*bar*bar*230-110*hori*bar-50*bar;
    
    //viavecthast1.x=-12;
    viavecthast1.y=30+foo*60+foo*foo*50+foo*foo*foo*foo*150;
    viavecthast1.z=-140-bar*bar*bar*200-80*hori*bar;

    // viapoint with respect to toFrame:
    viavectpos2.y=150+bar2*bar2*bar2*100+150*foo2*foo2*foo2;
    viavectpos2.z=40+bar2*bar2*150+70*foo2+bar2*bar2*bar2*400;
    
    viavecthast2.y=-110-bar2*bar2*bar2*50-120*foo2*foo2;
    viavecthast2.z=-30-160*bar2*bar2-100*foo2-bar2*bar2*bar2*200;
    
    tmpnJointsUnion ma = {{MTOMM(4.0),RADTODEG(2.0),RADTODEG(4.5),RADTODEG(5),RADTODEG(5)}};             //rad/s/s 
    trajopt(robot, ptrpath, moveItem->idx, 24, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&spiralmacro,blendtype);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==25) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
  
    tmpnVector viavectpos4={0,0,0,0,0,0};
    tmpnVector viavecthast4={0,0,0,0,0,0};

    viavectpos4.y = 400*bar2*bar2+200*hori2*bar2;
    viavectpos4.z = -10-20*bar2*bar2; 
    
    viavecthast4.y= -200*bar2*bar2-100*hori2*bar2;
    viavecthast4.z= 10+40*bar2*bar2+20*hori2*bar2; 
  
    // viapoints with respect to toFrame:
    viavectpos.y=100+foo2*foo2*70+foo2*foo2*foo2*foo2*220;
    viavectpos.z=310-foo2*foo2*60;
   
    viavecthast.y=foo2*foo2*45+foo2*foo2*foo2*foo2*80;
    viavecthast.z=200-foo2*foo2*40+50*hori2;
    
    if (bar2>=0.58) {
      trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos, &viavecthast, &viavectpos4, &viavecthast4,&uplinemacro3,&nomacro,blendtype);
    }
   else {
     trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos, &viavecthast, &zero, &zero,&uplinemacro3,&nomacro,blendtype);
   }


  }
  //*********************
}



//***********************************************************************
//*                                                                     *
//* Automatically generates optimal path for Out trajectories of 602    *
//* No check for collisions!!!                                          *
//*                                                                     *
//***********************************************************************

void expandPath602BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup) 
{
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

  tmpnFloat maxheight = 2200.0;
  tmpnFloat minheight = 300.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);


  thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  if (thisitem==NULL) return;
  printf("thisItem name: %s\n",thisitem->name);

  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;
  
  fromVector.y += thisitem->gy + layer*thisitem->sy;    
  toVector.y += thisitem->my + (maxlayers-layer-1)*thisitem->sy; 
  tmpnFloat hori=1.0;
  if (!(moveItem->idx%2)) hori=0.0;

  tmpnFloat hori2=0.0;
  if (!(moveItem->idx%2)) hori2=1.0;
  
  tmpnFloat bar = (fromVector.y-minheight)/(maxheight-minheight);
  tmpnFloat foo = (1.0-bar); //1.0 at bottom layer, 0.0 at top layer.

  tmpnFloat bar2 = (toVector.y-minheight)/(maxheight-minheight);
  tmpnFloat foo2 = (1.0-bar2); //1.0 at bottom layer, 0.0 at top layer.

  printf("PPScript is %s. Height adjusting with fb(%f,%f) and fb2(%f,%f)\n",ppscriptA->name,bar,foo,bar2,foo2);
  
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
  macroparamstruct uplinemacro3={UPLINE,0,0,0,80,0,0.300,0};
  macroparamstruct downlinemacro2={DOWNLINE,0,0,0,80,0,0.300,0};


  tmpnFloat offset=0.0;
  if (!(moveItem->idx%2)) offset=-1.6;
  else offset=1.6;
  macroparamstruct spiralmacro={SPIRAL,12*(1-foo2*foo2*foo2*foo2),0,offset*bar2,12.0,2.0,1.450*(1-foo2*foo2*foo2)+0.4,0};

  //************************************
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}};  //rad/s
  
  //********************************************************************
  //* Pick                                                             *
  //********************************************************************
  if (ptrpath->pathtype==23) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
  
    tmpnVector viavectpos4={0,0,0,0,0,0};
    tmpnVector viavecthast4={0,0,0,0,0,0};

    viavectpos4.y = 400*bar*bar+200*hori*bar;
    viavectpos4.z = -10-20*bar*bar; 
    
    viavecthast4.y= 200*bar*bar+100*hori*bar;
    viavecthast4.z= -10-40*bar*bar-20*hori*bar; 
  
    // viapoints with respect to fromFrame:
    //viavectpos.x=-22;
    viavectpos.y=100+foo*foo*70+foo*foo*foo*foo*220;
    viavectpos.z=310-foo*foo*60+40*hori*bar*bar;
    
    //viavecthast.x=12;
    viavecthast.y=-foo*foo*50-foo*foo*foo*foo*80;
    viavecthast.z=-200+foo*foo*40-60*hori;
    
   if (bar>=0.58) {
     trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &viavectpos4, &viavecthast4, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
   }
   else {
     trajopt(robot, ptrpath, moveItem->idx, 23, loadgroup, ENDVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &homeVector, &zero, &fromVector, &zero, &zero, &zero, &viavectpos, &viavecthast,&nomacro,&downlinemacro2,blendtype);
   }
  }
  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  else if (ptrpath->pathtype==24) {

    //startvia for placepath
    tmpnVector viavectpos1={0,0,0,0,0,0};
    tmpnVector viavecthast1={0,0,0,0,0,0};
    
    //endvia for placepath
    tmpnVector viavectpos2={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast2={0,0,0,0,0,0}; //cartesian mm and degrees
        
    //viavectpos1.x=-20;
    viavectpos1.y=152+foo*50+foo*foo*40+foo*foo*foo*foo*150;
    viavectpos1.z=80+bar*bar*bar*230+110*hori*bar+50*bar;
    
    //viavecthast1.x=-12;
    viavecthast1.y=30+foo*60+foo*foo*50+foo*foo*foo*foo*150;
    viavecthast1.z=140+bar*bar*bar*200+80*hori*bar;

    // viapoint with respect to toFrame:
    viavectpos2.y=150+bar2*bar2*bar2*100+150*foo2*foo2*foo2;
    viavectpos2.z=-40-bar2*bar2*150-70*foo2-bar2*bar2*bar2*400;
    
    viavecthast2.y=-110-bar2*bar2*bar2*50-120*foo2*foo2;
    viavecthast2.z=30+160*bar2*bar2+100*foo2+bar2*bar2*bar2*200;
    
    tmpnJointsUnion ma = {{MTOMM(4.0),RADTODEG(2.0),RADTODEG(4.5),RADTODEG(5),RADTODEG(5)}};             //rad/s/s 
    trajopt(robot, ptrpath, moveItem->idx, 24, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&uplinemacro,&spiralmacro,blendtype);
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==25) {
    tmpnJointsUnion ma = {{MTOMM(4.5),RADTODEG(2.2),RADTODEG(5),RADTODEG(6),RADTODEG(6)}};             //rad/s/s 
    //endvia's for pickpath
    tmpnVector viavectpos={0,0,0,0,0,0};
    tmpnVector viavecthast={0,0,0,0,0,0};
  
    tmpnVector viavectpos4={0,0,0,0,0,0};
    tmpnVector viavecthast4={0,0,0,0,0,0};

    viavectpos4.y = 400*bar2*bar2+200*hori2*bar2;
    viavectpos4.z = 10+20*bar2*bar2; 
    
    viavecthast4.y= -200*bar2*bar2-100*hori2*bar2;
    viavecthast4.z= -10-40*bar2*bar2-20*hori2*bar2; 
  
    // viapoints with respect to toFrame:
    viavectpos.y=100+foo2*foo2*70+foo2*foo2*foo2*foo2*220;
    viavectpos.z=-310+foo2*foo2*60;
   
    viavecthast.y=foo2*foo2*45+foo2*foo2*foo2*foo2*80;
    viavecthast.z=-200+foo2*foo2*40-50*hori2;
    
    if (bar2>=0.58) {
      trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos, &viavecthast, &viavectpos4, &viavecthast4,&uplinemacro3,&nomacro,blendtype);
    }
   else {
     trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, STARTVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &homeVector, &zero, &viavectpos, &viavecthast, &zero, &zero,&uplinemacro3,&nomacro,blendtype);
   }


  }
  //*********************
}

