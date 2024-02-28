/*
  This program serves as the cpp program for the Shunting Yard Program's 
  operator stack class. It has all the functions that will be used in the 
  main.cpp file. REVISE STACK CLASS TO USE NODE CLASS
  Author: Kevin Chacko
  Last Updated: WRITE DATE HERE
  Period 5, C++ / Data Structures
*/

//imports
#include "stack.h"

//Constructor for stack class
stack::stack(char inputOperator) {
  //Assign stack node's operator character based on what was passed in
  operator = inputOperator;

  //Set the next node to null (will be set if pushed into stack)
  nextNode = NULL;
}

//Destructor for stack class
stack::~stack() {
  nextNode = NULL;
}

//Push function for stack, will set the node as the head of the stack and the
//old head as its next node
void stack::push(stack* oldHead) {
  nextNode = oldHead;
}

//Pop function for stack, will return the value of the current node and change
//the node to its next node before deleting the old node
char stack::pop() {
  char data = operator;
  this = ()
}
