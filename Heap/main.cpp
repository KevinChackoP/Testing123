/* 
   This project... DESCRIBE WHAT THIS PROJECT DOES
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got some of help with learning what a heap is from the 
  "Hash Table" module and the "Assignment | Heap" module, and from 
  the latter resource I got the requirements for how I should make 
  my binary search tree.

  I learned much more about what a Binary Tree and a Heap is from the 
  Wikipedia pages on them.
  URL: https://en.wikipedia.org/wiki/Binary_tree
  URL: https://en.wikipedia.org/wiki/Heap_(data_structure)
  These pages gave me an overview on how my binary search tree works 
  and what their benefits are.

  I got the structure for command input, taking file inputs, and executing 
  actions stuff from my Hash Student List. I used this as the base and 
  modified these parts to get number inputs from a file, recieving the 
  commands for adding and removing nodes to my tree or printing my tree, and 
  for organizing my main function in relation the specific functions it uses. 

  ADD MORE CITATIONS HERE
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

using namespace std;

//Constant global variable declarations
const int emptyNode = -1;

//Function prototypes
void instructions();
int askCommand();
void addNodesManually(int* & tree);
void addNodesByFile(int* & tree);
void addNode(int input, int* & tree);
void removeNode(int* & tree);
void removeAll(int* & tree);
void printTree(int* tree);

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  int commandKey = 0;
  int heap[100] = new int[100];
  for(int i = 0; i < 100; i++) {
    //Set everything in the heap to null
    heap[i] = emptyNode;
  }

  //Tell the user how the program works
  instructions();

  //Put them through the loop of interacting with the heap until
  //they are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something with the heap or quit the program
    if(commandKey == 1) {
      //If they want to add nodes to the tree manually, do so
      cout << "Adding nodes to tree manually." << endl;
      cout << endl;
      addNodesManually(heap);
      
    } else if(commandKey == 2) {
      //If they want to add nodes to the tree through a file, do so
      cout << "Adding nodes to tree via a file." << endl;
      cout << endl;
      addNodesByFile(heap);
      
    } else if(commandKey == 3) {
      //If they want to remove the root node in the tree, do so
      cout << "Removing root node from the tree and printing it out." << endl;
      cout << endl;
      removeNode(heap);
      
    } else if(commandKey == 4) {
      //If they want to remove all the nodes in the tree and have them
      //printed in greatest to highest order, do so
      cout << "Removing all nodes from tree and printing them in order." << endl;
      cout << endl;
      removeAll(heap);
      
    } else if(commandKey == 5) {
      //If they want to print the current tree out and see how it's structured,
      //do so
      cout << "Printing out the current tree as it is." << endl;
      cout << endl;

      
    } else if(commandKey == 6) {
      //If they want to quit the program, do so
      cout << "Ok then, I hope this was helpful!" << endl;
      cout << endl;

      //change the boolean that determines if the program continues
      inUse = false;
    }
  }

  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program helps you make a heap of 100 numbers " << endl;
  cout << "between 1-1000 (inclusive). You can use various commands to interact" << endl;
  cout << "with the heap binary search tree. You can interact with the binary" << endl;
  cout << "search tree by... WRITE WHAT YOU CAN DO WITH THE PROGRAM HERE!!!" << endl;
  cout << endl;
}
