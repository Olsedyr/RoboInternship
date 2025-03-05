/** bopt.cpp
 *
 * \brief Optimizes Trajectory between 2 joint-configurations of MPN robotarm.
 * \author Mads Lundstroem
 * \date   27 February 2004
 *
 */

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tmpnrobot.h"
#include "bopt.h"

int debug_bopt=0;

inline tmpnDouble uniform(tmpnDouble min, tmpnDouble max)
{
  static const tmpnDouble rmax=RAND_MAX+1.0;
  return (max-min)*(rand())/rmax+min;
}

inline int posi(tmpnDouble a) {
  if (a<0) return 0;
  return 1;
}  

/* Lagrange interpolation (parabel)*/

inline tmpnDouble A(point p1,point p2,point p3) {
  return p1.y/((p1.x-p2.x)*(p1.x-p3.x)) + p2.y/((p2.x-p1.x)*(p2.x-p3.x)) + p3.y/((p3.x-p1.x)*(p3.x-p2.x));
}

inline tmpnDouble B(point p1,point p2,point p3) {
  return -1.0*((p1.x+p2.x)*p3.y/((p3.x-p1.x)*(p3.x-p2.x))+(p1.x+p3.x)*p2.y/((p2.x-p1.x)*(p2.x-p3.x))+(p2.x+p3.x)*p1.y/((p1.x-p2.x)*(p1.x-p3.x)));
}

tmpnDouble C(point p1,point p2,point p3) {
    return p1.x*p2.x*p3.y/((p3.x-p1.x)*(p3.x-p2.x))+ p1.x*p3.x*p2.y/((p2.x-p1.x)*(p2.x-p3.x))+p2.x*p3.x*p1.y/((p1.x-p2.x)*(p1.x-p3.x));
}

tmpnDouble Tparabelx(point p1,point p2,point p3) {
  tmpnDouble A,B;
	tmpnDouble temp1,temp2,temp3;
	temp1=p1.y/((p1.x-p2.x)*(p1.x-p3.x));
	temp2=p2.y/((p2.x-p1.x)*(p2.x-p3.x));
	temp3=p3.y/((p3.x-p1.x)*(p3.x-p2.x));
	A = temp1 + temp2 + temp3;
	B = -1.0*((p1.x+p2.x)*temp3+(p1.x+p3.x)*temp2+(p2.x+p3.x)*temp1);
  return -1.0*B/(2*A);
}

/*
inline tmpnDouble Tparabelx(point p1,point p2,point p3) {
  return -1.0*B(p1,p2,p3)/(2*A(p1,p2,p3));
}
*/

tmpnDouble Tparabely(point p1,point p2,point p3) {
  tmpnDouble a=A(p1,p2,p3);
  tmpnDouble b=B(p1,p2,p3);
  return -1.0*(b*b-4*a*C(p1,p2,p3))/(4*a);
}


bane::bane(const tmpnJointsDUnion startpunkt,const tmpnJointsDUnion starthast,const tmpnJointsDUnion slutpunkt,const tmpnJointsDUnion sluthast,tmpnJointsDUnion mv,tmpnJointsDUnion ma) {
  init(startpunkt,starthast,slutpunkt,sluthast,mv,ma);
}

void bane::init(const tmpnJointsDUnion startpunkt,const tmpnJointsDUnion starthast,const tmpnJointsDUnion slutpunkt,const tmpnJointsDUnion sluthast, tmpnJointsDUnion mv,tmpnJointsDUnion ma) {
  maxvels = mv;
  maxaccs = ma;
  controlpoints.pos[0]=startpunkt;
  controlpoints.pos[4]=slutpunkt; 
  controlpoints.vel[0]=starthast;
  controlpoints.vel[4]=sluthast;
  alphatot=0.0;
  for (int i=0;i<5;i++) {
    /* Startgaet */
    controlpoints.pos[1].array[i]=-0.1875*controlpoints.vel[4].array[i]+0.5625*controlpoints.vel[0].array[i]+0.15625*slutpunkt.array[i]+0.84375*startpunkt.array[i];
    controlpoints.pos[2].array[i]=-0.5*controlpoints.vel[4].array[i]+0.5*controlpoints.vel[0].array[i]+0.5*slutpunkt.array[i]+0.5*startpunkt.array[i]+0.0000001;
    controlpoints.pos[3].array[i]=-0.5625*controlpoints.vel[4].array[i]+0.1875*controlpoints.vel[0].array[i]+0.84375*slutpunkt.array[i]+0.15625*startpunkt.array[i];
    //controlpoints.pos[1].array[i]=controlpoints.pos[0].array[i]+0.25*(slutpunkt.array[i]-startpunkt.array[i]);
    //controlpoints.pos[2].array[i]=controlpoints.pos[0].array[i]+0.5*(slutpunkt.array[i]-startpunkt.array[i]);
    //controlpoints.pos[3].array[i]=controlpoints.pos[0].array[i]+0.75*(slutpunkt.array[i]-startpunkt.array[i]);
    /* Saet alpha for hvert joint */
    alpha[i] = findalpha(controlpoints,i);
    if (alpha[i]>alphatot) alphatot=alpha[i];
  }
	if(debug_bopt>0) printf("startalpha: %f %f %f %f %f\n", alpha[0],alpha[1],alpha[2],alpha[3],alpha[4]);
  for (int i=0;i<5;i++) {
    if (fabs(controlpoints.vel[0].array[i]/alphatot)>maxvels.array[i])   if(debug_bopt>0) printf("Warning!: Absolute value of startvelocity of joint %i initially choosen to big!\n Resulting in speed: %f\nResulting trajectory will not be optimal.\nLower startvelocity and retry method!\n",i+1,controlpoints.vel[0].array[i]/alphatot);
    if (fabs(controlpoints.vel[4].array[i]/alphatot)>maxvels.array[i])   if(debug_bopt>0) printf("Warning!: Absolute value of endvelocity of joint %i initially choosen to big!\n Resulting in speed: %f\nResulting trajectory will not be optimal.\nLower endvelocity and retry method!\n",i+1,controlpoints.vel[4].array[i]/alphatot);
  }
}

void bane::setLimits(tmpnJointsDUnion mv,tmpnJointsDUnion ma) {
  maxvels = mv;
  maxaccs = ma;
}

