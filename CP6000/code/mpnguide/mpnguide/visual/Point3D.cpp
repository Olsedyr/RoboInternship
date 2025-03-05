#include "Point3D.h"

Point3D::Point3D()
{
  vec[0] = 0; vec[1] = 0; vec[2] = 0;
}

Point3D::Point3D(double x, double y, double z)
{
    vec[0] = x; vec[1] = y; vec[2] = z;
}

Point3D::~Point3D()
{
}

double Point3D::operator[](int i) const
{
    assert(0 <= i && i < 3);
    return vec[i];
}

Point3D& Point3D::operator+=(const Point3D& p)
{
    for (int i = 0; i < 3; i++) vec[i] += p.vec[i];
    return *this;
}

Point3D& Point3D::operator*=(double scale)
{
    for (int i = 0; i < 3; i++) vec[i] *= scale;
    return *this;
}

Point3D Point3D::operator-(const Point3D& p) const
{
    return
        Point3D(vec[0] - p.vec[0],
                vec[1] - p.vec[1],
                vec[2] - p.vec[2]);
}

Point3D Point3D::operator+(const Point3D& p) const
{
    return
        Point3D(vec[0] + p.vec[0],
                vec[1] + p.vec[1],
                vec[2] + p.vec[2]);
}

Point3D Point3D::operator/(double d) const
{
    assert(d != 0);
    return
        Point3D(vec[0] / d,
                vec[1] / d,
                vec[2] / d);
}

Point3D operator*(double s, const Point3D& p)
{
    return Point3D(s * p[0], s * p[1], s * p[2]);
}

Point3D operator*(const Point3D& p, double s)
{
    return s * p;
}

bool Point3D::operator==(const Point3D& p) const
{
    for (int i = 0; i < 3; i++)
        if (vec[i] != p.vec[i])
            return false;
    return true;
}

bool Point3D::operator!=(const Point3D& p) const
{
    return !(*this == p);
}

double Point3D::length() const
{
    double sum = 0;
    for (int i = 0; i < 3; i++) sum += vec[i] * vec[i];
    return sqrt(sum);
}

void Point3D::draw() const
{
  glVertex3dv(vec);
}
