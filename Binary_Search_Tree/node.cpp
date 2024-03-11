/*
  This program serves as the cpp program for the Shunting Yard Program's
  node class. It has all the functions that will be used in the stack, 
  queue, and expression tree.
  Author: Kevin Chacko
  Last Updated: 3/7/2024
  Period 5, C++ / Data Structures
*/

//imports
#include "node.h"

//Constructor for node class
node::node(int inputInt) {
  //Assign node's number based on what was passed in
  number = inputInt;

  //Set the children to null (will be set later on in program)
  left = NULL;
  right = NULL;
}

//Destructor for node class
node::~node() {
  //delete all the nodes the node points to
  if(nextNode != NULL) {
    delete nextNode;
  }
  if(left != NULL) {
    delete left;
  }
  if(right != NULL) {
    delete right;
  }
}

//node value getter
int node::getInt() {
  return number;
}

//left node setter
void node::setLeft(node* newLeft) {
  left = newLeft;
}

//left node getter
node* node::getLeft() {
  return left;
}

//right node setter
void node::setRight(node* newRight) {
  right = newRight;
}

//right node getter
node* node::getRight() {
  return right;
}
