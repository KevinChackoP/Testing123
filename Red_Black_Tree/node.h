/*
  This program serves as the header for the Red-Black Tree Program's node
  class which will be used to make up the red-black tree. It defines 
  everything for the node.cpp file to use.
  Author: Kevin Chacko
  Last Updated: 5/22/2024
  Period 5, C++ / Data Structures
*/

/*
  For this whole file I copy pasted my code from my Binary Search Tree 
  project's node.h file and just modified the code to fit my red-black tree.
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
  void setInt(int newValue);
  int getInt();
  void setBlack();
  void setRed();
  int getColor();
  void setLeft(node* newLeft);
  node* getLeft();
  void setRight(node* newRight);
  node* getRight();
  void setParent(node* newParent);
  node* getParent();

 //Private variables and pointers for class
 private:
  //node data
  int number;
  int color; //black = 0, red = 1
  
  //for node children
  node* left;
  node* right;
  
  //for node parent
  node* parent;
};

#endif
