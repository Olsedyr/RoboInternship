/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*                                                                           *
* based on dynamic model created by Mads Lundstroem                         *
*                                                                           *
*****************************************************************************/
#ifndef MPNGUIDE
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#endif                        
#include "dynomads.h"

/* Prototypes */
static tmpnDouble avek(int i);
static tmpnDouble alphavek(int i);
static tmpnDouble dvek(int i);
static tmpnDouble ddvek(int i);
static tmpnDouble dddvek(int i);
static tmpnDouble tvek(int i);
static tmpnDouble dtvek(int i);
static tmpnDouble ddtvek(int i);
//static tmpnDouble** TT(int i); //not used
static tmpnDouble* P(int i,int timestep);
static int R(int i,int timestep);
static tmpnDouble* computeV(int i,int timestep);
static tmpnDouble* computeOmega(int i,int timestep);
static tmpnDouble* computeOmegaDot(int i,int timestep);
static tmpnDouble* computeVDot(int i,int timestep);
static tmpnDouble* computeForce(int i, int timestep);
static tmpnDouble* computeN(int i, int timestep);
static tmpnDouble* inwardForce(int i, int timestep);
static tmpnDouble* inwardTorque(int i, int timestep);
void printvec(tmpnDouble* vec);

//Joint variables
static tmpnDouble q[5];
//Derivatives of joint variables
static tmpnDouble dq[5];
//tmpnDouble derivatives of joint angles/displacements
static tmpnDouble ddq[5];
//avek = Joint length
static tmpnDouble L[6];
// Centre of Mass displacements
static tmpnDouble pdis[5][3];
/* Link Masses */
static tmpnDouble Mass[5];
// Inertia tensors for link 0 to 4
static tmpnDouble I[5][3][3];
#define I1 I[0]
#define I2 I[1]
#define I3 I[2]
#define I4 I[3]
#define I5 I[4]
/* Denavit Hartenberg Parameters */

static tmpnDouble avek(int i) {
  return L[i];
}

static tmpnDouble alphavek(int i) {
  static tmpnDouble alv[5]={0,0,0,0,PI/2};
  return alv[i];
}

static tmpnDouble dvek(int i) {
  static tmpnDouble dv[5]={0,0,0,0,0};
  if (i==0) return q[0];
  return dv[i];
}

static tmpnDouble ddvek(int i) {
  static tmpnDouble dv[5]={0,0,0,0,0};
  if (i==0) return dq[0];
  return dv[i];
}

static tmpnDouble dddvek(int i) {
  static tmpnDouble dv[5]={0,0,0,0,0};
  if (i==0) return ddq[0];
  return dv[i];
}

//tvek = position in rad's
static tmpnDouble tvek(int i) {
  if (i==0) return 0;
  if (i==1) return q[1];
  if (i==2) return q[2];
  if (i==3) return q[3]+PI/2;
  return q[4];
}

static tmpnDouble dtvek(int i) {
  if (i==0) return 0;
  return dq[i];
}

static tmpnDouble ddtvek(int i) {
  if (i==0) return 0;
  return ddq[i];
}

static tmpnDouble ptrans[6][3];

static tmpnDouble* P(int i,int timestep) {
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if ((timestep==last_timestep[i])||(i>0)) {  // Only P(first) is time-variable
    if (last_timestep[i]!=-1) return ptrans[i];
  }
  last_timestep[i] = timestep;
  if (i==5) {
    ptrans[i][0] = 0;
    ptrans[i][1] = 0;
    ptrans[i][2] = 0;
  }
  else
  {
    ptrans[i][0] = avek(i);
    ptrans[i][1] = -sin(alphavek(i))*dvek(i);
    ptrans[i][2] = cos(alphavek(i))*dvek(i);
  }
  return ptrans[i];
}

static tmpnDouble rtrans[6][3][3];

