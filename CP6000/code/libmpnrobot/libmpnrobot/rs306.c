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
//* handmade and can only be used to generate sub path's that moves  *
//* a box from palletA to conveyorA in workcell 306 (Katrine)        *
//*                                                                  *
//********************************************************************
COMMANDSTRUCT *expandSubPathKatrineIn(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptA;
  tmpnFrame *toFrame,*fromFrame,*homeFrame;
  int exectime;
  tmpnFloat bcl=220.0; //minimum distance over items on pallet
  COMMANDSTRUCT *start0,*corner[20];
  tmpnFloat dist;  
  ppscriptA = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);

  moveItem=&ppscriptA->item[forceItem];
  fromFrame=&robot->m_frames.frame[getFrameIdx(moveItem->from,robot)];
  toFrame=&robot->m_frames.frame[getFrameIdx(moveItem->to,robot)];
  homeFrame=&robot->m_frames.frame[getFrameIdx("home",robot)];
  
//********************************************************************
//* Pick                                                             *
//********************************************************************
  exectime = 1200;
  dist=fabs(homeFrame->y-fromFrame->y-moveItem->wcp.y); //add 1 ms for each mm
  exectime+=dist*0.80;
  dist=fabs(homeFrame->z-fromFrame->z); //add 1 ms for each mm
  exectime+=dist*0.80;
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 1",level);
  sprintf(s,"PATH pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d",moveItem->from,moveItem->idx,moveItem->idx,20,exectime,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
    //HOME
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    start0=ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    //UP
    corner[0]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,90,0,"home"
                        ,0,MAX(0,moveItem->wcp.y+fromFrame->y+bcl-homeFrame->y),0,90,90,0,"home"
                        ,robot,-1,level,"home","case",TRUE);
    //OVER
    corner[1]=ptrcmd=convertsplit(ptrcmd
                        ,0,MAX(0,moveItem->wcp.y+fromFrame->y+bcl-homeFrame->y),0,90,90,0,"home"
                        ,moveItem->wcp.x,MAX(homeFrame->y-fromFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
                        ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,-1,level,moveItem->from,"case",TRUE);
    //DOWN
    corner[2]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(homeFrame->y-fromFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
                        ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,-1,level,moveItem->from,"case",TRUE);
    //TCP
    corner[4]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,3,level,moveItem->from,"case",TRUE);
  ptrcmd=addCommandString(ptrcmd,"END",level);
 //blend corners
  blendCorner3(robot,start0);
  blendCorner3(robot,corner[0]);
  blendCorner3(robot,corner[1]);
  blendCorner3(robot,corner[2]);
//********************************************************************
//*  Place                                                           *
//********************************************************************
  exectime = 1500;
  dist=fabs(homeFrame->y-fromFrame->y-moveItem->wcp.y); //add 1 ms for each mm
  exectime+=dist*1.15;
  dist=fabs(toFrame->z-fromFrame->z); //add 1 ms for each mm
  exectime+=dist*1.15;
//ptrcmd=addCommandString(ptrcmd,"COUNTER restart = 0",level);
  sprintf(s,"PATH place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d",moveItem->to,moveItem->idx,moveItem->idx,21,exectime,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
    //TCP
    corner[5]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,4,level,moveItem->from,"case",TRUE);
    //UP
    corner[3]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                                        ,moveItem->wcp.x,moveItem->wcp.y+100,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,-1,level,moveItem->from,"case",FALSE);
    ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 1",level);
    //UP
    corner[6]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+100,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,moveItem->wcp.x,MAX(homeFrame->y-fromFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
                        ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,robot,-1,level,moveItem->from,"case",TRUE);
    //OVER
    corner[7]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(homeFrame->y-fromFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
                        ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->from
                        ,0,MAX(homeFrame->y-toFrame->y,moveItem->wcp.y+bcl+fromFrame->y-toFrame->y),0,90,0,0,moveItem->to
                        ,robot,-1,level,moveItem->from,"case",TRUE);
    //DOWN
    corner[8]=ptrcmd=convertsplit(ptrcmd,
                           0,MAX(homeFrame->y-toFrame->y,moveItem->wcp.y+bcl+fromFrame->y-toFrame->y),0,90,0,0,moveItem->to
                                        ,0,0,0,90,0,0,moveItem->to
                                        ,robot,-1,level,moveItem->to,"case",TRUE);
    //TCP
    corner[9]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,0,0,moveItem->to
                          ,0,0,0,90,0,0,moveItem->to
                          ,robot,3,level,moveItem->to,"case",TRUE);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  blendCorner3(robot,corner[5]);
  blendCorner3(robot,corner[6]);
  blendCorner3(robot,corner[7]);
  blendCorner3(robot,corner[8]);
  ptrcmd=addCommandString(ptrcmd,"COUNTER cAItems += 1",level);