void bane::cubickoeffs(const baneConf& c,koeffs& k, int i) 
{
  tmpnDouble cp0 = c.pos[0].array[i];
  tmpnDouble cp1 = c.pos[1].array[i];
  tmpnDouble cp2 = c.pos[2].array[i];
  tmpnDouble cp3 = c.pos[3].array[i];
  tmpnDouble cp4 = c.pos[4].array[i];

  tmpnDouble cv0 = c.vel[0].array[i];
  tmpnDouble cv4 = c.vel[4].array[i];
  
  k.a0[0].array[i] = cp0;
  k.a1[0].array[i] = cv0;
  k.a2[0].array[i] = (-123*cp0+156*cp1-42*cp2+12*cp3-3*cp4-97*cv0+cv4)/56.0;
  k.a3[0].array[i] = (67*cp0-100*cp1+42*cp2-12*cp3+3*cp4+41*cv0-cv4)/56.0;
  k.a0[1].array[i] = (39*cp0-44*cp1+28*cp2-12*cp3+3*cp4+13*cv0-cv4)/14.0;
  k.a1[1].array[i] = (-75*cp0+132*cp1-84*cp2+36*cp3-9*cp4-25*cv0+3*cv4)/14.0;
  k.a2[1].array[i] = (177*cp0-372*cp1+294*cp2-132*cp3+33*cp4+59*cv0-11*cv4)/56.0;
  k.a3[1].array[i] = (-33*cp0+76*cp1-70*cp2+36*cp3-9*cp4-11*cv0+3*cv4)/56.0;
  k.a0[2].array[i] = (-45*cp0+180*cp1-252*cp2+212*cp3-81*cp4-15*cv0+27*cv4)/14.0;
  k.a1[2].array[i] = (51*cp0-204*cp1+336*cp2-300*cp3+117*cp4+17*cv0-39*cv4)/14.0;
  k.a2[2].array[i] = (-75*cp0+300*cp1-546*cp2+540*cp3-219*cp4-25*cv0+73*cv4)/56.0;
  k.a3[2].array[i] = (9*cp0-36*cp1+70*cp2-76*cp3+33*cp4+3*cv0-11*cv4)/56.0;
  k.a0[3].array[i] = (18*cp0-72*cp1+252*cp2-488*cp3+297*cp4+6*cv0-162*cv4)/7.0;
  k.a1[3].array[i] = (-15*cp0+60*cp1-210*cp2+444*cp3-279*cp4-5*cv0+156*cv4)/7.0;
  k.a2[3].array[i] = (33*cp0-132*cp1+462*cp2-1044*cp3+681*cp4+11*cv0-395*cv4)/56.0;
  k.a3[3].array[i] = (-3*cp0+12*cp1-42*cp2+100*cp3-67*cp4-cv0+41*cv4)/56.0;
}

int alfcount=0;

tmpnDouble bane::findalpha(const baneConf& c, int i) { // i=jointnr.
  tmpnDouble s[3]; //4 delpolynomier med 3 extrumumspunkter.
  koeffs kof;
  tmpnDouble alf,tmpalf;
  /**** equivalent to  cubickoeffs(c,kof,i) **********/ 
  tmpnDouble cp0 = c.pos[0].array[i];
  tmpnDouble cp1 = c.pos[1].array[i];
  tmpnDouble cp2 = c.pos[2].array[i];
  tmpnDouble cp3 = c.pos[3].array[i];
  tmpnDouble cp4 = c.pos[4].array[i];
  tmpnDouble cv0 = c.vel[0].array[i];
  tmpnDouble cv4 = c.vel[4].array[i];
  
	tmpnDouble rfivesix=1/56.0;
	tmpnDouble rfourteen=1/14.0;

  kof.a1[0].array[i] = cv0;
  kof.a2[0].array[i] = (-123*cp0+156*cp1-42*cp2+12*cp3-3*cp4-97*cv0+cv4)*rfivesix;
  kof.a3[0].array[i] = (67*cp0-100*cp1+42*cp2-12*cp3+3*cp4+41*cv0-cv4)*rfivesix;
  kof.a1[1].array[i] = (-75*cp0+132*cp1-84*cp2+36*cp3-9*cp4-25*cv0+3*cv4)*rfourteen;
  kof.a2[1].array[i] = (177*cp0-372*cp1+294*cp2-132*cp3+33*cp4+59*cv0-11*cv4)*rfivesix;
  kof.a3[1].array[i] = (-33*cp0+76*cp1-70*cp2+36*cp3-9*cp4-11*cv0+3*cv4)*rfivesix;
  kof.a1[2].array[i] = (51*cp0-204*cp1+336*cp2-300*cp3+117*cp4+17*cv0-39*cv4)*rfourteen;
  kof.a2[2].array[i] = (-75*cp0+300*cp1-546*cp2+540*cp3-219*cp4-25*cv0+73*cv4)*rfivesix;
  kof.a3[2].array[i] = (9*cp0-36*cp1+70*cp2-76*cp3+33*cp4+3*cv0-11*cv4)*rfivesix;
  kof.a1[3].array[i] = (-15*cp0+60*cp1-210*cp2+444*cp3-279*cp4-5*cv0+156*cv4)/7.0;
  kof.a2[3].array[i] = (33*cp0-132*cp1+462*cp2-1044*cp3+681*cp4+11*cv0-395*cv4)*rfivesix;
  kof.a3[3].array[i] = (-3*cp0+12*cp1-42*cp2+100*cp3-67*cp4-cv0+41*cv4)*rfivesix;

  /*********************************/
  register tmpnDouble maxvel=0;
  register tmpnDouble maxacc=0;
  register tmpnDouble dq; //dq^2
  register tmpnDouble ddq; //ddq^2
  for (int j=0;j<4;j++) { //delpolynomie
    int jp1=j+1;
    tmpnDouble k1 = kof.a1[j].array[i];
    tmpnDouble k2 = kof.a2[j].array[i];
    tmpnDouble threekofa3=3*kof.a3[j].array[i];
    tmpnDouble rthreekofa3=1.0/threekofa3;
    tmpnDouble twokofa2=2*k2;
    tmpnDouble sixkofa3=2*threekofa3;
    tmpnDouble sqtemp = sqrt(k2*k2-k1*threekofa3);
    s[0] =  (sqtemp-k2)*rthreekofa3;
    s[1] =  (-sqtemp-k2)*rthreekofa3;
    s[2] = -k2*rthreekofa3;
    if (finite(s[0])&&(s[0]>=j)&&(s[0]<=jp1)){ // hvis delpolynomiets vel-ekstrema ligger indenfor intervallet
      dq = k1+twokofa2*s[0]+threekofa3*s[0]*s[0];
      dq*=dq;
      if (dq>maxvel) maxvel=dq;
    }
    if (finite(s[1])&&(s[1]>=j)&&(s[1]<=jp1)){ // hvis delpolynomiets vel-ekstrema ligger indenfor intervallet
      dq = k1+twokofa2*s[1]+threekofa3*s[1]*s[1];
      dq*=dq;
      if (dq>maxvel) maxvel=dq;
    }
    if (finite(s[2])&&(s[2]>=j)&&(s[2]<=jp1)){ // hvis delpolynomiets vel-ekstrema ligger indenfor intervallet
      dq = k1+twokofa2*s[2]+threekofa3*s[2]*s[2];
      dq*=dq;
      if (dq>maxvel) maxvel=dq;
    }
    dq = k1+twokofa2*j+threekofa3*j*j; //tjek hvert delpolynomie i startpunkt for maxvel
    dq*=dq;
    if (dq>maxvel) maxvel=dq;	    
    dq = k1+twokofa2*jp1+threekofa3*jp1*jp1; //tjek hvert delpolynomie i slutpunkt for maxvel
    dq*=dq;
    if (dq>maxvel) maxvel=dq;
    ddq = twokofa2+sixkofa3*j; //tjek hvert delpolynomie i startpunkt for maxacc
    ddq *= ddq;
    if (ddq>maxacc) maxacc=ddq;
    ddq = twokofa2+sixkofa3*jp1; //tjek hvert delpolynomie i slutpunkt for maxacc
    ddq *= ddq;
    if (ddq>maxacc) maxacc=ddq;
  }
  tmpalf = sqrt(maxvel/(maxvels.array[i]*maxvels.array[i])); //maxvel er i anden i forvejen 
  alf = sqrt(sqrt(maxacc/(maxaccs.array[i]*maxaccs.array[i]))); //maxacc er i anden i forvejen 
  if (tmpalf>alf) alf=tmpalf;
  alfcount++;
  return alf;
}

