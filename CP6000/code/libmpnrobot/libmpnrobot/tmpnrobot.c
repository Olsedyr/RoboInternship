/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
//#include <qgl.h>
#include	<stdio.h>
#include	<string.h>
#include <math.h>
#include "tmpnrobot.h"
#include "dynomads.h"
#include "spline.h"
#include "hermite.h"
#include "cmd.h"

int newtau=1;

static tmpnRobot gtrobot = {
"Palm.robot"
,3300.0
,530.0
,463.5
,{
 {400.0,158.0,{0.15,-0.12,0.11}
,{{9.20,7.70,-3.05},{7.70,18.13,-1.31},{-3.05,-1.31,21.95}}}
,{1000.0,58.87,{0.3555,0.0,-0.1399}
,{{0.3946,0.0003,-0.0634},{0.0003,9.6749,0.0001},{-0.0634,0.0001,9.6749}}}
,{1036.0,57.0,{0.25,0.0408,0.0080}
,{{1.1317, 2.2587,-0.4839},{2.2587,13.5974,0.0091},{-0.4839,-0.0091,13.8765}}}
,{155.0,4.79,{0.0,-0.0575,-0.0096}
,{{0.0287,0.0,0.0},{0.0,0.0085,0.0027},{0.0,0.0027,0.0294}}}
,{0.0,1.69,{0.0,0.0,0.1167}
,{{0.0058,0.0,0.0},{0.0,0.0058,0.0},{0.0,0.0,0.0010}}}
 }
,{
 {0.0,7.2,{0.0390,-0.0002,0.25}
,{{0.3778,0.0002,0.0159},{0.0002,0.2536,-0.0007},{0.0159,-0.0007,0.2591}}}
,{0.0,25.69,{0.0302,-0.0006,0.45}
,{{1.1679,0.0006,-0.0277},{0.0006,0.7650,-0.0027},{-0.0277,-0.0027,0.9227}}}
,{0.0,45.69,{0.0027,-0.0019,0.45}
,{{2.2679,0.0006,-0.0277},{0.0006,1.4650,-0.0027},{-0.0277,-0.0027,1.8227}}}
 }
,{{-1.0,-1.0,1.0,1.0,-1.0}}      //sign
,{{680.0,27.0,42.0,20.0,40.0}}     //rated rpm gear
,{{40.0,1568.0,491.0,108.0,55.0}}    //rated Nm gear
,{{3000.0,3000.0,3000.0,3000.0,3000.0}}  //rated rpm motor
,{{7.5,18.4,7.5,2.2,2.2}}                //rated Nm motor
,{{75.0,3716.8,1575.0,220.0,110.0}}                //max force Nm
,{{65536.0,65536.0,65536.0,65536.0,65536.0,65536.0}}
,{{5.0,101.0,105.0,100.0,50.0,5.0}}
,{{50.0*PI,360.0,360.0,360.0,360.0,360.0}}
,{{(65536*5)/(50*PI),65536*101/360,65536*105/360,65536*100/360,65536*50/360}}
,{{0.1,0.1,0.12,0.15,0.2}}                //p_gain         
,{{0.0,0.0,0.0,0.0,0.0}}                //i_gain         
,{{0.15,0.15,0.15,0.20,0.25}}           //d_gain         
,{{0.0,0.0,0.0,0.0,0.0}}           //vff_gain       
,{{8.0,8.0,8.0,8.0,8.0}}           //vff_gain       
,{{50.0,4.0,4.0,4.0,4.0}}           //
,{{100.0,8.0,8.0,8.0,8.0}}           //
,{{100.0,8.0,8.0,8.0,8.0}}           //
,{{0.1,0.1,0.1,0.1,0.1}}           //
,{{0.5,0.5,0.5,0.5,0.5}}           //
,{{10.0,1.0,1.0,1.0,1.0}}           //
,{{0.0,0.0,0.0,0.0,0.0}}
,{{0.0,0.0,0.0,0.0,0.0}}
,{-9999.0,-9999.0,0.0,-360.0,-360.0}      //min values in base coord
,{9999.0,9999.0,2450.0,360.0,360.0}   //max values in base coord
,{0.0,0.0,0.0,0.0,0.0}        //worldPoint - from offline programme
,{0.0,-1333.5,0.0,0.0,0.0}    //robot trans - center of gear B
,{0.0,0.0,0.0,0.0,0.0}        //calib trans - offset from offline programme
,{0.0,0.0,0.0,0.0,0.0}        //mpnhome SLM absolute position
,0
,0
,{
   {"case",205.0,0.0,0.0,0.0,0.0}        //caseGripper
  ,{"bag",410.0,-40.0,0.0,0.0,0.0}       //bagGripper
  ,{"zero",-171.0,0.0,0.0,0.0,0.0}      //zeoGripper
}
,{0.0,0.0,0.0,0.0,0.0}        //actuatorSpace
,{0.0,0.0,0.0,0.0,0.0}        //jointSpace
,{{0.0,0.0,0.0,0.0,0.0}}        //staticForce
,{0
 ,{
  }
}
,0//simuate
,0//snapToGrid
,1
};
static tmpnRobot temprobot;
tmpnPlant Tplant;
tmpnRobot *initrobot=&gtrobot;
tmpnPlant *tplant=&Tplant;

volatile tmpnRobot *trobot=NULL;
volatile tmpnWorkcell *tworkcell=NULL;

//tmpnRobot *trobot=&gtrobot;
//tmpnWorkcell *tworkcell=NULL;
//tmpnPlant *tplant=&Tplant;

void setLink(tmpnLink *link, int idx)
{
  setLinkLength(link->length, idx);
	if (idx!=4)
		setMass(link->mass,idx);
	else
		setMass(link->mass+tworkcell->tools.tool[0].weight,idx);
  setMassDisplacement(link->massDisplacement[0]
                     ,link->massDisplacement[1]
                     ,link->massDisplacement[2],idx);
  setInertiaTensor(link->inertia[0][0]
                  ,link->inertia[0][1]
                  ,link->inertia[0][2]
                  ,link->inertia[1][0]
                  ,link->inertia[1][1]
                  ,link->inertia[1][2]
                  ,link->inertia[2][0]
                  ,link->inertia[2][1]
                  ,link->inertia[2][2]
                  ,idx);
}

int staticforce(tmpnRobot *robot)
{
  int i,j;
  static int stime=0;
  for(j=0;j<5;j++)
  {
    setLink(&robot->m_Link[j],j);
  }
  setLink(&robot->m_State[0],4);
  setq(MMTOM(robot->m_max.z-robot->m_joint.a)
    ,DEGTORAD(robot->m_joint.b+90.0)
    ,DEGTORAD(robot->m_joint.c)
    ,DEGTORAD(robot->m_joint.d)
    ,DEGTORAD(robot->m_joint.e));
  setdq(0.0,0.0,0.0,0.0,0.0);
  setddq(0.0,0.0,0.0,0.0,0.0);


  if(newtau==1)
    computetaus();
  
  for (i=0;i<5;i++)
  {
    if(newtau==1)
      robot->m_staticForce.array[i] = tau(i);
    else
      robot->m_staticForce.array[i] = oldtau(i,stime++);
//    printf("tau[%i]:%f\n",i,tau(i,0));
  }
  return 1;
}