//********************************************************************
//*  Home                                                            *
//********************************************************************
/*  exectime = 1000; 
  dist=fabs(homeFrame->y-toFrame->y); //add 1 ms for each mm
  exectime+=dist*0.80;
  dist=fabs(homeFrame->z-toFrame->z); //add 1 ms for each mm
  exectime+=dist*0.80;
  sprintf(s,"PATH home id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,22,exectime,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
    //TCP
    corner[10]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,90,0,moveItem->to
                          ,0,0,0,90,90,0,moveItem->to
                          ,robot,4,level,moveItem->to,"case",TRUE);
    //UP
    corner[11]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,90,0,moveItem->to
                           ,0,homeFrame->y-toFrame->y,0,90,90,0,moveItem->to
                           ,robot,-1,level,moveItem->to,"case",TRUE);
    //HOME
    corner[12]=ptrcmd=convertsplit(ptrcmd,0,homeFrame->y-toFrame->y,0,90,90,0,moveItem->to
                           ,0,0,0,90,90,0,"home"
                           ,robot,-1,level,moveItem->to,"case",TRUE);
    //HOME
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
   //blend corners
  blendCorner3(robot,corner[10]);
  blendCorner3(robot,corner[11]);
  blendCorner3(robot,corner[12]);
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 Tipper ST_RESET",level);
*/
 
  return ptrcmd;
}
//********************************************************************
//*                                                                  *
//* handmade and can only be used to generate sub path's that moves  *
//* a box from conveyorB to palletB in workcell 306 (Katrine)        *
//*                                                                  *
//********************************************************************
COMMANDSTRUCT *expandSubPathKatrineOut(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup) 
{
  char s[512];
  tmpnPPScriptItem *moveItem;
  tmpnPPScript *ppscriptB;
  tmpnFrame *toFrame,*fromFrame,*homeFrame;
  int exectime;
  tmpnFloat bcl=100.0; //minimum distance over items on pallet
  tmpnFloat diagxy=0.0; 
  COMMANDSTRUCT *corner[40];
  tmpnFloat dist,rzminus,rzplus,rxminus,rxplus,hightfactor,ry;
  tmpnFloat rzminus0,rzplus0,rxminus0,rxplus0;
  tmpnFloat rzminus1,rzplus1,rxminus1,rxplus1;
  ppscriptB = getPPScript(ppscriptname,(tmpnWorkcell*)tworkcell);

  rzminus0=atof(getCounterValue("rzminus0"));
  rzplus0 =atof(getCounterValue("rzplus0"));
  rxminus0=atof(getCounterValue("rxminus0"));
  rxplus0 =atof(getCounterValue("rxplus0"));
  rzminus1=atof(getCounterValue("rzminus1"));
  rzplus1 =atof(getCounterValue("rzplus1"));
  rxminus1=atof(getCounterValue("rxminus1"));
  rxplus1 =atof(getCounterValue("rxplus1"));
  diagxy =atof(getCounterValue("diagxy"));
  ry =atof(getCounterValue("ry"));

    
  moveItem=&ppscriptB->item[forceItem];
  fromFrame=&robot->m_frames.frame[getFrameIdx(moveItem->from,robot)];
  toFrame=&robot->m_frames.frame[getFrameIdx(moveItem->to,robot)];
  homeFrame=&robot->m_frames.frame[getFrameIdx("home",robot)];


//********************************************************************
//* Pick                                                             *
//********************************************************************
 //trcmd=addCommandString(ptrcmd,"TESTEVENT station ST_READY",level);
//  ptrcmd=addCommandString(ptrcmd,"SUB",level);
//ptrcmd=addCommandString(ptrcmd,"TESTEVENT station ST_READY",level);

//if station ST_READY

/*  sprintf(s,"PATH getTom1 id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,2000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,200,0,90,45,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,200,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH moveTom1 id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,2000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT dispenser0 0,200,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,200,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH pickBox id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,2000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,300,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  //if station ST_READY
  sprintf(s,"PATH sugBakker id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,1800,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,700,100,45,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,500,160,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH sugBakker id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,800,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH toVacuumTest2 id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,800,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH flytBakker id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,1500,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT buffer 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,200,-700,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,200,-350,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,200,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,100,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);

  sprintf(s,"PATH pickBox id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,20,2000,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,300,0,180,0,0,10 bag",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,300,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"POINT station 0,0,0,90,0,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
*/

//********************************************************************
//* Place                                                            *
//********************************************************************
  exectime = 2500;
  dist=fabs(homeFrame->y-toFrame->y-moveItem->wcp.y); //add 1 ms for each mm
  exectime+=dist*1.15;
  dist=fabs(fromFrame->z-toFrame->z); //add 1 ms for each mm
  exectime+=dist*1.15;
  sprintf(s,"PATH place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d",moveItem->to,moveItem->idx,moveItem->idx,24,exectime,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
    //TCP
    corner[3]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,0,0,moveItem->from
			  ,0,0,0,90,0,0,moveItem->from
			  ,robot,4,level,moveItem->from,"case",TRUE);
    //UP
    corner[4]=ptrcmd=convertsplit(ptrcmd,0,0,0,90,0,0,moveItem->from
					,0,100,0,90,0,0,moveItem->from
			  ,robot,-1,level,moveItem->from,"case",TRUE);
    ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 1",level);
   if((moveItem->wcp.y+bcl)+toFrame->y-fromFrame->y>100)
    {
      //WE ARE OVER THE CONVEYOR LEVEL
      //UP
      corner[5]=ptrcmd=convertsplit(ptrcmd,0,100,0,90,0,0,moveItem->from
        ,0,(moveItem->wcp.y+bcl)+toFrame->y-fromFrame->y,0,90,0,0,moveItem->from
			  ,robot,-1,level,moveItem->from,"case",TRUE);
      //OVER
      corner[6]=ptrcmd=convertsplit(ptrcmd
        ,0,(moveItem->wcp.y+bcl)+toFrame->y-fromFrame->y,0,90,0,0,moveItem->from
			  ,moveItem->wcp.x,moveItem->wcp.y+bcl,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,-1,level,moveItem->to,"case",TRUE);
     //DOWN
      corner[7]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+bcl,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,moveItem->wcp.x,moveItem->wcp.y+ry,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,4,level,moveItem->to,"case",TRUE);
     //TCP
      corner[12]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+ry,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			    ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			    ,robot,18,level,moveItem->to,"case",TRUE);
      blendCorner3(robot,corner[5]);
    }
    else
    { //WE ARE UNDER THE CONVEYOR LEVEL AND CAN MOVE DIRECT TO wcp+bcl
      //OVER
      corner[6]=ptrcmd=convertsplit(ptrcmd
        ,0,100,0,90,0,0,moveItem->from
			  ,moveItem->wcp.x-diagxy,100+fromFrame->y-toFrame->y,moveItem->wcp.z+diagxy,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,-1,level,moveItem->to,"case",TRUE);
      //DOWN
      corner[7]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x-diagxy,100+fromFrame->y-toFrame->y,moveItem->wcp.z+diagxy,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,moveItem->wcp.x-diagxy,moveItem->wcp.y+bcl,moveItem->wcp.z+diagxy,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,-1,level,moveItem->to,"case",TRUE);
      //DOWN
      corner[9]=ptrcmd=convertsplit(ptrcmd
			  ,moveItem->wcp.x-diagxy,moveItem->wcp.y+bcl,moveItem->wcp.z+diagxy,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,moveItem->wcp.x,moveItem->wcp.y+bcl,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,-1,level,moveItem->to,"case",TRUE);
      //DOWN
      corner[11]=ptrcmd=convertsplit(ptrcmd
			  ,moveItem->wcp.x,moveItem->wcp.y+bcl,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,moveItem->wcp.x,moveItem->wcp.y+ry,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,-1,level,moveItem->to,"case",TRUE);
     //TCP
      corner[12]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+ry,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
		  	  ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			    ,robot,18,level,moveItem->to,"case",TRUE);
      blendCorner3(robot,corner[9]);
      blendCorner3(robot,corner[11]);
    }
  ptrcmd=addCommandString(ptrcmd,"END",level);
  blendCorner3(robot,corner[3]);
  blendCorner3(robot,corner[4]);
  blendCorner3(robot,corner[6]);
  blendCorner3(robot,corner[7]);

  if(moveItem->layer==0)
  {
    hightfactor=0;
    rzminus = 0;
    rzplus  = 0;
    rxminus = 0;
    rxplus  = 0;
  }
  else
  {
    hightfactor=moveItem->layer;
    hightfactor/=11;
    rzminus = rzminus0+hightfactor*rzminus1;
    rzplus  = rzplus0+hightfactor*rzplus1;
    rxminus = rxminus0+hightfactor*rxminus1;
    rxplus  = rxplus0+hightfactor*rxplus1;
  }
  seekCornerX(robot
             ,corner[12]->prev->prev
             ,rzminus
             ,rzplus
             ,rxminus
             ,rxplus);
   
  ptrcmd=addCommandString(ptrcmd,"COUNTER cBItems += 1",level);
  ptrcmd=addCommandString(ptrcmd,"SIGNALEVENT 1 Station ST_RESET",level);

