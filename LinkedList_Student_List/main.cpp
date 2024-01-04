/* 
   This project... WRITE ABOUT WHAT THIS PROJECT DOES
   Author: Kevin Chacko
   Last Updated: 1/4/2024
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Linked List Part 1" module.
  
  I got help with transferring cstrings into integers from
  Cplusplus's article on "atoi".
  URL: https://cplusplus.com/reference/cstdlib/atoi/
  This part of the cstdlib library will convert a cstring into an integer 
  whether negative or positive while ignoring leading spaces. This is crucial
  for finding the integer values of my cstring ids for the brief purpose of 
  sorting them from greatest to least in the linked list.
  
  ADD ANY OTHER NEEDED CITATIONS HERE!!!
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <cstdlib>

//class inclusions
#include "Node.h"
#include "Student.h"

using namespace std;

//Function prototypes
void instructions();
int askCommand();
void addStudent(Node* & head);
void addStudentNode(Student* newStudent, Node* current, Node* & head);
void printList(Node* current, Node* head);
void deleteStudent(Node* & head);
bool deleteStudentNode(char* deleteID, Node* previous, Node* current, Node* & head);
void averageList(Node* current, Node* head, float total);

//Start of main function
int main() {
  //local variable declarations
  Node* head = NULL;
  bool inUse = true;
  int commandKey = 0;
  
  //Tell them how the program works
  instructions();

  //Put them through the loop of interacting with the list until they are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something to the list or quit from the program
    if(commandKey == 1) {
      //If they want to add a student to the list
      cout << "Adding a student to list." << endl;
      cout << endl;
      addStudent(head);
      
    } else if(commandKey == 2) {
      //If they want to delete a student from the list, do so
      cout << "Deleting a student from list." << endl;
      cout << endl;
      deleteStudent(head);
      
    } else if(commandKey == 3) {
      //If they want to print out the list, do so
      cout << "Printing current student list out." << endl;
      cout << endl;
      printList(head, head);
      
    } else if(commandKey == 4) {
      //If they want to find the average of all the students' scores, do so
      cout << "Finding average GPA of class" << endl;
      cout << endl;
      averageList(head, head, 0.0);
      
    } else if(commandKey == 5) {
      //If they want to quit the program, do so
      cout << "Ok then, have a good day!" << endl;

      //delete everything on the heap from my student linked list
      while(head != NULL) {
	Node* placeholderHead = head;
	head = head -> getNext();
	delete placeholderHead;
      }

      //change the boolean that determines if the program continues
      inUse = false;
    }
  }
  
  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program that can keep track of students in a class" << endl;
  cout << "using a list! You can use various commands to interact with the list." << endl;
  cout << "That is to say, you can add students to the list, print out the list, " << endl;
  cout << "delete students from the list, or find the average gpa of the class. " << endl;
  cout << "You can also quit out of the program whenever you'd like to." << endl;
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
  cout << "Input ADD for adding a new student to the list." << endl;
  cout << "Input DELETE to delete a student from the list." << endl;
  cout << "Input PRINT to print out the current list of students." << endl;
  cout << "Input AVERAGE to find the average gpa of the list of students." << endl;
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
    if(strcmp(input, "ADD") == 0) {
      return 1;
    } else if(strcmp(input, "DELETE") == 0) {
      return 2;
    } else if(strcmp(input, "PRINT") == 0) {
      return 3;
    } else if(strcmp(input, "AVERAGE") == 0) {
      return 4;
    } else if(strcmp(input, "QUIT") == 0) {
      return 5;
    } else {
      //If their command is invalid, tell the and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADD, DELETE, PRINT, AVERAGE, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function helps the user to add a student to the list
void addStudent(Node* & head) {
  //These are a local variables being used
  char firstNameInput[16];
  char lastNameInput[16];
  for(int i = 0; i < 16; i++) {
    firstNameInput[i] = '\0';
    lastNameInput[i] = '\0';
  }
  char idInput[7];
  for(int i = 0; i < 7; i++) {
    idInput[i] = '\0';
  }
  char gpaInput1[5];
  for(int i = 0; i < 5; i++) {
    gpaInput1[i] = '\0';
  }
  float gpaInput2 = 10.00;

  //Take first name
  cout << "What's the student's first name?" << endl;
  cin.getline(firstNameInput, 16);
  cout << endl;

  //Take last name
  cout << "What's the student's last name?" << endl;
  cin.getline(lastNameInput, 16);
  cout << endl;

  //Get id and make sure that it is a 6 digit integer
  cout << "What's the student's id number (6 number integer)?" << endl;
  while(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
    cin.getline(idInput, 7);
    cout << endl;
    
    //If the whole id isn't just numbers, let the user know they made a mistake
    if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
      cout << "You didn't enter a 6 digit integer." << endl;
      cout << "Could you try inputting the id again?" << endl;
      cout << "(i.e. 464877, 342907)" << endl;
      cout << endl;
    }
  }

  //get student GPA and make sure that it is a two decimal number
  cout << "Please input the student's GPA to 2 decimal places (i.e. 3.00)." << endl;
  while((isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) || (gpaInput2 > 5.00 || gpaInput2 < 0.00)) {
    cin.getline(gpaInput1, 5);

    //If the user didn't enter a string with one leading number, a decimal
    //point, and two trailing numbers, tell them they need to do it again
    if(isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) {
      cout << "Your given gpa isn't in the correct format of one leading " << endl;
      cout << "number, one decimal point, and two trailing numbers." << endl;
      cout << "(ie: 3.24, 4.22, 2.76, 3.00)" << endl;
      cout << "Could you please try inputting the gpa again?" << endl;
      
    } else { //If the gpa is in the right format, make sure it's in the range
      //transfer their string input into a float
      gpaInput2 = stof(gpaInput1);
      cout << endl;
      
      //If the gpa isn't a within 0.00 and 5.00 let the user know the gpa isn't
      //a valid gpa
      if(gpaInput2 > 5.00 || gpaInput2 < 0.00) {
	cout << "Sorry, the two decimal place gpa is either over 5.00" << endl;
	cout << "(5.00 is max weighted gpa) or is under 0.00 (gpa must " << endl;
	cout << "be positive or zero). Could you enter the student's " << endl;
	cout << "gpa again? (i.e. 2.34, 4.14, 3.59...)" << endl;
	cout << endl;
      }
    }
  }
  
  //When finished checking all the inputs and validating them all, make the
  //finalized student pointer
  Student* addedStudent = new Student(firstNameInput, lastNameInput, idInput, gpaInput2);

  //Add the finalized student pointer to where it should be in the list
  addStudentNode(addedStudent, head, head);
}

//This function will sort and add the passed in student pointer into the
//properly sorted location in the linked list
void addStudentNode(Student* newStudent, Node* current, Node* & head) {
  /*
    I got help with transferring cstrings into integers from
    Cplusplus's article on "atoi".
    URL: https://cplusplus.com/reference/cstdlib/atoi/
    This part of the cstdlib library will convert a cstring into an integer 
    whether negative or positive while ignoring leading spaces. This is crucial
    for finding the integer values of my cstring ids for the brief purpose of 
    sorting them from greatest to least in the linked list.
  */

  //go through recursion step
  if(head == NULL) {
    //If the current linked list is empty, make the student the head node
    head = new Node(newStudent);
    
  } else if(current == head && atoi(newStudent -> getID()) < atoi(current -> getStudent() -> getID())) {
    //If the current node being looked at is the head node and the new student
    //being added has an ID that's smaller than the head node, make a new head
    //node using the new student and link it to the old head
    head = new Node(newStudent);
    head -> setNext(current);
    
  } else if(current -> getNext() != NULL) {
    //If the next node isn't null, make comparisons to the next node's student
    //and the student being added to the list
    if(atoi(newStudent -> getID()) < atoi(current -> getNext() -> getStudent() -> getID())) {
      //If the new student's ID is less than the next node, add it into the
      //linked list between the current node and the next node
      Node* placeholderNode = new Node(newStudent);
      placeholderNode -> setNext(current -> getNext());
      current -> setNext(placeholderNode);

    } else {
      //Move onto the next step of recursion by looking at the next node
      addStudentNode(newStudent, current -> getNext(), head);
    }
    
  } else {
    //If the next node is null, add the student into a node at the end of the
    //list
    current -> setNext(new Node(newStudent));
  }
}

