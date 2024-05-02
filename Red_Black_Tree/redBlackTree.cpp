/*
  This program serves as the cpp program for the Red-Black Tree Program's
  RedBlackTree class. It has all the functions that will be used to make 
  and interact with the red-black tree.
  Author: Kevin Chacko
  Last Updated: 4/30/2024
  Period 5, C++ / Data Structures
*/

/*
  For a lot of this file I copy pasted my code from my Binary Search Tree
  project's main.cpp file and just modified the code to fit my red-black tree 
  for the base tree functions. 
*/

//imports
#include "redBlackTree.h"

//Constructor for redBlackTree class
redBlackTree::redBlackTree() {
  root = NULL;
}

//Destructor for redBlackTree class
redBlackTree::~redBlackTree() {
  deleteTreeStep(root);
  root = NULL;
}

//This function will take the input given by the user and put it
//into the tree
void redBlackTree::addNode(int input) {
  //make the node for the new number being inputted
  node* newNode = new node(input);

  //Add the new node to the tree
  if(root == NULL) {
    //If the tree root node is null, set the new node to be the root node
    root = newNode;
    
  } else {
    //go down tree until the new node is added to correct place in tree
    node* indexNode = root;
    bool added = false;
    int steps = 0;

    while(!added) {
      steps++;
      if(newNode -> getInt() < indexNode -> getInt()) {
	//if the new node is smaller than the index node...
	if(indexNode -> getLeft() == NULL) {
	  //and the left node is NULL, set the new node to the left child node
	  indexNode -> setLeft(newNode);
	  newNode -> setParent(indexNode);
	  added = true;
	} else {
	  //otherwise, set the index node to its left child node
	  indexNode = indexNode -> getLeft();
	}
	
      } else {
	//if the new node is greater than or equal to the index node...
	if(indexNode -> getRight() == NULL) {
	  //and the right node is NULL, set the new node to the right
	  //child node
	  indexNode -> setRight(newNode);
	  newNode -> setParent(indexNode);
	  added = true;
	} else {
	  //otherwise, set the index node to its right child node
	  indexNode = indexNode -> getRight();
	}
      }
    }
  }

  //Go through Red-Black Tree insertion cases
  insertionCases(newNode);
}

//This function goes through the red-black tree cases upon insertion
void redBlackTree::insertionCases(node* index) {
  //CASE 1: if the node was added to the root, set it black
  if(index == root) {
    index -> setBlack();
    return;
  }
  
  //CASE 2: if the parent is black, do nothing
  if(index -> getParent() -> getColor() == 0) {
    return;
  } else {
    //Parent is red, so it must have a parent itself that is black
    node* parent = index -> getParent();
    node* grandparent = index -> getParent() -> getParent();
    node* uncle;
    bool parentLeft = false;
    bool indexLeft = false;
    if(parent == grandparent -> getLeft()) {
      //if the parent is the left child of the grandparent, set the uncle
      //as the right child and mark the parent as the left child
      uncle = grandparent -> getRight();
      parentLeft = true;
    } else if(parent == grandparent -> getRight()) {
      //if the parent is the right child of the grandparent, set the uncle
      //as the left child and mark the parent as not the left child (so it's
      //the right child)
      uncle = grandparent -> getLeft();
      parentLeft = false;
    }
    if(index == parent -> getLeft()) {
      //the current node is the left child of the parent, so mark it as that
      indexLeft = true;
    } else if(index == parent -> getRight()) {
      //the current node is the right child of the parent, so mark it as not
      //the left child (so therefore the right child)
      indexLeft = false;
    }
    
    if(uncle != NULL) {
      //CASE 3: parent and uncle nodes are red
      if(uncle -> getColor() == 1) {
	//change parent and uncle nodes to black
	parent -> setBlack();
	uncle -> setBlack();
    
	//make grandparent node red and recursivally call it through the cases
	grandparent -> setRed();
	insertionCases(grandparent);
	return;
	
      } else if(uncle -> getColor() == 0) {
	//CASE 4: parent is red while uncle is black (exists case)
	//AND parent is left while node is right or parent is right while
	//node is left
	if(parentLeft && !(indexLeft)) {
	  leftRotation(parent);

	} else if(!(parentLeft) && indexLeft) {
	  rightRotation(parent);
	}
	//Run recursion cases on parent (will lead into case 5)
	insertionCases(parent);

	//CASE 5: parent is red while uncle is black (exists case)
	//AND parent is left and node is left or parent is right while
	//node is right
	if(parentLeft && indexLeft) {
	  rightRotation(grandparent);

	  //swap colors of parent and grandparent
	  parent -> setBlack();
	  grandparent -> setRed();

	} else if(!(parentLeft) && !(indexLeft)) {
	  leftRotation(grandparent);

	  //swap colors of parent and grandparent
	  parent -> setBlack();
	  grandparent -> setRed();
	}
      }
      
    } else {
      //CASE 4: parent is red while uncle is black (is NULL case)
      //AND parent is left while node is right or parent is right while
      //node is left
      if(parentLeft && !(indexLeft)) {
	leftRotation(parent);

      } else if(!(parentLeft) && indexLeft) {
	rightRotation(parent);
      }
      //Run recursion cases on parent (will lead into case 5)
      insertionCases(parent);

      //CASE 5: parent is red while uncle is black (is NULL case)
      //AND parent is left and node is left or parent is right while
      //node is right
      if(parentLeft && indexLeft) {
	rightRotation(grandparent);
	
	//swap colors of parent and grandparent
	parent -> setBlack();
	grandparent -> setRed();

      } else if(!(parentLeft) && !(indexLeft)) {
	leftRotation(grandparent);

	//swap colors of parent and grandparent
	parent -> setBlack();
	grandparent -> setRed();
      }
    }
  }
}

