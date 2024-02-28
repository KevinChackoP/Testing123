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

  //Set the next node to null (will be set if pushed into stack)
  nextNode = NULL;
  left = NULL;
  right = NULL:
}

//Destructor for node class
node::~node() {
  nextNode = NULL;
}
