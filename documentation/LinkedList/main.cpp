//imports
#include <iostream>
#include "Node.h"

using namespace std;

//function prototypes
void add(int newvalue, Node* & head);
void print(Node* next, Node* head);

//main class
int main() {
  Node* head = NULL;

  add(5, head);
  print(head, head);
  add(7, head);
  print(head, head);
  add(2, head);
  print(head, head);
}

//Add a new node to end of linked list
void add(int newvalue, Node* & head) {
  Node* current = head;
  if(current == NULL) { //If no nodes made, start with this node
    head = new Node(); //Since I'm setting value need to pass head by reference
    head -> setValue(newvalue);
  } else { //otherwise, go to end of list then add new value to new end node
    //This method of getting to the end of the list is ITERATIVE
    while(current -> getNext() != NULL) {
      current = current -> getNext();
    }
    current -> setNext(new Node());
    current -> getNext() -> setValue(newvalue);
  }
}

//Print thru whole list starting with given node
//THIS USES RECURSION!
void print(Node* next, Node* head) {
  if(next == head) {
    cout << "list: ";
  }
  if(next != NULL) { //This is base case, will break recursion if false
    cout << next -> getValue() << " ";
    print(next -> getNext(), head);
  } else {
    cout << endl;
    //Basically do nothing if finished with recursion
    //This is useful in other programs
  }
}

//Both iteration (while loop thru) and recursion (call function on itself)
//work with linked lists
