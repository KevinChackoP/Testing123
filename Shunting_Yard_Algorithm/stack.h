/*
  This program serves as the header for the Shunting Yard Program's operator
  stack class. It defines everything for the stack.cpp file to use.
  REVISE STACK CLASS TO USE NODE CLASS
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
class stack {
 //Public functions for stack
 public:
  //Constructor and Destructor
  stack(char inputOperator);
  ~stack();

  //Stack specific functions
  void push(stack* oldHead);
  char pop();
  char peek();

 //Private variables and pointers for class
 private:
   char operator;
   stack* nextNode;
}

#endif
