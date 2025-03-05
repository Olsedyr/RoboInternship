#include "Triangle.h"

Triangle::Triangle(Point3D &aa, Point3D &bb, Point3D &cc, Point3D &n) : a (aa), b (bb), c (cc), normal (n)
{
}

Triangle::~Triangle(){}

void Triangle::draw () const{
  glNormal3dv(normal.vec);
  glBegin(GL_TRIANGLES
           /*GL_POLYGON*/
           /*GL_LINE_LOOP*/);
  { 
    glVertex3dv(a.vec);
    glVertex3dv(b.vec);
    glVertex3dv(c.vec);
  }
  glEnd ();
}