int tmpnComputeIK(tmpnRobot *robot
                  ,tmpnFloat wx
                  ,tmpnFloat wy
                  ,tmpnFloat wz
                  ,tmpnFloat wv
                  ,tmpnFloat ww
                  ,tmpnFloat wu
                  ,int tcpidx)
{
  /// Local Variables ///////////////////////////////////////////////////////////
  
  tmpnFloat sin2,cos2;	  // SINE AND COSINE OF ANGLE 2
  tmpnFloat angle1,angle2;// ANGLE 1 AND 2 IN RADIANS
  tmpnFloat angle1deg,angle2deg;// ANGLE 1 AND 2 IN DEGREES
  tmpnFloat beta,new;
  tmpnFloat ox,oy,ry,rz;
  tmpnVector localPointIK; //last computed invers kinematic local point
  tmpnVector worldPoint;   
  tmpnJoints joint;

///////////////////////////////////////////////////////////////////////////////
/// SNAP TO GRID
  if(robot->m_snapToGrid)
  {
    worldPoint.x=ROUND2(wx);
    worldPoint.y=ROUND2(wy);
    worldPoint.z=ROUND2(wz);
    worldPoint.v=ROUND2(wv-robot->m_tcp[tcpidx].v);
    worldPoint.w=ROUND2(ww-robot->m_tcp[tcpidx].w);
    worldPoint.u=ROUND2(wu-robot->m_tcp[tcpidx].u);
  } 
  else
  {
    worldPoint.x=wx;
    worldPoint.y=wy;
    worldPoint.z=wz;
    worldPoint.v=wv-robot->m_tcp[tcpidx].v;
    worldPoint.w=ww-robot->m_tcp[tcpidx].w;
    worldPoint.u=wu-robot->m_tcp[tcpidx].u;
  }
  
  /// TO LOCAL COORD
  // calculate TCP offset caused by rotate
  rz=(-robot->m_tcp[tcpidx].z)
    *cos(DEGTORAD(-worldPoint.w))
    -(-robot->m_tcp[tcpidx].y)
    *sin(DEGTORAD(-worldPoint.w));
  ry=(-robot->m_tcp[tcpidx].z)
    *sin(DEGTORAD(-worldPoint.w))
    +(-robot->m_tcp[tcpidx].y)
    *cos(DEGTORAD(-worldPoint.w));
  // calculate TCP offset caused by tilt
  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)
    *cos(DEGTORAD(-worldPoint.v))
    +(ry)*-sin(DEGTORAD(worldPoint.v));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)
    *sin(DEGTORAD(-worldPoint.v))
    -(ry)*cos(DEGTORAD(-worldPoint.v));
  
  localPointIK.x=worldPoint.x+robot->m_localTrans.x-ox;
  localPointIK.y=worldPoint.y+robot->m_localTrans.y-oy;
  localPointIK.z=worldPoint.z+robot->m_localTrans.z+rz;
  localPointIK.v=worldPoint.v+robot->m_localTrans.v;
  localPointIK.w=worldPoint.w+robot->m_localTrans.w;
  localPointIK.u=worldPoint.u+robot->m_localTrans.u;
  
  tmpnFloat ikxsq = localPointIK.x*localPointIK.x;
  tmpnFloat ikysq = localPointIK.y*localPointIK.y;
  
	//  printf("IK: %f %f %f %f %f\n",localPointIK.x,localPointIK.y,localPointIK.z,localPointIK.v,localPointIK.w);
  
  
  /// CALCULATE THE COSINE OF ANGLE 2
  cos2 = ( ikxsq + ikysq
	   - (robot->m_Link[1].length * robot->m_Link[1].length)
	   - (robot->m_Link[2].length * robot->m_Link[2].length) )
    / ((tmpnFloat)2.0 * robot->m_Link[1].length * robot->m_Link[2].length);
  /// IF IT IS NOT IN THIS RANGE, IT IS UNREACHABLE
  if (cos2 >= -1.0 && cos2 <= 1.0)
  {
    angle2 = (tmpnFloat)acos(cos2);  // GET THE ANGLE WITH AN ARCCOSINE
    //if (angle2>PI) angle2-=2*PI;   
    angle2deg = RADTODEG(angle2);	// CONVERT IT TO DEGREES
    
    sin2 = (tmpnFloat)sin(angle2);   // CALC THE SINE OF ANGLE 2
    /// COMPUTE ANGLE 1
    beta = atan2(localPointIK.x,localPointIK.y);
    new = acos((ikxsq + ikysq + robot->m_Link[1].length * robot->m_Link[1].length - robot->m_Link[2].length * robot->m_Link[2].length) / (2.0 * robot->m_Link[1].length * sqrt(ikxsq + ikysq)));
    //if (angle2deg >= 0.0 )
    angle1 = beta-new;
    //else
    //angle1 = beta+new;
    angle1deg = RADTODEG(angle1);	// CONVERT IT TO DEGREES
    //printf("angle1: %f, angle2: %f\n",angle1,angle2);
    
    //printf("bn: %f %f %f\n",beta,new,hej);
    //transform from cartesian to joint space
    //TODO kontroller fortegn joint.*
    joint.a=localPointIK.z;
    joint.b=-angle1deg+90.0;
    if (joint.b>180) joint.b-=360;  
    joint.c=-angle2deg;
    joint.d=localPointIK.v+joint.b+joint.c;
    joint.e=localPointIK.w;
    joint.f=localPointIK.u;

		worldPoint.v+=robot->m_tcp[tcpidx].v;
		worldPoint.w+=robot->m_tcp[tcpidx].w;
		worldPoint.w+=robot->m_tcp[tcpidx].u;

    if(joint.a<robot->m_min.z) return 0;
    if(joint.a>robot->m_max.z) return 0;
    if(worldPoint.x<robot->m_min.x) return 0;//worldPoint.x=robot->m_min.x;
    if(worldPoint.x>robot->m_max.x) return 0;//worldPoint.x=robot->m_max.x;
    if(worldPoint.y<robot->m_min.y) return 0;//worldPoint.y=robot->m_min.y;
    if(worldPoint.y>robot->m_max.y) return 0;//worldPoint.y=robot->m_max.y;

    robot->m_worldPoint.x=worldPoint.x;
    robot->m_worldPoint.y=worldPoint.y;
    robot->m_worldPoint.z=worldPoint.z;
    robot->m_worldPoint.v=worldPoint.v;
    robot->m_worldPoint.w=worldPoint.w;
    robot->m_worldPoint.u=worldPoint.u;
    robot->m_joint.a = joint.a;
    robot->m_joint.b = joint.b;
    robot->m_joint.c = joint.c;
    robot->m_joint.d = joint.d;
    robot->m_joint.e = joint.e;
    robot->m_joint.f = joint.f;
    robot->m_tcpidx=tcpidx;
    //printf("newnts: %f %f %f %f %f : %f %f\n",robot->m_joint.a,robot->m_joint.b,robot->m_joint.c,robot->m_joint.d,robot->m_joint.e,localPointIK.v,wv);
    return 1;
  }
  else
    return 0;
}

