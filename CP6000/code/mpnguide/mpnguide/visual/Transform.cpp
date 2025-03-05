#include "Transform.h"

Transform::Transform(){}
Transform::~Transform(){}

Transform::Transform(Point3D &RPY, Point3D &pos){
  //From John J. Craig's Introduction to Robotics p. 44 eq. 2.71
  float ca = cos(RPY.vec[0] * (M_PI/180));
  float sa = sin(RPY.vec[0] * (M_PI/180));
  float cb = cos(RPY.vec[1] * (M_PI/180));
  float sb = sin(RPY.vec[1] * (M_PI/180));
  float cc = cos(RPY.vec[2] * (M_PI/180));
  float sc = sin(RPY.vec[2] * (M_PI/180));
  /*Transform(ca*cb, ca*sb*sc-sa*cc, ca*sb*cc+sa*sc, pos.vec[0],
            sa*cb, sa*sb*sc+ca*cc, sa*sb*cc-ca*sc, pos.vec[1],
            -sb,cb*sc,cb*cc,pos.vec[2]);*/
  vals[0][0]=ca*cb;
  vals[0][1]=ca*sb*sc-sa*cc;
  vals[0][2]=ca*sb*cc+sa*sc;
  vals[0][3]=pos.vec[0];

  vals[1][0]=sa*cb;
  vals[1][1]=sa*sb*sc+ca*cc;
  vals[1][2]=sa*sb*cc-ca*sc;
  vals[1][3]=pos.vec[1];

  vals[2][0]=-sb;
  vals[2][1]=cb*sc;
  vals[2][2]=cb*cc;
  vals[2][3]=pos.vec[2];
}

Transform::Transform(Point3D &I, Point3D &J, Point3D &K, Point3D &pos){
  //I = first collum, J second...
  vals[0][0]=I.vec[0];
  vals[0][1]=J.vec[0];
  vals[0][2]=K.vec[0];
  vals[0][3]=pos.vec[0];

  vals[1][0]=I.vec[1];
  vals[1][1]=J.vec[1];
  vals[1][2]=K.vec[1];
  vals[1][3]=pos.vec[1];

  vals[2][0]=I.vec[2];
  vals[2][1]=J.vec[2];
  vals[2][2]=K.vec[2];
  vals[2][3]=pos.vec[2];
}

Transform::Transform(double m11, double m12, double m13, double m14,
                     double m21, double m22, double m23, double m24,
                     double m31, double m32, double m33, double m34){
  setValues( m11, m12, m13, m14,
             m21, m22, m23, m24,
             m31, m32, m33, m34);
}

Transform::Transform(float angle, float x, float y, float z){
  //EAA2R from John J. Craig's Introduction to Robotics p. 47 eq. 2.80
  //fprintf(stderr,"angle: %.3f, eaa: (%.3f,%.3f,%.3f)\n",angle,x,y,z);
  float ca = cos(angle);
  float sa = sin(angle);
  float va = 1-cos(angle);
  setValues(x*x*va + ca, x*y*va - z*sa, x*z*va + y*sa, 0,
            x*y*va + z*sa, y*y*va + ca, y*z*va - x*sa, 0,
            x*z*va - y*sa, y*z*va + x*sa, z*z*va + ca, 0);  
}

Transform Transform::Identity()
{
  Transform result;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      result.set (i, j, i == j ? 1 : 0);
    }
  }
  return result;
}

void Transform::setValues(double m11, double m12, double m13, double m14,
                          double m21, double m22, double m23, double m24,
                          double m31, double m32, double m33, double m34){
  vals[0][0]=m11; vals[0][1]=m12; vals[0][2]=m13; vals[0][3]=m14;
  vals[1][0]=m21; vals[1][1]=m22; vals[1][2]=m23; vals[1][3]=m24;
  vals[2][0]=m31; vals[2][1]=m32; vals[2][2]=m33; vals[2][3]=m34;
}

void Transform::translate (float x, float y, float z){  
  vals[0][3] = vals[0][3]+x;
  vals[1][3] = vals[1][3]+y;
  vals[2][3] = vals[2][3]+z;
}

void Transform::rotate (float angle, float x, float y, float z){
  Transform tt(angle, x, y, z);
  mul(tt);
}

