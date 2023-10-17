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

  I got help with transferring strings into floating points from
  Cplusplus's article on "stof".
  URL: https://cplusplus.com/reference/string/stof/
  This part of the std namespace allows me to change a string value into
  a floating point which is what I need after the first gpa input check.

  I got help with setting the precision of the gpa float while printing
  it out using cout from the canvas module "Introduction to C++: Video
  Tutorials". 

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
  char firstName[16];
  char lastName[16];
  char id[7];
  float gpa;
};

//Function prototypes
void instructions();
int askCommand();
void addStudent(vector<Student*> & list);
void printList(vector<Student*> & list);

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
      printList(studentList);
      
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
  cin.get(firstNameInput, 16);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  strcpy((*addedStudent).firstName, firstNameInput);
  cout << endl;

  //Take last name
  cout << "What's the student's last name?" << endl;
  cin.get(lastNameInput, 16);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  strcpy((*addedStudent).lastName, lastNameInput);
  cout << endl;

  //Get id and make sure that it is a 6 digit integer
  cout << "What's the student's id number (6 number integer)?" << endl;
  while(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
    cin.get(idInput, 7);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    /*
      To check if a character in a string is a valid digit I got help from
      cplusplus.com's article on "isdigit".
      url: https://cplusplus.com/reference/cctype/isdigit/
      This checks if each character the user inputted for the id number is 
      actually a number. 
     */
    //If the whole id isn't just numbers, let the user know they made a mistake
    if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
      cout << endl;
      cout << "You didn't enter a 6 digit integer." << endl;
      cout << "Could you try inputting the id again?" << endl;
      cout << "(i.e. 464877, 342907)" << endl;
      cout << endl;
    }
  }
  strcpy((*addedStudent).id, idInput);
  cout << endl;

  //get student GPA and make sure that it is a two decimal number
  cout << "Please input the student's GPA to 2 decimal places (i.e. 3.00)." << endl;
  while((isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) || (gpaInput2 > 5.00 || gpaInput2 < 0.00)) {
    cin.get(gpaInput1, 5);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //If the user didn't enter a string with one leading number, a decimal
    //point, and two trailing numbers, tell them they need to do it again
    if(isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) {
      cout << "Your given gpa isn't in the corrent format of one leading " << endl;
      cout << "number, one decimal point, and two trailing numbers." << endl;
      cout << "(ie: 3.24, 4.22, 2.76)" << endl;
      cout << "Could you please try inputting the gpa again?" << endl;
      
    } else {
      //transfer their string input into a float
      /*
	I got help with transferring strings into floating points from
	Cplusplus's article on "stof".
	URL: https://cplusplus.com/reference/string/stof/
	This part of the std namespace allows me to change a string value into
	a floating point which is what I need after the first gpa input check.
       */
      gpaInput2 = stof(gpaInput1);
      
      //If the gpa isn't a within 0.00 and 5.00 let the user know the gpa isn't
      //a valid gpa
      if(gpaInput2 > 5.00 || gpaInput2 < 0.00) {
	cout << endl;
	cout << "Sorry, the two decimal place gpa is either over 5.00" << endl;
	cout << "(5.00 is max weighted gpa) or is under 0.00 (gpa must " << endl;
	cout << "be positive or zero). Could you enter the student's " << endl;
	cout << "gpa again? (i.e. 2.34, 4.14, 3.59...)" << endl;
	cout << endl;
      }
    }
  }
  (*addedStudent).gpa = gpaInput2;
  cout << endl;
  
  //When finished checking all the inputs and putting them all in, add the
  //finalized student pointer to the main vector.
  list.push_back(addedStudent);
}

//This function helps the user to view their current student list by printing
//it out
void printList(vector<Student*> & list) {
  //give a header to the list
  cout << "firstname lastname, id, gpa" << endl;
  cout << endl;

  //Set precision for floats so that they always show two digits after the
  //decimal point
  /*
    Got help with this from the "Formatting Output" video in the Canvas
    module "Introduction to C++: Video Tutorials".
   */
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //Check for everything in the student list vector and print each out
  /*
    For getting help with iterators I used the vector example given in the
    "Functions, Structs, By Reference, By Value, Pointers" module in Canvas.
   */
  for(vector<Student*>::iterator it = list.begin(); it != list.end(); it++) {
    cout << (*it) -> firstName << " ";
    cout << (*it) -> lastName << ", ";
    cout << (*it) -> id << ", ";
    cout << (*it) -> gpa << endl;
  }
  cout << endl;
}
