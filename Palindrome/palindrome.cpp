/* 
   This project... WRITE MORE ABOUT WHAT THIS PROJECT DOES HERE!
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "CStrings and Arrays" module

  ADD MORE SOURCE HERE IF NEEDED
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>

using namespace std;

//start of main function
int main() {
  //Variable initializations
  bool inUse = true;
  char continueInput = 0;
  char input[80];
  int counter = 0;
  char cleanInput[80];
  char reverseInput[80];

  //Tell the user what this program does
  cout << "Hello!" << endl;
  cout << "This program will let you know if the text you just entered" << endl;
  cout << "was a palindrome or not, that way you can check!" << endl;
  cout << "Please make sure you don't input anything greater than 80 characters." << endl;
  cout << "Additionally, only type in alphanumeric characters (normal alphabet " << endl;
  cout << "including lower and upper case letters, and numbers, but no symbols " << endl;
  cout << "other than punctuation) for the program to work properly!" << endl;
  cout << "Keep in mind that spaces and punctuation won't be looked at when " << endl;
  cout << "checking if the text entered was a palindrome or not. " << endl;
  cout << endl;
  
  //While the program is currently in use, ask user for palindromes to check
  while(inUse) {
    //Ask for and get text input from user
    cout << "Please enter text that you want to see is a palindrome or not. " << endl;
    cin.get(input, 80);
    cout << "Your input: " << endl;
    cout << input << endl;
    cout << endl;

    //Process input by getting rid of punctuation and spaces
    for(int i = 0; i < strlen(input) + 1; i++) {
      /*
	I got help with isalnum from cplusplus.com's "isalnum" article.
	URL: https://cplusplus.com/reference/cctype/isalnum/
	This requires the <cctype> library which I included at the start of my 
	program and it will basically check if a character is a number or an 
	alphabetical letter. I need this to clean my input.
       */
      if(isalnum(input[i]) || input[i] == '\0') {
	cleanInput[counter] = toupper(input[i]);
	counter++;
      }
    }
    cout << "Your cleaned up input: " << cleanInput << endl;
    cout << endl;

    //Reverse the cleaned input
    for(int i = 1; i < strlen(cleanInput) + 1; i++) {
      reverseInput[i - 1] = cleanInput[strlen(cleanInput) - i];
    }
    reverseInput[strlen(reverseInput)] = '\0';
    cout << "Your cleaned up input reversed: " << reverseInput << endl;
    cout << endl;
    
    //check if cleaned input is the same as it is when reversed
    if(strcmp(cleanInput, reverseInput) == 0) {
      cout << "Your input was a PALINDROME!!! Cool!" << endl;
    } else {
      cout << "Your input was NOT a PALINDROME. Aww." << endl;
    }
    cout << endl;

    //Ask the user if they'd like to continue entering text
    cout << "Now that you've checked some text, would you like to continue " << endl;
    cout << "using this program to check text to see if it is a palindrome? " << endl;
    cout << "(type just 'y' for yes or just 'n' for no) " << endl;

    //Make sure they input something valid
    while(continueInput != 'n' && continueInput != 'y') {
      cin >> continueInput;
      
      if(continueInput != 'n' && continueInput != 'y') {
	cout << "Um, you didn't input something I understand." << endl;
	cout << "Please just input 'y' for yes or 'n' for no." << endl;
      }
    }
    cout << endl;

    if(continueInput == 'y') {
      //If they want to continue using the program, reset everything
      cout << "Ok! Let me just reset everything for you!" << endl;
      cout << endl;

      continueInput = 0;
      counter = 0;
      for(int i = 0; i < 80; i++) {
	input[i] = '\0';
	cleanInput[i] = '\0';
	reverseInput[i] = '\0';
      }
      /*
      I got help from the tutorialspoint article "What is the use of 
      cin.ignore() in C++" by Nishtha Thakur.
      URL: https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
      This helps ignore past enters in the input buffer so that the cin isn't skipped over. For this I needed to include <ios> and <limits>.
     */
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
    } else if(continueInput == 'n') {
      //if the don't want to continue using the program, exit the while loop
      cout << "Ok, I hope this program helped!" << endl;
      inUse = false;
      
    }
  }
  
  //end code if everything worked
  return 0;
}
