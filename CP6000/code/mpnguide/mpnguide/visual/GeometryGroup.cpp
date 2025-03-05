#include "GeometryGroup.h"

GeometryGroup::GeometryGroup()
{
}

GeometryGroup::~GeometryGroup()
{
}

void GeometryGroup::draw(){
  unsigned int i;
  glPushMatrix();
  transform.glMultMatrix();
 
  for(i=0; i < children.size (); i++){
    (children.at(i))->draw();
  } 
  glPopMatrix ();
}