tmpnDouble bane::findgradient(const baneConf& Q,tmpnDouble grad[], int i) {
  const tmpnDouble epsi=0.0000000000001;
	const tmpnDouble repsi=10000000000000.0;
  baneConf Qnew;
  Qnew.pos[0].array[i]=Q.pos[0].array[i];
  Qnew.pos[1].array[i]=Q.pos[1].array[i];
  Qnew.pos[2].array[i]=Q.pos[2].array[i];
  Qnew.pos[3].array[i]=Q.pos[3].array[i];
  Qnew.pos[4].array[i]=Q.pos[4].array[i];
  Qnew.vel[0].array[i]=Q.vel[0].array[i];
  Qnew.vel[4].array[i]=Q.vel[4].array[i];
	
  tmpnDouble neggrad[3];
  tmpnDouble F = findalpha(Q,i);
	
  Qnew.pos[1].array[i]=Q.pos[1].array[i]+epsi;
  //  Qnew.pos[2].array[i]=Q.pos[2].array[i];
  //  Qnew.pos[3].array[i]=Q.pos[3].array[i];
  grad[0]=(findalpha(Qnew,i)-F)*repsi;    
  Qnew.pos[1].array[i]=Q.pos[1].array[i]-epsi;
  neggrad[0]=(findalpha(Qnew,i)-F)*repsi;
  if (posi(grad[0])==posi(neggrad[0])) {
    grad[0]=0.00000;
  }
  Qnew.pos[1].array[i]=Q.pos[1].array[i];
  Qnew.pos[2].array[i]=Q.pos[2].array[i]+epsi;
  //  Qnew.pos[3].array[i]=Q.pos[3].array[i];
  grad[1]=(findalpha(Qnew,i)-F)*repsi;
  Qnew.pos[2].array[i]=Q.pos[2].array[i]-epsi;
  neggrad[1]=(findalpha(Qnew,i)-F)*repsi;
  if (posi(grad[1])==posi(neggrad[1])) {
    grad[1]=0.00000;
  }
  //  Qnew.pos[1].array[i]=Q.pos[1].array[i];
  Qnew.pos[2].array[i]=Q.pos[2].array[i];
  Qnew.pos[3].array[i]=Q.pos[3].array[i]+epsi;
  grad[2]=(findalpha(Qnew,i)-F)*repsi;    
  Qnew.pos[3].array[i]=Q.pos[3].array[i]-epsi;
  neggrad[2]=(findalpha(Qnew,i)-F)*repsi;
  if (posi(grad[2])==posi(neggrad[2])) {
    grad[2]=0.00000;
  }
  return F;
}

