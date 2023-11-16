/* 
   This program... WRITE MORE HERE, MAKE SURE TO INCLUDE MAP OF ZUUL GAME IN
   THIS PROGRAM'S FOLDER!
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
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

//Function prototypes
void instructions();
int askCommand();
void move(vector<room*> & list);
void take(vector<room*> & list);
void inventory(vector<item*> & inventory);
void drop(vector<room*> & list);

//Start of main function
int main() {
  //local variable declarations
  vector<room*> roomList;
  vector<item*> inventory;
  bool inUse = true;
  int commandKey = 0;

  //Set the situation up for the player and tell them how the game works
  instructions();
  
  //If nothing went wrong, return 0
  return 0;
}

//This function sets the situation the game takes place in up before telling
//the user how to use the program
void instructions() {
  cout << "Today is the day. You leave your make shift home buried " << endl;
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
  cout << "you can QUIT. I won't hold it against you if you do. " << endl;
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
