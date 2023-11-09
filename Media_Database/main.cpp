/* 
   This project...
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Classes and Inheritance" module

  I also transferred a lot of my code from my Student list project 
  since it used a lot of the same logic and structure as this project. 

  WRITE MORE CITATIONS HERE
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <vector>

//class imports
#include "digitalMedia.h"
#include "videoGame.h"
#include "music.h"
#include "movie.h"

using namespace std;

//Function prototypes
void instructions();
int askCommand();
void addMedia(vector<digitalMedia*> & database);
void searchDatabase(vector<digitalMedia*> & database);
void deleteMedia(vector<digitalMedia*> & database);

//Start of main function
int main() {
  //local variable declarations
  vector<digitalMedia*> mediaDatabase;
  bool inUse = true;
  int commandKey = 0;
  
  //Tell them how the program works
  instructions();

  //Put them through the loop of interacting with the database until they are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something to the database or quit from the program
    if(commandKey == 1) {
      //If they want to add media to the database
      cout << "Adding media to the database." << endl;
      cout << endl;
      addMedia(mediaDatabase);
      
    } else if(commandKey == 2) {
      //If they want to delete media from the database, do so
      cout << "Deleting media from the database." << endl;
      cout << endl;
      //deleteMedia(mediaDatabase); ADD THIS IN WHEN IT'S READY
      
    } else if(commandKey == 3) {
      //If they want to search for an item in the database, do so
      cout << "Searching for media in the database." << endl;
      cout << endl;
      searchDatabase(mediaDatabase);
      
    } else if(commandKey == 4) {
      //If they want to quit the program, do so
      cout << "Ok then, have a good day!" << endl;

      //delete everything on the heap from my media list vector
      while(!mediaDatabase.empty()) {
	delete mediaDatabase.back();
	mediaDatabase.pop_back();
      }

      //change the boolean that determines if the program continues
      inUse = false;
    }
  }
  
  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program that can keep track of media " << endl;
  cout << "using a database! You can use various commands to interact with the database." << endl;
  cout << "That is to say, you can add media to the database, search for an item " << endl;
  cout << "in the database, delete media from the database, or exit out of the program." << endl;
  cout << "I hope this program is of use to you!" << endl;
  cout << endl;
}

//This function asks the user for their command
int askCommand() {
  //make an input array and clean it up
  char input[10];
  for(int i = 0; i < 10; i++) {
    input[i] = '\0';
  }

  //Tell them how to input a command and what each of the commands do
  cout << "Please input a command to tell me what you want to do." << endl;
  cout << "Input ADD for adding new media to the database." << endl;
  cout << "Input DELETE to delete media from the database." << endl;
  cout << "Input SEARCH to find and print out matching media in the database." << endl;
  cout << "Input QUIT to exit the program." << endl;
  cout << endl;

  //ask them for a command input, if the input is valid return an int for the
  //command key, if invalid have them reinput their desired command.
  while(true) {
    //Ask for input
    cin.getline(input, 10);

    //Clean input up by making it all upper case
    for(int i = 0; i < 10; i++) {
      input[i] = toupper(input[i]);
    }

    //return the corresponding command key to their command
    if(strcmp(input, "ADD") == 0) {
      return 1;
    } else if(strcmp(input, "DELETE") == 0) {
      return 2;
    } else if(strcmp(input, "SEARCH") == 0) {
      return 3;
    } else if(strcmp(input, "QUIT") == 0) {
      return 4;
    } else { //If their command is invalid, tell the and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADD, DELETE, SEARCH, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function helps the user to add media to the database
void addMedia(vector<digitalMedia*> & database) {
  //These are a local variables being used
  digitalMedia* addedMedia;
  int mediaTypeCode = 0; //1 for videogame, 2 for music, 3 for movie
  char* title = new char[31];
  for(int i = 0; i < 31; i++) {
    title[i] = '\0';
  }
  int year = 0;
  char* publisher = new char[16];
  char* artist = new char[16];
  char* director = new char[16];
  for(int i = 0; i < 16; i++) {
    publisher[i] = '\0';
    artist[i] = '\0';
    director[i] = '\0';
  }
  int rating = 0;
  int duration = 0;

  //Ask for media type
  while(mediaTypeCode != 1 && mediaTypeCode != 2 && mediaTypeCode != 3) {
    cout << "What type of digital media are you entering?" << endl;
    cout << "Enter 1 for video games, 2 for music, or 3 for movies." << endl;
    cin >> mediaTypeCode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //If input is invalid
    if(mediaTypeCode != 1 && mediaTypeCode != 2 && mediaTypeCode != 3) {
      cout << endl;
      cout << "Sorry, that's not one of the available options." << endl;
      cout << "Please try again." << endl;
      cout << endl;
    }
  }
  cout << endl;

  //Ask for title input
  cout << "What's the title of the media? (make no more than 30 characters)" << endl;
  cin.getline(title, 31);
  cout << endl;

  //Ask for the year input
  cout << "In what year was the media released?" << endl;
  cout << "(positive numbers as A.D., negative as B.C.)" << endl;
  cin >> year;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;

  //If needed, ask for the publisher name
  if(mediaTypeCode == 1 || mediaTypeCode == 2) {
    cout << "What's the name of the media's publisher?" << endl;
    cout << "(make no more than 15 characters)" << endl;
    cin.getline(publisher, 16);
    cout << endl;
  }

  //If needed, ask for the artist name
  if(mediaTypeCode == 2) {
    cout << "What's the name of the media's artist?" << endl;
    cout << "(make no more than 15 characters)" << endl;
    cin.getline(artist, 16);
    cout << endl;
  }

  //If needed, ask for the director name
  if(mediaTypeCode == 3) {
    cout << "What's the name of the media's director?" << endl;
    cout << "(make no more than 15 characters)" << endl;
    cin.getline(director, 16);
    cout << endl;
  }

  //If needed, ask for the rating
  if(mediaTypeCode == 1 || mediaTypeCode == 3) {
    cout << "What's the rating that the media received? (0 to 100)" << endl;
    cin >> rating;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
  }

  //If needed, ask for the duration
  if(mediaTypeCode == 2) {
    //If for music, ask for seconds
    cout << "What's the duration of the media in seconds?" << endl;
    cout << "(Positive numbers only!)" << endl;
    cin >> duration;
    cout << endl;
  }
  if(mediaTypeCode == 3) {
    //If for movie, ask for minutes
    cout << "What's the duration of the media in minutes?" << endl;
    cout << "(Positive numbers only!)" << endl;
    cin >> duration;
    cout << endl;
  }
    
  //When finished taking all of the inputs, put them
  //Into the fitting child class
  if(mediaTypeCode == 1) { // video game
    digitalMedia* addedMedia = new videoGame(title, year, publisher, rating);
  } else if(mediaTypeCode == 2) { // music
    digitalMedia* addedMedia = new music(title, artist, year, publisher, duration);
  } else if(mediaTypeCode == 3) { // movie
    digitalMedia* addedMedia = new movie(title, director, year, rating, duration);
  }
  
  //Add finalized digitalMedia pointer to the main vector (database).
  database.push_back(addedMedia);
}
/*
//This function helps the user to delete media from the database
void deleteMedia(vector<digitalMedia*> & database) {
  //local variables for function
  char idInput[7];
  for(int i = 0; i < 7; i++) {
    idInput[i] = '\0';
  }
  bool matchingIdFound = false;

  //If the list is currently empty, don't let them delete any student
  if(list.empty()) {
    cout << "There isn't any students in the list to delete from " << endl;
    cout << "the list. After you've added a few students, then " << endl;
    cout << "consider deleting some of them from the list." << endl;
    cout << endl;
    
  } else { //Otherwise, continue with the rest of the function
    //ask user for the id of the student they want to remove from the list
    //and make sure the inputted id is valid and matches a student
    cout << "What's the id of the student you want to remove from the list?" << endl;
    cout << "Please make it a 6 digit integer like before (i.e. 464877)." << endl;
    while((isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) || !matchingIdFound) {
      cin.get(idInput, 7);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
      //If the whole id isn't just numbers, let the user know they made a mistake
      if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
	cout << endl;
	cout << "You didn't enter a 6 digit integer." << endl;
	cout << "Could you try inputting the student's id again?" << endl;
	cout << "(i.e. 464877, 342907)" << endl;
	cout << endl;
      } else { //Is there a matching student id in the list?
	for(vector<Student*>::iterator it = list.begin(); it != list.end(); it++) {
	  if(strcmp(((*it) -> id), idInput) == 0) { //There's a match
	    matchingIdFound = true;
	    cout << "Removing student " << (*it) -> firstName << " " << (*it) -> lastName << " from list." << endl;
	    cout << endl;
	  
	    //get rid of the student from the vector
	    delete *it;
	    list.erase(it);
	    break;
	  }
	}

	//If after going through the whole vector and no match could be found
	//let the user know that their id doesn't work before letting them
	//try again
	if(!matchingIdFound) {
	  cout << "Sorry, I couldn't find a student with that id in the list." << endl;
	  cout << "This is what your current list is like" << endl;
	  //Show the user their current list so they can see the right id
	  //of who they want to delete off the list
	  cout << endl;
	  printList(list);
	  cout << "Could you reinput the id of the student you want " << endl;
	  cout << "to remove from the list?" << endl;
	  cout << endl;
	}
      }
    }
  }
}*/