int tmpnJointToActuator(tmpnRobot *robot,int tcpidx)
{
  tmpnJoints actuator;
  //transform from joint space to logic actuator space
  actuator.a = robot->m_sign.name.a*robot->m_joint.a;
  actuator.b = robot->m_sign.name.b*robot->m_joint.b;
  actuator.c = robot->m_sign.name.c*robot->m_joint.c;
  actuator.d = robot->m_sign.name.d*robot->m_joint.d;
  actuator.e = robot->m_sign.name.e*(robot->m_joint.e-actuator.d/robot->m_gearing.name.e);
  actuator.f = robot->m_sign.name.f*robot->m_joint.f;
  
  //add calibration values to logic actuator position
  actuator.a += robot->m_jointCalib.a;
  actuator.b += robot->m_jointCalib.b;
  actuator.c += robot->m_jointCalib.c;
  actuator.d += robot->m_jointCalib.d;
//TODO we use m_tcp[x].v and w to have different tool90 values 
  actuator.e += robot->m_jointCalib.e;
  actuator.f += robot->m_jointCalib.f;
  
  robot->m_actuator.a = actuator.a;
  robot->m_actuator.b = actuator.b;
  robot->m_actuator.c = actuator.c;
  robot->m_actuator.d = actuator.d;
  robot->m_actuator.e = actuator.e;
  robot->m_actuator.f = actuator.f;
  return 1;
}


//find worldPoint from actuator angles
int tmpnComputeFK(tmpnRobot *robot, tmpnFloat a, tmpnFloat b, tmpnFloat c, tmpnFloat d, tmpnFloat e, tmpnFloat f, int tcpidx)
{
  tmpnFloat ox,oy,ry,rz;
  tmpnVector localPointFK; //computed forward kinematic local point
  tmpnJoints actuator;

  //subtract calibration values to get logic actuator position
  actuator.a = a-robot->m_jointCalib.a;
  actuator.b = b-robot->m_jointCalib.b;
  actuator.c = c-robot->m_jointCalib.c;
  actuator.d = d-robot->m_jointCalib.d;
//TODO we use m_tcp[x].v and w to have different tool90 values 
  actuator.e = e-robot->m_jointCalib.e;
  actuator.f = f-robot->m_jointCalib.f;

  //transform from logic actuator to joint space
  robot->m_joint.a = robot->m_sign.name.a*actuator.a;
  robot->m_joint.b = robot->m_sign.name.b*actuator.b;
  robot->m_joint.c = robot->m_sign.name.c*actuator.c;
  robot->m_joint.d = robot->m_sign.name.d*actuator.d;
  robot->m_joint.e = robot->m_sign.name.e*actuator.e + actuator.d/robot->m_gearing.name.e;
  robot->m_joint.f = robot->m_sign.name.f*actuator.f;
  //transform from joint to cartesian
  localPointFK.z = robot->m_joint.a;
  localPointFK.x = robot->m_Link[1].length*cos(DEGTORAD(robot->m_joint.b))
                 + (robot->m_Link[2].length*cos(DEGTORAD(robot->m_joint.b)
                 + DEGTORAD(robot->m_joint.c)));
  localPointFK.y = robot->m_Link[1].length*sin(DEGTORAD(robot->m_joint.b))
                 + (robot->m_Link[2].length*sin(DEGTORAD(robot->m_joint.b)
                 + DEGTORAD(robot->m_joint.c)));
  localPointFK.v = robot->m_joint.d-(robot->m_joint.b+robot->m_joint.c); //deg tilt
  localPointFK.w = robot->m_joint.e; //deg rotate
  localPointFK.u = robot->m_joint.f; //mm

// calculate TCP offset caused by rotate
  rz=(-robot->m_tcp[tcpidx].z)*cos(DEGTORAD(-localPointFK.w))
    -(-robot->m_tcp[tcpidx].y)*sin(DEGTORAD(-localPointFK.w));
  ry=(-robot->m_tcp[tcpidx].z)*sin(DEGTORAD(-localPointFK.w))
    +(-robot->m_tcp[tcpidx].y)*cos(DEGTORAD(-localPointFK.w));
// calculate TCP offset caused by tilt
  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*cos(DEGTORAD(-localPointFK.v))
    +(ry)*-sin(DEGTORAD(localPointFK.v));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*sin(DEGTORAD(-localPointFK.v))
    -(ry)*cos(DEGTORAD(localPointFK.v));

  if(robot->m_snapToGrid)
  {
    robot->m_worldPoint.x=ROUND2(localPointFK.x-robot->m_localTrans.x + ox);
    robot->m_worldPoint.y=ROUND2(localPointFK.y-robot->m_localTrans.y + oy);
    robot->m_worldPoint.z=ROUND2(localPointFK.z-robot->m_localTrans.z - rz);
    robot->m_worldPoint.v=ROUND2(localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v);
    robot->m_worldPoint.w=ROUND2(localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w);
    robot->m_worldPoint.u=ROUND2(localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u);
  }
  else
  {
    robot->m_worldPoint.x=localPointFK.x-robot->m_localTrans.x + ox;
    robot->m_worldPoint.y=localPointFK.y-robot->m_localTrans.y + oy;
    robot->m_worldPoint.z=localPointFK.z-robot->m_localTrans.z - rz;
    robot->m_worldPoint.v=localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v;
    robot->m_worldPoint.w=localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w;
    robot->m_worldPoint.u=localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u;
  }

  return 1;
}

// Find worldPoint from joint-angles
int tmpnComputeFKlogic(tmpnRobot *robot, tmpnFloat a, tmpnFloat b, tmpnFloat c, tmpnFloat d, tmpnFloat e, tmpnFloat f, int tcpidx)
{
  tmpnFloat ox,oy,ry,rz;
  tmpnVector localPointFK; //computed forward kinematic local point

  robot->m_joint.a = a;
  robot->m_joint.b = b;
  robot->m_joint.c = c;
  robot->m_joint.d = d;
  robot->m_joint.e = e;
  robot->m_joint.f = f;
  //transform from joint to cartesian
  localPointFK.z = robot->m_joint.a;
  localPointFK.x = robot->m_Link[1].length*cos(DEGTORAD(robot->m_joint.b))
                 + (robot->m_Link[2].length*cos(DEGTORAD(robot->m_joint.b)
                 + DEGTORAD(robot->m_joint.c)));
  localPointFK.y = robot->m_Link[1].length*sin(DEGTORAD(robot->m_joint.b))
                 + (robot->m_Link[2].length*sin(DEGTORAD(robot->m_joint.b)
                 + DEGTORAD(robot->m_joint.c)));
  localPointFK.v = robot->m_joint.d-(robot->m_joint.b+robot->m_joint.c); //deg tilt
  localPointFK.w = robot->m_joint.e; //deg rotate
  localPointFK.u = robot->m_joint.f; //mm

  // calculate TCP offset caused by rotate
  rz=(-robot->m_tcp[tcpidx].z)*cos(DEGTORAD(-localPointFK.w))
    -(-robot->m_tcp[tcpidx].y)*sin(DEGTORAD(-localPointFK.w));
  ry=(-robot->m_tcp[tcpidx].z)*sin(DEGTORAD(-localPointFK.w))
    +(-robot->m_tcp[tcpidx].y)*cos(DEGTORAD(-localPointFK.w));
  // calculate TCP offset caused by tilt
  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*cos(DEGTORAD(-localPointFK.v))
    +(ry)*-sin(DEGTORAD(localPointFK.v));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*sin(DEGTORAD(-localPointFK.v))
    -(ry)*cos(DEGTORAD(localPointFK.v));
  robot->m_worldPoint.x=localPointFK.x-robot->m_localTrans.x + ox;
  robot->m_worldPoint.y=localPointFK.y-robot->m_localTrans.y + oy;
  robot->m_worldPoint.z=localPointFK.z-robot->m_localTrans.z - rz;
  robot->m_worldPoint.v=localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v;
  robot->m_worldPoint.w=localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w;
  robot->m_worldPoint.u=localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u;
  return 1;
}

