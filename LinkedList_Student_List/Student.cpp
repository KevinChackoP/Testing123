/*
  This program is the cpp file for my Student class that will be used in my 
  linked lists student list project.
  Author: Kevin Chacko
  Last Updated: 1/4/2024
  Period 6, C++ / Data Structures
*/

//imports
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

//Student class constructor
Student::Student(char* inputFirstName, char* inputLastName, char* idInput, float gpaInput) {
  //On construction, set variables based on parameters
  firstName = new char[16];
  strcpy(firstName, inputFirstName);
  
  lastName = new char[16];
  strcpy(lastName, inputLastName);
  
  id = new char[7];
  strcpy(id, idInput);
  
  gpa = gpaInput;
}

//Student class deconstructor
Student::~Student() {
  delete firstName;
  delete lastName;
  delete id;
}

//getter function for first name cstring
char* getFirstName() {
  return firstName;
}

//getter function for last name cstring
char* getLastName() {
  return lastName;
}

//getter function for id cstring
char* getID() {
  return id;
}

//getter function for gpa floating number
float getGPA() {
  return gpa;
}
