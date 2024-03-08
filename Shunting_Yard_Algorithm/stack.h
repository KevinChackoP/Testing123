/*
  This program serves as the header for the Shunting Yard Program's operator
  stack class. It defines everything for the stack.cpp file to use.
  Author: Kevin Chacko
  Last Updated: 3/7/2024
  Period 5, C++ / Data Structures
*/

//Implementation of a header guard for header file
#ifndef STACK_H
#define STACK_H

//imports
#include <iostream>
#include "node.h"

using namespace std;

//Start of stack class
class stack {
 //Public functions for stack
 public:
  //Constructor and Destructor
  stack();
  ~stack();

  //Stack specific functions
  void push(node* newHead);
  char pop();
  char peek();

  //Expression tree functions
  node* popNode();
  void prefixPrint(node* tokenNode);
  void postfixPrint(node* tokenNode);
  void infixPrint(node* tokenNode);

 //Private variables and pointers for class
 private:
   node* head;
};

#endif
