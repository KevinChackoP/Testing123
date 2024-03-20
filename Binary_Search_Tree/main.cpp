/* 
   This project... WRITE ABOUT WHAT THIS PROJECT DOES!!!
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got some of help with learning what's needed for a Binary Search 
  Tree and how each of its functions work from the "Binary Search Tree" 
  module. This gave me some resources to refer to for help. Among these 
  useful resources was a video showing a visual example of the Binary 
  Search Tree by Mr. Galbraith, showing the things that need to be 
  considered when making the binary search tree (its add, search, and 
  delete functions).

  WRITE MORE CITATIONS HERE
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
#include "node.h"

using namespace std;

//Function prototypes
void instructions();
int askCommand();
void addNodesManually(node* & tree);
void addNodesByFile(node* & tree);
void addNode(node* & tree, int input);
int nodeInput();
void deleteNode(node* & tree);
void searchNode(node* tree);
void printTree(node* tree, int steps);
void deleteTree(node* tree);

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  int commandKey = 0;
  node* root = NULL;
  
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

      addNodesManually(root);
      
    } else if(commandKey == 2) {
      //If they want to add nodes to the tree through a file, do so
      cout << "Adding nodes to the tree via a file." << endl;
      cout << endl;
      
      addNodesByFile(root);

    } else if(commandKey == 3) {
      //If they want to delete a node from the tree, do so
      cout << "Deleting a node from the tree." << endl;
      cout << endl;

      deleteNode(root);

    } else if(commandKey == 4) {
      //If they want to search for whether a node is in the tree or not, do so
      cout << "Searching for a node in the tree." << endl;
      cout << endl;

      searchNode(root);

    } else if(commandKey == 5) {
      //If they want to print the current tree out and see how it's structured,
      //do so
      cout << "Printing out the current tree as it is." << endl;
      cout << endl;

      printTree(root, 0);
      
    } else if(commandKey == 6) {
      //If they want to quit the program, do so
      cout << "Ok then, I hope this was helpful!" << endl;
      cout << endl;

      //delete the tree which is on the heap
      deleteTree(root);

      //change the boolean that determines if the program continues running
      inUse = false;
    }
  }

  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program helps you make a binary search tree that " << endl;
  cout << "holds numbers between 1-999 (inclusive). You can use various " << endl;
  cout << "commands to interact with the binary search tree. You can interact " << endl;
  cout << "with the binary search tree by manually adding numbers to the tree," << endl;
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
void addNodesManually(node* & tree) {
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
      addNode(tree, numInput);
    }
  }

  //do some clean up
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
}

//This function will add nodes into the tree via file input
void addNodesByFile(node* & tree) {
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
      addNode(tree, numInput);
    }
  }

  //do some clean up
  fin.close();
  cout << endl;
}

//This function will take the input and actually put it into the tree properly
void addNode(node* & tree, int input) {
  //make the node for the new number being inputted
  node* newNode = new node(input);

  //Add the new node to the tree
  if(tree == NULL) {
    //If the tree root node is null, set the new node to be the root node
    tree = newNode;
    
  } else {
    //go down tree until the new node is added to correct place in tree
    node* indexNode = tree;
    bool added = false;
    int steps = 0;

    while(!added) {
      steps++;
      if(newNode -> getInt() < indexNode -> getInt()) {
	//if the new node is smaller than the index node...
	if(indexNode -> getLeft() == NULL) {
	  //and the left node is NULL, set the new node to the left child node
	  if(steps < 2) {
	    //make changes to root node instead of index node because it will
	    //be the new child of the root
	    tree -> setLeft(newNode);
	    added = true;

	  } else {
	    //make it the left child of the index node
	    indexNode -> setLeft(newNode);
	    added = true;
	  }
	} else {
	  //otherwise, set the index node to its left child node
	  indexNode = indexNode -> getLeft();
	}
	
      } else {
	//if the new node is greater than or equal to the index node...
	if(indexNode -> getRight() == NULL) {
	  //and the right node is NULL, set the new node to the right
	  //child node
	  if(steps < 2) {
	    //make changes to root node instead of index node because it will
	    //be the new child of the root
	    tree -> setRight(newNode);
	    added = true;

	  } else {
	    //make it the right child of the index node
	    indexNode -> setRight(newNode);
	    added = true;
	  }
	} else {
	  //otherwise, set the index node to its right child node
	  indexNode = indexNode -> getRight();
	}
      }
    }
  }
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

//This function will take a number input from the user and attempt to remove
//a node of that number from the tree
void deleteNode(node* & tree) {
  //local variables
  node* index = tree;
  node* prevIndex = tree;
  int target;
  bool targetFound = false;

  //Make sure the tree isn't empty before trying to delete from the tree
  if(tree == NULL) {
    //The tree is empty, so tell the user
    cout << "Sorry but the tree is empty! Please add nodes to the " << endl;
    cout << "tree before trying to search for nodes in the tree!" << endl;
    cout << endl;
    
  } else {
    //Ask the user for a number input
    cout << "What is the node value for the node you would like to " << endl;
    cout << "delete from the tree?" << endl;
    target = nodeInput();

    //Check the head node first to see if it's the target node
    if(tree -> getInt() == target) {
      //if it is, make the next largest node the new head
      targetFound = true;
    
      //go right once then all the way left in the tree if possible
      if(tree -> getRight() != NULL) {
	//if it is possible, do so
	index = index -> getRight();
	prevIndex = prevIndex -> getRight();
	while(index -> getLeft() != NULL) {
	  prevIndex = index;
	  index = index -> getLeft();
	}

	//fill the hole the index node will make when it's moved to the head
	if(prevIndex == index) {
	  tree -> setRight(index -> getRight());
	} else {
	  prevIndex -> setLeft(index -> getRight());
	}
	
      } else if(tree -> getLeft() != NULL) {
	//if it isn't, try going left first then all the way right to get
	//the next smallest node
	index = index -> getLeft();
	prevIndex = prevIndex -> getLeft();
	while(index -> getRight() != NULL) {
	  prevIndex = index;
	  index = index -> getRight();
	}

	//fill the hole the index node will make when it's moved to the head
	if(prevIndex == index) {
	  tree -> setLeft(index -> getLeft());
	} else {
	  prevIndex -> setRight(index -> getLeft());
	}
	
      } else {
	//If the head is the only node in the tree, delete only it
	node* temp = tree;
	tree = NULL;
	delete temp;
      }

      //if the head wasn't the only node in the tree, set it to the index node
      if(tree != NULL) {
	//set the new head as the index node
	node* temp = tree;
	tree = index;
	index -> setLeft(temp -> getLeft());
	index -> setRight(temp -> getRight());
    
	//delete the old head
	delete temp;
      }
    
    } else {
      //otherwise set the index to the next node on the path to the target,
      //offsetting it from the previous index node
      if(target < index -> getInt()) {
	//if the target is less than the head node, make the index the left
	//child of the head
	index = index -> getLeft();
      
      } else {
	//if the target is greater than the head node, make the index the right
	//child of the head
	index = index -> getRight();
      }
    }

    //iterate through the tree until the target value is found in a node or
    //until the end of the tree branch is reached
    while(index != NULL && !(targetFound)) {
      //check to see if the index node holds the target value
      if(index -> getInt() == target) {
	//if the index holds the target value, remove it from the tree
	cout << index -> getInt() << " was found in the tree and " << endl;
	cout << "will be removed from the tree." << endl;
	cout << endl;

	//mark the target as found in the tree
	targetFound = true;

	//REMEMBER THAT IN ORDER TO KEEP YOUR TREE ORDERED YOU NEED TO
	//GO RIGHT THEN ALL THE WAY LEFT OR LEFT THEN ALL THE WAY RIGHT
	//TO GET THE NEXT SMALLEST OR BIGGEST NODE TO REPLACE THE NODE
	//BEING DELETED, USE THE CODE YOU MADE FOR HEAD FOR THIS!!!

	//fill the hole the index node would create in the tree
	if(index == prevIndex -> getLeft()) {
	  //if the index node is the left child of the previous index, replace
	  //the previous index's left child with one of the index's children
	  if(prevIndex == tree) {
	    //if the previous index is the root, replace from the root instead
	    if(index -> getRight() != NULL) {
	      //if the right child isn't null, replace with the right child
	      tree -> setLeft(index -> getRight());
	    } else {
	      //if the left child isn't null or at least both children are
	      //null, replace with the left child
	      tree -> setLeft(index -> getLeft());
	    }
	  } else {
	    //if the previous index isn't the tree, replace from it
	    if(index -> getRight() != NULL) {
	      //if the right child isn't null, replace with the right child
	      tree -> setLeft(index -> getRight());
	    } else {
	      //if the left child isn't null or at least both children are
	      //null, replace with the left child
	      tree -> setLeft(index -> getLeft());
	    }
	  }
	}

	//actually delete the index node
	delete index;

      } else {
	//otherwise, go down the tree further
	if(target < index -> getInt()) {
	  //if the target is smaller than the index's node's data, make the
	  //next index node the current index node's left child
	  prevIndex = index;
	  index = index -> getLeft();
	
	} else if(target > index -> getInt()) {
	  //if the target is bigger than the index's node's data, make the next
	  //index node the current index node's right child
	  prevIndex = index;
	  index = index -> getRight();	
	}
      }
    }

    //check to see if the target value was found and deleted in the tree
    if(!(targetFound)) {
      //if it wasn't, let the user know
      cout << target << " was NOT found in the tree and thus it " << endl;
      cout << "couldn't be deleted from the tree." << endl;
      cout << endl;
    }
  }
}

//This function will take a number input from the user and attempt to find
//a node of that number from the tree
void searchNode(node* tree) {
  //local variables
  node* index = tree;
  int target;
  bool targetFound = false;

  //check to make sure the tree isn't empty before searching
  if(tree == NULL) {
    //The tree is empty, so tell the user
    cout << "Sorry but the tree is empty! Please add nodes to the " << endl;
    cout << "tree before trying to search for nodes in the tree!" << endl;
    cout << endl;
    
  } else {
    //Ask the user for a number input
    cout << "What is the node value for the node you would like to " << endl;
    cout << "search for in the tree?" << endl;
    target = nodeInput();

    //iterate through the tree until the target value is found in a node or
    //until the end of the tree branch is reached
    while(index != NULL && !(targetFound)) {
      //check to see if the index node holds the target value
      if(index -> getInt() == target) {
	//if the index holds the target value, tell the user that the node they
	//are looking for was found in the tree
	cout << index -> getInt() << " was found in the tree!" << endl;
	cout << endl;

	//mark the target as found in the tree
	targetFound = true;

      } else {
	//otherwise, go down the tree further
	if(target < index -> getInt()) {
	  //if the target is smaller than the index's node's data, make the
	  //next index node the current index node's left child
	  index = index -> getLeft();
	
	} else if(target > index -> getInt()) {
	  //if the target is bigger than the index's node's data, make the next
	  //index node the current index node's right child
	  index = index -> getRight();	
	}
      }
    }

    //check to see if the target value was found in the tree
    if(!(targetFound)) {
      //if it wasn't, let the user know
      cout << target << " was NOT found in the tree." << endl;
      cout << endl;
    }
  }
}

//This function will print out a visual representation of the tree
void printTree(node* tree, int steps) {
  //check to make sure node passed in isn't null
  if(tree != NULL) {
    //Do a new recursion step for the right child
    printTree(tree -> getRight(), (steps + 1));

    //print the current node out, tabbing based on how many steps of recursion
    //the function is in
    for(int i = 0; i < steps; i++) {
      cout << "\t";
    }
    cout << tree -> getInt() << endl;

    //Do a new recursion step for the left child
    printTree(tree -> getLeft(), (steps + 1));
  }
}

//This function will recursively delete all the nodes in the tree
void deleteTree(node* tree) {
  if(tree != NULL) {
    //delete the children nodes
    if(tree -> getLeft() != NULL) {
      //if the left node exists, delete it
      deleteTree(tree -> getLeft());
    }
    if(tree -> getRight() != NULL) {
      //if the right node exists, delete it
      deleteTree(tree -> getRight());
    }

    //delete the current node
    delete tree;
  }
}
