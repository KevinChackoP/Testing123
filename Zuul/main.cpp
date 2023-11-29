/* 
   This program... WRITE MORE HERE, MAKE SURE TO INCLUDE MAP OF ZUUL GAME IN
   THIS PROGRAM'S FOLDER!
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  To get help with assigning a value to a cstring I looked at the cplusplus
  documentation for strcpy.
  URL: https://cplusplus.com/reference/cstring/strcpy/
  This helped me deal with some issues involving giving a name and description
  to my rooms. I figured out that "" alone couldn't be passed as a cstring
  value into a parameter, but could be assigned to a cstring variable which
  could then be passed in as a parameter.

  To get help with using the map class I used the cplusplus docs on map.
  URL: https://cplusplus.com/reference/map/map/
  I used this and its pages in order to figure out how to initialize a map,
  access its values, and manipulate it. This was crucial for making my exits
  in my game work. 

  NOTE CITATIONS HERE
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <vector>
#include <map>

//class imports
#include "room.h"

using namespace std;

//Global constants
const int NORTH = 1;
const int EAST = 2;
const int SOUTH = 3;
const int WEST = 4;

//Function prototypes
void instructions();
int askCommand();
void roomDescription(vector<room*> & list, int roomID);
void move(vector<room*> & list, int & roomID);
void take(vector<room*> & list, vector<item*> & inventory, int roomID);
void inventoryPrint(vector<item*> & inventory);
void drop(vector<room*> & list, vector<item*> & inventory, int roomID);

//Start of main function
int main() {
  //local variable declarations
  vector<room*> roomList;

  //item declarations (added to rooms later)
  item* knife = new item(); //Item 1
  strcpy((*knife).name, "KNIFE");
  strcpy((*knife).description, "This should do as an adequate weapon.");
  (*knife).id = 1;
  item* key = new item(); //Item 2
  strcpy((*key).name, "KEY");
  strcpy((*key).description, "You snag a key from the key ring. The old drunkard should \nhave kept it safer.");
  (*key).id = 2;
  item* dustBottle = new item(); //Item 3
  strcpy((*dustBottle).name, "DUST BOTTLE");
  strcpy((*dustBottle).description, "You can burn some dust to use some black magic \nto find your target. Though, why does the old \ndrunkard have this?");
  (*dustBottle).id = 3;
  item* soul = new item(); //Item 4
  strcpy((*soul).name, "SOUL");
  strcpy((*soul).description, "This is what you needed to acquire from your \ntarget. You should head back to THE CROW as soon as possible.");
  (*soul).id = 4;
  item* photo = new item(); //Item 5
  strcpy((*photo).name, "PHOTO");
  strcpy((*photo).description, "It's a picture of your master from before the \nmonsters invaded. She's told you about it before.");
  (*photo).id = 5;
  
  //room declarations and additions to list
  char initName[31] = "Mostly Empty Hut";
  char initDescription[201] = "This is the makeshift home both you and your master are staying at. She's \ncurrently at a table writing something as she awaits for you to complete \nyour test. Don't disappoint her.";
  map<int,int> initExits = {{EAST, 3}, {SOUTH, 2}};
  room* emptyHut = new room(initName, initDescription, initExits, 1);
  roomList.push_back(emptyHut); //Room 1 added
  strcpy(initName, "Training Grounds");
  strcpy(initDescription, "This is where your master trained you so that you could fight off the \nmonsters alone. There should be something you can arm yourself with \nnearby.");
  initExits = {{NORTH, 1}};
  room* trainingGrounds = new room(initName, initDescription, initExits, 2);
  (*trainingGrounds).addRoomInv(knife); //Item 1 added
  roomList.push_back(trainingGrounds); //Room 2 added
  strcpy(initName, "Road with Branching Paths");
  strcpy(initDescription, "There are three tunnels, one that heads to the city, one \nwhich leads to the \"countryside\" where a few monsters live, and the last \n which leads to your makeshift home.");
  initExits = {{EAST, 4}, {SOUTH, 6}, {WEST, 1}};
  room* branchingRoad = new room(initName, initDescription, initExits, 3);
  roomList.push_back(branchingRoad); //Room 3 added
  strcpy(initName, "Hermit's House");
  strcpy(initDescription, "In the countryside you find a small house that's in pretty \nbad condition. It's probably owned by a hermit, though it's unusual that \nthey don't seem to be home.");
  initExits = {{EAST, 5}, {WEST, 3}};
  room* hermitHouse = new room(initName, initDescription, initExits, 4);
  roomList.push_back(hermitHouse); //Room 4 added
  strcpy(initName, "Indoors of Hermit's House");
  strcpy(initDescription, "With the door now open you are inside the hermit's house. \n Maybe you can find something useful in here.");
  initExits = {{WEST, 4}};
  room* insideHermitHouse = new room(initName, initDescription, initExits, 5);
  (*insideHermitHouse).addRoomInv(dustBottle); //Item 3 added
  roomList.push_back(insideHermitHouse); //Room 5 added
  strcpy(initName, "Clearing Before City");
  strcpy(initDescription, "You hear that there is a good view of the city from here. \nThe buildings are carved out from earthen pillars, the windows glistening \nwith blue light. Around the city is a lake covered in cave lilies.");
  initExits = {{NORTH, 3}, {EAST, 7}};
  room* cityClearing = new room(initName, initDescription, initExits, 6);
  roomList.push_back(cityClearing); //Room 6 added
  strcpy(initName, "City's Edge");
  strcpy(initDescription, "The area isn't busy. Around you are dated earthen mounds \nhousing small businesses. You get the idea that the monsters around here aren't \nto well to do.");
  initExits = {{EAST, 8}, {SOUTH, 9}, {WEST, 6}};
  room* cityEdge = new room(initName, initDescription, initExits, 7);
  roomList.push_back(cityEdge); //Room 7 added
  strcpy(initName, "The Drawl");
  strcpy(initDescription, "The draught house reeks of the smell of rotten marshmellos. \nThe customers around you are lively, with one's voice \nbeing accompanied by the clatter of keys.");
  initExits = {{WEST, 7}};
  room* theBar = new room(initName, initDescription, initExits, 8);
  (*theBar).addRoomInv(key); //Item 2 added
  roomList.push_back(theBar); //Room 8 added
  strcpy(initName, "City Crosswalks");
  strcpy(initDescription, "At the center of the city its streets all converge. You \nhear the pattering of feet and the flapping of wings all around you. You can \nget to wherever you need to go, given that you're careful.");
  initExits = {{NORTH, 7}, {EAST, 14}, {SOUTH, 12}, {WEST, 10}};
  room* cityCrosswalks = new room(initName, initDescription, initExits, 9);
  roomList.push_back(cityCrosswalks); //Room 9 added
  
  vector<item*> inventory;
  int currentRoom = 1; //Start with Mostly Empty Hut
  bool inUse = true;
  int commandKey = 0;

  //Set the situation up for the player and tell them how the game works
  instructions();

  //Let the player know the game has started (in story it's a test)
  cout << "------------------Test Start------------------" << endl;
  cout << endl;

  //Have them loop through doing actions in the game until they win or until
  //they want to quit
  while(inUse) {
    //Give the user a description of their surroundings based on the current
    //room they are in
    roomDescription(roomList, currentRoom);
    
    //ask the user to choose an action
    commandKey = askCommand();

    //Based on their command, have them do something in the game
    if(commandKey == 1) { //If they want to move...
      cout << "You consider where to go next..." << endl;
      cout << endl;
      move(roomList, currentRoom);
      
    } else if(commandKey == 2) { //If they want to take an item from their current room...
      cout << "You consider what to take from your surroundings..." << endl;
      cout << endl;
      take(roomList, inventory, currentRoom);

    } else if(commandKey == 3) { //If they want to check their inventory...
      cout << "You check your current belongings..." << endl;
      cout << endl;
      inventoryPrint(inventory);

    } else if(commandKey == 4) { //If they want to drop an item into their current room...
      cout << "You decide to leave one of your belongings in the room..." << endl;
      cout << endl;
      drop(roomList, inventory, currentRoom);
      
    } else if(commandKey == 5) { //If they want to quick the game
      cout << "You decide to give up. You feel THE CROW's disappointment " << endl;
      cout << "crawling on your back. " << endl;

      //delete the pointers from the vectors used
      while(!roomList.empty()) {
	delete roomList.back();
	roomList.pop_back();
      }
      while(!inventory.empty()) {
	delete inventory.back();
	inventory.pop_back();
      }

      inUse = false;
    }
  }
  
  //If nothing went wrong, return 0
  return 0;
}

//This function sets the situation the game takes place in up before telling
//the user how to use the program
void instructions() {
  cout << "Today is the day. You leave your makeshift home buried " << endl;
  cout << "miles under the SURFACE in the UNDERGROUND. The 'sky' " << endl;
  cout << "is pitch black with specs of light emminating from the " << endl;
  cout << "ember crystals scattered along the cave ceiling. The air " << endl;
  cout << "is suffocating. You're going to change that by making it " << endl;
  cout << "thick with dust. Outside your master is writing something." << endl;
  cout << "You head over and consult THE CROW. They repeat the " << endl;
  cout << "instructions the gave you the day before. Arm yourelf and " << endl;
  cout << "make your way to the city. Track down your target and " << endl;
  cout << "obtain what you need from them. Then you'll be ready. " << endl;
  cout << "\"Remember,\" she says. \"You can MOVE between areas " << endl;
  cout << "based on the exits available in each area. If there is " << endl;
  cout << "an item in the area you can TAKE it. You can also assess " << endl;
  cout << "your INVENTORY to see what items you currently have. " << endl;
  cout << "Furthermore, you can DROP items that you currently have " << endl;
  cout << "into the area you are in. Lastly, if you want to give up, " << endl;
  cout << "you can QUIT. I won't hold it against you if you do.\"" << endl;
  cout << endl;
}

//This function asks the user for their command
int askCommand() {
  //make an input array and clean it up
  char input[10];
  for(int i = 0; i < 10; i++) {
    input[i] = '\0';
  }

  //Tell them how to input a command (told in instructions)
  cout << "What do you want to do?" << endl;

  //ask them for a command input, if the input is valid return an int for the
  //command key, if invalid have them reinput their desired command.
  while(true) {
    //Ask for input
    cin.get(input, 10);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Clean input up by making it all upper case
    for(int i = 0; i < 10; i++) {
      input[i] = toupper(input[i]);
    }

    //return the corresponding command key to their command
    if(strcmp(input, "MOVE") == 0) {
      return 1;
    } else if(strcmp(input, "TAKE") == 0) {
      return 2;
    } else if(strcmp(input, "INVENTORY") == 0) {
      return 3;
    } else if(strcmp(input, "DROP") == 0) {
      return 4;
    } else if(strcmp(input, "QUIT") == 0) {
      return 5;
    } else { //If their command is invalid, tell them and have them try again
      cout << "What's that? You don't know how to do that!" << endl;
      cout << "This is what you know you can do: " << endl;
      cout << "MOVE, TAKE, INVENTORY, DROP, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function gives a description of the current room
void roomDescription(vector<room*> & list, int roomID) {
  //Loop through rooms list
  for(vector<room*>::iterator it = list.begin(); it != list.end(); it++) {
    //Find the current room in the rooms list
    if((*it) -> getID() == roomID) {
      //print out all the information about the room
      cout << (*it) -> getName() << endl; //Name
      cout << (*it) -> getDescription() << endl; //Description
      cout << endl;
      
      cout << "Current area exits:" << endl; //Exits
      map<int, int> roomExits = (*it) -> getExits();
      if(roomExits.find(NORTH) != roomExits.end()) {
	cout << "NORTH\t";
      }
      if(roomExits.find(EAST) != roomExits.end()) {
	cout << "EAST\t";
      }
      if(roomExits.find(SOUTH) != roomExits.end()) {
	cout << "SOUTH\t";
      }
      if(roomExits.find(WEST) != roomExits.end()) {
	cout << "WEST\t";
      }
      cout << endl;
      cout << endl;

      if(((*it) -> getRoomInv()).empty()) { //No Items
	cout << "There are no notable items here." << endl;
      } else { //Items List
	cout << "Notable items in the vicinity:" << endl; //Exits
	vector<item*> roomItems = (*it) -> getRoomInv();
	for(vector<item*>::iterator it2 = roomItems.begin(); it2 != roomItems.end(); it2++) {
	  cout << (*it2) -> name << "\t";
	}
	cout << endl;
      }
      
      cout << endl;
    }
  }
}

//This function moves the player from their current room into another one
void move(vector<room*> & list, int & roomID) {
  //make an input array for the exit name and clean it up
  char input[7];
  for(int i = 0; i < 7; i++) {
    input[i] = '\0';
  }
  bool invalidInput = true;

  //Ask the player for which exit they'd like to take
  cout << "Which exit would you like to take? (no more than 6 characters)" << endl;
  cout << endl;

  //Keep asking the player for an exit input until their input matches with
  //a valid exit or they want to quit.
  while(invalidInput) {
    cin.getline(input, 7);

    //Clean input up by making it all uppercase
    for(int i = 0; i < 7; i++) {
      input[i] = toupper(input[i]);
    }

    //validate the player's input
    if(strcmp(input, "QUIT") == 0) { //If they want to quit, exit function
      invalidInput = false;
    } else { //Find current room's exits
      for(vector<room*>::iterator it = list.begin(); it != list.end(); it++) {
	if((*it) -> getID() == roomID) {
	  map<int, int> roomExits = (*it) -> getExits();

	  //Check if the player's input matches one of the valid exit types and
	  //that said exit type exists for the current room
	  if(roomExits.find(NORTH) != roomExits.end() && strcmp(input, "NORTH") == 0) {
	    roomID = roomExits.at(NORTH); //Take the north exit
	    invalidInput = false;
	  } else if(roomExits.find(EAST) != roomExits.end() && strcmp(input, "EAST") == 0) {
	    roomID = roomExits.at(EAST); //Take the east exit
	    invalidInput = false;
	  } else if(roomExits.find(SOUTH) != roomExits.end() && strcmp(input, "SOUTH") == 0) {
	    roomID = roomExits.at(SOUTH); //Take the south exit
	    invalidInput = false;
	  } else if(roomExits.find(WEST) != roomExits.end() && strcmp(input, "WEST") == 0) {
	    roomID = roomExits.at(WEST); //Take the west exit
	    invalidInput = false;
	  }

	  //If an exit matching the user's input wasn't found...
	  if(invalidInput) { //The user's input was invalid, so tell them
	    cout << endl;
	    cout << "Sorry but that wasn't one of the available exits." << endl;
	    //Show them what exits are available for them to enter
	    cout << "These are the exits in the current area:" << endl;
	    if(roomExits.find(NORTH) != roomExits.end()) {
	      cout << "NORTH\t";
	    }
	    if(roomExits.find(EAST) != roomExits.end()) {
	      cout << "EAST\t";
	    }
	    if(roomExits.find(SOUTH) != roomExits.end()) {
	      cout << "SOUTH\t";
	    }
	    if(roomExits.find(WEST) != roomExits.end()) {
	      cout << "WEST\t";
	    }
	    cout << endl;
	    cout << "Please decide between one of these exits." << endl;
	    //Mention that they can also quit current action
	    cout << "Alternativally, if you don't want to move anymore, you " << endl;
	    cout << "can also QUIT instead." << endl;
	  }
	}
      }
    }
  }
  cout << endl;
}

//This function adds an item from the current room's inventory (removing it
//from the current room's inventory) into the player's inventory
void take(vector<room*> & list, vector<item*> & inventory, int roomID) {
  //check that the room isn't empty before proceeding
  for(vector<room*>::iterator it = list.begin(); it != list.end(); it++) {
    if((*it) -> getID() == roomID) {
      if(!((*it) -> getRoomInv()).empty()) {
	//make an input array for the item name and clean it up
	char input[16];
	for(int i = 0; i < 16; i++) {
	  input[i] = '\0';
	}
	bool invalidInput = true;
	
	//Ask the player for which item they'd like to take
	cout << "Which item from your surroundings would you like to take?" << endl;
	cout << "(no more than 15 characters)" << endl;
	cout << endl;
	
	//Keep asking the player for an item name input until their input 
	//matches with an item existing in the room or they want to quit.
	while(invalidInput) {
	  cin.getline(input, 16);
	  cout << endl;
	  
	  //Clean input up by making it all uppercase
	  for(int i = 0; i < 16; i++) {
	    input[i] = toupper(input[i]);
	  }
	  
	  //validate the player's input
	  if(strcmp(input, "QUIT") == 0) { //If they want to quit, exit function
	    invalidInput = false;
	  } else {
	    //Find the current room's inventory
	    vector<item*> roomItems = (*it) -> getRoomInv();
	    
	    //go through the items in the room's inventory and see if any of
	    //the names of the items inside match with the player's input
	    for(vector<item*>::iterator it2 = roomItems.begin(); it2 != roomItems.end(); it2++) {
	      if(strcmp(input, (*it2) -> name) == 0) { //matching item was found
		//Give name and description of item
		cout << "You got the " << (*it2) -> name << "." << endl;
		cout << (*it2) -> description << endl;
		cout << endl;
		
		//add item into player inventory and remove it from room
		inventory.push_back((*it) -> removeRoomInv(input));
		
		//validate input and break from for loop to avoid running off
		invalidInput = false;
		break;
	      }
	    }
	    
	    //If their input didn't match with the name of any of the items in
	    //the current room...
	    if(invalidInput) { //The user's input was invalid, so tell them
	      cout << "Sorry but that wasn't one of the available items." << endl;
	      //List the items they can take in the current room
	      cout << "These are the items in the current area:" << endl;
	      for(vector<item*>::iterator it2 = roomItems.begin(); it2 != roomItems.end(); it2++) {
		cout << (*it2) -> name << "\t";
	      }
	      cout << endl;
	      cout << "Please decide between one of these items." << endl;
	      //Mention that they can quit current action
	      cout << "Alternativally, if you don't want to take anything anymore, " << endl;
	      cout << "you can also QUIT instead." << endl;
	      cout << endl;
	    }
	  }
	}
      } else {
	cout << "But there is nothing notable around to take." << endl;
	cout << endl;
      }
    } 
  }
}

//This function prints a list of the player's current inventory items
void inventoryPrint(vector<item*> & inventory) {
  //If the player has nothing in their inventory, tell them
  if(inventory.empty()) {
    cout << "Though, you find that you have nothing useful on you." << endl;
  } else { //The player has stuff in their inventory
    cout << "You see that you currently have these items: " << endl;
    //loop through and list each item in the player's inventory
    for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
      cout << (*it) -> name << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

//This function removes an item from the player's inventory and adds it
//to the inventory of the player's current room
void drop(vector<room*> & list, vector<item*> & inventory, int roomID) {
  //check to first make sure that the player's inventory isn't empty
  if(inventory.empty()) { //It is empty
    cout << "But find that you have nothing to leave in the room " << endl;
    cout << "to begin with. " << endl;
    cout << endl;
    
  } else { //there are possible items to drop
    //find the room the player is currently in
    for(vector<room*>::iterator it = list.begin(); it != list.end(); it++) {
      if((*it) -> getID() == roomID) {
	//make an input array for the item name and clean it up
	char input[16];
	for(int i = 0; i < 16; i++) {
	  input[i] = '\0';
	}
	bool invalidInput = true;
	
	//Ask the player for which item they'd like to drop
	cout << "Which item from your inventory would you like to drop?" << endl;
	cout << "(no more than 15 characters)" << endl;
	cout << endl;
	
	//Keep asking the player for an item name input until their input
	//matches with an item in their inventory or they want to quit.
	while(invalidInput) {
	  cin.getline(input, 16);
	  cout << endl;
	  
	  //Clean input up by making it all uppercase
	  for(int i = 0; i < 16; i++) {
	    input[i] = toupper(input[i]);
	  }
	  
	  //validate the player's input
	  if(strcmp(input, "QUIT") == 0) { //If they want to quit, exit function
	    invalidInput = false;
	  } else {
	    //go through the items in the room's inventory and see if any of
	    //the names of the items inside match with the player's input
	    for(vector<item*>::iterator it2 = inventory.begin(); it2 != inventory.end(); it2++) {
	      if(strcmp(input, (*it2) -> name) == 0) { //matching item was found
		//Tell the player that they successfully dropped the item
		cout << "You dropped the " << (*it2) -> name << " into the " << endl;
		cout << "area you're currently in. " << endl;
		cout << endl;
		
		//add item into the room's inventory and remove it from the
		//player's inventory
		(*it) -> addRoomInv((*it2));
		inventory.erase(it2);
		
		//validate input and break from the for loop to avoid running off
		invalidInput = false;
		break;
	      }
	    }

	    //If their input didn't match with the name of any of the items in
	    //their inventory...
	    if(invalidInput) { //The user's input was invalid, so tell them
	      cout << "Sorry but you don't have an item like that on you." << endl;
	      //List the items they can take in the current room
	      cout << "These are the items you currently have:" << endl;
	      for(vector<item*>::iterator it2 = inventory.begin(); it2 != inventory.end(); it2++) {
		cout << (*it2) -> name << "\t";
	      }
	      cout << endl;
	      cout << "Please decide between one of these items." << endl;
	      //Mention that they can quit current action
	      cout << "Alternativally, if you don't want to drop anything anymore, " << endl;
	      cout << "you can also QUIT instead." << endl;
	      cout << endl;
	    }
	  }
	}
      }
    }
  }
}
