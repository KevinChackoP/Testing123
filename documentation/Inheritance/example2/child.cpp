#include "child.h"

child::child(int value, int secondvalue):parent(value) {
  //Child constructor gets called after parent constructor
  id = value;
  second = secondvalue;
  cout << "In child constructor" << endl;
}
