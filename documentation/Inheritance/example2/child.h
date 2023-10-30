#include <iostream>
#include "parent.h"

using namespace std;

class child : public parent {
 public:
  int second;
  child(int value, int secondvalue);
};
