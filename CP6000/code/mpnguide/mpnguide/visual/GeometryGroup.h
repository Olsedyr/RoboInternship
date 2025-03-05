#ifndef GEOMETRYGROUP_H_
#define GEOMETRYGROUP_H_

#include "Node.h"
#include "Transform.h"
#include "Geometry.h"

/** \brief GeometryGroup represents a group of other GeometryGroups or Geometrys
 *  
 */
class GeometryGroup : public Node
{
private:
  Transform transform;

public:
	GeometryGroup();
	virtual ~GeometryGroup();
  virtual void draw ();
};

#endif /*GEOMETRYGROUP_H_*/
