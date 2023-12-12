#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

#include "Student.h"

class Node {
 public:
  //Constructor and Deconstructor
  Node(Student* newstudent);
  ~Node();
  
  //Gets the next node
  Node* getNext();
  
  //returns student
  Student* getStudent();
  
  //sets the next node
  void setNext(Node* newnext);
  
 private:
  Student* student;
  Node* next;
};

#endif