//This function helps the user to delete a student from the list
void deleteStudent(Node* & head) {
  //If the list is currently empty, don't let them delete any student
  if(head == NULL) {
    cout << "There isn't any students in the list to delete from " << endl;
    cout << "the list. After you've added a few students, then " << endl;
    cout << "consider deleting some of them from the list." << endl;
    cout << endl;
    
  } else { //Otherwise, continue with the rest of the function
    //local variables for function
    char idInput[7];
    for(int i = 0; i < 7; i++) {
      idInput[i] = '\0';
    }
    bool matchingIdFound = false;
  
    //ask user for the id of the student they want to remove from the list
    //and make sure the inputted id is valid and matches a student
    cout << "What's the id of the student you want to remove from the list?" << endl;
    cout << "Please make it a 6 digit integer like before (i.e. 464877)." << endl;
    while((isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) || !matchingIdFound) {
      cin.getline(idInput, 7);
      cout << endl;
      //In case they typed exit to quit out, set everything to upper case
      for(int i = 0; i < strlen(idInput); i++) {
	idInput[i] = toupper(idInput[i]);
      }

      //Check if the user input the exit command to quit out of function
      if(strcmp(idInput, "EXIT") == 0) {
	return;
      }
      
      //If the whole id isn't just numbers, let the user know they made
      //a mistake
      if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
	cout << "You didn't enter a 6 digit integer." << endl;
	cout << "Could you try inputting the student's id again?" << endl;
	cout << "(i.e. 464877, 342907)" << endl;
	cout << endl;
      } else { //valid id input
	//Is there a matching student id in the list? If so, delete it!
	matchingIdFound = deleteStudentNode(idInput, head, head, head);

	//If after going through the whole list and no match could be found
	//let the user know that their id doesn't work before letting them
	//try again
	if(!matchingIdFound) {
	  cout << "Sorry, I couldn't find a student with that id in the list." << endl;
	  cout << "This is what your current list is like:" << endl;
	  //Show the user their current list so they can see the right id
	  //of who they want to delete off the list
	  cout << endl;
	  printList(head, head);
	  cout << "Could you reinput the id of the student you want " << endl;
	  cout << "to remove from the list?" << endl;
	  //If they want to quit out of the function, let them know that they
	  //can input exit instead
	  cout << "If you no longer want to delete a student from the" << endl;
	  cout << "list, type EXIT instead." << endl;
	  cout << endl;
	}
      }
    }
  }
}

