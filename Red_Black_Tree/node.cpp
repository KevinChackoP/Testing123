/*
  This program serves as the cpp program for the Red-Black Tree Program's
  node class. It has all the functions that will be used to make and modify
  the nodes for the Red-Black Tree.
  Author: Kevin Chacko
  Last Updated: WRITE END DATE HERE
  Period 5, C++ / Data Structures
*/

/*
  For this whole file I copy pasted my code from my Binary Search Tree 
  project's node.cpp file and just modified the code to fit my red-black tree.
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
  //set the nodes the node points to to NULL
  left = NULL;
  right = NULL;
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