static int dynomads(tmpnRobot *robot, tmpnPosition *position)
{
  int i;
  static int time=0;
  setLink(&robot->m_State[position->statehint],4);
  setq(position->posRad.name.a
      ,position->posRad.name.b
      ,position->posRad.name.c
      ,position->posRad.name.d
      ,position->posRad.name.e);
  setdq(position->speedRad.name.a
       ,position->speedRad.name.b
       ,position->speedRad.name.c
       ,position->speedRad.name.d
       ,position->speedRad.name.e);
  setddq(position->accelRad.name.a
        ,position->accelRad.name.b
        ,position->accelRad.name.c
        ,position->accelRad.name.d
        ,position->accelRad.name.e);
  if(newtau==1)
    computetaus();
  for (i=0;i<5;i++)
  {
    if(newtau==1)
      position->force.array[i] = tau(i);
    else
      position->force.array[i] = oldtau(i,time++);
//      printf("tau[%i]:%f\n",i,oldtau(i,time++));
  }
  return 1;
}


void solveIK(tmpnRobot *robot, int maxidx, tmpnPosition *position)
{
  int i;
  for ( i=0; i<maxidx; i++)
  {
    tmpnComputeIK(robot
            ,position[i].taskSpace.x
            ,position[i].taskSpace.y
            ,position[i].taskSpace.z
            ,position[i].taskSpace.v
            ,position[i].taskSpace.w
            ,position[i].taskSpace.u
            ,position[i].tcpidx);
    tmpnJointToActuator(robot,position[i].tcpidx);
    position[i].jointSpace.name.a=robot->m_joint.a;
    position[i].jointSpace.name.b=robot->m_joint.b;
    position[i].jointSpace.name.c=robot->m_joint.c;
    position[i].jointSpace.name.d=robot->m_joint.d;
    position[i].jointSpace.name.e=robot->m_joint.e;
    position[i].jointSpace.name.f=robot->m_joint.f;
    position[i].actuatorSpace.name.a=robot->m_actuator.a;
    position[i].actuatorSpace.name.b=robot->m_actuator.b;
    position[i].actuatorSpace.name.c=robot->m_actuator.c;
    position[i].actuatorSpace.name.d=robot->m_actuator.d;
    position[i].actuatorSpace.name.e=robot->m_actuator.e;
    position[i].actuatorSpace.name.f=robot->m_actuator.f;
  }
}
void solveFK(tmpnRobot *robot, int maxidx, tmpnPosition *position)
{
  int i;
  for ( i=0; i<maxidx; i++)
  {
    tmpnComputeFK(robot
                 ,position[i].actuatorSpace.name.a
                 ,position[i].actuatorSpace.name.b
                 ,position[i].actuatorSpace.name.c
                 ,position[i].actuatorSpace.name.d
                 ,position[i].actuatorSpace.name.e
                 ,position[i].actuatorSpace.name.f
                 ,position[i].tcpidx);
    position[i].taskSpace.x=robot->m_worldPoint.x;
    position[i].taskSpace.y=robot->m_worldPoint.y;
    position[i].taskSpace.z=robot->m_worldPoint.z;
    position[i].taskSpace.v=robot->m_worldPoint.v;
    position[i].taskSpace.w=robot->m_worldPoint.w;
    position[i].taskSpace.u=robot->m_worldPoint.u;
    position[i].jointSpace.name.a=robot->m_joint.a;
    position[i].jointSpace.name.b=robot->m_joint.b;
    position[i].jointSpace.name.c=robot->m_joint.c;
    position[i].jointSpace.name.d=robot->m_joint.d;
    position[i].jointSpace.name.e=robot->m_joint.e;
    position[i].jointSpace.name.f=robot->m_joint.f;
  }
/*  for(i=0;i<maxidx-1;i++)
  {
    for(j=0;j<5;j++)
      if(fabs(position[j+1].jointSpace.array[j]-position[i].jointSpace.array[j])<0.0001)
        position[j+1].jointSpace.array[j]=position[j].jointSpace.array[j];
  }*/
}