void bane::gradientMetode() {
  tmpnDouble g[5][3];
  tmpnDouble v[5][3];
  tmpnDouble gmax=100;
  const tmpnDouble mindeta=0.00000000001;  
  tmpnDouble maxeta;
  tmpnDouble deta,detafact;
  int detafreq,detaalarm;
  baneConf Q(controlpoints);
  baneConf Qr(controlpoints);
  point p1,p2,p3,p4;
  alphatot=0.0;
  int irank[5]={0,1,2,3,4}; 
  int swaps=1;
  // int pcount,gcount,
  int ite=0;
  tmpnDouble c1,c2;
  /* Sorter efter alpha paa startgaet */
  while(swaps) {
    swaps=0;
    for (int i=0;i<4;i++) { 
      if (alpha[irank[i]]<alpha[irank[i+1]]) { 
				int s=irank[i];
				irank[i]=irank[i+1];
				irank[i+1]=s;
				swaps++;
      }
    }
  }
  for (int j=0;j<5;j++) { //joints
    maxeta=0.1;
    deta=0.01;
    detafact=0.45;
    detafreq=70;
    detaalarm=12000;
    //deta=mindeta;
    int gtgold=0;
    tmpnDouble olalf=100;
    tmpnDouble lalf=90; 
    //pcount=0;
    //gcount=0;
    ite=0;
    int i=irank[j];
    tmpnDouble step=maxeta*0.5;
    tmpnDouble nstep=0.0;
    findgradient(Q,g[i],i); //udregn gradient
    gmax = sqrt(g[i][0]*g[i][0]+g[i][1]*g[i][1]+g[i][2]*g[i][2]);
    v[i][0]=g[i][0];   
    v[i][1]=g[i][1];   
    v[i][2]=g[i][2];   
    if (alpha[i]>alphatot)
			if(debug_bopt>0) printf("optimizing joint %i...\n",i+1);   
    int detaupdate=1;
    while ((gmax>0.000001)&&(alpha[i]>alphatot)) {
      //while (gmax>0.000001) {
      if (detaupdate) maxeta=17.5*deta;
      Qr.pos[1].array[i] = Q.pos[1].array[i]-maxeta*v[i][0];
      Qr.pos[2].array[i] = Q.pos[2].array[i]-maxeta*v[i][1];
      Qr.pos[3].array[i] = Q.pos[3].array[i]-maxeta*v[i][2];
      p3.y=findalpha(Qr,i);
      tmpnDouble tgold = 0.618034*maxeta;
      Qr.pos[1].array[i] = Q.pos[1].array[i]-tgold*v[i][0];
      Qr.pos[2].array[i] = Q.pos[2].array[i]-tgold*v[i][1];
      Qr.pos[3].array[i] = Q.pos[3].array[i]-tgold*v[i][2];
      p2.y=findalpha(Qr,i);
      if (p2.y>p3.y) {
				//fprintf(stderr,"P123: %21.20f %21.20f %21.20f\n",p1.y,p2.y,p3.y);
				maxeta*=2.0;
				detaupdate=0;
				continue;
      }
      p1.y=findalpha(Q,i);		
      p1.x=0.00000000000;
      p2.x=tgold;
      p3.x=maxeta;
      while (1) {
				/* parabel linear soegning */
				if ((!gtgold)&&(p2.y<p1.y)&&(p2.y<p3.y)) {
					p4.x=Tparabelx(p1,p2,p3);
					c1=p4.x-p1.x;
					c2=p3.x-p4.x;
					nstep=fabs(p4.x-p2.x);
					if ((nstep<(step*0.55))&&(c1>0)&&(c2>0)) {
						step=nstep;
						Qr.pos[1].array[i] = Q.pos[1].array[i]-p4.x*v[i][0];
						Qr.pos[2].array[i] = Q.pos[2].array[i]-p4.x*v[i][1];
						Qr.pos[3].array[i] = Q.pos[3].array[i]-p4.x*v[i][2];
						p4.y=findalpha(Qr,i);
						if (p4.x>p2.x) {
							if (p4.y<p2.y) {
								p1=p2;
								p2=p4;
							}
							else {
								p3=p4;
							}
						}
						else {
							if (p4.y<p2.y) {
								p3=p2;
								p2=p4;
							}
							else {
								p1=p4;
							}
						}
						//pcount++;	  
						if (fabs(p1.x-p3.x)<deta) break;
					}
					else {
						gtgold++;
						continue; //goto gyldent snit
					}
				}
				/* gyldent snit lineaer soegning */
				else { 
					gtgold=0;
					tmpnDouble p2_p1=p2.x-p1.x;
					tmpnDouble p3_p2=p3.x-p2.x;
					if (p2_p1>p3_p2) {
						p4.x=p2_p1*0.618034+p1.x;
						step=p2.x-p4.x;
						Qr.pos[1].array[i] = Q.pos[1].array[i]-p4.x*v[i][0];
						Qr.pos[2].array[i] = Q.pos[2].array[i]-p4.x*v[i][1];
						Qr.pos[3].array[i] = Q.pos[3].array[i]-p4.x*v[i][2];
						p4.y=findalpha(Qr,i);
						if (p4.y<p2.y) {
							p3=p2;
							p2=p4;
						}
						else p1=p4;
					}
					else {
						p4.x=p3_p2*0.381966+p2.x;
						step=p4.x-p2.x;
						Qr.pos[1].array[i] = Q.pos[1].array[i]-p4.x*v[i][0];
						Qr.pos[2].array[i] = Q.pos[2].array[i]-p4.x*v[i][1];
						Qr.pos[3].array[i] = Q.pos[3].array[i]-p4.x*v[i][2];
						p4.y=findalpha(Qr,i);
						if (p4.y<p2.y) {
							p1=p2;
							p2=p4;
						}
						else p3=p4;
						
					}
					//gcount++;	  
					if (fabs(p1.x-p3.x)<deta) break;  
				}
      }
      p4.x = (p1.x+p3.x)*0.5; //saet midtpunkt mellem brackets -> kendes med en sikkerhed på deta.
      Q.pos[1].array[i] = Q.pos[1].array[i]-p4.x*v[i][0];
      Q.pos[2].array[i] = Q.pos[2].array[i]-p4.x*v[i][1];
      Q.pos[3].array[i] = Q.pos[3].array[i]-p4.x*v[i][2];
      ite++;
      alpha[i]=findgradient(Q,g[i],i); //udregn gradient i nyt punkt.
      if (!(ite%detafreq)) { 
				olalf=lalf;
				lalf=alpha[i];
				//	if (lalf>0.99999998*olalf) {
				if (lalf>=olalf) {
					detaupdate++;
					deta*=detafact;   
					if (deta<mindeta) deta=mindeta;
				}
      }
      tmpnDouble oldgmax=gmax;
      gmax = sqrt(g[i][0]*g[i][0]+g[i][1]*g[i][1]+g[i][2]*g[i][2]);
      //gmax = fabs(g[i][0]+g[i][1]+g[i][2]);
      //fprintf(stderr,"gmax: %12.11f %12.11f\n",gmax,alpha[i]);
      //fprintf(stderr,"controlpoints: %21.20f %21.20f %21.20f\n",Q.pos[1].array[i],Q.pos[2].array[i],Q.pos[3].array[i]);
      if ((gmax<0.000001)&&(deta>mindeta)) {
				//hvis slut og oploesning ikke hoejest
				gmax=0.00001;
				deta=mindeta;
				//fprintf(stderr,"final\n");
      }
      if ((!(ite%5))) { //reset til alm. gradient hver 5. gang
				v[i][0]=g[i][0];
				v[i][1]=g[i][1];
				v[i][2]=g[i][2];
      }
      else {
				tmpnDouble gscale=(gmax*gmax)/(oldgmax*oldgmax);
				v[i][0]=g[i][0]-v[i][0]*gscale; //Fletcher-Reeves
				v[i][1]=g[i][1]-v[i][1]*gscale; 
				v[i][2]=g[i][2]-v[i][2]*gscale;
      }
      /*  if (!(ite%2000)) {
			//fprintf(stderr,"gmax: %11.10f %11.10f %11.10f %11.10f %11.10f %13.12f\n",gmax,Q.pos[1].array[i],Q.pos[2].array[i],Q.pos[3].array[i],alpha[i],deta);
			fprintf(stderr,"gmax: %12.11f %12.11f %12.11f\n",gmax,alpha[i],deta);
			fprintf(stderr,"controlpoints: %21.20f %21.20f %21.20f\n",Q.pos[1].array[i],Q.pos[2].array[i],Q.pos[3].array[i]);
	}*/
      if ((deta==mindeta)&&(!(ite%detaalarm))) {
				deta=0.1;
				detafact=0.81;
				detafreq=100;
				detaalarm=50000;
      }
    }
    //set controlpoints
    controlpoints=Q;
    if (alpha[i]>alphatot) alphatot=alpha[i];
    //fprintf(stderr,"done: %i %i\n",pcount,gcount);   
    //fprintf(stderr,"alpha: %f %i\n",alpha[i],irank[j]+1);   
  }
  if(debug_bopt>0) printf("alfcount: %i \n",alfcount);   
}

