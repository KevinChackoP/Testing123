/*
  This program serves as the header file for the Red-Black Tree Program's 
  redBlackTree class which holds the red-black tree data structure used in 
  main.cpp. It defines everything for the redBlackTree.cpp file to use.
  Author: Kevin Chacko
  Last Updated: WRITE END DATE HERE
  Period 5, C++ / Data Structures
*/

/*
  For this class's functions I mainly just used the functions I used in my 
  Binary Search Tree project, but also added other functions for the red-black 
  tree itself.
*/

//Implementation of a header guard for header file
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

//imports
#include <iostream>
#include "node.h"

using namespace std;

//Start of stack class
class redBlackTree {
 //Public Functions for main.cpp
 public:
  //Constructor and Destructor
  redBlackTree();
  ~redBlackTree();

  //Normal BST functions
  void addNode(int input);
  void deleteNode(int target);
  void searchNode(int target);
  void printTree();
  void printTreeStep(node* index, int steps);
  void deleteTreeStep(node* index);
  bool isTreeEmpty();

  //Red-Black Tree functions
  void insertionCases(node* index);
  void rightRotation(node* pivot);
  void leftRotation(node* pivot);

 //Private variables and pointers for class
 private:
  node* root;
};

#endif
