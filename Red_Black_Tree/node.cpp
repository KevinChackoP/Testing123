/*
  This program serves as the cpp program for the Red-Black Tree Program's
  node class. It has all the functions that will be used to make and modify
  the nodes for the Red-Black Tree.
  Author: Kevin Chacko
  Last Updated: 4/30/2024
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

  //Set the node's color to red
  color = 1;

  //Set the children to null (will be set later on in program)
  left = NULL;
  right = NULL;

  //Set the parent to null (will also be set later on in program)
  parent = NULL;
}

//Destructor for node class
node::~node() {
  //set the nodes the node points to to NULL
  left = NULL;
  right = NULL;
  parent = NULL;
}

//node value setter
void node::setInt(int newValue) {
  number = newValue;
}

//node value getter
int node::getInt() {
  return number;
}

//node color black setter
void node::setBlack() {
  color = 0;
}

//node color red setter
void node::setRed() {
  color = 1;
}

//node color getter
int node::getColor() {
  return color;
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

//parent node setter
void node::setParent(node* newParent) {
  parent = newParent;
}

//parent node getter
node* node::getParent() {
  return parent;
}
