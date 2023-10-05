/* 
   This project plays a TicTacToe game that can be played between two players.
   The game starts by telling the players the instructions and showing them 
   the blank board. Then it prompts player 1 to enter a coordinate to play 
   their move. It will then switch between players asking for their moves as 
   their moves are played to the board. Once a player won or after all the 
   spots in the board have been played on an end result will be declared while
   also mentioning how many times each player has won respectivally. Then 
   the game will ask the users if they'd like to play again. If they say yes 
   everything will be reset and ready for them to start playing again. If they 
   say no the program will end. 
   Author: Kevin Chacko
   Last Updated: 10/4/2023
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Functions, Structs, By Reference, By Value, Pointers" module
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
void askInput(bool & turn, int & inputRow, int & inputColumn, char grid[][3]);
void printGrid(char grid[][3]);
void checkAssignWin(int & playState, char grid[][3], int & p1Wins, int & p2Wins, int & ties);
void printEndGameText(int playState, int p1Wins, int p2Wins, int ties);
void playAgain(bool & playingGame);

//Global constants
const char p1Sym = 'x';
const char p2Sym = 'o';
const bool p1Turn = true;
const bool p2Turn = false;
const int playingGameState = 0;
const int p1WinState = 1;
const int p2WinState = 2;
const int tieState = 3;

//start of main function
int main() {
  //variable declarations
  bool playerTurn = true;
  char grid[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      grid[i][j] = '\0';
    }
  }
  int inputRow = 0;
  int inputColumn = 0;
  bool playingGame = true;
  int playState = 0;
  int p1Wins = 0;
  int p2Wins = 0;
  int ties = 0;
  
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

    //check for win
    checkAssignWin(playState, grid, p1Wins, p2Wins, ties);
    if(playState > playingGameState) {
      //Go through after game text
      printEndGameText(playState, p1Wins, p2Wins, ties);

      //ask player if they'd like to play again
      playAgain(playingGame);
      if(playingGame == true) { //reset everything that needs to be reset
	for(int i = 0; i < 3; i++) {
	  for(int j = 0; j < 3; j++) {
	    grid[i][j] = '\0';
	  }
	}
	playerTurn = true;
	inputRow = 0;
	inputColumn = 0;
	playState = 0;
      }
    }
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
  cout << endl;
  cout << "Player 1 will be assigned the symbol '" << p1Sym << "' and will go first." << endl;
  cout << "Player 2 will be assigned the symbol '" << p2Sym << "' and will go second." << endl;
  cout << "The grid will consist of rows labeled a, b and c, and " << endl;
  cout << "columns labeled 1, 2, or 3." << endl;
  cout << endl;
  cout << "When inputting your coordinates make sure to put the row " << endl;
  cout << "first, then the column second with no spaces or other " << endl;
  cout << "characters included (ie 'a1' or 'b3')." << endl;
  cout << "Please take turns inputting your plays and have a good time!" << endl;
  cout << endl;
}

//This function prints out the current playing grid of the game
void printGrid(char grid[][3]) {
  cout << "\t|1|\t|2|\t|3|" << endl;
  cout << "|a|\t" << grid[0][0] << "\t" << grid[0][1] << "\t" << grid[0][2] << endl;
  cout << "|b|\t" << grid[1][0] << "\t" << grid[1][1] << "\t" << grid[1][2] << endl;
  cout << "|c|\t" << grid[2][0] << "\t" << grid[2][1] << "\t" << grid[2][2] << endl;
  cout << endl;
}

//This function asks for the player's input, validates it, and adds it to the grid.
void askInput (bool & turn, int & inputRow, int & inputColumn, char grid[][3]) {
  //local variable declarations
  char input[2];
  bool validInput = false;
  
  //Name who's turn it is
  if(turn == p1Turn) {
    cout << "Player 1's Turn! (Player '" << p1Sym << "')" << endl;
  } else if(turn == p2Turn) {
    cout << "Player 2's Turn! (Player '" << p2Sym << "')" << endl;
  }
  cout << endl;

  //check the user's input
  while(!validInput) {
    //ask for and receive input
    cout << "Name the coordinates for where you want to play your symbol:" << endl;
    cout << "Format your input like a1 or b3 (row first, then column)." << endl;
    cin.get(input, 3);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
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
	    turn = p2Turn; //change to p2 turn
	  } else if(turn == p2Turn) {
	    grid[inputRow][inputColumn] = p2Sym;
	    turn = p1Turn; //change to p1 turn
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

  cout << endl;
}

//This method checks if a win or tie has happened and will change the state
//of the game based on the result if there is a difference
void checkAssignWin(int & playState, char grid[][3], int & p1Wins, int & p2Wins, int & ties) {
  //Check diagonals first
  if((grid[0][0] == p1Sym && grid[1][1] == p1Sym && grid[2][2] == p1Sym) || (grid[0][2] == p1Sym && grid[1][1] == p1Sym && grid[2][0] == p1Sym)) {
      //If the player one symbols make a diagonal, give player 1 the win
      playState = p1WinState;
      p1Wins++;
      
    } else if((grid[0][0] == p2Sym && grid[1][1] == p2Sym && grid[2][2] == p2Sym) || (grid[0][2] == p2Sym && grid[1][1] == p2Sym && grid[2][0] == p2Sym)) {
      //If the player two symbols make a diagonal, give player 2 the win
      playState = p2WinState;
      p2Wins++;
      
    }

  //Check for rows and columns next
  for(int i = 0; i < 3; i++) {
    //check rows
    if(grid[i][0] == p1Sym && grid[i][1] == p1Sym && grid[i][2] == p1Sym) {
      //If the player one symbols make a row, give player 1 the win
      playState = p1WinState;
      p1Wins++;
      
    } else if(grid[i][0] == p2Sym && grid[i][1] == p2Sym && grid[i][2] == p2Sym) {
      //If the player two symbols make a diagonal, give player 2 the win
      playState = p2WinState;
      p2Wins++;
      
    }

    //check columns
    if(grid[0][i] == p1Sym && grid[1][i] == p1Sym && grid[2][i] == p1Sym) {
      //If the player one symbols make a column, give player 1 the win
      playState = p1WinState;
      p1Wins++;
      
    } else if(grid[0][i] == p2Sym && grid[1][i] == p2Sym && grid[2][i] == p2Sym) {
      //If the player two symbols make a column, give player 2 the win
      playState = p2WinState;
      p2Wins++;
      
    }
  }

  //check for tie by seeing if everything on the grid is filled in
  if((grid[0][0] != '\0' && grid[0][1] != '\0' && grid[0][2] != '\0' && grid[1][0] != '\0' && grid[1][1] != '\0' && grid[1][2] != '\0' && grid[2][0] != '\0' && grid[2][1] != '\0' && grid[2][2] != '\0') && playState == playingGameState) {
    playState = tieState;
    ties++;
  }
  
}

//This function prints out the text at the end of the game
void printEndGameText(int playState, int p1Wins, int p2Wins, int ties) {
  if(playState == p1WinState) { //if player 1 wins...
    cout << "Player 1 wins! Congradulations!" << endl;
    
  } else if(playState == p2WinState) { //if player 2 wins...
    cout << "Player 2 wins! Nice job!" << endl;
    
  } else if(playState == tieState) { //if there is a tie
    cout << "It's a tie! It seems like it was a tough game!" << endl;
    
  }

  cout << endl;

  //Name current win and tie totals
  cout << "So far..." << endl;
  cout << "Player 1 has won " << p1Wins << " time(s)." << endl;
  cout << "Player 2 has won " << p2Wins << " time(s)." << endl;
  cout << "Both players have tied " << ties << " time(s)." << endl;

  cout << endl;
}

//This function asks the players if they'd like to keep playing, resetting the
//game if they say yes, and ending the program if they say no
void playAgain(bool & playingGame) {
  //Ask the players if they'd like to play again
  cout << "Would you both like to play another game of Tic Tac Toe?" << endl;
  cout << "Enter (y) for yes or (n) for no." << endl;
  cout << endl;

  //Take the users' input
  char input = 0;
  while(input != 'y' && input != 'n') {
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //If their input doesn't work, tell them
    if(input != 'y' && input != 'n') {
      cout << "Sorry, I don't understand that." << endl;
      cout << "Please enter either 'y' for yes or 'n' for no." << endl;
      cout << endl;
    }
  }

  //if the said yes, keep playing game as true and reset variables in main
  if(input == 'y') {
    playingGame = true;
    cout << "Ok! I'll get everything set up again for you both!" << endl;
    
  } else if(input == 'n') { //If they said no, end the program
    cout << "Ok! Thanks for playing!" << endl;
    playingGame = false;
  }

  cout << endl;
}
