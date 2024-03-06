/*
  This program serves as the cpp program for the Shunting Yard Program's 
  operator stack class. It has all the functions that will be used in the 
  main.cpp file. 
  Author: Kevin Chacko
  Last Updated: WRITE DATE HERE
  Period 5, C++ / Data Structures
*/

//imports
#include "stack.h"

//Constructor for stack class
stack::stack() {
  //Assign stack's head node to NULL
  head = NULL;
}

//Destructor for stack class
stack::~stack() {
  if(head != NULL) {
    delete head;
  }
}

//Push function for stack, will set the inputted new head node as the
//head of the stack and the old head as its next node
void stack::push(node* newHead) {
  newHead -> setNext(head);
  head = newHead;
}

//Pop function for stack, will return the value of the current head node and
//will remove the head from the stack, setting it's next node as the new head
char stack::pop() {
  char data = head -> getCharacter();

  node* temp = head;
  head = head -> getNext();
  temp -> setNext(NULL);
  delete temp;
  
  return data;
}

//Peek function for stack, will return the value of the current head node
char stack::peek() {
  if(head == NULL) {
    //if the head is null, return a null character
    return '\0';
    
  } else {
    //if the head is a valid node, return the node's character
    return (head -> getCharacter());
  }
}
