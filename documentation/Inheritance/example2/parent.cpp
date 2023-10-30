#include "parent.h"

parent::parent(int value) {
  //Notice that id isn't set in the constructor, so it can be anything
  cout << "Parent Constructor" << endl;
}

int parent::getID() {
  return id;
}
