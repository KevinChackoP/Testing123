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
void addNodesManually(int* tree, int & lastI);
void addNodesByFile(int* tree, int & lastI);
void addNode(int input, int* tree, int & lastI);
void removeNode(int* tree, int & lastI);
void removeAll(int* tree, int & lastI);
void printTree(int* tree, int & lastI, int nodeI, int steps);

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  int commandKey = 0;
  int heap[100];
  for(int i = 0; i < 100; i++) {
    //Set everything in the heap to the empty node number
    heap[i] = emptyNode;
  }
  int lastIndex = 1;

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
      
      if(lastIndex <= 100) {
	//if the tree isn't full, continue
	addNodesManually(heap, lastIndex);
	
      } else {
	//if the tree is full let the user know
	cout << "Sorry, the tree is currently full." << endl;
	cout << "Please remove nodes before trying to add more." << endl;
	cout << endl;
      }
      
    } else if(commandKey == 2) {
      //If they want to add nodes to the tree through a file, do so
      cout << "Adding nodes to tree via a file." << endl;
      cout << endl;
      
      if(lastIndex <= 100) {
	//if the tree isn't full, continue
	addNodesByFile(heap, lastIndex);
	
      } else {
	//if the tree is full let the user know
	cout << "Sorry, the tree is currently full." << endl;
	cout << "Please remove nodes before trying to add more." << endl;
	cout << endl;
      }
      
    } else if(commandKey == 3) {
      //If they want to remove the root node in the tree, do so
      cout << "Removing root node from the tree and printing it out." << endl;
      cout << endl;
      
      if(lastIndex > 1) {
	//if the tree isn't empty, continue
	removeNode(heap, lastIndex);
	
      } else {
	//if the tree is empty let the user know
	cout << "Sorry, there currently aren't any nodes in the tree." << endl;
	cout << "Please add nodes first before removing them." << endl;
      }
      cout << endl;
      
    } else if(commandKey == 4) {
      //If they want to remove all the nodes in the tree and have them
      //printed in greatest to highest order, do so
      cout << "Removing all nodes from tree and printing them in order." << endl;
      cout << endl;
      
      if(lastIndex > 1) {
	//if the tree isn't empty, continue
	removeAll(heap, lastIndex);
	
      } else {
	//if the tree is empty let the user know
	cout << "Sorry, there currently aren't any nodes in the tree." << endl;
	cout << "Please add nodes first before removing them." << endl;
	cout << endl;
      }
      
    } else if(commandKey == 5) {
      //If they want to print the current tree out and see how it's structured,
      //do so
      cout << "Printing out the current tree as it is." << endl;
      cout << endl;
      
      if(lastIndex > 1) {
	//if the tree isn't empty, continue
	printTree(heap, lastIndex, 1, 0);
	
      } else {
	//if the tree is empty let the user know
	cout << "Sorry, there currently aren't any nodes in the tree." << endl;
	cout << "Please add nodes first before printing the tree out." << endl;
	cout << endl;
      }
      
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
  cout << "search tree by manually adding numbers to the tree, using a file " << endl;
  cout << "with various numbers between 1-1000 seperated by spaces to add to " << endl;
  cout << "the tree, removing and viewing the root node of the tree, removing " << endl;
  cout << "all the nodes of the tree and seeing them in order of greatest to " << endl;
  cout << "least, and you can print out the tree to visually see its current " << endl;
  cout << "structure. I hope this program is of use to you!" << endl;
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
  cout << "Input ADDM to add numbers to the list manually." << endl;
  cout << "Input ADDF to add numbers to the list via a file." << endl;
  cout << "Input REM to remove the root node and print it out." << endl;
  cout << "Input REMALL to remove all the nodes and print them in " << endl;
  cout << "order from greatest to least." << endl;
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
    } else if(strcmp(input, "REM") == 0) {
      return 3;
    } else if(strcmp(input, "REMALL") == 0) {
      return 4;
    } else if(strcmp(input, "PRINT") == 0) {
      return 5;
    } else if(strcmp(input, "QUIT") == 0) {
      return 6;
    } else { //If their command is invalid, tell them and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADDM, ADDF, REM, REMALL, PRINT, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function will add nodes into the tree via manual input
void addNodesManually(int* tree, int & lastI) {
  //local variables
  int numInput = 0;

  //Tell them what to input
  cout << "Please input an integer number between 1-1000 (inclusive)." << endl;
  cout << "If you wish to add multiple numbers, put your numbers in " << endl;
  cout << "a string with only spaces between each of your numbers." << endl;
  cout << "In both cases, after you're done typing all the numbers " << endl;
  cout << "you want to add, click enter and then type and enter " << endl;
  cout << "\"-1\" to signal that you're finished." << endl;
  cout << endl;

  //read through their input and add their numbers to the tree
  while((cin >> numInput) && numInput != -1 && lastI <= 100) {
    if(numInput < 1) {
      cout << numInput << " is lower than number range of 1-1000 and won't be added to tree." << endl;
      cout << endl;
    } else if(numInput > 1000) {
      cout << numInput << " is higher than number range of 1-1000 and won't be added to tree." << endl;
      cout << endl;
    } else {
      addNode(numInput, tree, lastI);
    }
  }

  //tell the user the tree is full if it's indeed full
  if(lastI > 100) {
    cout << endl;
    cout << "The tree has been completely filled. Numbers " << endl;
    cout << numInput << " and onward will not be added." << endl;
    cout << endl;
  }

  //do some clean up
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
}

//This function will add nodes into the tree via file input
void addNodesByFile(int* tree, int & lastI) {
  //local variables
  int numInput = 0;
  char filename[31];
  for(int i = 0; i < 31; i++) {
    filename[i] = '\0';
  }

  //Tell them what to input
  cout << "Please input the name of your file with integers numbered " << endl;
  cout << "between 1-1000 (inclusive). Please only seperate your " << endl;
  cout << "numbers using spaces or new lines, and include the file " << endl;
  cout << "type tag at the end of your filename (ie .txt). Don't use " << endl;
  cout << "a file with a name and tag longer than 30 characters." << endl;
  cout << endl;

  //take their input and open the file whose name they inputted
  cin.getline(filename, 31);
  ifstream fin(filename);

  //read through their file and add their numbers to the tree
  while((fin >> numInput) && numInput != -1 && lastI <= 100) {
    if(numInput < 1) {
      cout << numInput << " is lower than number range of 1-1000 and won't be added to tree." << endl;
      cout << endl;
    } else if(numInput > 1000) {
      cout << numInput << " is higher than number range of 1-1000 and won't be added to tree." << endl;
      cout << endl;
    } else {
      addNode(numInput, tree, lastI);
    }
  }

  //tell the user the tree is full if it's indeed full
  if(lastI > 100) {
    cout << endl;
    cout << "The tree has been completely filled. Numbers " << endl;
    cout << numInput << " and onward will not be added." << endl;
    cout << endl;
  }
  
  //do some clean up
  fin.close();
  cout << endl;
}

//This function will take the input and actually put it into the tree properly
void addNode(int input, int* tree, int & lastI) {
  //add the new node to the last index
  tree[lastI - 1] = input;

  //keep track of the added node's index and if the current node is smaller
  //than its parent node
  int nodeI = lastI;
  bool smaller = false;

  //If the node is bigger than its parent node, swap it with its parent node
  //and keep doing this until it's at the root or it's smaller than its parent
  while(nodeI != 1 && !(smaller)) {
    if(tree[nodeI - 1] > tree[(nodeI / 2) - 1]) {
      //check to see if the node is bigger than its parent
      int placeholder = tree[(nodeI / 2) - 1];
      tree[(nodeI / 2) - 1] = tree[nodeI - 1];
      tree[nodeI - 1] = placeholder;
      nodeI = nodeI / 2;
      
    } else {
      //if not, get out of the loop
      smaller = true;
    }
  }

  //increment the index of the last index slot
  lastI++;
}


//This function will remove the root node of the tree and print it out
void removeNode(int* tree, int & lastI) {
  //check that the tree isn't currently empty before attempting to
  //remove a node
  if(lastI > 1) {
    //deincrement the index of the last slot (for use in this function the
    //last slot will serve as the last filled slot)
    lastI--;
  
    //print the root of the tree's value out before replacing it with the
    //placeholder value to signal that the root is now empty
    cout << tree[0] << endl;
    tree[0] = emptyNode;

    //swap the root with the last filled slot of the tree, making it empty
    int placeholder = tree[0];
    tree[0] = tree[lastI - 1];
    tree[lastI - 1] = placeholder;

    //Keep track of the swapped last node
    int nodeI = 1;
    bool greater = false;

    //If the node is smaller than at least one of its children nodes swap with 
    //the larger of the two children until the node is bigger than both of
    //its children or it's at a leaf
    while(((nodeI * 2) + 1) <= 100 && !(greater)) {
      //check if both children are bigger than the node
      if(tree[nodeI - 1] < tree[(nodeI * 2) - 1] || tree[nodeI - 1] < tree[((nodeI * 2) + 1) - 1]) {
	//check which child node is bigger and swap with the bigger node
	if(tree[(nodeI * 2) - 1] >= tree[((nodeI * 2) + 1) - 1]) {
	  //If the left child is the bigger child (or if both children are the
	  //same value) swap with the left child
	  placeholder = tree[(nodeI * 2) - 1];
	  tree[(nodeI * 2) - 1] = tree[nodeI - 1];
	  tree[nodeI - 1] = placeholder;
	  nodeI = nodeI * 2;
	
	} else if(tree[(nodeI * 2) - 1] < tree[((nodeI * 2) + 1) - 1]) {
	  //If the right child is the bigger child swap with the right child
	  placeholder = tree[((nodeI * 2) + 1) - 1];
	  tree[((nodeI * 2) + 1) - 1] = tree[nodeI - 1];
	  tree[nodeI - 1] = placeholder;
	  nodeI = nodeI * 2 - 1;
	}
	
      } else {
	//if not, get out of the loop
	greater = true;
      }
    }
  }
}

//This function will remove all the nodes of the tree and print them out
//in order of greatest to least
void removeAll(int* tree, int & lastI) {
  //until lastI is 1 signalling that the last available slot is the
  //first slot, keep removing nodes from the tree and printing them out
  while(lastI > 1) {
    removeNode(tree, lastI);
  }
  
  cout << endl;
}

//This function will print out a visual representation of the tree
void printTree(int* tree, int & lastI, int nodeI, int steps) {
  //print the current node out, tabbing based on how many steps of recursion
  //the function is in
  
}
