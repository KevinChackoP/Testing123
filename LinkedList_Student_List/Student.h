/*
  This program is the header file for my Student.cpp file that will be used 
  in my linked lists student list project. 
  Author: Kevin Chacko
  Last Updated: 1/4/2024
  Period 6, C++ / Data Structures
*/

//Implemention of a header guard for header file
#ifndef STUDENT_H
#define STUDENT_H

//imports
#include <iostream>
#include <cstring>

using namespace std;

//Start of student class
class Student {
 //Public functions for class
 public:
  //constructor function for student class
  Student(char* inputFirstName, char* inputLastName, char* idInput, float gpaInput);

  //destructor function for student class
  ~Student();

  //getter function for first name cstring
  char* getFirstName();

  //getter function for last name cstring
  char* getLastName();

  //getter function for id cstring (will be converted into int while sorting
  //and finding average GPA briefly, but elsewise it's better to keep as this)
  char* getID();

  //getter function for gpa floating number
  float getGPA();

 //Private variables & pointers for class
 private:
  char* firstName;
  char* lastName;
  char* id;
  float gpa;
};

#endif
