#ifndef NODE_H_
#define NODE_H_

#include <vector>

using namespace std;

class Node
{
protected:
  int type;
  vector<Node*> children;
  
public:
	Node();
	virtual ~Node();
  bool hasParent;
  bool addChild(Node &node);
  Node* getChild(int i);
  int getType();
  virtual void draw() = 0;
};

#endif /*NODE_H_*/