int maxalfcount=0;
long int avgalfcount=0;
int minalfcount=10000000;

double tota=0.0;

void bane::optimer() {
  alfcount=0;
  for (int i=0;i<5;i++) {
    // fprintf(stderr,"cp[%i]: %f %f %f %f %f\n",i,controlpoints.pos[0].array[i],controlpoints.pos[1].array[i],controlpoints.pos[2].array[i],controlpoints.pos[3].array[i],controlpoints.pos[4].array[i]);
  }
  gradientMetode(); 
  for (int i=0;i<5;i++) {
    // fprintf(stderr,"ncp[%i]: %f %f %f %f %f\n",i,controlpoints.pos[0].array[i],controlpoints.pos[1].array[i],controlpoints.pos[2].array[i],controlpoints.pos[3].array[i],controlpoints.pos[4].array[i]);
  }
   if(debug_bopt>0)  printf("alpha_opt: %f \n",alphatot);
  tota+=alphatot;
  for (int i=0;i<5;i++) {
    cubickoeffs(controlpoints,kf,i);
  }
  if (alfcount>maxalfcount) maxalfcount=alfcount;
  avgalfcount+=alfcount;
  if (alfcount<minalfcount) minalfcount=alfcount;
}

void bane::getResult(baneConf& Q,tmpnDouble& alfa) {
  Q=controlpoints;
  alfa=alphatot;
}

tmpnDouble bane::cubicpoly(const int joint, const tmpnDouble t) {
  tmpnDouble s = t/alphatot;
  if ((s<0)||(s>4)) 
		if(debug_bopt>0)    printf("\n!!!!s stoerre end 4, eller mindre end 0!!!!: %f\n",s);
  int i=(int)s;
  return (kf.a0[i].array[joint]+(s*kf.a1[i].array[joint])+(s*s*kf.a2[i].array[joint])+(s*s*s*kf.a3[i].array[joint]));
}


tmpnDouble bane::dcubicpoly(const int joint, const tmpnDouble t) {
  tmpnDouble s = t/alphatot;
  if ((s<0)||(s>4)) 
		if(debug_bopt>0)  printf("\n!!!!s stoerre end 4, eller mindre end 0!!!!: %f\n",s);
  int i=(int)s;
  return (kf.a1[i].array[joint]+2*s*kf.a2[i].array[joint]+3*s*s*kf.a3[i].array[joint])/alphatot;
}

tmpnDouble bane::ddcubicpoly(const int joint, const tmpnDouble t) {
  tmpnDouble s = t/alphatot;
  if ((s<0)||(s>4)) 
		if(debug_bopt>0)  printf("\n!!!!s stoerre end 4, eller mindre end 0!!!!: %f\n",s);
  int i=(int)s;
  return (2*kf.a2[i].array[joint]+6*s*kf.a3[i].array[joint])/(alphatot*alphatot);
}

//#define TESTA //Graf af linjesoegning

//#define TESTB //Test at løsning er globalt optimal

//#define TESTC // Test eksekveringstid

//#define TESTD //Lav gradient vektorfeltplot

//#define TESTMAIN

