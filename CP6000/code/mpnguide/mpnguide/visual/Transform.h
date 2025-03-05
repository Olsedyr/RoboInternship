#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point3D.h"
#include <GL/glut.h>
#include <cassert>
#include <math.h>
#include <stdio.h>
#ifndef M_PI
#define M_PI 3.1415926535
#endif

using namespace std;

class Transform
{
private:
  double vals[3][4];
  void getGlMatrix (double (&mat)[16]) const;
  
public:
	Transform();
  Transform(Point3D &RPY, Point3D &pos);
  Transform(Point3D &I, Point3D &J, Point3D &K, Point3D &pos);
  Transform(double m11, double m12, double m13, double m14,
            double m21, double m22, double m23, double m24,
            double m31, double m32, double m33, double m34);
  Transform(float angle, float x, float y, float z);
	virtual ~Transform();
  
  static Transform Identity ();
  void setValues(double m11, double m12, double m13, double m14,
                 double m21, double m22, double m23, double m24,
                 double m31, double m32, double m33, double m34);
  void translate (float x, float y, float z);
  void rotate (float angle, float x, float y, float z);
  void mul(Transform &tt);
  Point3D mul(const Point3D &p);
  void getRotation(double (&rot)[3][3]);
  void getTranslation(double (&tran)[3]);
  Point3D getTranslation();
  //friend Transform operator* (const Transform & a, const Transform & b);
  //friend Point3D operator* (const Transform & a, const Point3D & b);
  void glMultMatrix () const;
  void print();
  void copy(Transform &t);
  double get (int i, int j) const;
  void set (int i, int j, double val);
};

#endif /*TRANSFORM_H_*/
