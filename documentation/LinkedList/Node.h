#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

//This is for a singly linked list (can only go one direction, has null
//pointer to signal end of list)
class Node {
 public:
  Node();
  ~Node();
  void setValue(int newvalue);
  int getValue();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  int value; //This is the main thing that the linked list holds
  Node* next;
};

#endif