#ifdef TESTA
int main () {
  tmpnJointsDUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //grader/s
  tmpnJointsDUnion ma = {{MTOMM(4),RADTODEG(2),RADTODEG(5),RADTODEG(7),RADTODEG(7)}};             //grader/s/s 
  tmpnJointsDUnion startpos = {{0.95,0,0,0,0}};           // rad
  tmpnJointsDUnion startvel = {{-0.18,0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion liftmvel = {{-0.18,0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion liftmacc = {{0.0,0.0,0.0,0.0,0.0}}; //rad/s/s
  tmpnJointsDUnion slutpos =  {{1.95,0,0,0,0}};           // rad
  tmpnJointsDUnion slutvel =  {{-0.22,0.1,0.1,0.1,-0.1}}; //rad/s
  tmpnJointsDUnion placemvel =  {{-0.22,0.1,0.1,0.1,0.1}}; //rad/s
  tmpnJointsDUnion placemacc =  {{0.0,0.1,0.1,0.1,0.1}}; //rad/s/s
  bane b(startpos,startvel,slutpos,slutvel,liftmvel,liftmacc,placemvel,placemacc,mv,ma);

  tmpnDouble g[5][3];
  tmpnDouble maxeta=0.2;
  //b.controlpoints.pos[2].array[0]=3.5; //Tving viapunkt til bestemt værdi
  baneConf Q(b.controlpoints);
  baneConf Qr(b.controlpoints);
  int i=0;
  b.findgradient(Q,g[i],i); //udregn gradient
  int maxsamples=5000;
  for (int j=0;j<maxsamples;j++) { //controlpoints
    for (int h=1;h<4;h++) { //controlpoints
      Qr.pos[h].array[i] = Q.pos[h].array[i]-(j-2500)*maxeta*g[i][h-1]/maxsamples;
    }
    printf("%f %f\n",j*maxeta/maxsamples,b.findalpha(Qr,i));	
  }
  return 0;
}

#elif defined TESTB

int main () {
  int tries=1000;
  tmpnJointsDUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //grader/s
  tmpnJointsDUnion ma = {{MTOMM(4),RADTODEG(2),RADTODEG(5),RADTODEG(7),RADTODEG(7)}};             //grader/s/s 
  tmpnJointsDUnion startpos = {{0,0,0,0,1}};           // rad
  tmpnJointsDUnion startvel = {{0.5,0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion liftmvel = {{0.5,0.1,0.1,0.1,0.1}}; //rad/s
  tmpnJointsDUnion liftmacc = {{0.45,0.1,0.1,0.1,0.1}}; //rad/s/s
  tmpnJointsDUnion slutpos =  {{2,1,1,1,2}};           // rad
  tmpnJointsDUnion slutvel =  {{0.49,0.1,0.1,0.1,-0.1}}; //rad/s
  tmpnJointsDUnion placemvel =  {{0.49,0.1,0.1,0.1,0.1}}; //rad/s
  tmpnJointsDUnion placemacc =  {{0.47,0.1,0.1,0.1,0.1}}; //rad/s/s
  bane b(startpos,startvel,slutpos,slutvel,liftmvel,liftmacc,placemvel,placemacc,mv,ma);
  for (int t=0;t<tries;t++) {
		if(debug_bopt>0) printf("try: %i\n",t);
    srand((unsigned)time(NULL)); //initialiser random number generator
    tmpnDouble as=uniform(0,1800);
    tmpnDouble ae=uniform(0,1800);
    tmpnDouble acc=uniform(0,sqrt(ma.array[0]*ma.array[0]*pow( (ae-as) / (4*mv.array[0]),4)));
    tmpnJointsDUnion startpos = {{as,0.0,0.0,0.0,0.0}};           // rad
    tmpnJointsDUnion startvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
    tmpnJointsDUnion liftmvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
    tmpnJointsDUnion liftmacc = {{acc,0.0,0.0,0.0,0.0}}; //rad/s/s
    tmpnJointsDUnion slutpos =  {{ae,0.0,0.0,0.0,0.0}};           // rad
    tmpnJointsDUnion slutvel =  {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
    tmpnJointsDUnion placemvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
    tmpnJointsDUnion placemacc = {{acc,0.0,0.0,0.0,0.0}}; //rad/s/s
    b.init(startpos,startvel,slutpos,slutvel,liftmvel,liftmacc,placemvel,placemacc,mv,ma);
    b.optimer();
    baneConf baneRes;
    tmpnDouble alpha;
    b.getResult(baneRes,alpha);
		if(debug_bopt>0) printf("Resulting alpha: %f\n",alpha);
    int maxtries=10000000;
    tmpnDouble bestralf=5;
    baneConf Q(b.controlpoints);
    baneConf bestQ(b.controlpoints);  
    for (int i=0;i<maxtries;i++) {  
      Q.pos[1].array[0]=uniform(as,as+0.4*(ae-as));
      Q.pos[2].array[0]=uniform(as+0.3*(ae-as),as+0.7*(ae-as));
      Q.pos[3].array[0]=uniform(as+0.6*(ae-as),ae);
      tmpnDouble nalf=b.findalpha(Q,0);
      if (nalf<bestralf) {
				bestralf=nalf;
				bestQ=Q;
      }
      if ((i==maxtries-1)&&(bestralf<alpha)) {
				if(debug_bopt>0) printf("alpha: %f nalpha: %f\n",alpha,bestralf);
				for (int j=0;j<5;j++) { 
					if(debug_bopt>0) printf("joint %i: %f %f %f %f %f\n",j,bestQ.pos[0].array[j],bestQ.pos[1].array[j],bestQ.pos[2].array[j],bestQ.pos[3].array[j],bestQ.pos[4].array[j]);
					if(debug_bopt>0) printf("vels[%i]: %f %f: %f %f : %f %f\n",j,b.controlpoints.vel[0].array[j],b.controlpoints.vel[4].array[j],bestQ.vel[0].array[j],bestQ.vel[4].array[j],startvel.array[j],slutvel.array[j]);
				}
				tmpnDouble val,dval,ddval;
				tmpnDouble nval,ndval,nddval;
				tmpnDouble nnval,nndval,nnddval;
				bane nb(b);
				nb.controlpoints=bestQ;
				nb.alphatot=nb.findalpha(nb.controlpoints,0);
				for (int g=0;g<5;g++) {
					nb.cubickoeffs(nb.controlpoints,nb.kf,g);
				}
				bane nnb(nb);
				nnb.optimer();
				if(debug_bopt>0) printf("alfs: %f %f %f\n",alpha,nb.alphatot,nnb.alphatot);
				if(debug_bopt>0) printf("cps: %f %f %f\n",nb.controlpoints.pos[1].array[0],nb.controlpoints.pos[2].array[0],nb.controlpoints.pos[3].array[0]);
				int maxsamples=5000;
				for (int i=0;i<maxsamples;i++) {
					tmpnDouble thistime=4*i*alpha/maxsamples;
					tmpnDouble nthistime=4*i*nb.alphatot/maxsamples;
					tmpnDouble nnthistime=4*i*nnb.alphatot/maxsamples;
					val = b.cubicpoly(0,thistime);  
					dval = b.dcubicpoly(0,thistime);  
					ddval = b.ddcubicpoly(0,thistime);
					nval = nb.cubicpoly(0,nthistime);  
					ndval = nb.dcubicpoly(0,nthistime);  
					nddval = nb.ddcubicpoly(0,nthistime);
					nnval = nnb.cubicpoly(0,nnthistime);  
					nndval = nnb.dcubicpoly(0,nnthistime);  
					nnddval = nnb.ddcubicpoly(0,nnthistime);
					printf("%f %f %f %f %f %f %f %f %f %f %f %f\n",thistime,nthistime,nnthistime,val,dval,ddval,nval,ndval,nddval,nnval,nndval,nnddval); 
				}
				exit(0);
      }
    }
		if(debug_bopt>0) printf("bestralf: %f\n",bestralf);
    printf("%f %f %f \n",bestralf,alpha,fabs(bestralf-alpha));
    for (int i=0;i<5;i++) {
			if(debug_bopt>0) printf("bestralfcp[%i]: %f %f %f %f %f\n",i,Q.pos[0].array[i],Q.pos[1].array[i],Q.pos[2].array[i],Q.pos[3].array[i],Q.pos[4].array[i]);
    }
  }
  return 0;
}

#elif defined TESTC

int main () {
  clock_t at,bt;
  //srand((unsigned)time(NULL)); //initialiser random number generator
  srand(435);
  baneConf baneRes;
  tmpnDouble alpha;
  tmpnJointsDUnion mv = {{1.7,3.11,3.24,2.62,5.236}}; //grader/s
  tmpnJointsDUnion ma = {{4,2,5,7,7}};             //grader/s/s 
  int tries=100;
  at=clock();
  for (int i=0;i<tries;i++) {
    tmpnDouble as=uniform(0,MMTOM(1800));
    tmpnDouble bs=uniform(0,DEGTORAD(100));
    tmpnDouble cs=uniform(0,DEGTORAD(110));
    tmpnDouble ds=uniform(DEGTORAD(-60),DEGTORAD(60));
    tmpnDouble es=uniform(DEGTORAD(-180),DEGTORAD(180));
    tmpnDouble ae=uniform(0,MMTOM(1800));
    tmpnDouble be=uniform(0,DEGTORAD(90));
    tmpnDouble ce=uniform(0,DEGTORAD(120));
    tmpnDouble de=uniform(DEGTORAD(-60),DEGTORAD(60));
    tmpnDouble ee=uniform(DEGTORAD(-180),DEGTORAD(180));
    tmpnJointsDUnion startpos = {{as,bs,cs,ds,es}};   // rad
    tmpnJointsDUnion startvel = {{uniform(-(ae-as)/4,(ae-as)/4),uniform(-(be-bs)/4,(be-bs)/4),uniform(-(ce-cs)/4,(ce-cs)/4),uniform(-(de-ds)/4,(de-ds)/4),uniform(-(de-ds)/4,(de-ds)/4)}}; //rad/s
    tmpnJointsDUnion slutpos = {{ae,be,ce,de,ee}};   // rad
    tmpnJointsDUnion slutvel =  {{uniform(-(ae-as)/4,(ae-as)/4),uniform(-(be-bs)/4,(be-bs)/4),uniform(-(ce-cs)/4,(ce-cs)/4),uniform(-(de-ds)/4,(de-ds)/4),uniform(-(de-ds)/4,(de-ds)/4)}}; //rad/s
    /*   if (i>837) {
				 printf("tmpnJointsDUnion startpos = {{%15.14f, %15.14f, %15.14f, %15.14f, %15.14f}};\n",startpos.array[0],startpos.array[1],startpos.array[2],startpos.array[3],startpos.array[4]);
				 printf("tmpnJointsDUnion slutpos = {{%15.14f, %15.14f, %15.14f, %15.14f, %15.14f}};\n",slutpos.array[0],slutpos.array[1],slutpos.array[2],slutpos.array[3],slutpos.array[4]);
				 printf("tmpnJointsDUnion startvel = {{%15.14f, %15.14f, %15.14f, %15.14f, %15.14f}};\n",startvel.array[0],startvel.array[1],startvel.array[2],startvel.array[3],startvel.array[4]);
				 printf("tmpnJointsDUnion slutvel = {{%15.14f, %15.14f, %15.14f, %15.14f, %15.14f}};\n",slutvel.array[0],slutvel.array[1],slutvel.array[2],slutvel.array[3],slutvel.array[4]);
				 }*/
    bane b(startpos,startvel,slutpos,slutvel,mv,ma);
    b.optimer();
    b.getResult(baneRes,alpha);
    //printf("tries: %i\n",i);
  }
  bt=clock();
  printf("\n%i udregninger:\n",tries);
  printf("(minalfcount,maxalfcount,avgalfcount): %i %i %li\n",minalfcount,maxalfcount,avgalfcount/tries);
  printf("total tid: %f avg: %f\n",(bt-at)/(CLOCKS_PER_SEC*1.0),(bt-at)/(CLOCKS_PER_SEC*1.0*tries));
  printf("tota: %f\n",tota);
  return 0;
}

#elif defined TESTD

int main () {
	if(debug_bopt>0) printf("%i",RAND_MAX);
  srand((unsigned)time(NULL)); //initialiser random number generator
	
  tmpnJointsDUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //grader/s
  tmpnJointsDUnion ma = {{MTOMM(4),RADTODEG(2),RADTODEG(5),RADTODEG(7),RADTODEG(7)}};             //grader/s/s 
  
	tmpnDouble as=uniform(0,2);
  tmpnDouble ae=uniform(0,2);
  tmpnDouble acc1=uniform(0,sqrt(ma.array[0]*ma.array[0]*pow( (ae-as) / (4*mv.array[0]),4)));
  tmpnDouble acc2=uniform(0,sqrt(ma.array[0]*ma.array[0]*pow( (ae-as) / (4*mv.array[0]),4)));
  tmpnJointsDUnion startpos = {{as,0,0,0,0}};           // rad
  tmpnJointsDUnion startvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion liftmvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion liftmacc = {{acc1,0.0,0.0,0.0,0.0}}; //rad/s/s
  tmpnJointsDUnion slutpos =  {{ae,0,0,0,0}};           // rad
  tmpnJointsDUnion slutvel =  {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion placemvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion placemacc = {{acc2,0.0,0.0,0.0,0.0}}; //rad/s/s 
	
	
  bane b(startpos,startvel,slutpos,slutvel,liftmvel,liftmacc,placemvel,placemacc,mv,ma);
  b.optimer();
  baneConf baneRes;
  tmpnDouble alpha;
  b.getResult(baneRes,alpha);
  baneConf Q(b.controlpoints);  
  baneConf Qr(b.controlpoints);  
	if(debug_bopt>0) printf("Resulting alpha: %f\n",alpha);
	if(debug_bopt>0) printf("\n");
  tmpnDouble g[3];
  int maxtries=200;
  printf("array={");
  for (int i=0;i<maxtries;i++) {
    tmpnDouble h[3]={1,1,1};
    Qr.pos[1].array[0]=Q.pos[1].array[0]+0.05*h[0]*uniform(-1,1);
    Qr.pos[2].array[0]=Q.pos[2].array[0]+0.05*h[1]*uniform(-1,1);
    Qr.pos[3].array[0]=Q.pos[3].array[0]+0.05*h[2]*uniform(-1,1);
    alpha = b.findgradient(Qr,g,0);
    printf("{{%f,%f,%f},{%f*scale,%f*scale,%f*scale}}",Qr.pos[1].array[0],Qr.pos[2].array[0],Qr.pos[3].array[0],-g[0],-g[1],-g[2]);
    if (i!=(maxtries-1)) printf(",\n");
  }
  printf("};\n");
  return 0;
}
/*
0, mv: 1700.000000   ma: 4000.000000
1, mv: 178.189869   ma: 114.591553
2, mv: 185.638320   ma: 286.478882
3, mv: 150.114938   ma: 401.070435
4, mv: 300.000693   ma: 401.070435
*/

#elif defined TESTMAIN

int main () {
  tmpnDouble val,dval,ddval;
  int maxsamples=1001; 
  FILE *fp=NULL;
	if(debug_bopt>0) printf("%i",RAND_MAX);
	srand((unsigned)time(NULL)); //initialiser random number generator
  //tmpnJointsDUnion mv = {{MTOMM(1.7),RADTODEG(3.11),RADTODEG(3.24),RADTODEG(2.62),RADTODEG(5.236)}}; //grader/s
  //tmpnJointsDUnion ma = {{MTOMM(4),RADTODEG(2),RADTODEG(5),RADTODEG(7),RADTODEG(7)}};             //grader/s/s 
  tmpnJointsDUnion mv = {{1.7,3.11,3.24,2.62,5.236}}; //grader/s
  tmpnJointsDUnion ma = {{4,2,5,7,7}};             //grader/s/s 
	
  
  /*tmpnJointsDUnion startpos = {{0,0,0,0,0}};            // rad
  tmpnJointsDUnion startvel = {{0.25,0.0,0.0,0.0,0.0}};   //rad/s
  tmpnJointsDUnion liftmvel = {{0.0,0.0,0.0,0.0,0.0}};   //rad/s
  tmpnJointsDUnion liftmacc = {{0.0,0.0,0.0,0.0,0.0}};   //rad/s/s
  tmpnJointsDUnion slutpos =  {{1,0,0,0,0}};             //rad
  tmpnJointsDUnion slutvel =  {{0.25,0.0,0.0,0.0,0.0}};  //rad/s
  tmpnJointsDUnion placemvel =  {{0.0,0.0,0.0,0.0,0.0}}; //rad/s
  tmpnJointsDUnion placemacc =  {{0.0,0.0,0.0,0.0,0.0}}; //rad/s/s */
  tmpnJointsDUnion startpos = {{1.74551152379732, 1.53956271840301, 0.18979798863732, 0.30781574202183, -1.13733847433778}};
  tmpnJointsDUnion slutpos = {{0.04139377145668, 1.07044104126680, 1.59348886282446, -0.28545701934913, -0.03640996636583}};
  tmpnJointsDUnion startvel = {{-0.12740941048066, -0.11673284580743, 0.00114438346807, 0.02426258181552, -0.01956198073691}};
  tmpnJointsDUnion slutvel = {{0.12941909799853, -0.08335491647854, -0.26677928535140, -0.05306104648767, -0.13952758225430}};
	
	
  /*  tmpnDouble as=uniform(0,1.800);
			tmpnDouble ae=uniform(0,1.800);
			tmpnDouble acc1=uniform(0,sqrt(ma.array[0]*ma.array[0]*pow( (ae-as) / (4*mv.array[0]),4)));
			tmpnDouble acc2=uniform(0,sqrt(ma.array[0]*ma.array[0]*pow( (ae-as) / (4*mv.array[0]),4)));
			tmpnJointsDUnion startpos = {{as,0,0,0,0}};           // rad
			tmpnJointsDUnion startvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
			tmpnJointsDUnion liftmvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
			tmpnJointsDUnion liftmacc = {{acc1,0.0,0.0,0.0,0.0}}; //rad/s/s
			tmpnJointsDUnion slutpos =  {{ae,0,0,0,0}};           // rad
			tmpnJointsDUnion slutvel =  {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
			tmpnJointsDUnion placemvel = {{uniform(-(ae-as)/4,(ae-as)/4),0.0,0.0,0.0,0.0}}; //rad/s
			tmpnJointsDUnion placemacc = {{acc2,0.0,0.0,0.0,0.0}}; //rad/s/s 
  */

  bane b(startpos,startvel,slutpos,slutvel,mv,ma);
  for (int i=0;i<5;i++) {
    b.cubickoeffs(b.controlpoints,b.kf,i);
  }
	fp=fopen("hejsa2","w");
  tmpnDouble startalf=b.alpha[0];
  for (int i=0;i<maxsamples;i++) { 
    tmpnDouble thistime=4*i*startalf/maxsamples;
    val = b.cubicpoly(0,thistime);  
    dval = b.dcubicpoly(0,thistime);  
    ddval = b.ddcubicpoly(0,thistime);  
    fprintf(fp,"%f %f %f %f %f %f\n",thistime,val,dval,ddval,mv.array[0],ma.array[0]); 
  }
  fclose(fp);
  b.optimer();
  baneConf baneRes;
  tmpnDouble alpha;
  b.getResult(baneRes,alpha);
	if(debug_bopt>0) printf("\\multicolumn{3}{c}{ Startgaet: $\\alpha = %f$}\\\\ \n \\hline \n Tidspunkt & $ t=0 \\, s$ & $t=T=%f \\, s$\\\\ \n \\hline \n Position & $%f \\, m$ & $%f \\, m$\\\\ \n \\hline \n Hastighed & $%f \\, m/s$ & $%f \\, m/s$\\\\ \n \\hline \n \\multicolumn{3}{c}{ Optimeret: $\\alpha = %f$}\\\\ \n \\hline \n Tidspunkt & $ t=0 \\, s$ & $t=T=%f \\, s$\\\\ \n \\hline \n Position & $%f \\, m$ & $%f \\, m$\\\\ \n \\hline \n Hastighed & $%f \\, m/s$ & $%f \\, m/s$\\\\ \n",startalf,4*startalf,startpos.array[0],slutpos.array[0],startvel.array[0],slutvel.array[0],alpha,4*alpha,startpos.array[0],slutpos.array[0],startvel.array[0]/alpha,slutvel.array[0]/alpha);
  for (int i=0;i<maxsamples;i++) { 
    tmpnDouble thistime=4*i*alpha/maxsamples;
    val = b.cubicpoly(0,thistime);  
    dval = b.dcubicpoly(0,thistime);  
    ddval = b.ddcubicpoly(0,thistime);  
    printf("%f %f %f %f %f %f\n",thistime,val,dval,ddval,mv.array[0],ma.array[0]); 
  }
  return 0;
}

#endif //TEST
