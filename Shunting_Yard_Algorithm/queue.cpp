/*
  This program serves as the cpp program for the Shunting Yard Program's
  output queue class. It has all the functions that will be used in the
  main.cpp file.
  Author: Kevin Chacko
  Last Updated: WRITE DATE HERE
  Period 5, C++ / Data Structures
*/

//imports
#include "queue.h"

//Constructor for queue class
queue::queue() {
  //Assign queue's head node to NULL
  head = NULL;
}

//Destructor for queue class
queue::~queue() {
  if(head != NULL) {
    delete head;
  }
}

//Enqueue function for queue, will set the inputted node as the new head node
//and the old head as its next node, putting the new node at the start of
//the queue
void queue::enqueue(node* newHead) {
  newHead -> setNext(head);
  head = newHead;
}

//Dequeue function for queue, will return the character of the tail node of
//the queue's linked list, and will remove the tail node from the list
char queue::dequeue() {
  //set variables
  node* tail = head;
  char data;

  //check to make sure that the head isn't null
  if(head == NULL) {
    //if so, return a null character
    return '\0';
  }

  //check tail's next node
  if(tail -> getNext() != NULL) {
    //if the tail has a next node, keep going down the list until the tail
    //is the second to last node
    while(tail -> getNext() -> getNext() != NULL) {
      tail = tail -> getNext();
    }

    //get the character of the next node of the tail (the actual tail node)
    data = tail -> getNext() -> getCharacter();

    //delete the node after the tail node (the actual tail node of the
    //linked list) and set the next node the tail node is pointing to to NULL
    delete (tail -> getNext());
    tail -> setNext(NULL);
    
  } else {
    //the tail doesn't have a next node, meaning that the tail is the head,
    //get the head's character and delete it.
    data = head -> getCharacter();

    delete head;
    head = NULL;
  }

  //return the deleted node's (actual tail node's) character
  return data;
}