static void keypoint_sumt(int maxidx, tmpnKeyPoint *keypoint, tmpnFloat maxTime)
{
  int i;
  tmpnFloat sumt,units,dt,temp1;
  sumt=0.0;
  keypoint[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {
/*    if(keypoint[i].dt==0.0)
      dt=0.0;
    else
      dt=10.0/keypoint[i].dt; //TRIO*/
    dt=keypoint[i].dt; //mpnGuide
    sumt+=dt;
    keypoint[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {
//    temp1 = keypoint[i].t*(1000000.0/sumt);
    temp1 = keypoint[i].t/sumt;
    keypoint[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    keypoint[i].sp = (keypoint[i+1].t-keypoint[i].t)*maxTime;
  }
//t=number between 0 and 1
}
static void position_sumt4(int maxidx, tmpnPosition *position, tmpnFloat maxTime)
{
  int i;
  tmpnFloat sumt,units,temp1;
  sumt=0.0;
  position[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {
    sumt+=position[i].dt;
    position[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {
    temp1 = position[i].t/sumt;
    position[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
}

static void position_sumt(int maxidx, tmpnPosition *position, tmpnFloat maxTime)
{
  int i;
  tmpnFloat sumt,units,dt,temp1;
  sumt=0.0;
  position[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {
    dt=10;
    sumt+=dt;
    position[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {
    temp1 = position[i].t/sumt;
    position[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
}

//#define SAMPLEPERIOD(i,maxidxm,maxTime) ((maxidx)*1000.0/(maxTime))
#define SAMPLEPERIOD(i,maxidx,maxTime) (1000.0/((maxTime)*((position[(i)+1].t-position[(i)].t)/position[maxidx-1].t)))

void VA(tmpnFloat x1,tmpnFloat x2,tmpnFloat x3,tmpnFloat y1,tmpnFloat y2,tmpnFloat y3,tmpnFloat* vel,tmpnFloat* acc) {
  tmpnFloat A,B;
	tmpnFloat temp1,temp2,temp3;
	temp1=y1/((x1-x2)*(x1-x3));
	temp2=y2/((x2-x1)*(x2-x3));
	temp3=y3/((x3-x1)*(x3-x2));
	A = temp1 + temp2 + temp3;
	B = -1.0*((x1+x2)*temp3+(x1+x3)*temp2+(x2+x3)*temp1);
	*acc=2*A;
	*vel=(*acc)*x2+B;	
}

void solve(tmpnRobot *robot, int maxidx, tmpnPosition *position, tmpnFloat maxTime, tmpnFloat *maxSpeed, int order)
{
  int i,j;
  tmpnJointsUnion nsum,tsum,T,n,Trms;
  tmpnFloat p,rGear,tdif,tmax,ts;
  *maxSpeed=0.0;
  tmpnFloat samplePeriod = SAMPLEPERIOD(0,maxidx,maxTime);
  if(order==4)
    position_sumt(maxidx,position,maxTime);
  else 
    position_sumt4(maxidx,position,maxTime);
  solveIK(robot,maxidx,position);
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
  for ( i=0; i<maxidx; i++)
  {   
    // transformation fra mpn-koordinatsystem til mads-koordinatsystem
    position[i].posRad.name.a=MMTOM(robot->m_max.z-position[i].jointSpace.name.a);
    position[i].posRad.name.b=DEGTORAD(90.0-position[i].jointSpace.name.b);
    position[i].posRad.name.c=DEGTORAD(-position[i].jointSpace.name.c);
    position[i].posRad.name.d=DEGTORAD(position[i].jointSpace.name.d);
    position[i].posRad.name.e=DEGTORAD(position[i].jointSpace.name.e);
    position[i].posRad.name.f=MMTOM(position[i].jointSpace.name.f);
  }
  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
    samplePeriod=1000.0/position[(i)].sp;
    //   samplePeriod = SAMPLEPERIOD(i,maxidx,maxTime);
    for(j=0;j<MAXROBOTAXIS;j++)
    {
      //mm or deg
      position[i].dif.array[j]=(position[i+1].jointSpace.array[j]-position[i].jointSpace.array[j]);
      //1 sampleperiod = maxidx(antalsamples)/sec
      //mm or deg/sec
      position[i].speed.array[j]=position[i].dif.array[j]*samplePeriod;
      //motor rev/min
      position[i].rev.array[j]=position[i].speed.array[j]*60.0*robot->m_gearing.array[j]/robot->m_unit.array[j];
      //% off nominel speed
      position[i].pctRatedSpeed.array[j]=position[i].rev.array[j]*100.0/temprobot.m_ratedRPM.array[j];
      if(fabs(position[i].pctRatedSpeed.array[j])>*maxSpeed)
      {
        *maxSpeed=fabs(position[i].pctRatedSpeed.array[j]);
        position[i].maxrev=j;
      }
    }
    //meter or rad/s
		if (i!=0)
		{
			float dummy;
			for(j=0;j<MAXROBOTAXIS;j++)
				VA(position[i-1].t*maxTime*0.001,
           position[i  ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].posRad.array[j],
           position[i  ].posRad.array[j],
           position[i+1].posRad.array[j],
          &position[i].speedRad.array[j],&dummy);
		}
		else
		{
			position[i].speedRad.name.a=(position[i+1].posRad.name.a-position[i].posRad.name.a)*samplePeriod;
			for(j=0;j<MAXROBOTAXIS;j++)
				position[i].speedRad.array[j]=(position[i+1].posRad.array[j]-position[i].posRad.array[j])*samplePeriod;
		}
  }
  //speed=0 in last pos
  for(j=0;j<MAXROBOTAXIS;j++)
  {
    position[maxidx-1].dif.array[j]=0;
    position[maxidx-1].speed.array[j]=0;
    position[maxidx-1].speedRad.array[j]=0;
    position[maxidx-1].rev.array[j]=0;
    position[maxidx-1].pctRatedSpeed.array[j]=0;
  }
//  resample(maxidx,position,&temprobot);
  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
//    samplePeriod=position[(i)+1].sp;
//    samplePeriod = SAMPLEPERIOD(i,maxidx,maxTime);
    samplePeriod=1000.0/position[(i)].sp;
    for(j=0;j<MAXROBOTAXIS;j++)
    {
			if (i!=0)
			{
				float dummy;
				VA(position[i-1].t*maxTime*0.001,
           position[i  ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].speedRad.array[j],
           position[i  ].speedRad.array[j],
           position[i+1].speedRad.array[j],
          &position[i  ].accelRad.array[j],&dummy);
			}
			else
			{
				 position[i].accelRad.array[j]=position[i+1].speedRad.array[j]-position[i].speedRad.array[j];
				 position[i].accelRad.array[j]*=samplePeriod;
			}
    }
  }                            
  for(j=0;j<MAXROBOTAXIS;j++)
  {
    position[maxidx-1].accelRad.array[j]=0;
  }
  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
    samplePeriod=1000.0/position[(i)].sp;
//    printf("%05d t=%f samplePeriod=%f sp=%f\n",i,position[i+1].t,samplePeriod,position[(i)+1].sp);
//    samplePeriod=position[(i)+1].sp;
//    samplePeriod = SAMPLEPERIOD(i,maxidx,maxTime);
    for(j=0;j<MAXROBOTAXIS;j++)
    {
			if (i!=0)
			{
				float dummy;
				VA(position[i-1].t*maxTime*0.001,
           position[i  ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].accelRad.array[j],
           position[i  ].accelRad.array[j],
           position[i+1].accelRad.array[j],
           &position[i ].jerkRad.array[j],&dummy);
			}
			else
			{
				position[i].jerkRad.array[j]=position[i+1].accelRad.array[j]-position[i].accelRad.array[j];
				position[i].jerkRad.array[j]*=samplePeriod;
			}
    }
  }                            
  for(j=0;j<MAXROBOTAXIS;j++)
  {
    position[maxidx-1].jerkRad.array[j]=0;
  }
  for(j=0;j<5;j++)
  {
    setLink(&robot->m_Link[j],j);
  }
  for(i=0;i<maxidx;i++)
  {
    dynomads(robot,&position[i]);
  }
  //LIFETIME FOR GEAR AND MOTOR
  for(j=0;j<MAXROBOTAXIS;j++)
  {
    Trms.array[j]=0.0;
    nsum.array[j]=0.0;
    tsum.array[j]=0.0;
    T.array[j]=0.0;
  }                       
  for(i=0;i<maxidx-1;i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
    //samplePeriod = SAMPLEPERIOD(i,maxidx,maxTime);
    //ALPHA AND TEIJIN-SEIKI
    for(j=0;j<MAXROBOTAXIS;j++)
    {
      //GEAR
      p = pow(fabs(position[i].force.array[j]),10.0/3.0);
      rGear = fabs(position[i].rev.array[j]/robot->m_gearing.array[j]);
      T.array[j] += (1.0/samplePeriod) * rGear * p;
      nsum.array[j] += (1.0/samplePeriod) * rGear;
      tsum.array[j] += (1.0/samplePeriod);
      //MOTOR
      Trms.array[j] += ((1.0/samplePeriod)
                      *(position[i].force.array[j]/robot->m_gearing.array[j])
                      *(position[i].force.array[j]/robot->m_gearing.array[j]));
    }
  }
  //ALPHA AND TEIJIN-SEIKI
  for(j=0;j<MAXROBOTAXIS;j++)
  {
    T.array[j]=pow(T.array[j]/nsum.array[j],3.0/10.0);
    n.array[j]=nsum.array[j]/tsum.array[j];
    p = pow(robot->m_ratedNmGear.array[j]/T.array[j],10.0/3.0);
    robot->m_lifeTimeGear.array[j] = 6000.0 * (robot->m_ratedRpmGear.array[j]/n.array[j]) * p;
    //MOTOR
    robot->m_Trms.array[j]=sqrt(Trms.array[j]/tsum.array[j]);
  }
}

/*void solveOne(tmpnPosition *position, tmpnFloat samplePeriod)
{
  int i,j;
  tmpnJointsUnion nsum,tsum,T,n,Trms;
  tmpnFloat p,rGear;
  i=0;
  solveIK(&temprobot,1,position);
  position[0].posRad.name.a=MMTOM(temprobot.m_max.z-position[0].jointSpace.name.a);
  position[0].posRad.name.b=DEGTORAD(position[0].jointSpace.name.b+90.0);
  position[0].posRad.name.c=DEGTORAD(position[0].jointSpace.name.c);
  position[0].posRad.name.d=DEGTORAD(position[0].jointSpace.name.d);
  position[0].posRad.name.e=DEGTORAD(position[0].jointSpace.name.e);
  for(j=0;j<5;j++)
  {
    //mm or deg
    position[i].dif.array[j]=(position[i+1].jointSpace.array[j]-position[i].jointSpace.array[j]);
    //1 sampleperiod = maxidx(antalsamples)/sec
    //mm or deg/sec
    position[i].speed.array[j]=position[i].dif.array[j]*samplePeriod;
    //motor rev/min
    position[i].rev.array[j]=position[i].speed.array[j]*60.0*temprobot.m_gearing.array[j]/temprobot.m_unit.array[j];
    //% off nominel speed
    position[i].pctRatedSpeed.array[j]=position[i].rev.array[j]*100.0/temprobot.m_ratedRPM.array[j];
  }
  //meter or rad/s
  position[i].speedRad.name.a=(position[i+1].posRad.name.a-position[i].posRad.name.a)*samplePeriod;
  for(j=1;j<5;j++)
    position[i].speedRad.array[j]=(position[i+1].posRad.array[j]-position[i].posRad.array[j])*samplePeriod;
//  resample(maxidx,position,&temprobot);
  for(j=0;j<5;j++)
  {
    position[i].accelRad.array[j]=position[i+1].speedRad.array[j]-position[i].speedRad.array[j];
    position[i].accelRad.array[j]*=samplePeriod;
  }
  for(j=0;j<5;j++)
  {
    setLink(&temprobot.m_Link[j],j);
  }
  dynomads(&temprobot,&position[i]);
  //LIFETIME FOR GEAR AND MOTOR
  for(j=0;j<5;j++)
  {
    Trms.array[j]=0.0;
    nsum.array[j]=0.0;
    tsum.array[j]=0.0;
    T.array[j]=0.0;
  }
  //ALPHA AND TEIJIN-SEIKI
  for(j=0;j<5;j++)
  {
    //GEAR
    p = pow(fabs(position[i].force.array[j]),10.0/3.0);
    rGear = fabs(position[i].rev.array[j]/temprobot.m_gearing.array[j]);
    T.array[j] += (1.0/samplePeriod) * rGear * p;
    nsum.array[j] += (1.0/samplePeriod) * rGear;
    tsum.array[j] += (1.0/samplePeriod);
    //MOTOR
    Trms.array[j] += ((1.0/samplePeriod)
                    *(position[i].force.array[j]/temprobot.m_gearing.array[j])
                    *(position[i].force.array[j]/temprobot.m_gearing.array[j]));
  }
  //ALPHA AND TEIJIN-SEIKI
  for(j=0;j<5;j++)
  {
    T.array[j]=pow(T.array[j]/nsum.array[j],3.0/10.0);
    n.array[j]=nsum.array[j]/tsum.array[j];
    p = pow(robot->m_ratedNmGear.array[j]/T.array[j],10.0/3.0);
    robot->m_lifeTimeGear.array[j] = 6000.0 * (robot->m_ratedRpmGear.array[j]/n.array[j]) * p;
    //MOTOR
    robot->m_Trms.array[j]=sqrt(Trms.array[j]/tsum.array[j]);
  }
}
  */
static tmpnPath ipath;

void B_SPLINE(tmpnRobot *robot, tmpnPath *path, tmpnPath *ipath, int nos, int order);

void mpnSplineJointSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos);
void mpnSplineTaskSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos);

/*tmpnFloat findClosestPoint(int startidx
                ,tmpnVector *point
                ,int maxidx
                ,tmpnPosition *position)
{
  tmpnVector tempd;
  int i;
  int mi=0;
  tmpnFloat dist,mindist;
  mindist=999999.0;
  mi=0;
  for(i=startidx;i<maxidx;i++)
  {
    tempd.x = (point->x - position[i].taskSpace.x) * (point->x - position[i].taskSpace.x);
    tempd.y = (point->y - position[i].taskSpace.y) * (point->y - position[i].taskSpace.y);
    tempd.z = (point->z - position[i].taskSpace.z) * (point->z - position[i].taskSpace.z);
    tempd.v = (point->v - position[i].taskSpace.v) * (point->v - position[i].taskSpace.v);
    tempd.w = (point->w - position[i].taskSpace.w) * (point->w - position[i].taskSpace.w);
    tempd.u = (point->u - position[i].taskSpace.u) * (point->u - position[i].taskSpace.u);
    dist = sqrt(tempd.x+tempd.y+tempd.z+tempd.v+tempd.w+tempd.u);
    if(dist<=mindist)
    {
      mindist=dist;
      mi=i;
    }
  }
  
}*/

void solvePositionHint(int maxpidx
                      ,tmpnPosHint *poshint
                      ,int maxidx
                      ,tmpnPosition *position
                      ,int bsplinesamples)
{
  int p,i,ii=1;
  for(p=0;p<maxpidx;p++)
  {
    for(i=ii;i<maxidx;i++)
    {
      //TODO right now we depend on POSITIONHINT to be 0,1,2,3,4,5,6,7,8,9
      // we could calgulate middle of to points instead of testing with 0.5
      if(position[i].positionhint+0.50005>poshint[p].positionhint)
      {
        poshint[p].i=i; //not used anymore TODO remove
        //TODO better calgulation off time
        poshint[p].time=position[i].t;
        ii=i;
        i=maxidx;
      }
    }
  }
}

void generatePath(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path)
{
  int j;
  if(pathdef==NULL||path==NULL) return;
  path->maxidx=0;
  if(pathdef->maxidx<=1) return;
  memcpy(&temprobot,robot,sizeof(temprobot));
  temprobot.m_snapToGrid=FALSE;
  switch(pathdef->spline)
  {
    case 5://for test purpuse only!!!!!!!!!
            //simulate joint interpolation between keypoints on
            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            copyKeypoint(path, pathdef);
            //calgulate joint acuator positions from cartesian taskSpace
            solveIK(&temprobot,path->maxidx,path->position);
            mpnSplineJointSpace(&temprobot, pathdef, path, &ipath, pathdef->samplesBetweenKeypoints);
            copyPath(path, &ipath);
            break;
    case 6://for test purpuse only!!!!!!!!!
            //simulate task interpolation between keypoints on
            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            copyKeypoint(path, pathdef);
            mpnSplineTaskSpace(&temprobot, pathdef, path, &ipath, pathdef->samplesBetweenKeypoints);
            //calgulate joint acuator positions from cartesian taskSpace
            solveIK(&temprobot,ipath.maxidx,ipath.position);
            copyPath(path, &ipath);
            break;
    case 7: //for test purpuse only!!!!!!!!!
            //taskspace interpolation between keypoints using bspline
            //+ joint interpolation on TRIO using B_SPLINE
            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            path->maxidx = bspline(pathdef->maxidx
                                  ,pathdef->splineorder
                                  ,pathdef->samplesBetweenKeypoints
                                  ,pathdef->keypoint
                                  ,path->position
                                  ,0);
            //calgulate joint acuator positions from cartesian taskSpace
            solveIK(&temprobot,path->maxidx,path->position);
            break;
    case 8: //THIS IS THE NEW FUNCTION USED IN PRODUCTION (without TRIO simulation)
            //TRIO using B_SPLINE
            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            //copy keyPoints to cartesian taskSpace
            copyKeypoint(path, pathdef);
            //calgulate joint acuator positions from cartesian taskSpace
            solveIK(&temprobot,path->maxidx,path->position);
	    break;
    case 9://THIS IS THE OLD FUNCTION USED IN PRODUCTION (without TRIO simulation)
            //DUE TO BUG HAS BEEN REPALCED BY B_SPLINE
            //taskspace interpolation between keypoints using bspline
            //+ joint interpolation on TRIO using B_SPLINE
            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            path->maxidx = bspline(pathdef->maxidx
                                  ,pathdef->splineorder
                                  ,pathdef->samplesBetweenKeypoints
                                  ,pathdef->keypoint
                                  ,path->position
                                  ,0);
            solve(&temprobot,path->maxidx,path->position,pathdef->maxTime,&pathdef->maxSpeed,pathdef->splineorder);
            break;
  }
  //TRIO simulation in order to calgulate PositionHint
  if(pathdef->spline==8)
  {
    B_SPLINE(&temprobot, path, &ipath, pathdef->samplesBetweenKeypoints,pathdef->splineorder);
  }
  else
  {
    copyPath(&ipath, path);
  }
  solveFK(&temprobot,ipath.maxidx,ipath.position);
  solve(&temprobot,ipath.maxidx,ipath.position,pathdef->maxTime,&pathdef->maxSpeed,pathdef->splineorder);
  
  hackPositionHint(&ipath, pathdef);
  solvePositionHint(pathdef->maxpidx
        ,pathdef->poshint
		    ,ipath.maxidx
		    ,ipath.position
		    ,pathdef->samplesBetweenKeypoints);
  if(temprobot.m_simulateTRIO==1)
  {
    copyPath(path, &ipath);
  }


  for(j=0;j<MAXROBOTAXIS;j++)
  {
    robot->m_lifeTimeGear.array[j] = temprobot.m_lifeTimeGear.array[j];
    robot->m_Trms.array[j]=temprobot.m_Trms.array[j];
  }
}

void hackPositionHint(tmpnPath *path, tmpnPathDef *pathdef) 
{
  if (!strcmp(rs_param.script,"308C14")&&(pathdef->pathtype==21)) 
  {
    int i;
    tmpnFloat positionhint=-1.0;
    tmpnFloat minSpecialPct=0.5;
    tmpnFloat specialPos=920.0;
    tmpnFloat ttime=path->position[path->maxidx-1].t;
    for(i=0;i<path->maxidx;i++)
    {
      tmpnFloat Pct=path->position[i].t/ttime;
      if ((Pct>minSpecialPct)&&(path->position[i].taskSpace.y<=specialPos))
      {
				path->position[i].positionhint++;
				if (positionhint==-1.0)
					positionhint=path->position[i].positionhint;
      }
    }
    if (positionhint!=-1.0)
    {
      pathdef->poshint[pathdef->maxpidx].positionhint=positionhint;
      pathdef->maxpidx++;
    }
  }
}

void copyKeypoint(tmpnPath *path, tmpnPathDef *pathdef)
{
  int i;
  path->maxidx=pathdef->maxidx;
  for(i=0;i<pathdef->maxidx;i++)
  {
    path->position[i].taskSpace.x = pathdef->keypoint[i].x;
    path->position[i].taskSpace.y = pathdef->keypoint[i].y;
    path->position[i].taskSpace.z = pathdef->keypoint[i].z;
    path->position[i].taskSpace.v = pathdef->keypoint[i].v;
    path->position[i].taskSpace.w = pathdef->keypoint[i].w;
    path->position[i].taskSpace.u = pathdef->keypoint[i].u;
    path->position[i].dt = pathdef->keypoint[i].dt;
    path->position[i].t = pathdef->keypoint[i].t;
    path->position[i].sp = pathdef->keypoint[i].sp;
    path->position[i].statehint   = pathdef->keypoint[i].statehint;
    path->position[i].positionhint   = pathdef->keypoint[i].positionhint;
    path->position[i].tcpidx   = pathdef->keypoint[i].tcpidx;
    path->position[i].keypoint = &pathdef->keypoint[i];
  }
}

void copyPath(tmpnPath *dest, tmpnPath *source)
{
  int i;
  dest->maxidx=source->maxidx;
  for(i=0;i<source->maxidx;i++)
  {
    dest->position[i] = source->position[i];
  }
}

/***************************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby. email: thn@mpn.nu *
* All rights reserved.                                                                 *
*                                                                                      *
*   Subroutine to generate spline points                                               *
*                                                                                      *
*   maxidx        = current number of points in CAMBOX                                 *
*   samples  = number of inserted points between keypoints                        *
*   p1,p2,p3,p4   = the four keypoints needed to interpolate between p2 and p3         *
*   cambox        = address of first expanded CAMBOX table element                     *
*                                                                                      *
***************************************************************************************/
void splinePoints(int *maxidx, int samples, splineFloat *cambox, splineFloat p1, splineFloat p2, splineFloat p3, splineFloat p4)
{
  splineFloat onesixth=1.0/6.0;
  splineFloat t,stepsize;
  splineFloat a0,a1,a2,a3;
  int i;
  a0 = ( -p1 + 3.0*p2 - 3.0*p3 + p4) * onesixth;
  a1 = ( 3.0*p1 - 6.0*p2 + 3.0*p3 ) * onesixth;
  a2 = (-3.0*p1 + 3.0*p3 ) * onesixth;
  a3 = ( p1 + 4.0*p2 + p3 ) * onesixth;
  stepsize=1.0/(splineFloat)samples;

  for(i=0;i<samples;i++)
  {
		t=i*stepsize;
    cambox[*maxidx] = a3 + t*(a2 + t*(a1 + t*a0));
    (*maxidx)++;    
  }
}
/***************************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby. email: thn@mpn.nu *
* All rights reserved.                                                                 *
*                                                                                      *
*   Subroutine to generate a CAMBOX table using third order B-spline interpolation     *
*   with multiple start and stop points                                                *
*   numofkeypoints = number of points in input table                                   *
*   keypoint       = address of first input table element                              *
*   samples   = number of inserted points between keypoints                       *
*   cambox         = address of first expanded CAMBOX table element                    *
*                                                                                      *
*   returns number of generated elements in CAMBOX                                     *
***************************************************************************************/
int splineExpand(int numofkeypoints, splineFloat *keypoint, int samples, splineFloat *cambox)
{
  int i,pmaxidx;
  if(numofkeypoints<4) return 0;
//  cambox[0] = keypoint[0];
  pmaxidx=0;
  splinePoints(&pmaxidx,samples,cambox,keypoint[0],keypoint[0],keypoint[0],keypoint[1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[0],keypoint[0],keypoint[1],keypoint[2]);
  for ( i=2; i < numofkeypoints-1; i++)
    splinePoints(&pmaxidx,samples,cambox,keypoint[i-2],keypoint[i-1],keypoint[i],keypoint[i+1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[numofkeypoints-3],keypoint[numofkeypoints-2],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[numofkeypoints-2],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1]);
  cambox[pmaxidx] = keypoint[numofkeypoints-1];
  pmaxidx++;

/*  for(i=0;i<pmaxidx-1;i++)
  {
    if(fabs(cambox[i+1]-cambox[i])<0.0001)
    {
      cambox[i+1]=cambox[i];
    }
  }
  */
  return pmaxidx;
}

int timeExpand(int numofkeypoints, splineFloat *keypoint, int samples, splineFloat *cambox)
{
  int i,pmaxidx;
	tmpnFloat diff;
  if(numofkeypoints<4) return 0;
  pmaxidx=(numofkeypoints+1)*samples;
	diff=(keypoint[numofkeypoints-1]-keypoint[0])/((tmpnFloat)pmaxidx);
  for ( i=0; i < pmaxidx; i++)
	{
		cambox[i]=diff*i;
	}
  return pmaxidx;
}

void B_SPLINE(tmpnRobot *robot, tmpnPath *path, tmpnPath *ipath, int nos, int order)
{
  int i,j,p;
  splineFloat table[MAXKEYPOINTS];
  splineFloat cambox[MAXPOSITIONS];
  //A
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.a;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.a=cambox[i];
  //B
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.b;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.b=cambox[i];
  //C
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.c;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.c=cambox[i];
  //D
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.d;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.d=cambox[i];
  //E
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.e;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.e=cambox[i];
  //F
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.f;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.f=cambox[i];
  //t
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].t;
  if(order==4)
    ipath->maxidx=timeExpand(path->maxidx,table,nos,cambox);
  else
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].t=cambox[i];
  
  //dt
  if(order!=4)
  {
    for(i=0;i<path->maxidx;i++)
      table[i]=path->position[i].dt;
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
    for(i=0;i<ipath->maxidx;i++)
      ipath->position[i].dt=cambox[i];
  }
  //sp
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].sp;
  if(order==4)
    ipath->maxidx=timeExpand(path->maxidx,table,nos,cambox);
  else
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].sp=cambox[i];

  //positionhint
  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].positionhint;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].positionhint=cambox[i];

  p=1;
  ipath->position[0].statehint = path->position[0].statehint;
  ipath->position[0].keypoint = path->position[0].keypoint;
  ipath->position[0].tcpidx = path->position[0].tcpidx;
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[0].statehint;
    ipath->position[p].keypoint = path->position[0].keypoint;
    ipath->position[p++].tcpidx = path->position[0].tcpidx;
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[1].statehint;
    ipath->position[p].keypoint = path->position[1].keypoint;
    ipath->position[p++].tcpidx = path->position[1].tcpidx;
  }
  for(i=2;i<path->maxidx-1;i++)
  {
    for(j=0;j<nos;j++)
    {
      ipath->position[p].statehint = path->position[i].statehint;
      ipath->position[p].keypoint = path->position[i].keypoint;
      ipath->position[p++].tcpidx = path->position[i].tcpidx;
    }
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[path->maxidx-2].statehint;
    ipath->position[p].keypoint = path->position[path->maxidx-2].keypoint;
    ipath->position[p++].tcpidx = path->position[path->maxidx-2].tcpidx;
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[path->maxidx-1].statehint;
    ipath->position[p].keypoint = path->position[path->maxidx-1].keypoint;
    ipath->position[p++].tcpidx = path->position[path->maxidx-1].tcpidx;
  }
    
}

//this function should be impl. on TRIO due to float precision problems with B_SPLINE
void mpnSplineJointSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos)
{
  int i;
  tmpnKeyPoint keytable[MAXKEYPOINTS];
  tmpnPosition postable[MAXPOSITIONS];
  for(i=0;i<path->maxidx;i++)
  {
    keytable[i].x=path->position[i].actuatorSpace.name.a;
    keytable[i].y=path->position[i].actuatorSpace.name.b;
    keytable[i].z=path->position[i].actuatorSpace.name.c;
    keytable[i].v=path->position[i].actuatorSpace.name.d;
    keytable[i].w=path->position[i].actuatorSpace.name.e;
    keytable[i].u=path->position[i].actuatorSpace.name.f;
    keytable[i].t=path->position[i].t;
    keytable[i].statehint=path->position[i].statehint;
    keytable[i].positionhint=path->position[i].positionhint;
    keytable[i].tcpidx   =path->position[i].tcpidx;
  }
  ipath->maxidx = bspline(path->maxidx
                          ,pathdef->splineorder
                          ,nos
                          ,keytable
                          ,postable
                          ,0/*pathdef->splineorder-2*/);
  for(i=0;i<ipath->maxidx;i++)
  {
    ipath->position[i].actuatorSpace.name.a=postable[i].taskSpace.x;
    ipath->position[i].actuatorSpace.name.b=postable[i].taskSpace.y;
    ipath->position[i].actuatorSpace.name.c=postable[i].taskSpace.z;
    ipath->position[i].actuatorSpace.name.d=postable[i].taskSpace.v;
    ipath->position[i].actuatorSpace.name.e=postable[i].taskSpace.w;
    ipath->position[i].actuatorSpace.name.f=postable[i].taskSpace.u;
    ipath->position[i].t                   =postable[i].t;
    ipath->position[i].statehint=postable[i].statehint;
    ipath->position[i].positionhint=postable[i].positionhint;
    ipath->position[i].tcpidx=postable[i].tcpidx;
  }
}

void mpnSplineTaskSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos)
{
  int i;
  tmpnKeyPoint keytable[MAXKEYPOINTS];
  tmpnPosition postable[MAXPOSITIONS];
  for(i=0;i<path->maxidx;i++)
  {
    keytable[i].x=path->position[i].taskSpace.x;
    keytable[i].y=path->position[i].taskSpace.y;
    keytable[i].z=path->position[i].taskSpace.z;
    keytable[i].v=path->position[i].taskSpace.v;
    keytable[i].w=path->position[i].taskSpace.w;
    keytable[i].u=path->position[i].taskSpace.u;
    keytable[i].t=path->position[i].t;
    keytable[i].statehint=path->position[i].statehint;
    keytable[i].positionhint=path->position[i].positionhint;
  }
  ipath->maxidx = bspline(path->maxidx
                          ,pathdef->splineorder
                          ,nos
                          ,keytable
                          ,postable
                          ,0/*pathdef->splineorder-2*/);
  for(i=0;i<ipath->maxidx;i++)
  {
    ipath->position[i].taskSpace.x=postable[i].taskSpace.x;
    ipath->position[i].taskSpace.y=postable[i].taskSpace.y;
    ipath->position[i].taskSpace.z=postable[i].taskSpace.z;
    ipath->position[i].taskSpace.v=postable[i].taskSpace.v;
    ipath->position[i].taskSpace.w=postable[i].taskSpace.w;
    ipath->position[i].taskSpace.u=postable[i].taskSpace.u;
    ipath->position[i].t          =postable[i].t;
    ipath->position[i].statehint=postable[i].statehint;
    ipath->position[i].positionhint=postable[i].positionhint;
  }
}

