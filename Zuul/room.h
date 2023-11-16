//Implement a header guard
#ifndef ROOM_H
#define ROOM_H

//Add imports
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

//struct declarations
struct item {
  char name[16];
  char description[51];
  int id;
};

//start of room class
class room {
 public:
  //Public variables and functions open for use wherever
  room(char* nameInput, char* descriptionInput, map<int, int> & exitsInput, vector<item*> & roomInvInput);
  ~room();
  char* getName();
  char* getDescription();
  void setDescription(char* newDescription);
  map<int, int> getExits();
  vector<item*> getRoomInv();
  void addRoomInv(item* newItem);
  item* removeRoomInv(char* itemName);
 protected:
  //secured variables that can't be accessed outside of class
  char* name;
  char* description;
  map<int, int> exits;
  vector<item*> roomInv;
}

#endif
