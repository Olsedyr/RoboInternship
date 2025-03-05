#include "Geometry.h"

Geometry::Geometry(){
  inCollision=0;
  color[0] = 0.6;
  color[1] = 0.6;
  color[2] = 0.6; //TODO: move to Triangle and use color from STL
}

Geometry::~Geometry(){}

void Geometry::addTriangle(Point3D a, Point3D b, Point3D c, Point3D n){
  triangles.push_back(Triangle(a, b, c, n));
}

void Geometry::setColor(float r, float g, float b){
  color[0] = r;
  color[1] = g;
  color[2] = b;
} 

void Geometry::draw(){
  unsigned int i;
  if(inCollision){
    float tcolor[] = {1,0,0};//red
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, tcolor);
  }else{
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
  }
  for(i=0; i < triangles.size(); i++){
    triangles.at(i).draw();
  } 
}
