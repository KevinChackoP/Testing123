/*
  This program serves as the cpp program for the Shunting Yard Program's 
  operator stack class. It has all the functions that will be used in the 
  main.cpp file. 
  Author: Kevin Chacko
  Last Updated: 3/7/2024
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
  //delete the head of the stack (will also delete all nodes in stack)
  if(head != NULL) {
    delete head;
  }
}

/*Stack Functions*/

//Push function for stack, will set the inputted new head node as the
//head of the stack and the old head as its next node
void stack::push(node* newHead) {
  newHead -> setNext(head);
  head = newHead;
}

//Pop function for stack, will return the value of the current head node and
//will remove the head from the stack, setting its next node as the new head
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

/*Expression Tree Functions*/

//Pop function for expression tree stack, will return the current head node and
//will remove the head from the stack, setting its next node as the new head
node* stack::popNode() {
  node* temp = head;
  head = head -> getNext();
  temp -> setNext(NULL);
  return temp;
  //No need to delete temp because this will be used for forming expression
  //tree, meaning what's popped will be put back into the stack as a child
  //node of another node, meaning it will be deleted when its parent is popped
}

//Prefix print function for expression tree, will print the expression tree's
//expression in prefix notation
void stack::prefixPrint(node* tokenNode) {
  //If input token node is null, it's the start of the recursive print,
  //set the token node to the head of the stack
  if(tokenNode == NULL) {
    tokenNode = head;
  }

  //do recursive print on token node:
  
  //print out the token in the node
  cout << (tokenNode -> getCharacter()) << " ";
  if(tokenNode -> getLeft() != NULL) {
    //if the left node exists, recurse through it
    prefixPrint(tokenNode -> getLeft());
  }
  if(tokenNode -> getRight() != NULL) {
    //if the right node exists, recurse through it
    prefixPrint(tokenNode -> getRight());
  }
}

//Postfix print function for expression tree, will print the expression tree's
//expression in postfix notation
void stack::postfixPrint(node* tokenNode) {
  //If input token node is null, it's the start of the recursive print,
  //set the token node to the head of the stack
  if(tokenNode == NULL) {
    tokenNode = head;
  }

  //do recursive print on token node:
  
  if(tokenNode -> getLeft() != NULL) {
    //if the left node exists, recurse through it
    postfixPrint(tokenNode -> getLeft());
  }
  if(tokenNode -> getRight() != NULL) {
    //if the right node exists, recurse through it
    postfixPrint(tokenNode -> getRight());
  }
  //print out the token in the node
  cout << (tokenNode -> getCharacter()) << " ";
}

//Infix print function for expression tree, will print the expression tree's
//expression in infix notation
void stack::infixPrint(node* tokenNode) {
  //If input token node is null, it's the start of the recursive print,
  //set the token node to the head of the stack
  if(tokenNode == NULL) {
    tokenNode = head;
  }

  //do recursive print on token node:
  
  if(tokenNode -> getLeft() != NULL) {
    if(((tokenNode -> getCharacter() == 'x'
	 || tokenNode -> getCharacter() == '/')
	&& (tokenNode -> getLeft() -> getCharacter() == '+'
	    || tokenNode -> getLeft() -> getCharacter() == '-'))
       || ((tokenNode -> getCharacter() == '^')
	&& (tokenNode -> getLeft() -> getCharacter() == 'x'
	    || tokenNode -> getLeft() -> getCharacter() == '/'
	    || tokenNode -> getLeft() -> getCharacter() == '+'
	    || tokenNode -> getLeft() -> getCharacter() == '-'))) {
      //if the operator of the left child is of lower precedence than the
      //parent child (if the parent is an operator), add parenthesis and
      //recurse through the left child
      cout << "( ";
      infixPrint(tokenNode -> getLeft());
      cout << ") ";

    } else {
      //recurse through the left node
      infixPrint(tokenNode -> getLeft());
    }
  }
  
  //print out the token in the node
  cout << (tokenNode -> getCharacter()) << " ";
  
  if(tokenNode -> getRight() != NULL) {
    if(((tokenNode -> getCharacter() == 'x'
	 || tokenNode -> getCharacter() == '/')
	&& (tokenNode -> getRight() -> getCharacter() == '+'
	    || tokenNode -> getRight() -> getCharacter() == '-'))
       || ((tokenNode -> getCharacter() == '^')
	&& (tokenNode -> getRight() -> getCharacter() == 'x'
	    || tokenNode -> getRight() -> getCharacter() == '/'
	    || tokenNode -> getRight() -> getCharacter() == '+'
	    || tokenNode -> getRight() -> getCharacter() == '-'))) {
      //if the operator of the right child is of lower precedence than the
      //parent child (if the parent is an operator), add parenthesis and
      //recurse through the right child
      cout << "( ";
      infixPrint(tokenNode -> getRight());
      cout << ") ";

    } else {
      //recurse through the right node
      infixPrint(tokenNode -> getRight());
    }
  }
}
