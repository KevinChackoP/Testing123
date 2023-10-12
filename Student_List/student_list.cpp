/* 
   This project...
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Functions, Structs, By Reference, By Value, Pointers" module

  To check if a character in a string is a valid digit I got help from
  cplusplus.com's article on "isdigit".
  url: https://cplusplus.com/reference/cctype/isdigit/
  This checks if each character the user inputted for the id number is 
  actually a number.

  In order to round the gpa to two decimal places I needed help from 
  Java2Blog's "Round to 2 decimal places in C++" article
  URL: https://java2blog.com/round-to-2-decimal-places-cpp/
  This told me that because round always goes rounds to a whole number the 
  best way to get around this is to multiply by 100, round, divide by 100.

  WRITE ANY MORE RESOURCES YOU USED HERE
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <vector>

using namespace std;

//struct declarations
struct Student {
  char firstName[15];
  char lastName[15];
  char id[6];
  float gpa;
};

//Function prototypes
void instructions();
int askCommand();
void addStudent(vector<Student*> & list);

//Start of main function
int main() {
  //local variable declarations
  vector<Student*> studentList;
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
      addStudent(studentList);
      
    } else if(commandKey == 2) {
      //If they want to delete a student from the list, do so
      cout << "Deleting a student from list." << endl;
      cout << endl;
      //
      
    } else if(commandKey == 3) {
      //If they want to print out the list, do so
      cout << "Printing current student list out." << endl;
      cout << endl;
      //
      
    } else if(commandKey == 4) {
      //If they want to quit the program, do so
      cout << "Ok then, have a good day!" << endl;
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
  cout << "delete students from the list, or exit out of the program." << endl;
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
  cout << "Input QUIT to exit the program." << endl;
  cout << endl;

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
    if(strcmp(input, "ADD") == 0) {
      return 1;
    } else if(strcmp(input, "DELETE") == 0) {
      return 2;
    } else if(strcmp(input, "PRINT") == 0) {
      return 3;
    } else if(strcmp(input, "QUIT") == 0) {
      return 4;
    } else { //If their command is invalid, tell the and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADD, DELETE, PRINT, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function helps the user to add a student to the list
void addStudent(vector<Student*> & list) {
  //These are a local variables being used
  Student* addedStudent = new Student();
  char firstNameInput[15];
  char lastNameInput[15];
  for(int i = 0; i < 15; i++) {
    firstNameInput[i] = '\0';
    lastNameInput[i] = '\0';
  }
  char idInput[6];
  for(int i = 0; i < 6; i++) {
    idInput[i] = '\0';
  }
  float gpaInput = 10.00;

  //Take first name
  cout << "What's the student's first name?" << endl;
  cin.get(firstNameInput, 15);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  strcpy((*addedStudent).firstName, firstNameInput);
  cout << endl;

  //Take last name
  cout << "What's the student's last name?" << endl;
  cin.get(lastNameInput, 15);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  strcpy((*addedStudent).lastName, lastNameInput);
  cout << endl;

  //Get id and make sure that it is a 6 digit integer
  cout << "What's the student's id number (6 number integer)?" << endl;
  while(isdigit(idInput[0]) != 0 && isdigit(idInput[1]) != 0 && isdigit(idInput[2]) != 0 && isdigit(idInput[3]) != 0 && isdigit(idInput[4]) != 0 && isdigit(idInput[5]) != 0) {
    cin.get(idInput, 6);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /*
      To check if a character in a string is a valid digit I got help from
      cplusplus.com's article on "isdigit".
      url: https://cplusplus.com/reference/cctype/isdigit/
      This checks if each character the user inputted for the id number is 
      actually a number.
     */
    if(isdigit(idInput[0]) != 0 && isdigit(idInput[1]) != 0 && isdigit(idInput[2]) != 0 && isdigit(idInput[3]) != 0 && isdigit(idInput[4]) != 0 && isdigit(idInput[5]) != 0) {
      cout << "You didn't enter a 6 digit integer." << endl;
      cout << "Could you try inputting the id again?" << endl;
      cout << "(i.e. 464877, 342907)" << endl;
      cout << endl;
    }
  }
  strcpy((*addedStudent).id, idInput);
  cout << endl;

  //get student GPA
  cout << "Please input the student's GPA to 2 decimal places (i.e. 3.00)." << endl;
  while(gpaInput > 5.00 || gpaInput < 0.00) {
    cin >> gpaInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  /*
    In order to round the gpa to two decimal places I needed help from 
    Java2Blog's "Round to 2 decimal places in C++" article
    URL: https://java2blog.com/round-to-2-decimal-places-cpp/
    This told me that because round always goes rounds to a whole number the 
    best way to get around this is to multiply by 100, round, divide by 100.
   */
  gpaInput = round(gpaInput * 100.0) / 100.0;
  (*addedStudent).gpa = gpaInput;
  cout << endl;
  
  //When finished checking all the inputs and putting them all in, add the
  //finalized student pointer to the main vector.
  list.push_back(addedStudent);
}
