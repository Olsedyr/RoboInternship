/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#ifndef __DYNMOD_H
#define __DYNMOD_H

#ifndef PI
#define PI 3.1415926535898
//#define PI 3.14159265358979323846
#endif

#define tmpnDouble double

#undef TRAP
#define TRAP(err) {printf(err);exit(0);}



/* Link lengths */
#define L2 (tmpnDouble)1.0
#define L3 (tmpnDouble)1.066

#define Mone (tmpnDouble)158.0
#define Mtwo (tmpnDouble)58.87
#define Mthree (tmpnDouble)66.8109
#define Mfour (tmpnDouble)4.79


#define G 9.81 //One G in m/s^2


void computetaus(void);
tmpnDouble tau(int i);
tmpnDouble oldtau(int i,int timestep);

void settoolstate(int state);
void setq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble r);
void setdq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble e);
void setddq(tmpnDouble a,tmpnDouble b,tmpnDouble c,tmpnDouble d,tmpnDouble e);
void setLinkLength(tmpnDouble l, int idx);
void setMass(tmpnDouble m, int idx);
void setMassDisplacement(tmpnDouble p0, tmpnDouble p1, tmpnDouble p2, int idx);
void setInertiaTensor(tmpnDouble i00,tmpnDouble i01,tmpnDouble i02
                     ,tmpnDouble i10,tmpnDouble i11,tmpnDouble i12
                     ,tmpnDouble i20,tmpnDouble i21,tmpnDouble i22
                     ,int idx);

//static void printvec(tmpnDouble* vec);

#endif /* __DYNMOD_H */
