/* 
   This project... WRITE PROJECT DESCRIPTION HERE
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got some of help with learning what's needed for a Shunting Yard
  and how it's parts work individually and together from the "Stacks, 
  Queues, Lists" module. This gave me some resources to refer to for 
  help, teaching me about the whole Shunting Yard Algorithm, Stacks, 
  Queues, the Binary Expression tree, and giving worked examples of 
  the process a Shunting Yard Algorithm will work through.

  I learned much more about what a Shunting Yard Algorithm and a 
  Binary Expression Tree is from the Wikipedia pages on them.
  URL: https://en.wikipedia.org/wiki/Shunting_yard_algorithm
  URL: https://en.wikipedia.org/wiki/Binary_expression_tree
  These pages gave me an overview on the structure of a Shunting 
  Yard Algorithm and a Binary Expression Tree, as well as some tips 
  and psuedo-code on what my program should do to work. 

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

using namespace std;

//Function prototypes
void instructions();
//ADD MORE FUNCTION PROTOTYPES HERE

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;

  //Tell the user how the program works
  instructions();

  //Keep asking the user to input expressions in infix to convert to other
  //fix notations until they are finished using the program
  while(inUse) {
    /*Ask the user to input an infix notation math expression and use 
     the shunting yard algorithm to get it in postfix.*/
    //ADD STUFF HERE

    /*Ask the user to convert their input into a different notation and 
      use the postfix output from the shunting yard algorithm to make a
      binary expression tree which will convert the input into the desired
      notation*/

    /*After a run of asking for an expression and converting it into the
    desired notation, ask the user if they'd like to continue using the
    program.*/
    //make variables for the continue or not input
    char input[5];
    for(int i = 0; i < 5; i++) {
      input[i] = '\0';
    }
    bool validAnswer = false;

    //Ask the user for their input
    cout << "Would you like to continue converting mathematical " << endl;
    cout << "expressions into other notations?" << endl;
    cout << "(enter \"YES\" to continue or \"NO\" to stop)" << endl;
    cout << endl;

    //Keep asking them for an input until they give a valid answer
    while(!validAnswer) {
      //Ask for input
      cin.getline(input, 5);

      //Clean input up by making it all upper case
      for(int i = 0; i < 5; i++) {
	input[i] = toupper(input[i]);
      }

      //check whether their input is valid or not
      if(strcmp(input, "YES") == 0 || strcmp(input, "Y") == 0) {
	validAnswer = true;
	inUse = true;
	
      } else if(strcmp(input, "NO") == 0 || strcmp(input, "N") == 0) {
	validAnswer = true;
	inUse = false;
	
      } else { //If their input is invalid, tell them and have them try again
	cout << "Sorry, I don't understand what you mean." << endl;
	cout << "Please input either \"YES\" to continue or " << endl;
	cout << "\"NO\" to stop." << endl;
	cout << endl;

	for(int i = 0; i < 5; i++) {
	  input[i] = '\0';
	}
      }
    }

    if(!inUse) {
      //If the user no longer wants to use the program, delete everything off
      //the heap and send the user off
      cout << "Ok then, I hope you found this program useful!" << endl;

      //ADD DELETION PROCESSES FOR DATA STRUCTURES ON THE HEAP!!!
    } else {
      //if they want to continue using the program, reset anything that
      //needs to be reset for the next run
      cout << "Ok, well get everything read for you again!" << endl;

      //ADD RESET PROCESSES
    }
  }

  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program that will help you to convert " << endl;
  cout << "an infix mathematical expression into fix notation of " << endl;
  cout << "your choice (infix, prefix, or postfix). Start by " << endl;
  cout << "inputting an infix expression, then it will be converted " << endl;
  cout << "into postfix. After that, input what format you want the " << endl;
  cout << "expression to be in and it will be converted into that " << end;
  cout << "notation. You can do this as many times as you'd like!" << endl;
  cout << endl;
}

