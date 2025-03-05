#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Point3D.h"

class Triangle{
private:
  Point3D a;
  Point3D b;
  Point3D c;
  Point3D normal;
  
public:
	virtual ~Triangle();
  Triangle(Point3D &aa, Point3D &bb, Point3D &cc, Point3D &n);
  void draw() const;
};

#endif /*TRIANGLE_H_*/