//********************************************************************
//* Home                                                             *
//********************************************************************
  exectime = 1500;
  dist=fabs(homeFrame->y-toFrame->y-moveItem->wcp.y); //add 1 ms for each mm
  exectime+=dist*0.80;
  dist=fabs(homeFrame->z-toFrame->z); //add 0 ms for each mm
  exectime+=dist*0.80;
  sprintf(s,"PATH home id=%d,type=%d,time=%d,loadgroup=%d",moveItem->idx,25,exectime,loadgroup);
  ptrcmd=addCommandString(ptrcmd,s,level);
    //TCP
    corner[19]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
                                         ,moveItem->wcp.x,moveItem->wcp.y,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,4,level,moveItem->to,"case",FALSE);
   //TCP
    corner[20]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+50,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
                                         ,moveItem->wcp.x,moveItem->wcp.y+50,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,4,level,moveItem->to,"case",FALSE);

   ptrcmd=addCommandString(ptrcmd,"POSITIONHINT 1",level);
   //TCP
    corner[21]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+50,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
                                         ,moveItem->wcp.x,moveItem->wcp.y+50,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			  ,robot,4,level,moveItem->to,"case",FALSE);
   //UP
    corner[22]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,moveItem->wcp.y+50,moveItem->wcp.z,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			   ,moveItem->wcp.x,MAX(homeFrame->y-toFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
			   ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			   ,robot,-1,level,moveItem->to,"case",TRUE);
   //OVER
    corner[23]=ptrcmd=convertsplit(ptrcmd,moveItem->wcp.x,MAX(homeFrame->y-toFrame->y,moveItem->wcp.y+bcl),moveItem->wcp.z
			   ,moveItem->wcp.v,moveItem->wcp.w,0,moveItem->to
			   ,0,MAX(0,moveItem->wcp.y+bcl+toFrame->y-homeFrame->y),0,90,90,0,"home"
			   ,robot,-1,level,moveItem->to,"case",TRUE);
    //DOWN
    corner[24]=ptrcmd=convertsplit(ptrcmd
        ,0,MAX(0,moveItem->wcp.y+bcl+toFrame->y-homeFrame->y),0,90,90,0,"home"
        ,0,0,0,90,90,0,"home"
			  ,robot,-1,level,"home","case",TRUE);
     //HOME
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
    ptrcmd=addCommandString(ptrcmd,"POINT home 0,0,0,90,90,0,10 case",level);
  ptrcmd=addCommandString(ptrcmd,"END",level);
  //blend corners
  blendCorner3(robot,corner[19]);
  blendCorner3(robot,corner[20]);
  blendCorner3(robot,corner[21]);
  blendCorner3(robot,corner[22]);
  blendCorner3(robot,corner[23]);
  blendCorner3(robot,corner[24]);
  ptrcmd=addCommandString(ptrcmd,"COUNTER delaystop = 0",level);
  return ptrcmd;  
}