int R(int i,int timestep) {
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i]||(i==0)) { //R(first) is not time-dependent
    if (last_timestep[i]!=-1) return i;
  }
  last_timestep[i] = timestep;
  if (i==5) {
    rtrans[i][0][0] = 1;
    rtrans[i][0][1] = 0;
    rtrans[i][0][2] = 0;
    rtrans[i][1][0] = 0;
    rtrans[i][1][1] = 1;
    rtrans[i][1][2] = 0;
    rtrans[i][2][0] = 0;
    rtrans[i][2][1] = 0;
    rtrans[i][2][2] = 1;
  }
  else {
    rtrans[i][0][0] = cos(tvek(i));
    rtrans[i][0][1] = -sin(tvek(i));
    rtrans[i][0][2] = 0;
    rtrans[i][1][0] = sin(tvek(i))*cos(alphavek(i));
    rtrans[i][1][1] = cos(tvek(i))*cos(alphavek(i));
    rtrans[i][1][2] = -sin(alphavek(i));
    rtrans[i][2][0] = sin(tvek(i))*sin(alphavek(i));
    rtrans[i][2][1] = cos(tvek(i))*sin(alphavek(i));
    rtrans[i][2][2] = cos(alphavek(i));
  }
  return i;
}

static tmpnDouble vvec[6][3];
//timestep shold be switched if parameters change
tmpnDouble* computeV(int i,int timestep) {
  tmpnDouble* o;
  tmpnDouble* p;
  tmpnDouble* l;
  tmpnDouble temp[3];
  int r;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    vvec[5][0]=0.0;
    vvec[5][1]=0.0;
    vvec[5][2]=0.0;
    return vvec[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return vvec[i];
  }
  last_timestep[i] = timestep;
  o = computeOmega(i-1,timestep);
  p = P(i, timestep);
  l = computeV(i-1,timestep);
  r = R(i,timestep);
  vvec[i][0] = (l[0]+(o[1]*p[2]-o[2]*p[1]));
  vvec[i][1] = (l[1]+(o[2]*p[0]-o[0]*p[2]));
  vvec[i][2] = (l[2]+(o[0]*p[1]-o[1]*p[0]));
  temp[0] = rtrans[r][0][0]*vvec[i][0]+rtrans[r][1][0]*vvec[i][1]+rtrans[r][2][0]*vvec[i][2];
  temp[1] = rtrans[r][0][1]*vvec[i][0]+rtrans[r][1][1]*vvec[i][1]+rtrans[r][2][1]*vvec[i][2];
  temp[2] = rtrans[r][0][2]*vvec[i][0]+rtrans[r][1][2]*vvec[i][1]+rtrans[r][2][2]*vvec[i][2];
  vvec[i][0] = temp[0];
  vvec[i][1] = temp[1];
  vvec[i][2] = temp[2] + ddvek(i);
  return vvec[i];
}

static tmpnDouble om[6][3];

tmpnDouble* computeOmega(int i,int timestep) {
  tmpnDouble* ino;
  int r;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    om[5][0] = 0.0;
    om[5][1] = 0.0;
    om[5][2] = 0.0;
    return om[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return om[i];
  }
  last_timestep[i] = timestep;
  ino = computeOmega(i-1,timestep);
  r = R(i,timestep);
  om[i][0] = rtrans[r][0][0]*ino[0]+rtrans[r][1][0]*ino[1]+rtrans[r][2][0]*ino[2];
  om[i][1] = rtrans[r][0][1]*ino[0]+rtrans[r][1][1]*ino[1]+rtrans[r][2][1]*ino[2];
  om[i][2] = rtrans[r][0][2]*ino[0]+rtrans[r][1][2]*ino[1]+rtrans[r][2][2]*ino[2]+dtvek(i);
  return om[i];
}
static tmpnDouble omd[6][3];

