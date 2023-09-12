/* 
   This program plays a guessing game in which the user will have to guess a 
   number between 0 and 100 (inclusive) to find the computer's hidden random 
   number. After each guess the guess counter will go up and the player will 
   be awarded feedback telling them if their guessed number was lower than the 
   hidden number, higher than the hidden number, not in the range, or equal to 
   the hidden number. If the players guess was equal to the hidden number their
   number of guesses will be displayed and they'll be asked if they want to 
   play again. If they say yes the variables will be reset and they can play 
   through again. If they say no the program will thank them for playing before
   ending with exit code 0.
   Author: Kevin Chacko
   Last Updated: 9/12/2023
   Period 6, C++ / Data Structures
*/

/*
  THE 3 RULES FOR C++ CLASS:
  1. No global variables! (Though Global constants are ok).
  2. Never use strings! (Use cstrings or character arrays instead, and the 
  cstring and cctype libraries are ok. Its recommended that you use strcmp 
  and strlen in your projects).
  3. You should include <iostream>, not stdio. Also, use "new" and "delete" 
  instead of "malloc" and "free".

  Also as for a few recommendations:
  1. Avoid using the mouse when possible. Learn the shortcuts. If you ever work
  through a shell, you won't have a mouse available to you.
  2. Only use break/continue if you have to, like in switch statements. 
  Otherwise don't use them.
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Introduction to C++: Video Tutorials" module

  I also got help from the GeeksforGeeks article on "rand() and srand() in C++"
  to help me get my random number which the player would have to guess for.
*/

#include <iostream>

using namespace std;

//start of main function
int main() {
  //Variable initializations
    //Generate random number and random number seed
  srand(time(NULL));
  /*
    I got help with making a random number that would be within a range of 0 to
    100 inclusive from a Geeksforgeeks article called "rand() and srand() in 
    C++".
    URL: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#
    This taught me how srand and rand work, and then gave an example function 
    for how to create a random number between and upper and lower bound 
    including both boundaries in the "implementation of the rand() function 
    to get a value from Upper_Bound to Lower_Bound" section on the webpage. 
    Understanding this function helped me use the rand() function to get a 
    random number within my desired value range. 
  */
  int randNum = rand() % 101;
  int guessNum = 0;
  int input = 0;
  char input2 = 0;
  bool keepPlaying = true;

  //Instructions
  cout << "This is a guessing game!" << endl;
  cout << "In this game, I'll pick a number between 0 and 100" << endl;
  cout << "(including 0 and 100)" << endl;
  cout << "and you'll have to trying finding it!" << endl;
  cout << "After each guess I'll tell you whether your guess was " << endl;
  cout << "higher or lower than the number I picked, then you can guess again." << endl;
  cout << "Try getting my random number in the fewest number of guesses!" << endl;
  
  //Start game loop
  while(keepPlaying) {
    //Ask them for an input and take it
    cout << "Guess a number between 0 and 100 (inclusive)." << endl;
    cin >> input;
    cout << "Your guess was: " << input << endl;
    guessNum++;

    //check their guess value against the random number
    if(input == randNum) {
      if(guessNum == 1) {
	//If they got it in one guess
	cout << "Congradulations! You got my number in 1 guess! How Lucky!" << endl;
      } else {
	//If they were able to get it in more than one guess
	cout << "Nice Job! You got my number in " << guessNum << " guesses." << endl;
      }

      //Ask the player if they'd like to play again and make sure they don't
      //input something that wouldn't work
      do {
	cout << "Would you like to play again?" << endl;
	cout << "(Type 'y' for yes or 'n' for no)" << endl;
	cin >> input2;

	if(input2 != 'n' && input2 != 'y') {
	  cout << "Sorry, could you just input 'n' or 'y' then ENTER?" << endl;
	}
	
      } while(input2 != 'n' && input2 != 'y');
      
      //Based on input end or restart the game
      if(input2 == 'n') {
	//If they said no
	cout << "Thanks so much for playing!" << endl;
	keepPlaying = false;
	
      } else if(input2 == 'y') {
	//If they said yes
	cout << "Ok, I'll pick a new number!" << endl;
	  //reset variables
	randNum = rand() % 101;
	guessNum = 0;
	input = 0;
	input2 = 0;
	
      }
      
    } else if(input < randNum && input >= 0) {
      //If their guess was lower than the random number and in range...
      cout << "Fine guess, but that's not it! Your guess was LOWER than my number!" << endl;
      
    } else if(input > randNum && input <= 100) {
      //If their guess was higher than the random number and in range...
      cout << "That's a good guess, but it isn't my number! Your guess was HIGHER than my number!" << endl;
      
    } else {
      //If their number wasn't in range...
      cout << "Um, your number isn't in my number range. Try again, this time with a number between 0 and 100, including 0 and 100!" << endl;
      
    }
  }
  
  //If nothing went wrong, return 0
  return 0;
}
