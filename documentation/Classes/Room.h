#include <iostream>
#include <cstring>

using namespace std;

class Room {
 public:
  Room();
  Room(char*);
  char* getDescription();
  int getID();
 private:
  char* description;
  int id;
};
