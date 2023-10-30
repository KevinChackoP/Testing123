#include <iostream>
#include "parent.h"
using namespace std;

parent::parent() {
  cout << "Parent Constructor" << endl;
  id = 0;
}
int parent::getid() {
  return id;
}
int parent::myfunction() {
  return 100;
}
