#ifndef POINT3D_H_
#define POINT3D_H_

#include <cassert>
#include <cmath>
#include <GL/glut.h>

class Point3D
{
public:
  double vec[3];
  
public:
	Point3D();
  Point3D(double x, double y, double z);
	virtual ~Point3D();
  
  Point3D& operator+=(const Point3D& p);
  Point3D& operator*=(double scale);

  double operator[](int i) const;

  Point3D operator-(const Point3D& p) const;
  Point3D operator+(const Point3D& p) const;
  Point3D operator/(double d) const;

  friend Point3D operator*(double s, const Point3D& other);
  friend Point3D operator*(const Point3D& other, double s);

  bool operator==(const Point3D& p) const;
  bool operator!=(const Point3D& p) const;
  double length() const;

  void draw () const;
};

#endif /*POINT3D_H_*/
