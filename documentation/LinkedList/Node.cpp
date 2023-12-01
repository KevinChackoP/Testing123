#include "Node.h"

Node::Node() {
  value = 0;
  next = NULL;
}

Node::~Node() {
  delete &(value); //we use & since value isn't a pointer but a variable type
  next = NULL;
}

void Node::setValue(int newvalue) {
  value = newvalue;
}

int Node::getValue() {
  return value;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}
