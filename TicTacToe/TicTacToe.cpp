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
void askInput(bool turn, int & inputRow, int & inputColumn, char grid[][3]);
void printGrid(char grid[][3]);

//Global constants
const char p1Sym = 'o';
const char p2Sym = 'x';
const bool p1Turn = true;
const bool p2Turn = false;

//start of main function
int main() {
  //variable declarations
  bool playerTurn = true;
  char grid[3][3];
  int inputRow = 0;
  int inputColumn = 0;
  bool playingGame = true;
  
  //give instructions first time playing
  instructions();

  //keep them in the loop until they say that they don't want to play anymore
  while(playingGame) {
    //Show grid for the first time if the grid is currently clear
    if(grid[0][0] == '\0' && grid[0][1] == '\0' && grid[0][2] == '\0'
       && grid[1][0] == '\0' && grid[1][1] == '\0' && grid[1][2] == '\0'
       && grid[2][0] == '\0' && grid[2][1] == '\0' && grid[2][2] == '\0') {
      printGrid(grid);
    }
    
    //Ask for player input and add it to the grid
    askInput(playerTurn, inputRow, inputColumn, grid);

    //print out board
    printGrid(grid);
  }
  
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

//This function prints out the current playing grid of the game
void printGrid(char grid[][3]) {
  cout << "\t|1|\t|2|\t|3|" << endl;
  cout << "|a|\t" << grid[0][0] << "\t" << grid[0][1] << "\t" << grid[0][2] << endl;
  cout << "|a|\t" << grid[1][0] << "\t" << grid[1][1] << "\t" << grid[1][2] << endl;
  cout << "|a|\t" << grid[2][0] << "\t" << grid[2][1] << "\t" << grid[2][2] << endl;
  cout << endl;
}

//This function asks for the player's input, validates it, and adds it to the grid.
void askInput (bool turn, int & inputRow, int & inputColumn, char grid[][3]) {
  //local variable declarations
  char input[2];
  bool validInput = false;
  
  //Name who's turn it is
  if(turn == p1Turn) {
    cout << "Player 1's Turn! (Player 'o')" << endl;
  } else if(turn == p2Turn) {
    cout << "Player 2's Turn! (Player 'x')" << endl;
  }
  cout << endl;
  
  //ask for and receive input
  cout << "Name the coordinates for where you want to play your symbol:" << endl;
  cout << "Format your input like a1 or b3 (row first, then column)." << endl;
  cin.get(input, 3);
  cin.get();

  //check the user's input
  while(!validInput) {
    //check for first input's validity
    if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c') { //row
      if(input[1] == '1' || input[1] == '2' || input[1] == '3') { //column
	//Match their input to the coordinates
	if(input[0] == 'a') { //row coordinate
	  inputRow = 0;
	} else if(input[0] == 'b') {
	  inputRow = 1;
	} else if(input[0] == 'c') {
	  inputRow = 2;
	}

	if(input[1] == '1') { //column coordinate
	  inputColumn = 0;
	} else if(input[1] == '2') {
	  inputColumn = 1;
	} else if(input[1] == '3') {
	  inputColumn = 2;
	}

	//Make sure the move trying to be played hasn't already been played
	if(grid[inputRow][inputColumn] == '\0') {
	  //Their input was fully validated, add their move to the grid
	  if(turn == p1Turn) {
	    grid[inputRow][inputColumn] = p1Sym;
	  } else if(turn == p2Turn) {
	    grid[inputRow][inputColumn] = p2Sym;
	  }
	  validInput = true;
	} else { //If the move has already been played
	  cout << "Sorry, that move has already been played." << endl;
	  cout << "Please pick a different place to play your symbol." << endl;
	}
	
      } else { //Their second character input was invalid, so tell them!
	cout << "The second part of your input (the column input) doesn't work." << endl;
	cout << "Please input either '1', '2', or '3' for the column" << endl;
	cout << "you want to place your symbol in. (i.e. a1, b3)" << endl;
      }
      
    } else { //Their first character input was invalid, so tell them!
      cout << "The first part of your input (the row input) doesn't work." << endl;
      cout << "Please input either 'a', 'b', or 'c' for the row" << endl;
      cout << "you want to place your symbol in. (i.e. a1, b3)" << endl;
    }
  }
}