void Transform::mul(Transform &tt){
  //JJ Craig p. 35 eq. 2.41 
  // 3x3 Matrix multiplication (A.B):
  //  a00*b00 + a01*b10 + a02*b20   a00*b01 + a01*b11 + a02*b21   a00*b02 + a01*b12 + a02*b22
  //  a10*b00 + a11*b10 + a12*b20   a10*b01 + a11*b11 + a12*b21   a10*b02 + a11*b12 + a12*b22 
  //  a20*b00 + a21*b10 + a22*b20   a20*b01 + a21*b11 + a22*b21   a20*b02 + a21*b12 + a22*b22

  double t1,t2,t3; //temps
  //calc row 1:
  t1 = vals[0][0]*tt.vals[0][0] + vals[0][1]*tt.vals[1][0] + vals[0][2]*tt.vals[2][0]; // 
  t2 = vals[0][0]*tt.vals[0][1] + vals[0][1]*tt.vals[1][1] + vals[0][2]*tt.vals[2][1]; //  > row 1
  t3 = vals[0][0]*tt.vals[0][2] + vals[0][1]*tt.vals[1][2] + vals[0][2]*tt.vals[2][2]; //     
  //calc x translation:
  vals[0][3] = (vals[0][0] * tt.vals[0][3] + vals[0][1] * tt.vals[1][3] +  vals[0][2] * tt.vals[2][3]) + vals[0][3];
  //update values for row 1:
  vals[0][0] = t1;
  vals[0][1] = t2;
  vals[0][2] = t3;

  //calc row 2:
  t1 = vals[1][0]*tt.vals[0][0] + vals[1][1]*tt.vals[1][0] + vals[1][2]*tt.vals[2][0]; // 
  t2 = vals[1][0]*tt.vals[0][1] + vals[1][1]*tt.vals[1][1] + vals[1][2]*tt.vals[2][1]; //  > row 2
  t3 = vals[1][0]*tt.vals[0][2] + vals[1][1]*tt.vals[1][2] + vals[1][2]*tt.vals[2][2]; // 
  //calc y translation:
  vals[1][3] = (vals[1][0] * tt.vals[0][3] + vals[1][1] * tt.vals[1][3] +  vals[1][2] * tt.vals[2][3]) + vals[1][3];
  //update values for row 2:
  vals[1][0] = t1;
  vals[1][1] = t2;
  vals[1][2] = t3;

  //calc row 3:
  t1 = vals[2][0]*tt.vals[0][0] + vals[2][1]*tt.vals[1][0] + vals[2][2]*tt.vals[2][0]; // 
  t2 = vals[2][0]*tt.vals[0][1] + vals[2][1]*tt.vals[1][1] + vals[2][2]*tt.vals[2][1]; //  > row 3
  t3 = vals[2][0]*tt.vals[0][2] + vals[2][1]*tt.vals[1][2] + vals[2][2]*tt.vals[2][2]; // 
  //calc z translation:
  vals[2][3] = (vals[2][0] * tt.vals[0][3] + vals[2][1] * tt.vals[1][3] +  vals[2][2] * tt.vals[2][3]) + vals[2][3];
  //update values for row 3:
  vals[2][0] = t1;
  vals[2][1] = t2;
  vals[2][2] = t3;
  
  //this method is testet and verified with mathematica
}

Point3D Transform::mul(const Point3D &p){
  return Point3D(vals[0][0]*p[0] + vals[0][1]*p[1] + vals[0][2]*p[2],
                 vals[1][0]*p[0] + vals[1][1]*p[1] + vals[1][2]*p[2],
                 vals[2][0]*p[0] + vals[2][1]*p[1] + vals[2][2]*p[2]);
}

void Transform::getRotation(double (&rot)[3][3]){
  //double rot[3][3];
  //  return rot;
  for (int col = 0; col < 3; col++)
    for (int row = 0; row < 3; row++)
      rot[row][col]=vals[row][col];
      //      mat[4 * col + row] = row < 3 ? get (row, col) : col == 3 ? 1 : 0;
}

void Transform::getTranslation(double (&tran)[3]){
  tran[0] = vals[0][3];
  tran[1] = vals[1][3];
  tran[2] = vals[2][3];
}

Point3D Transform::getTranslation(){
  return Point3D(vals[0][3],vals[1][3],vals[2][3]);
}

void Transform::getGlMatrix (double (&mat)[16]) const  {
  for (int col = 0; col < 4; col++)
    for (int row = 0; row < 4; row++)
      mat[4 * col + row] = row < 3 ? get (row, col) : col == 3 ? 1 : 0;
}
     
void Transform::glMultMatrix () const{
  double mat[16];
  getGlMatrix (mat);
  glMultMatrixd (mat);
}

void Transform::print(){
  fprintf(stderr,"+-------------------------+\n");
  fprintf(stderr,"| %.2f  %.2f  %.2f | %.2f |\n", vals[0][0],vals[0][1],vals[0][2],vals[0][3]);
  fprintf(stderr,"| %.2f  %.2f  %.2f | %.2f |\n", vals[1][0],vals[1][1],vals[1][2],vals[1][3]);
  fprintf(stderr,"| %.2f  %.2f  %.2f | %.2f |\n", vals[2][0],vals[2][1],vals[2][2],vals[2][3]);
  fprintf(stderr,"| %.2f  %.2f  %.2f | %.2f |\n", 0.0,0.0,0.0,1.0);
  fprintf(stderr,"+-------------------------+\n");
}

void Transform::copy(Transform &t){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      vals[i][j]=t.vals[i][j];
    }
  }
}

double Transform::get (int i, int j) const  {
  assert (0 <= i && i < 3 && 0 <= j && j < 4);
  return vals[i][j];
}

void Transform::set (int i, int j, double val)
{
  assert (0 <= i && i < 3 && 0 <= j && j < 4);
  vals[i][j] = val;
}
