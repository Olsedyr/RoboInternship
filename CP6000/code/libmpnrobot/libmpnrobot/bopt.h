/** bopt.h   (c++)
 *
 * \brief Optimizes Trajectory between 2 joint-configurations of MPN-robot.
 * \author Mads Lundstroem
 * \date   27 February 2004
 *
 */

#ifndef __BOPT_H
#define __BOPT_H

#define tmpnDouble double

#ifndef PI
#define PI 3.14159265358979323846
#endif

typedef struct point 
{
  double x;
  double y;
} point;

typedef struct tmpnJointsD
{
  tmpnDouble a,b,c,d,e;
} tmpnJointsD;

typedef union tmpnJointsDUnion
{
  tmpnJointsD name;
  tmpnDouble array[5];
} tmpnJointsDUnion;


typedef struct baneConf
{
  tmpnJointsDUnion pos[5];
  tmpnJointsDUnion vel[5];  
} baneConf;

typedef struct koeffs
{
  tmpnJointsDUnion a0[4];
  tmpnJointsDUnion a1[4];
  tmpnJointsDUnion a2[4];
  tmpnJointsDUnion a3[4];
} koeffs;

class bane 
{
 private:
  baneConf controlpoints;
  tmpnJointsDUnion maxvels;
  tmpnJointsDUnion maxaccs;
  tmpnDouble alpha[5];
  tmpnDouble alphatot;  
  koeffs kf;
  void cubickoeffs(const baneConf& c, koeffs& k, int i);
  tmpnDouble findalpha(const baneConf& c, int i);
  tmpnDouble findgradient(const baneConf& Q, tmpnDouble grad[],int i);
  void gradientMetode();
 public:
  bane(const tmpnJointsDUnion startpunkt,const tmpnJointsDUnion starthast,const tmpnJointsDUnion slutpunkt,const tmpnJointsDUnion sluthast,tmpnJointsDUnion mv,tmpnJointsDUnion ma); 
  void init(const tmpnJointsDUnion startpunkt,const tmpnJointsDUnion starthast,const tmpnJointsDUnion slutpunkt,const tmpnJointsDUnion sluthast,tmpnJointsDUnion mv,tmpnJointsDUnion ma); // Constructor
  void setLimits(tmpnJointsDUnion mv,tmpnJointsDUnion ma); 
  void optimer();
  void getResult(baneConf& Q,tmpnDouble& alfa);
  tmpnDouble cubicpoly(const int joint,const tmpnDouble t);
  tmpnDouble dcubicpoly(const int joint,const tmpnDouble t);
  tmpnDouble ddcubicpoly(const int joint,const tmpnDouble t);
};

#endif /* __BOPT_H */
