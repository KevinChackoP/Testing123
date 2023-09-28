/* 
   This project...
   Author: Kevin Chacko
   Last Updated: Write End Date Here!
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Functions, Structs, By Reference, By Value, Pointers" module

  NAME ANY OTHER RESOURCES YOU USED HERE!!!!!
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>

using namespace std;

//Function prototypes
void instructions();
char[2] askInput(bool turn, char grid[3][3]);

//start of main function
int main() {
  //variable declarations
  const char p1Sym = 'o';
  const char p2Sym = 'x';
  bool playerTurn = true;
  const bool p1Turn = true;
  const bool p2Turn = false;
  char grid[3][3];
  int inputRow = 0;
  int inputColumn = 0;
  
  //give instructions first
  instructions();
  
  //if everything turned out fine, return 0
  return 0;
}

//This method prints out all of the instructions on how to play the game
void instructions() {
  cout << "Hello, welcome to 2-player tic tac toe!" << endl;
  cout << "In this game you and a friend will take turns inputting " << endl;
  cout << "coordinates on a grid to try getting a vertical, " << endl;
  cout << "horizontal, or diagonal line of 3 symbols before your " << endl;
  cout << "opponent." << endl;
  cout << "Player 1 will be assigned the symbol 'o' and will go first." << endl;
  cout << "Player 2 will be assigned the symbol 'x' and will go second." << endl;
  cout << "The grid will consist of rows labeled a, b and c, and " << endl;
  cout << "columns labeled 1, 2, or 3. When inputting your coordinates " << endl;
  cout << "make sure to put the row first, then the column second with " << endl;
  cout << "no spaces or other characters include (ie 'a1' or 'b3')." << endl;
  cout << "Please take turns inputting your plays and have a good time!" << endl;
  cout << endl;
}

//This function asks for the player's input and validates it.
char askInput[2] (bool turn, char grid[3][3]) {
  //local variable declarations
  char input[2];
  bool validInput = false;

  //ask for and receive input
  cout << "please input either 'a', 'b', or 'c' for the row" << endl;
  cout << "you want to place your symbol in, followed by " << endl;
  cout << "'1', '2', or '3' for the column you want to " << end;
  cout << "place your symbol in." << endl;
  cin.get(input, 2);
  cin.get();

  //check the user's input
  while(!validInput) {
    //check for first input's validity
    if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c') {
       if(input[1] == '1' || input[1] == '2' || input[1] == '3') {
	 validInput = true;
       } else {
	 //Their second character input was invalid, so tell them!
	 
       }
    } else {
      //Their first character input was invalid, so tell them!
      
    }

    }
  }


  //Return checked and validated input
  return input;
}