tmpnDouble* computeOmegaDot(int i,int timestep) {
  tmpnDouble* inod;
  tmpnDouble* ino;
  int r;
  tmpnDouble temp[3];
  tmpnDouble tem[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    omd[5][0] = 0.0;
    omd[5][1] = 0.0;
    omd[5][2] = 0.0;
    return omd[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return omd[i];
  }
  last_timestep[i] = timestep;
  r = R(i,timestep);
  inod = computeOmegaDot(i-1,timestep);
  ino = computeOmega(i-1,timestep);
  temp[0] = rtrans[r][0][0]*ino[0]+rtrans[r][1][0]*ino[1]+rtrans[r][2][0]*ino[2];
  temp[1] = rtrans[r][0][1]*ino[0]+rtrans[r][1][1]*ino[1]+rtrans[r][2][1]*ino[2];
  temp[2] = rtrans[r][0][2]*ino[0]+rtrans[r][1][2]*ino[1]+rtrans[r][2][2]*ino[2];
  tem[0] = rtrans[r][0][0]*inod[0]+rtrans[r][1][0]*inod[1]+rtrans[r][2][0]*inod[2];
  tem[1] = rtrans[r][0][1]*inod[0]+rtrans[r][1][1]*inod[1]+rtrans[r][2][1]*inod[2];
  tem[2] = rtrans[r][0][2]*inod[0]+rtrans[r][1][2]*inod[1]+rtrans[r][2][2]*inod[2];
  omd[i][0] = tem[0]+temp[1]*dtvek(i);
  omd[i][1] = tem[1]-temp[0]*dtvek(i);
  omd[i][2] = tem[2]+ddtvek(i);
  return omd[i];
}
static tmpnDouble ved[6][3];
tmpnDouble* computeVDot(int i,int timestep) {
  tmpnDouble* invd;
  tmpnDouble* inod;
  tmpnDouble* ino;
  tmpnDouble* o;
  int r;
  tmpnDouble* p;
  tmpnDouble temp[3];
  tmpnDouble tem[3];
  tmpnDouble temo[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    ved[5][0] = G; //9.81
    ved[5][1] = 0.0;
    ved[5][2] = 0.0;
    return ved[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return ved[i];
  }
  last_timestep[i] = timestep;
  r = R(i,timestep);
  inod = computeOmegaDot(i-1,timestep);
  ino = computeOmega(i-1,timestep);
  o = computeOmega(i,timestep);
  invd = computeVDot(i-1,timestep);
  p = P(i,timestep);
  temp[0] = (ino[1]*p[2]-ino[2]*p[1]);
  temp[1] = (ino[2]*p[0]-ino[0]*p[2]);
  temp[2] = (ino[0]*p[1]-ino[1]*p[0]);
  temo[0] = (inod[1]*p[2]-inod[2]*p[1]);
  temo[1] = (inod[2]*p[0]-inod[0]*p[2]);
  temo[2] = (inod[0]*p[1]-inod[1]*p[0]);
  tem[0] = temo[0]+(ino[1]*temp[2]-ino[2]*temp[1])+invd[0];
  tem[1] = temo[1]+(ino[2]*temp[0]-ino[0]*temp[2])+invd[1];
  tem[2] = temo[2]+(ino[0]*temp[1]-ino[1]*temp[0])+invd[2];
  temp[0] = rtrans[r][0][0]*tem[0]+rtrans[r][1][0]*tem[1]+rtrans[r][2][0]*tem[2];
  temp[1] = rtrans[r][0][1]*tem[0]+rtrans[r][1][1]*tem[1]+rtrans[r][2][1]*tem[2];
  temp[2] = rtrans[r][0][2]*tem[0]+rtrans[r][1][2]*tem[1]+rtrans[r][2][2]*tem[2];
  ved[i][0] = temp[0]+2*o[1]*ddvek(i);
  ved[i][1] = temp[1]-2*o[0]*ddvek(i);
  ved[i][2] = temp[2]+dddvek(i);
  return ved[i];
}

//Firsts computes VDotCent (acceleration) and then the force

static tmpnDouble vedc[5][3];
tmpnDouble* computeForce(int i, int timestep) {
  int j;
  tmpnDouble* od;
  tmpnDouble* o;
  tmpnDouble* vd;
  tmpnDouble temp[3];
  tmpnDouble tem[3];
  static int last_timestep[5]={-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return vedc[i];
  }
  last_timestep[i] = timestep;
  od = computeOmegaDot(i, timestep);
  o = computeOmega(i, timestep);
  vd = computeVDot(i, timestep);
  temp[0] = (od[1]*pdis[i][2]-od[2]*pdis[i][1]);
  temp[1] = (od[2]*pdis[i][0]-od[0]*pdis[i][2]);
  temp[2] = (od[0]*pdis[i][1]-od[1]*pdis[i][0]);
  tem[0] = (o[1]*pdis[i][2]-o[2]*pdis[i][1]);
  tem[1] = (o[2]*pdis[i][0]-o[0]*pdis[i][2]);
  tem[2] = (o[0]*pdis[i][1]-o[1]*pdis[i][0]);
  vedc[i][0] = temp[0]+(o[1]*tem[2]-o[2]*tem[1])+vd[0];
  vedc[i][1] = temp[1]+(o[2]*tem[0]-o[0]*tem[2])+vd[1];
  vedc[i][2] = temp[2]+(o[0]*tem[1]-o[1]*tem[0])+vd[2];
  for(j=0;j<3;j++) vedc[i][j] *= Mass[i];
  return vedc[i];
}

static tmpnDouble cn[5][3];
tmpnDouble* computeN(int i, int timestep) {
  tmpnDouble* o;
  tmpnDouble* od;
  tmpnDouble temp[3];
  tmpnDouble tem[3];
  int j;
  static int last_timestep[5]={-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i])
  {
    if (last_timestep[i]!=-1) return cn[i];
  }
  last_timestep[i] = timestep;
  o = computeOmega(i, timestep);
  od = computeOmegaDot(i, timestep);
  for (j=0;j<3;j++)
  {
    temp[j] = I[i][j][0]*od[0]+I[i][j][1]*od[1]+I[i][j][2]*od[2];
    tem[j] = I[i][j][0]*o[0]+I[i][j][1]*o[1]+I[i][j][2]*o[2];
  }
  cn[i][0] = temp[0]+(o[1]*tem[2]-o[2]*tem[1]);
  cn[i][1] = temp[1]+(o[2]*tem[0]-o[0]*tem[2]);
  cn[i][2] = temp[2]+(o[0]*tem[1]-o[1]*tem[0]);
  return cn[i];
}


static tmpnDouble inwaf[6][3];
tmpnDouble* inwardForce(int i, int timestep) {
  tmpnDouble* outinwf;
  int outr;
  tmpnDouble* f;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==5) {
    inwaf[5][0]=0;
    inwaf[5][1]=0;
    inwaf[5][2]=0;
    return inwaf[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return inwaf[i];
  }
  last_timestep[i] = timestep;
  outr = R(i+1,timestep);
  f = computeForce(i,timestep);
  outinwf = inwardForce(i+1,timestep);
  inwaf[i][0] = rtrans[outr][0][0]*outinwf[0]+rtrans[outr][0][1]*outinwf[1]+rtrans[outr][0][2]*outinwf[2]+f[0];
  inwaf[i][1] = rtrans[outr][1][0]*outinwf[0]+rtrans[outr][1][1]*outinwf[1]+rtrans[outr][1][2]*outinwf[2]+f[1];
  inwaf[i][2] = rtrans[outr][2][0]*outinwf[0]+rtrans[outr][2][1]*outinwf[1]+rtrans[outr][2][2]*outinwf[2]+f[2];
  return inwaf[i];
}

static tmpnDouble inwat[6][3];
tmpnDouble* inwardTorque(int i, int timestep) {
  tmpnDouble* outinwt;
  tmpnDouble* outinwf;
  int outr;
  tmpnDouble* t;
  tmpnDouble* f;
  tmpnDouble* p;
  tmpnDouble temp[3];
  tmpnDouble temo[3];
  tmpnDouble tem[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==5) {
    inwat[5][0]=0;
    inwat[5][1]=0;
    inwat[5][2]=0;
    return inwat[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return inwat[i];
  }
  last_timestep[i] = timestep;
  outr = R(i+1,timestep);
  t = computeN(i,timestep);
  f = computeForce(i,timestep);
  p = P(i+1,timestep);
  outinwf = inwardForce(i+1,timestep);
  outinwt = inwardTorque(i+1,timestep);
  temp[0] = rtrans[outr][0][0]*outinwt[0]+rtrans[outr][0][1]*outinwt[1]+rtrans[outr][0][1]*outinwt[2]+t[0];
  temp[1] = rtrans[outr][1][0]*outinwt[0]+rtrans[outr][1][1]*outinwt[1]+rtrans[outr][1][2]*outinwt[2]+t[1];
  temp[2] = rtrans[outr][2][0]*outinwt[0]+rtrans[outr][2][1]*outinwt[1]+rtrans[outr][2][2]*outinwt[2]+t[2];
  tem[0] = (pdis[i][1]*f[2]-pdis[i][2]*f[1]);
  tem[1] = (pdis[i][2]*f[0]-pdis[i][0]*f[2]);
  tem[2] = (pdis[i][0]*f[1]-pdis[i][1]*f[0]);
  temo[0] = rtrans[outr][0][0]*outinwf[0]+rtrans[outr][0][1]*outinwf[1]+rtrans[outr][0][1]*outinwf[2];
  temo[1] = rtrans[outr][1][0]*outinwf[0]+rtrans[outr][1][1]*outinwf[1]+rtrans[outr][1][2]*outinwf[2];
  temo[2] = rtrans[outr][2][0]*outinwf[0]+rtrans[outr][2][1]*outinwf[1]+rtrans[outr][2][2]*outinwf[2];
  inwat[i][0] = (p[1]*temo[2]-p[2]*temo[1])+tem[0]+temp[0];
  inwat[i][1] = (p[2]*temo[0]-p[0]*temo[2])+tem[1]+temp[1];
  inwat[i][2] = (p[0]*temo[1]-p[1]*temo[0])+tem[2]+temp[2];
  return inwat[i];
}

void setq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble e) {
  q[0]=a;
  q[1]=b;
  q[2]=c;
  q[3]=d;
  q[4]=e;
}

void setdq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble e) {
  dq[0]=a;
  dq[1]=b;
  dq[2]=c;
  dq[3]=d;
  dq[4]=e;
}

