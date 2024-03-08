/*
  This program serves as the header for the Shunting Yard Program's output
  queue class. It defines everything for the queue.cpp file to use.
  Author: Kevin Chacko
  Last Updated: 3/7/2024
  Period 5, C++ / Data Structures
*/

//Implementation of a header guard for header file
#ifndef QUEUE_H
#define QUEUE_H

//imports
#include <iostream>
#include "node.h"

using namespace std;

//Start of queue class
class queue {
 //Public functions for queue
 public:
  //Constructor and Destructor
  queue();
  ~queue();

  //Queue specific functions
  void enqueue(node* newHead);
  char dequeue();

 //Private variables and pointers for class
 private:
  node* head;
};

#endif
