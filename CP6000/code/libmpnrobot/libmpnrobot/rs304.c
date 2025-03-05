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

//********************************************************************
//*                                                                  *
//* handmade and can only be used to generate path's that moves      *
//* a bag from conveyorA to palletA in workcell 304 (Nyhuus)         *
//* bags can be Nyhuus10Kg and Nyhuus5Kg                             *
//********************************************************************
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
  char s[256];
  int i,id=5100,iA,bagsPrLayer=7;
  tmpnFloat towerHight=400,difw;
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  int toFrameIdx,fromFrameIdx;
  tmpnFrame *toFrame,*fromFrame;
  int exectime;
  COMMANDSTRUCT *start0,*stop0,*corner0,*corner1,*corner2,*corner3,*corner4,*corner5;
  int layer,istart;

//  printf("*********  testMM=%d\n",testMM);
  ppscriptA = getPPScript(ppscriptnameA,(tmpnWorkcell*)tworkcell);
  bagsPrLayer=ppscriptA->itemsPrLayer;

  sprintf(s,"SUB %s",ppscriptnameA);
  ptrcmd=addCommandString(ptrcmd,s,level);

  if(forceLayer>=0)
  {  //we are called from mpnguide
    sprintf(s,"%d",forceLayer);
    initCounter("cLayer",s);
    sprintf(s,"%d",forceLayer*bagsPrLayer);
    initCounter("cBags",s);
  }
  layer=atoi(getCounterValue("cLayer"));
  iA=atoi(getCounterValue("cBags"));
  istart=iA-layer*bagsPrLayer;
  for(i=istart;i<bagsPrLayer;i++)
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
    sprintf(s,"PATH %s-%s-%d-%d id=%d,type=%d,time=%d,loadgroup=2",moveItem->from,moveItem->to,layer,moveItem->idx,id++,13,exectime);
    ptrcmd=addCommandString(ptrcmd,s,level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      start0=ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
//      ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 1",level);
      //UP
      corner0=ptrcmd=convertsplit(ptrcmd,320,-100,0,100,0,0,moveItem->from
                          ,500,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+200,fromFrameIdx,toFrameIdx)),0,90,moveItem->wcp.w/2,0,moveItem->from
                          ,robot,-1,level,moveItem->from,"case",TRUE);
      //OVER/OUT + ROTATE
      corner1=ptrcmd=convertsplit(ptrcmd,500,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+200,fromFrameIdx,toFrameIdx)),0,90,moveItem->wcp.w/2,0,moveItem->from
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //PLACE 3xTCP
      corner2=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                            ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                            ,robot,3,level,moveItem->to,"case",TRUE);
      ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 2",level);
      //PLACE 3xTCP
      corner3=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,robot,3,level,moveItem->to,"case",TRUE);
      //UP
      corner4=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+200,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+300,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //BACK/IN + ROTATE
      corner5=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(towerHight,moveItem->wcp.y)+300,moveItem->wcp.z,90,moveItem->wcp.w,0,moveItem->to
                  ,550,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+300,fromFrameIdx,toFrameIdx)),0,90,moveItem->wcp.w/2,0,moveItem->from
                  ,robot,-1,level,moveItem->to,"case",TRUE);
      //DOWN/IN
      stop0=ptrcmd=convertsplit(ptrcmd,550,MAX(0,FCONY(MAX(towerHight,moveItem->wcp.y)+300,fromFrameIdx,toFrameIdx)),0,90,moveItem->wcp.w/2,0,moveItem->from
                  ,320,-100,0,100,0,0,moveItem->from
                  ,robot,-1,level,moveItem->from,"case",FALSE);
      stop0=ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
      ptrcmd=addCommandString(ptrcmd,"POINT conveyorA 320,-100,0,100,0,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"END",level);
    ptrcmd=addCommandString(ptrcmd,"COUNTER cBags += 1",level);
    ptrcmd=addCommandString(ptrcmd,"COUNTER cBags >= wBags",level);
//for at stoppe midt i loopet
    sprintf(s,"CALL %sAfterEachLayer -1",ppscriptnameA);
    ptrcmd=addCommandString(ptrcmd,s,level);
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
//  testMM+=10;
//  ptrcmd=addCommandString(ptrcmd,"JUMPLAYER fotoFriMM 0",level); //DEBUG
  sprintf(s,"CALL %sAfterEachLayer -1",ppscriptnameA);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  return ptrcmd;
}


