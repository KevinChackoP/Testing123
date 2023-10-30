#include <iostream>
#include <vector>
#include "child.h"

int main() {
  child* c = new child();
  vector<parent*> storage;
  storage.push_back(c);
  cout << "vector storage id " << storage[0]->getid() << endl;
  cout << "c's n value " << c->getN() << endl;
  if(storage[0]->getid() == 1) {
    ((child*)storage[0])->setN();
  }
  cout << "c's n value " << c->getN() << endl;
  cout << "my function " << storage[0]->myfunction() << endl;
}
