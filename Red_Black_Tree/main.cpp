/* 
   This project...
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got help for learning what a red-black tree is and what I need to do in 
  order to successfully make one from the "Red-Black Tree - Insertion"
  canvas module. Among these resources were videos made by Mr. Galbraith 
  on red-black concepts and red-black insertion cases and how to handle them.
  It also gave additional resources like a red-black visualizer, other videos, 
  and a link to the wikipedia page on red-black.

  For a lot of the processes that come with a normal binary search tree such 
  as printing, adding, deleting, searching with the tree I took from my 
  Binary_Search_Tree project and modified them to better fit the red-black.
  The same also goes for what I made my structure of this main.cpp file.

  ADD MORE CITATIONS HERE!!!
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <cstdlib>
#include <fstream>

//classes
#include "redBlackTree.h"

//create std shortcut
using namespace std;

//Function Prototypes
void instructions();
int askCommand();
void addNodesManually(redBlackTree* & tree);
void addNodesByFile(redBlackTree* & tree);
int nodeInput();

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  int commandKey = 0;
  redBlackTree* redBlack = new redBlackTree();
  
  //Tell the user how the program works
  instructions();

  //Put them through the loop of interacting with the binary search tree
  //until they are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something with the binary search tree or
    //quit the program
    if(commandKey == 1) {
      //If they want to add nodes to the tree manually, do so
      cout << "Adding nodes to the tree manually." << endl;
      cout << endl;

      addNodesManually(redBlack);
      
    } else if(commandKey == 2) {
      //If they want to add nodes to the tree through a file, do so
      cout << "Adding nodes to the tree via a file." << endl;
      cout << endl;
      
      addNodesByFile(redBlack);

    } else if(commandKey == 3) {
      //If they want to delete a node from the tree, do so
      cout << "Deleting a node from the tree." << endl;
      cout << endl;

      //check to make sure the tree isn't empty before deleting
      if(redBlack -> isTreeEmpty()) {
	//The tree is empty, so tell the user
	cout << "Sorry but the tree is empty! Please add nodes to the " << endl;
	cout << "tree before trying to delete them from the tree!" << endl;
	cout << endl;
	
      } else {
	//Ask the user for a number input
	cout << "What is the node value for the node you would like to " << endl;
	cout << "delete from the tree?" << endl;
	int userInput = nodeInput();
	redBlack -> deleteNode(userInput);
      }

    } else if(commandKey == 4) {
      //If they want to search for whether a node is in the tree or not, do so
      cout << "Searching for a node in the tree." << endl;
      cout << endl;

      //check to make sure the tree isn't empty before searching
      if(redBlack -> isTreeEmpty()) {
	//The tree is empty, so tell the user
	cout << "Sorry but the tree is empty! Please add nodes to the " << endl;
	cout << "tree before trying to search for nodes in the tree!" << endl;
	cout << endl;
	
      } else {
	//Ask the user for a number input
	cout << "What is the node value for the node you would like to " << endl;
	cout << "search for in the tree?" << endl;
	int userInput = nodeInput();
	redBlack -> searchNode(userInput);
      }

    } else if(commandKey == 5) {
      //If they want to print the current tree out and see how it's structured,
      //do so
      cout << "Printing out the current tree as it is." << endl;
      cout << endl;
      
      if(!(redBlack -> isTreeEmpty())) {
	//there is stuff in the tree, so continue printing
	redBlack -> printTree();
	cout << endl;
	
      } else {
	//the root is null and nothing will print, so tell the user that
	cout << "The tree is currently empty! Please try printing " << endl;
	cout << "out the tree after you've added nodes to it!" << endl;
	cout << endl;
      }
      
    } else if(commandKey == 6) {
      //If they want to quit the program, do so
      cout << "Ok then, I hope this was helpful!" << endl;
      cout << endl;

      //delete the tree which is on the heap
      delete redBlack;

      //change the boolean that determines if the program continues running
      inUse = false;
    }
  }

  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program helps you make a red-black tree that " << endl;
  cout << "holds numbers between 1-999 (inclusive). You can use various " << endl;
  cout << "commands to interact with the red-black tree. You can interact " << endl;
  cout << "with the red-black tree by manually adding numbers to the tree," << endl;
  cout << "using a file with various numbers between 1-999 seperated by " << endl;
  cout << "spaces to add to the tree, deleting a node from the tree, searching" << endl;
  cout << "for a node in the tree to see if it's there, and printing out the " << endl;
  cout << "tree to visually see its current structure. " << endl;
  cout << "I hope this program is of use to you!" << endl;
  cout << endl;
}

//This function asks the user for their command
int askCommand() {
  //make an input array and clean it up
  char input[10];
  for(int i = 0; i < 10; i++) {
    input[i] = '\0';
  }

  //Tell them how to input a command and what each of the commands do
  cout << "Please input a command to tell me what you want to do." << endl;
  cout << "Input ADDM to add numbers to the tree manually." << endl;
  cout << "Input ADDF to add numbers to the tree via a file." << endl;
  cout << "Input DELETE to delete a node from the tree." << endl;
  cout << "Input SEARCH to search for a node in the tree." << endl;
  cout << "Input PRINT to print out the tree's structure visually." << endl;
  cout << "Input QUIT to exit the program." << endl;
  cout << endl;

  //ask them for a command input, if the input is valid return an int for the
  //command key, if invalid have them reinput their desired command.
  while(true) {
    //Ask for input
    cin.getline(input, 10);

    //Clean input up by making it all upper case
    for(int i = 0; i < 10; i++) {
      input[i] = toupper(input[i]);
    }

    //return the corresponding command key to their command
    if(strcmp(input, "ADDM") == 0) {
      return 1;
    } else if(strcmp(input, "ADDF") == 0) {
      return 2;
    } else if(strcmp(input, "DELETE") == 0) {
      return 3;
    } else if(strcmp(input, "SEARCH") == 0) {
      return 4;
    } else if(strcmp(input, "PRINT") == 0) {
      return 5;
    } else if(strcmp(input, "QUIT") == 0) {
      return 6;
    } else { //If their command is invalid, tell them and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADDM, ADDF, DELETE, SEARCH, PRINT, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function will add nodes into the tree via manual input
void addNodesManually(redBlackTree* & tree) {
  //local variables
  int numInput = 0;

  //Tell them what to input
  cout << "Please input an integer number between 1-999 (inclusive)." << endl;
  cout << "If you wish to add multiple numbers, put your numbers in " << endl;
  cout << "a string with only spaces between each of your numbers." << endl;
  cout << "In both cases, after you're done typing all the numbers " << endl;
  cout << "you want to add, click enter and then type and enter " << endl;
  cout << "\"-1\" to signal that you're finished." << endl;
  cout << endl;

  //read through their input and add their numbers to the tree
  while((cin >> numInput) && numInput != -1) {
    if(numInput < 1) {
      //if their input is too low, let them know
      cout << numInput << " is lower than number range of 1-999 and won't be added to tree." << endl;
      cout << endl;
      
    } else if(numInput > 999) {
      //if their input is too high, let them know
      cout << numInput << " is higher than number range of 1-999 and won't be added to tree." << endl;
      cout << endl;
      
    } else {
      //if their input is within the range, add it to the tree
      tree -> addNode(numInput);
    }
  }

  //do some clean up
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
}

//This function will add nodes into the tree via file input
void addNodesByFile(redBlackTree* & tree) {
  //local variables
  int numInput = 0;
  char filename[31];
  for(int i = 0; i < 31; i++) {
    filename[i] = '\0';
  }

  //Tell them what to input
  cout << "Please input the name of your file with integers numbered " << endl;
  cout << "between 1-999 (inclusive). Please only seperate your " << endl;
  cout << "numbers using spaces or new lines, and include the file " << endl;
  cout << "type tag at the end of your filename (ie .txt). Don't use " << endl;
  cout << "a file with a name and tag longer than 30 characters." << endl;
  cout << endl;

  //take their input and open the file whose name they inputted
  cin.getline(filename, 31);
  ifstream fin(filename);

  //read through their file and add their numbers to the tree
  while(fin >> numInput) {
    if(numInput < 1) {
      //if their input is too low, let them know
      cout << numInput << " is lower than number range of 1-999 and won't be added to tree." << endl;
      cout << endl;
      
    } else if(numInput > 999) {
      //if their input is too high, let them know
      cout << numInput << " is higher than number range of 1-999 and won't be added to tree." << endl;
      cout << endl;
      
    } else {
      //if their input is within the range, add it to the tree
      tree -> addNode(numInput);
    }
  }

  //do some clean up
  fin.close();
  cout << endl;
}

//This function will take the user's input for what data they want to use
//in order to find a node in the tree with that data in it
int nodeInput() {
  //make input variable
  int input = -1;

  //tell the user what to input for their first input
  cout << "Please input an integer number between 1-999 (inclusive)." << endl;

  //until the user enters a valid input, keep taking their input
  while(input < 1 || input > 999) {
    //take their input
    cin >> input;

    //check if their input is valid and tell them if it isn't
    if(input < 1) {
      //if their input is too low, let them know
      cout << input << " is lower than the number range of 1-999." << endl;
      cout << "Please input a positive integer greater than 0." << endl;
      cout << endl;
      
    } else if(input > 999) {
      //if their input is too high, let them know
      cout << input << " is higher than the number range of 1-999." << endl;
      cout << "Please input a positive integer smaller than 1000." << endl;
      cout << endl;
    }
  }

  //do some clean up
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;

  //return their validated input
  return input;
}