//This function will rotate the tree right at the pivot node
void redBlackTree::rightRotation(node* pivot) {
  //make local variables for nodes involved in rotation
  node* parent = pivot -> getParent();
  node* leftChild = pivot -> getLeft();

  //move pivot right
  pivot -> setLeft(leftChild -> getRight());
  if(pivot -> getLeft() != NULL) {
    pivot -> getLeft() -> setParent(pivot);
  }
  pivot -> setParent(leftChild);

  //move left child of pivot up
  leftChild -> setRight(pivot);
  leftChild -> setParent(parent);

  //make pivot's parent's new left/right child the pivot's left child
  if(parent != NULL) {
    if(parent -> getLeft() == pivot) {
      parent -> setLeft(leftChild);
    } else if(parent -> getRight() == pivot) {
      parent -> setRight(leftChild);
    }
  }
  
  //if the pivot was the root, make the left child the new root
  if(pivot == root) {
    root = leftChild;
  }
}

//This function will rotate the tree left at the pivot node
void redBlackTree::leftRotation(node* pivot) {
  //make local variables for nodes involved in rotation
  node* parent = pivot -> getParent();
  node* rightChild = pivot -> getRight();

  //move pivot left
  pivot -> setRight(rightChild -> getLeft());
  if(pivot -> getRight() != NULL) {
    pivot -> getRight() -> setParent(pivot);
  }
  pivot -> setParent(rightChild);

  //move right child of pivot up
  rightChild -> setLeft(pivot);
  rightChild -> setParent(parent);

  //make pivot's parent's new left/right child the pivot's right child
  if(parent != NULL) {
    if(parent -> getLeft() == pivot) {
      parent -> setLeft(rightChild);
    } else if(parent -> getRight() == pivot) {
      parent -> setRight(rightChild);
    }
  }

  //if the pivot was the root, make the right child the new root
  if(pivot == root) {
    root = rightChild;
  }
}

