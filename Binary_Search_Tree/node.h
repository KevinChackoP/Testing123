/*
  This program serves as the header for the Binary Search Tree Program's node
  class which will be used to make up the binary search tree. It defines 
  everything for the node.cpp file to use.
  Author: Kevin Chacko
  Last Updated: WRITE END DATE HERE
  Period 5, C++ / Data Structures
*/

//Implementation of a header guard for header file
#ifndef NODE_H
#define NODE_H

//imports
#include <iostream>

using namespace std;

//Start of stack class
class node {
 //Public functions for stack
 public:
  //Constructor and Destructor
  node(int inputInt);
  ~node();
  
  //Node specific functions
  int getInt();
  void setLeft(node* newLeft);
  node* getLeft();
  void setRight(node* newRight);
  node* getRight();

 //Private variables and pointers for class
 private:
   //node data
   int number;
   
   //for node children
   node* left;
   node* right;
};

#endif