void setddq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble e) {
  ddq[0]=a;
  ddq[1]=b;
  ddq[2]=c;
  ddq[3]=d;
  ddq[4]=e;
}

void setLinkLength(tmpnDouble l, int idx)
{
  L[idx+1]=l*0.001;
//  L[0]=0.0;
//  L[1]=0.0;
  L[2]=L2;
  L[3]=L3;
//  L[4]=0.0;
  
}

static tmpnDouble Mfive;

void setMass(tmpnDouble m, int idx)
{
  Mass[idx]=m;
  if(idx==4) Mfive=m;
  if(idx==0) Mass[idx]=Mone;
  if(idx==1) Mass[idx]=Mtwo;
  if(idx==2) Mass[idx]=Mthree;
  if(idx==3) Mass[idx]=Mfour;
  if(idx==4) Mass[idx]=Mfive;
}
void setMassDisplacement(tmpnDouble p0, tmpnDouble p1, tmpnDouble p2, int idx)
{
  pdis[idx][0]=p0;
  pdis[idx][1]=p1;
  pdis[idx][2]=p2;
}
void setInertiaTensor(tmpnDouble i00,tmpnDouble i01,tmpnDouble i02
                     ,tmpnDouble i10,tmpnDouble i11,tmpnDouble i12
                     ,tmpnDouble i20,tmpnDouble i21,tmpnDouble i22
                     ,int idx)
{
  I[idx][0][0]=i00;
  I[idx][0][1]=i01;
  I[idx][0][2]=i02;
  I[idx][1][0]=i10;
  I[idx][1][1]=i11;
  I[idx][1][2]=i12;
  I[idx][2][0]=i20;
  I[idx][2][1]=i21;
  I[idx][2][2]=i22;
}

tmpnDouble oldtau(int i,int timestep) {
  if (i==0) return 0.025*(inwardForce(i,timestep)[2]);
  		//Force converted to Torque on gantry. T = F*arm
  return inwardTorque(i,timestep)[2];
}	

#include "tau.c"
