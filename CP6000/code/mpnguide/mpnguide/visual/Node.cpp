#include "Node.h"

Node::Node(){
  hasParent = false;
}

Node::~Node(){
}

bool Node::addChild(Node &node){
  if(!node.hasParent){
    children.push_back(&node);
    node.hasParent=true;
    return true;
  }else{
    fprintf(stderr, "Error: Already got a parent\n");
    return false;
  }
}

Node* Node::getChild(int i){
  return children.at(i);
}
int Node::getType(){
  return type;
}

void Node::draw(){
  printf("Node draw, this should be overwritten by inheriting class\n");
}
