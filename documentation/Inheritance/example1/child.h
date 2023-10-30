#include <iostream>
#include "parent.h"
using namespace std;

class child : public parent {
 public:
  child();
  void setN();
  int getN();
  int myfunction();
 protected:
  int n;
};
