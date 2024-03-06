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

#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

//Function prototypes
void instructions();
bool askRestart();

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  char eqnInput = 'b';
  stack* operatorsS = new stack();
  queue* outputQ = new queue();

  //Tell the user how the program works
  instructions();

  //Keep asking the user to input expressions in infix to convert to other
  //fix notations until they are finished using the program
  while(inUse) {
    /*Ask the user to input an infix notation math expression and use 
     the shunting yard algorithm to get it in postfix.*/
    //ask for input
    cout << "Please input a mathematical expression in infix " << endl;
    cout << "notation to convert into postfix notation. Seperate " << endl;
    cout << "numbers, operators (+, -, x, /, ^), and parenthesis " << endl;
    cout << "in your expression using spaces between each token. " << endl;
    cout << "To signal the end of your mathematical expression input " << endl;
    cout << "just add a \';\' right after your last token, no space " << endl;
    cout << "before the semi-colon required." << endl;
    cout << endl;

    //take input and go through shunting yard algorithm
    while((cin >> eqnInput) && eqnInput != ';') {
      //check what the token they inputted is
      if(eqnInput >= 48 && eqnInput <= 57) {
	//if it's a number, shift it into the output queue
	node* newNode = new node(eqnInput);
	outputQ -> enqueue(newNode);
	
      } else if(eqnInput == '+' || eqnInput == '-' || eqnInput == 'x'
	|| eqnInput == '/' || eqnInput == '^') {
	//if it's an operator...
	node* newNode = new node(eqnInput);
	while((operatorsS -> peek() != '(' && operatorsS -> peek() != '\0')
	      && ((operatorsS -> peek() == '+' || operatorsS -> peek() == '-')
		  && (eqnInput == '+' || eqnInput == '-'))
	      || ((operatorsS -> peek() == 'x' || operatorsS -> peek() == '/')
		  && (eqnInput == 'x' || eqnInput == '/' || eqnInput == '+'
		      || eqnInput == '-'))
	      || ((operatorsS -> peek() == '^')
		  && (eqnInput == 'x' || eqnInput == '/' || eqnInput == '+'
		      || eqnInput == '-'))) {
	  //while the operator on the top of the stack isn't null or (,
	  //And it has higher precedence than the current operator or
	  //the same precedence as the current operator but is left-associative
	  //pop it from the stack into the output queue to maintain order
	  node* stackNode = new node(operatorsS -> pop());
	  outputQ -> enqueue(stackNode);
	}
	//add the operator to the stack
	operatorsS -> push(newNode);
	
      } else if(eqnInput == '(') {
	//if it's a left parenthesis, add it to the operator stack
	node* newNode = new node(eqnInput);
	operatorsS -> push(newNode);
	
      } else if(eqnInput == ')') {
	//if it's a right parenthesis...
	while(operatorsS -> peek() != '(' && operatorsS -> peek() != '\0') {
	  //Keep moving operators from the stack into the queue until you
	  //run into a (, or the stack is empty (in which case there is a
	  //parenthesis mismatch)
	  node* stackNode = new node(operatorsS -> pop());
	  outputQ -> enqueue(stackNode);
	}
	//Pop out and discard the ( if no parenthesis mismatch
	if(operatorsS -> peek() != '\0') {
	  operatorsS -> pop();
	}
      }
    }
    while(operatorsS -> peek() != '\0') {
      //put the remaining things in the operator stack in the output queue
      //if they aren't parenthesis (in which case the parenthesis would
      //be mismatched)
      if(operatorsS -> peek() != '(' && operatorsS -> peek() != ')') {
	node* stackNode = new node(operatorsS -> pop());
	outputQ -> enqueue(stackNode);
	
      } else {
	//Pop out and discard the ( or ) that were mismatched
	operatorsS -> pop();
      }
    }

    //print out the whole output queue to show the postfix expression
    //THINKING ABOUT USING CSTRING TO HOLD THE CHARACTERS OF THE OUTPUT QUEUE
    //AND PRINT OUT THE CSTRING, THEN USE THE CSTRING AND >> TO REREAD ALL THE
    //CHARACTERS IN POSTFIX NOTATION TO THEN USE FOR THE EXPRESSION TREE
    

    /*Ask the user to convert their input into a different notation and 
      use the postfix output from the shunting yard algorithm to make a
      binary expression tree which will convert the input into the desired
      notation*/
    //ADD STUFF HERE

    /*After a run of asking for an expression and converting it into the
    desired notation, ask the user if they'd like to continue using the
    program and change things accordingly*/
    inUse = askRestart();

    if(!inUse) {
      //If the user no longer wants to use the program, delete everything off
      //the heap and send the user off
      cout << "Ok then, I hope you found this program useful!" << endl;
      cout << endl;

      //ADD DELETION PROCESSES FOR DATA STRUCTURES ON THE HEAP!!!
    } else {
      //if they want to continue using the program, reset anything that
      //needs to be reset for the next run
      cout << "Ok, well get everything read for you again!" << endl;
      cout << endl;

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
  cout << "expression to be in and it will be converted into that " << endl;
  cout << "notation. You can do this as many times as you'd like!" << endl;
  cout << endl;
}

//This function asks the user after a cycle of the program if they'd like to
//use the program again
bool askRestart() {
  //make variables for the continue or not input
  char input[5];
  for(int i = 0; i < 5; i++) {
    input[i] = '\0';
  }

  //Ask the user for their input
  cout << "Would you like to continue converting mathematical " << endl;
  cout << "expressions into other notations?" << endl;
  cout << "(enter \"YES\" to continue or \"NO\" to stop)" << endl;
  cout << endl;

  //Keep asking them for an input until they give a valid answer
  while(true) {
    //Ask for input
    cin.getline(input, 5);

    //Clean input up by making it all upper case
    for(int i = 0; i < 5; i++) {
      input[i] = toupper(input[i]);
    }

    //check whether their input is valid or not
    if(strcmp(input, "YES") == 0 || strcmp(input, "Y") == 0) {
      return true;
	
    } else if(strcmp(input, "NO") == 0 || strcmp(input, "N") == 0) {
      return false;
	
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
}