//This function will look for a student in the list with a matching id to the
//id entered for deletion and will delete the student from the list
bool deleteStudentNode(char* deleteID, Node* previous, Node* current, Node* & head) {
  //See if there is a match with the current node and do stuff
  if(strcmp((current -> getStudent() -> getID()), deleteID) == 0) {
    //There's a match!!!
    cout << "Removing student " << current -> getStudent() -> getFirstName() << " " << current -> getStudent() -> getLastName() << " from list." << endl;
    cout << endl;

    //Check for different deletion cases
    if(current == head) {
      //If the current node is the head and it needs to be deleted, make the
      //head the next node and delete the old head
      Node* placeholderHead = head;
      head = head -> getNext();
      delete placeholderHead;
      
    } else {
      //If the node to be deleted is between two nodes or a node before and the
      //end of the list, carefully parse in out and make a link from the
      //previous node and the next node
      previous -> setNext(current -> getNext()); //make link
      delete current; //delete target node
    }

    //return true to show that a match was found and deleted
    return true;
    
  } else if(current -> getNext() == NULL) {
    //There wasn't a match and this is the last node in the list return false
    //to show that now matches were found
    return false;
    
  } else {
    //It's not the end of the list, and there wasn't a match with the current
    //node, so go through the next step in recursion (and have its result be
    //what this function returns)
    return deleteStudentNode(deleteID, current, current -> getNext(), head);
  }
}

//This function helps the user to view their current student list by printing
//it out
void printList(Node* current, Node* head) {
  if(head == NULL) {
    //If there is nobody in the list, tell the user
    cout << "Sorry, there is currently nobody in the list!" << endl;
    cout << endl;
    
  } else {
    if(current == head) {
      //give a header to the list if it's the first node
      cout << "firstname lastname, id, gpa" << endl;
      cout << "---------------------------------------------------" << endl;
    }

    //if the node exists, print it
    if(current != NULL) {
      //Set precision for floats so that they always show two digits after the
      //decimal point
      cout.setf(ios::fixed, ios::floatfield);
      cout.setf(ios::showpoint);
      cout.precision(2);

      //print out the student's information
      cout << current -> getStudent() -> getFirstName() << " ";
      cout << current -> getStudent() -> getLastName() << ", ";
      cout << current -> getStudent() -> getID() << ", ";
      cout << current -> getStudent() -> getGPA() << endl;

      //Next step in recursion
      printList(current -> getNext(), head);
      
    } else {
      //If the node doesn't exist, add an empty line for spacing
      cout << endl;
    }
  }
}

//This function finds and prints the average gpa of the class
void averageList(Node* current, Node* head, float total) {
  //Make sure the list isn't empty
  if(head == NULL) {
    //The list is empty so there's no GPAs to average, so let the user know!
    cout << "There aren't any students in the list. Please add " << endl;
    cout << "students to the list first before finding their " << endl;
    cout << "average gpa." << endl;
    cout << endl;
    
  } else { //There are students in the list

  }
}
