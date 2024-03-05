/*
  This program serves as the cpp program for the Shunting Yard Program's
  node class. It has all the functions that will be used in the stack, 
  queue, and expression tree.
  Author: Kevin Chacko
  Last Updated: WRITE DATE HERE
  Period 5, C++ / Data Structures
*/

//imports
#include "node.h"

//Constructor for node class
node::node(char inputChar) {
  //Assign node's character based on what was passed in
  mathChar = inputChar;

  //Set the next node to null (will be set by other class functions)
  nextNode = NULL;
  left = NULL;
  right = NULL;
}

//Destructor for node class
node::~node() {
  //delete all the node pointers this node has
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
char node::getCharacter() {
  return mathChar;
}

//next node setter
void node::setNext(node* newNext) {
  nextNode = newNext;
}

//next node getter
node* node::getNext() {
  return nextNode;
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
