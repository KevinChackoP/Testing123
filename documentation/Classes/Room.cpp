#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room() {
  description = new char[80];
  id = 0;
}

Room::Room(char* newdescription) {
  description = new char[80];
  strcpy(description, newdescription);
  id = 0;
}

char* Room::getDescription() {
  return description;
}

int Room::getID() {
  return id;
}