//This function helps the user to search for media in the database and print
//out media that matches with their search (based on title or year released)
void searchDatabase(vector<digitalMedia*> & database) {
  //If there is nobody in the database, tell the user
  if(database.empty()) {
    cout << "Sorry, there is currently no media in the database!" << endl;
    cout << "Please try again after data has been ADDed." << endl;
  } else {
    //local variables
    int searchType = 0; //1 for title, 2 for year
    char title[31];
    for(int i = 0; i < 31; i++) {
      title[i] = '\0';
    }
    int year = 0;
    bool foundResult = false;
    int searchAgain = 0;
    
    //Ask for what they are searching for
    cout << "Do you want to search for items by title or year? " << endl;
    cout << "Enter 1 for title, or 2 for year." << endl;
    //take and validate their input asking for their preferred search attribute
    while(searchType != 1 && searchType != 2) {
      cin >> searchType;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl;
      
      //If input is invalid
      if(searchType != 1 && searchType != 2) {
	cout << "Sorry, that's not one of the available options." << endl;
	cout << "Please enter 1 for title, or 2 for year." << endl;
	cout << endl;
      }
    }

    //Start search loop (until they find something or want to quit search)
    while(!foundResult) {
      //Ask them to give the value they want to use for their database search
      if(searchType == 1) { //If they are searching by title, ask for the title
	cout << "What is the title of the media you're searching for?" << endl;
	cin.getline(title, 31);
	cout << endl;
	
      } else { //If they are searching by year, ask for the year
	cout << "What is the year the media you're searching for released?" << endl;
	cout << "(positive numbers as A.D., negative as B.C.)" << endl;
	cin >> year;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
      }
      
      //Check for everything in the student list vector and print each out
      for(vector<digitalMedia*>::iterator it = database.begin(); it != database.end(); it++) {
	if((searchType == 1 && strcmp((*it) -> getTitle(), title)) || (searchType == 2 && (*it) -> getYear() == year)) {
	  //If a matching title was found, print out whole media class
	  //Based on the type it is
	  if((*it) -> getID() == 1) { //If the media is a videogame
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getRating() << endl;
	    
	  } else if((*it) -> getID() == 2) { //If the media is music
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getArtist() << ", ";
	    cout << (*it) -> getDuration() << endl;
	    
	  } else if((*it) -> getID() == 3) { //If the media is a movie
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getDirector() << ", ";
	    cout << (*it) -> getRating() << ", ";
	    cout << (*it) -> getDuration() << endl;
	  }
	  
	  foundResult = true;
	}
      }

      if(!foundResult) {
	cout << "Sorry, no results were found. Would you like to " << endl;
	cout << " try again with a different search term?" << endl;
	cout << "Enter 1 for yes, or 2 for no." << endl;

	while(searchAgain != 1 && searchAgain != 2) {
	  cin >> searchAgain;
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  
	  //If input is invalid
	  if(searchAgain != 1 && searchAgain != 2) {
	    cout << endl;
	    cout << "Sorry, that's not one of the available options." << endl;
	    cout << "Please enter 1 to search again, or 2 to exit." << endl;
	    cout << endl;
	  }
	}

	//Based on their input, continue search or exit
	if(searchAgain == 1) { //if they enter yes, go to start of loop again
	  //reset variables
	  searchAgain = 0;
	  for(int i = 0; i < 31; i++) {
	    title[i] = '\0';
	  }
	  year = 0;
	} else {
	  foundResult = true;
	}
      }
    }
  }
  
  cout << endl;
}
