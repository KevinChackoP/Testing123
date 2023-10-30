#include <iostream>
#include "child.h"

using namespace std;

int main() {
  cout << "Parent object: " << endl;
  parent* newparent = new parent(5);
  cout << "Child object: " << endl;
  child* newchild = new child(3, 10);
  cout << newparent->getID() << endl;
  cout << newchild->getID() << endl;
}
