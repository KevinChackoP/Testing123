/*
  This program serves as the header for the Shunting Yard Program's node
  class which will be used for the stack, queue, and expression tree. 
  It defines everything for the node.cpp file to use.
  Author: Kevin Chacko
  Last Updated: WRITE DATE HERE
  Period 5, C++ / Data Structures
*/

//Implementation of a header guard for header file
#ifndef STACK_H
#define STACK_H

//imports
#include <iostream>

using namespace std;

//Start of stack class
class node {
 //Public functions for stack
 public:
  //Constructor and Destructor
  node(char inputChar);
  ~node();
  
  //Node specific functions
  char getCharacter();
  void setNext(node* newNext);
  node* getNext();

 //Private variables and pointers for class
 private:
   //node data
   char mathChar;
   
   //for stack and queue
   node* nextNode;

   //for expression tree
   node* left;
   node* right;
}

#endif
