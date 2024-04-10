/*
  This program serves as the cpp program for the Red-Black Tree Program's
  RedBlackTree class. It has all the functions that will be used to make 
  and interact with the red-black tree.
  Author: Kevin Chacko
  Last Updated: WRITE END DATE HERE
  Period 5, C++ / Data Structures
*/

/*
  For a lot of this file I copy pasted my code from my Binary Search Tree
  project's main.cpp file and just modified the code to fit my red-black tree 
  for the base tree functions. 
*/

//imports
#include "RedBlackTree.h"

//Constructor for redBlackTree class
redBlackTree::redBlackTree() {
  root = NULL;
}

//Destructor for redBlackTree class
redBlackTree::~redBlackTree() {
  deleteTreeStep(root);
  root = NULL
}

//This function will take the input given by the user and put it
//into the tree
void redBlackTree::addNode(int input) {
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

//This function will attempt to remove a node of the inputted number
//from the tree
void redBlackTree::deleteNode(int target) {
  //local variables
  node* index = root;
  node* prevIndex = root;
  bool targetFound = false;

  //Check the head node first to see if it's the target node
  if(root -> getInt() == target) {
    //if it is, make the next largest node the new head
    cout << root -> getInt() << " was found in the tree and " << endl;
    cout << "will be removed from the tree." << endl;
    cout << endl;
      
    //mark the target as found in the tree
    targetFound = true;
      
    //go right once then all the way left in the tree if possible
    if(root -> getRight() != NULL) {
      //if it is possible, do so
      index = index -> getRight();
      prevIndex = prevIndex -> getRight();
      while(index -> getLeft() != NULL) {
	prevIndex = index;
	index = index -> getLeft();
      }

      //fill the hole the index node will make when it's moved to the head
      if(prevIndex == index) {
	root -> setRight(index -> getRight());
      } else {
	prevIndex -> setLeft(index -> getRight());
      }
	
    } else if(root -> getLeft() != NULL) {
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
	root -> setLeft(index -> getLeft());
      } else {
	prevIndex -> setRight(index -> getLeft());
      }
	
    } else {
      //If the head is the only node in the tree, delete only it
      node* temp = root;
      root = NULL;
      delete temp;
    }

    //if the head wasn't the only node in the tree, set it to the index node
    if(root != NULL) {
      //set the new head as the index node
      node* temp = root;
      root = index;
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

      //fill the hole the index node would create in the tree
      if(index == prevIndex -> getLeft()) {
	//if the index node is the left child of the previous index, replace
	//the previous index's left child with one of the index's children
	if(index -> getRight() != NULL) {
	  //if the right child isn't null, replace with the right child
	  //or the right child's leftmost child
	  node* replacement = index -> getRight();
	  node* prevReplacement = index -> getRight();
	  while(replacement -> getLeft() != NULL) {
	    prevReplacement = replacement;
	    replacement = replacement -> getLeft();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == prevReplacement) {
	    //if the best replacement is just the right child of the
	    //index, have the previous index just point directly to it
	    //and set its left child to the index's left child
	    index -> getRight() -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setLeft(index -> getRight());
	    } else {
	      //otherwise just replace from the previous index
	      prevIndex -> setLeft(index -> getRight());
	    }
	  } else {
	    //set the replacement's parent's new left child as the
	    //replacement's right child
	    prevReplacement -> setLeft(replacement -> getRight());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setLeft(replacement);
	    } else {
	      //otherwise just replace from the previous index node
	      prevIndex -> setLeft(replacement);
	    }
	  }
	      
	} else if(index -> getLeft() != NULL) {
	  //if the right child is null but left child isn't null, replace
	  //with the left child or the left child's rightmost child
	  node* replacement = index -> getLeft();
	  node* prevReplacement = index -> getLeft();
	  while(replacement -> getRight() != NULL) {
	    prevReplacement = replacement;
	    replacement = replacement -> getRight();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == prevReplacement) {
	    //if the best replacement is just the left child of the
	    //index, have the previous node just point directly to it
	    //and set its right child to the index's right child
	    index -> getLeft() -> setRight(index -> getRight());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setLeft(index -> getLeft());
	    } else {
	      //otherwise, just replace from the previous index
	      prevIndex -> setLeft(index -> getLeft());
	    }
	  } else {
	    //set the replacement's parent's new right child as the
	    //replacement's left child
	    prevReplacement -> setRight(replacement -> getLeft());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setLeft(replacement);
	    } else {
	      //otherwise just replace from the previous index node
	      prevIndex -> setLeft(replacement);
	    }
	  }

	} else {
	  //if both children are null, just replace with the left child
	  if(prevIndex == root) {
	    //if the previous index is the root, replace from the
	    //root instead
	    root -> setLeft(index -> getLeft());
	  } else {
	    //otherwise just replace from the previous index
	    prevIndex -> setLeft(index -> getLeft());
	  } 
	}
	  
      } else if(index == prevIndex -> getRight()) {
	//if the index node is the right child of the previous index, replace
	//the previous index's right child with one of the index's children
	if(index -> getRight() != NULL) {
	  //if the right child isn't null, replace with the right child
	  //or the right child's leftmost child
	  node* replacement = index -> getRight();
	  node* prevReplacement = index -> getRight();
	  while(replacement -> getLeft() != NULL) {
	    prevReplacement = replacement;
	    replacement = replacement -> getLeft();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == prevReplacement) {
	    //if the best replacement is just the right child of the
	    //index, have the previous index just point directly to it
	    //and set its left child to the index's left child
	    index -> getRight() -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setRight(index -> getRight());
	    } else {
	      //otherwise just replace from the previous index
	      prevIndex -> setRight(index -> getRight());
	    }
	  } else {
	    //set the replacement's parent's new left child as the
	    //replacement's right child
	    prevReplacement -> setLeft(replacement -> getRight());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setRight(replacement);
	    } else {
	      //otherwise just replace from the previous index node
	      prevIndex -> setRight(replacement);
	    }
	  }
	      
	} else if(index -> getLeft() != NULL) {
	  //if the right child is null but left child isn't null, replace
	  //with the left child or the left child's rightmost child
	  node* replacement = index -> getLeft();
	  node* prevReplacement = index -> getLeft();
	  while(replacement -> getRight() != NULL) {
	    prevReplacement = replacement;
	    replacement = replacement -> getRight();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == prevReplacement) {
	    //if the best replacement is just the left child of the
	    //index, have the previous node just point directly to it
	    //and set its right child to the index's right child
	    index -> getLeft() -> setRight(index -> getRight());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setRight(index -> getLeft());
	    } else {
	      //otherwise, just replace from the previous index
	      prevIndex -> setRight(index -> getLeft());
	    }
	  } else {
	    //set the replacement's parent's new right child as the
	    //replacement's left child
	    prevReplacement -> setRight(replacement -> getLeft());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    if(prevIndex == root) {
	      //if the previous index is the root, replace from the
	      //root instead
	      root -> setRight(replacement);
	    } else {
	      //otherwise just replace from the previous index node
	      prevIndex -> setRight(replacement);
	    }
	  }

	} else {
	  //if both children are null, just replace with the left child
	  if(prevIndex == root) {
	    //if the previous index is the root, replace from the
	    //root instead
	    root -> setRight(index -> getLeft());
	  } else {
	    //otherwise just replace from the previous index
	    prevIndex -> setRight(index -> getLeft());
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

//This function will attempt to find a node of the inputted number
//from the tree
void redBlackTree::searchNode(int target) {
  //local variables
  node* index = root;
  bool targetFound = false;

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

//This function will print out a visual representation of the tree
void redBlackTree::printTree() {
  if(root != NULL) {
    //there is stuff in the tree, so continue printing
    printTree(root, 0);
    cout << endl;
    
  } else {
    //the root is null and nothing will print, so tell the user that
    cout << "The tree is currently empty! Please try printing " << endl;
    cout << "out the tree after you've added nodes to it!" << endl;
    cout << endl;
  }
}

//This function recursivally goes through a step of printing out the current
//node passed in and its children
void redBlackTree::printTreeStep(node* index, int steps) {
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

//This function recursivally deletes all the nodes in the tree
void redBlackTree::deleteTreeStep(node* tree) {
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

bool redBlackTree::isTreeEmpty() {
  if(root == NULL) {
    return true;
  } else {
    return false;
  }
}
