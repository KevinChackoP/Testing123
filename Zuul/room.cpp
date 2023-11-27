//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

//room class constructor
room::room(char* nameInput, char* descriptionInput, map<int, int> & exitsInput, int idInput) {
  //On construction, set variables based on parameters passed in
  name = new char[31];
  strcpy(name, nameInput);
  description = new char[201];
  strcpy(description, descriptionInput);
  exits = exitsInput;
  id = idInput;
  
  //empty room inventory vector was made in header
}

//room class deconstructor
room::~room() {
  //delete cstrings
  delete name;
  delete description;

  //empty inventory vector
  while(!roomInv.empty()) {
    delete roomInv.back();
    roomInv.pop_back();
  }
}

//room name getter function
char* room::getName() {
  return name;
}

//room description getter function
char* room::getDescription() {
  return description;
}

//room description setter function
void room::setDescription(char* newDescription) {
  strcpy(description, newDescription);
}

//room exits map getter function
map<int, int> room::getExits() {
  return exits;
}

//room inventory getter function
vector<item*> room::getRoomInv() {
  return roomInv;
}

//This function will take an item and push it into the room inventory vector
void room::addRoomInv(item* newItem) {
  roomInv.push_back(newItem);
}

//This function will search the room's inventory for an item, remove it from
//the room's inventory, then return that item
/*
  I got a lot of help for this function by looking back and using my code
  from the student list project from the deleteStudent function. This helped
  me remember how to remove an item from a vector and delete or reassign it
  before doing so.
 */
item* room::removeRoomInv(char* itemName) {
  //end variable to return
  item* returnItem = NULL;

  //loop through room inventory
  for(vector<item*>::iterator it = roomInv.begin(); it != roomInv.end(); it++) {
    if(strcmp(((*it) -> name), itemName) == 0) {
      //If an item in the room's inventory matches with the name being used
      //to search for the item, assign it to the return item variable
      returnItem = *it;

      //And remove it from the vector before leaving the loop
      roomInv.erase(it);
      break;
    }
  }

  //If an item matched with the search name, return it, else return NULL
  //to show that there wasn't a matching item
  return returnItem;
}

//room ID getter function
int room::getID() {
  return id;
}
