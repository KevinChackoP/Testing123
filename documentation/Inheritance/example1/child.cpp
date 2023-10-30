#include <iostream>
#include "child.h"
using namespace std;

child::child() {
  cout << "Child Constructor" << endl;
  id = 1;
  n = 0;
}
void child::setN() {
  n = 20;
}
int child::getN() {
  return n;
}
int child::myfunction() {
  return 200;
}