//This function will attempt to remove a node of the inputted number
//from the tree
/*
  CHANGES THAT NEED TO BE MADE:
  We run the normal BST deletion process on the target node, except what 
  we want to do is move the value of the replacement node into the "deleted" 
  node that had the target value we were looking for. In effect though, this 
  makes the replacement node the ACTUAL DELETED NODE which we need to run the 
  red-black tree deletion cases on. So, you should go through the BST process 
  as normal, but keep track of the replacement node. Then when you are done 
  you should pass the replacement node into the deletion cases! Then for 
  The deletion cases you can actually move the nodes themselves around, not 
  just their values. When you get to your node with single child system, M 
  is the replacement node, C is its child, and when you get into the cases 
  where both M and C are black, N is node C which was as a node moved into 
  M since replacement node M was actually deleted.
*/
void redBlackTree::deleteNode(int target) {
  //local variables
  node* index = root;
  bool targetFound = false;

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
      if(index == index -> getParent() -> getLeft()) {
	//if the index node is the left child of its parent, replace
	//the parent's left child with one of the index's children
	if(index -> getRight() != NULL) {
	  //if the right child isn't null, replace with the right child
	  //or the right child's leftmost child
	  node* replacement = index -> getRight();
	  while(replacement -> getLeft() != NULL) {
	    replacement = replacement -> getLeft();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == index -> getRight()) {
	    //if the best replacement is just the right child of the
	    //index, have the index's parent just point directly to it
	    //and set its left child to the index's left child
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setLeft(index -> getRight());
	  } else {
	    //set the replacement's parent's new left child as the
	    //replacement's right child
	    replacement -> getParent() -> setLeft(replacement -> getRight());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setLeft(replacement);
	  }
	      
	} else if(index -> getLeft() != NULL) {
	  //if the right child is null but left child isn't null, replace
	  //with the left child or the left child's rightmost child
	  node* replacement = index -> getLeft();
	  while(replacement -> getRight() != NULL) {
	    replacement = replacement -> getRight();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == index -> getLeft()) {
	    //if the best replacement is just the left child of the
	    //index, have the index's parent just point directly to it
	    //and set its right child to the index's right child
	    replacement -> setRight(index -> getRight());
	    index -> getParent() -> setLeft(index -> getLeft());
	  } else {
	    //set the replacement's parent's new right child as the
	    //replacement's left child
	    replacement -> getParent -> setRight(replacement -> getLeft());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setLeft(replacement);
	  }

	} else {
	  //if both children are null, just replace with the left child
	  index -> getParent() -> setLeft(index -> getLeft());
	}
	  
      } else if(index == index -> getParent() -> getRight()) {
	//if the index node is the right child of its parent, replace
	//its parent's right child with one of the index's children
	if(index -> getRight() != NULL) {
	  //if the right child isn't null, replace with the right child
	  //or the right child's leftmost child
	  node* replacement = index -> getRight();
	  while(replacement -> getLeft() != NULL) {
	    replacement = replacement -> getLeft();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == index -> getRight()) {
	    //if the best replacement is just the right child of the
	    //index, have the index's parent just point directly to it
	    //and set its left child to the index's left child
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setRight(index -> getRight());
	  } else {
	    //set the replacement's parent's new left child as the
	    //replacement's right child
	    replacement -> getParent() -> setLeft(replacement -> getRight());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setRight(replacement);
	  }
	      
	} else if(index -> getLeft() != NULL) {
	  //if the right child is null but left child isn't null, replace
	  //with the left child or the left child's rightmost child
	  node* replacement = index -> getLeft();
	  while(replacement -> getRight() != NULL) {
	    replacement = replacement -> getRight();
	  }
	      
	  //fill the hole the replacement will make when it's moved
	  if(replacement == index -> getLeft()) {
	    //if the best replacement is just the left child of the
	    //index, have the index's parent just point directly to it
	    //and set its right child to the index's right child
	    replacement -> setRight(index -> getRight());
	    index -> getParent() -> setRight(index -> getLeft());
	  } else {
	    //set the replacement's parent's new right child as the
	    //replacement's left child
	    replacement -> getParent() -> setRight(replacement -> getLeft());

	    //actually replace the index node with the replacement node
	    replacement -> setRight(index -> getRight());
	    replacement -> setLeft(index -> getLeft());
	    index -> getParent() -> setRight(replacement);
	  }

	} else {
	  //if both children are null, just replace with the left child
	  index -> getParent() -> setRight(index -> getLeft());
	}
      }

      //actually delete the index node
      delete index;

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

  //If the index has no parent, signalling that it is at the root, make
  //it the new root of the tree
  if(index -> getParent == NULL && targetFound) {
    root = index;
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
  //there is stuff in the tree, so start the recursive print
  printTreeStep(root, 0);
}

//This function recursivally goes through a step of printing out the current
//node passed in and its children
void redBlackTree::printTreeStep(node* index, int steps) {
  //check to make sure node passed in isn't null
  if(index != NULL) {
    //Do a new recursion step for the right child
    printTreeStep(index -> getRight(), (steps + 1));

    //print the current node out, tabbing based on how many steps of recursion
    //the function is in
    for(int i = 0; i < steps; i++) {
      cout << "\t";
    }

    //state the color of the node first
    if(index -> getColor() == 0) {
      cout << "B-";
    } else {
      cout << "R-";
    }

    //print the value of the current node
    cout << index -> getInt() << endl;

    //Do a new recursion step for the left child
    printTreeStep(index -> getLeft(), (steps + 1));
  }
}

//This function recursivally deletes all the nodes in the tree
void redBlackTree::deleteTreeStep(node* index) {
  if(index != NULL) {
    //delete the children nodes
    deleteTreeStep(index -> getLeft());
    deleteTreeStep(index -> getRight());
    
    //delete the current node
    delete index;
  }
}

//This function checks if the tree is empty and returns true if it is
bool redBlackTree::isTreeEmpty() {
  if(root == NULL) {
    //the root's null, so the tree is too!
    return true;
  } else {
    //the root isn't null, so the tree shouldn't be empty.
    return false;
  }
}
