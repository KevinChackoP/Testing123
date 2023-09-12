/* 
   This program... WRITE WHAT THIS PROGRAM DOES HERE!
   Author: Kevin Chacko
   Period 6, C++ / Data Structures
*/

/*
  THE 3 RULES FOR C++ CLASS:
  1. No global variables! (Though Global constants are ok).
  2. Never use strings! (Use cstrings or character arrays instead, and the cstring and cctype libraries are ok. Its recommended that you use strcmp and strlen in your projects).
  3. You should include <iostream>, not stdio. Also, use "new" and "delete" instead of "malloc" and "free".

  Also as for a few recommendations:
  1. Avoid using the mouse when possible. Learn the shortcuts. If you ever work through a shell, you won't have a mouse available to you.
  2. Only use break/continue if you have to, like in switch statements. Otherwise don't use them.
*/

/*
  I got a lot of help with learning c++ for this project from the "Introduction to C++: Video Tutorials" module

  I also got help from the GeeksforGeeks article on "rand() and srand() in C++" to help me get my random number which the player would have to guess for.
*/

#include <iostream>

using namespace std;

//start of main function
int main() {
  //Generate random number and random number seed
  srand(time(NULL));
  /*
    I got help with making a random number that would be within a range of 0 to 100 inclusive from a Geeksforgeeks article called "rand() and srand() in C++".
    URL: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#
    This taught me how srand and rand work, and then gave an example function for how to create a random number between and upper and lower bound including both boundaries in the "implementation of the rand() function to get a value from Upper_Bound to Lower_Bound" section on the webpage. Understanding this function helped me use the rand() function to get a random number within my desired value range. 
  */
  int randNum = rand() % 101;
  cout << randNum << endl;
 
  //If nothing went wrong, return 0
  return 0;
}
