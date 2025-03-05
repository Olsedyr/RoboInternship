#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include "Triangle.h"
#include "Node.h"
#include <GL/glut.h>
#include <vector>

using namespace std;

/** \brief Geometry represents one single 3D object.
 *  
 * Længere beskrivelse
 */
class Geometry : public Node
{
protected:
  vector<Triangle> triangles; ///< Collections of triangles
  GLfloat color[3]; ///< RGB color of Geometry
  
public:
  /** \brief Constructor
   * 
   * Constructs a Geometry with initially no triangles
   * 
   */
	Geometry();
	virtual ~Geometry();
  bool inCollision;

  /** \brief Adds Triangle to Geometry 
   * 
   * \param a Corner a of Triangle
   * \param b Corner b of Triangle
   * \param c Corner c of Triangle
   * \param n Normal of Triangle
   */
  void addTriangle (Point3D a, Point3D b, Point3D c, Point3D n);
  
  /** \brief Sets color the color of the Geometry using RGB
   * 
   * \param r red color
   * \param g green color
   * \param b blue color
   */
  void setColor(float r, float g, float b);
  vector<Triangle>* getTriangles();
  void draw();
};

#endif /*GEOMETRY_H_*/