COMMANDSTRUCT *expandPath304BoptHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);
  moveItem=&ppscriptA->item[forceItem];

  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);

  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  sprintf(s,"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->to,moveItem->idx,moveItem->idx,34,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);


  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems += 1",level);
      
  //********************************************************************
  //* Home                                                             *
  //********************************************************************

  sprintf(s,"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1", moveItem->idx,35,1000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  
  //*********************
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;
}



//***********************************************************************
//*                                                                     *
//* Automatically generates optimal path for trajectories of 304        *
//* No check for collisions!!!                                          *
//*                                                                     *
//***********************************************************************

void expandPath304Bopt(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup, int layerHeightMM) 
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
  
  tmpnFloat maxheight=2100.0;
  tmpnFloat minheight=300.0;
  
  convertToFrame_vectorstyle(&fromVector,fromFrame,&zero,baseFrame);
  convertToFrame_vectorstyle(&toVector,toFrame,&moveItem->wcp,baseFrame);
  convertToFrame_vectorstyle(&homeVector,homeFrame,&zero,baseFrame);

  // thisitem = getItem(moveItem->item,(tmpnWorkcell*)tworkcell);
  // printf("thisItem\n");
  // if (thisitem==NULL) return;
  // printf("thisItem name: %s\n",thisitem->name);
  
  int layer = moveItem->layer;  // moveItem->idx/itemsPrLayer;

  toVector.y = (tmpnFloat)layerHeightMM;

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
  
  
  tmpnFloat macrolen = 100.0;
  
  macroparamstruct nomacro={NOMACRO,0,0,0,0,0,0,0};
  macroparamstruct uplinemacro={UPLINE,0,0,0,macrolen,0,0.004*macrolen,1};
   
  
  //************************************
  tmpnFloat samplerate= 25.0; //Hz
  
  tmpnJointsUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}};  //rad/s

  //********************************************************************
  //* Place                                                            *
  //********************************************************************
  if (ptrpath->pathtype==34) {
    tmpnJointsUnion ma = {{MTOMM(5.0),RADTODEG(3.5),RADTODEG(5),RADTODEG(6),RADTODEG(20)}};  //rad/s/s       
      
    //startvia for placepath
    tmpnVector viavectpos1={0,0,0,0,0,0};
    tmpnVector viavecthast1={0,0,0,0,0,0};
    
    //endvia for placepath
    tmpnVector viavectpos2={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast2={0,0,0,0,0,0}; //cartesian mm and degrees
    
    // viapoints with respect to fromFrame:
    tmpnFloat distmetric=(toVector.y-fromVector.y);
    viavectpos1.x=(toVector.x-fromVector.x)/2.0;
    if (viavectpos1.x<10.0) viavectpos1.x=10.0;
    viavectpos1.y=toVector.y-fromVector.y-300.0;
    if (viavectpos1.y < 200.0) viavectpos1.y=200.0;

    viavectpos1.z=0.0;
    viavectpos1.v=(toVector.v-fromVector.v)/3.0;
  
    viavecthast1.x=(toVector.x-fromVector.x)*0.15;
    viavecthast1.y=100+100*bar;
    viavecthast1.z=-10;
    viavecthast1.v=viavectpos1.v*0.5;
    // viapoint with respect to toFrame:

    viavectpos2.y=100+bar*100;
    viavectpos2.z=50+bar*130;
    

    viavecthast2.y=-100-bar*50;
    viavecthast2.z=-40-100*bar;
    
    trajopt(robot, ptrpath, moveItem->idx, 24, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &fromVector, &zero, &toVector, &zero, &viavectpos1, &viavecthast1, &viavectpos2, &viavecthast2,&nomacro,&nomacro,blendtype);
    
  }
  //********************************************************************
  //* Home                                                             *
  //********************************************************************
  else if (ptrpath->pathtype==35) {
    tmpnJointsUnion ma = {{MTOMM(5.5),RADTODEG(4.0),RADTODEG(5.5),RADTODEG(6.5),RADTODEG(20)}};  //rad/s/s       
    
    //startvia for homepath
    tmpnVector viavectpos3={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast3={0,0,0,0,0,0}; //cartesian mm and degrees

    tmpnVector viavectpos4={0,0,0,0,0,0}; //cartesian mm and degrees
    tmpnVector viavecthast4={0,0,0,0,0,0}; //cartesian mm and degrees
    
    viavectpos3.y=160+foo*foo*foo*foo*150+bar*bar*bar*bar*60;
    viavectpos3.z=90+bar*bar*bar*180;
    
    viavecthast3.y=60+foo*foo*foo*90+bar*bar*bar*bar*90;
    viavecthast3.z=100+bar*bar*bar*100;

    viavectpos4.z=-8;
    viavecthast4.z=6;
    viavectpos4.y=250;    
    viavecthast4.y=-140;
 
    trajopt(robot, ptrpath, moveItem->idx, 25, loadgroup, BOTHVIA, samplerate, getTCPidx("case",robot) , getTCPidx("case",robot) , &mv, &ma, &toVector, &zero, &fromVector, &zero, &viavectpos3, &viavecthast3, &viavectpos4, &viavecthast4,&nomacro,&nomacro,blendtype);
  }
  //*********************
}

