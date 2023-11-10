/* 
   This project creates a media database to which the user may type a command
   in in order to do things with the media database. They may add data to the
   database following the prompts for their inputs. They may search for data
   from the database by title or by year of the media. Lastly, they may delete
   data from the database also by searching by title or year of the media.
   When they are done they can type the quit command. 
   Author: Kevin Chacko
   Last Updated: 11/9/2023
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning c++ for this project from the 
  "Classes and Inheritance" module

  I also transferred a lot of my code from my Student list project 
  since it used a lot of the same logic and structure as this project. 

  I got help with deleting everything marked in my vector with the
  help of cplusplus doc's pages on the vector at function and the
  erase function.
  URL: https://cplusplus.com/reference/vector/vector/at/
  URL: https://cplusplus.com/reference/vector/vector/erase/
  The at function on vectors helped me pick out items in the
  vector at certain indexes. The erase doc's example showed me
  that to erase something with an index you can add that index
  to a .begin() call on the same vector (which turns the value
  into an iterator position).

  Additionally I'd like to thank Lucas for helping me with figuring out
  how to get cstrings into my classes. He recommended that I used char* as
  a parameter and that I don't use any setter functions. He also told me
  that to properly implement it into my code I'd need to use strcpy to get
  my passed in value into my protected class value.

  Lastly, I'd like to thank Mr. Galbraith for a lot of help with segFaults
  involving virtual functions and other problems involving syntax with all
  my classes!
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
      deleteMedia(mediaDatabase);
      
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
  cout << "In what whole number year was the media released?" << endl;
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
    addedMedia = new videoGame(title, year, publisher, rating);
  } else if(mediaTypeCode == 2) { // music
    addedMedia = new music(title, artist, year, publisher, duration);
  } else if(mediaTypeCode == 3) { // movie
    addedMedia = new movie(title, director, year, rating, duration);
  }
  
  //Add finalized digitalMedia pointer to the main vector (database).
  database.push_back(addedMedia);

  //delete heap data pointed to made in function
  delete title;
  delete publisher;
  delete director;
  delete artist;
}

//This function helps the user to delete media from the database
//using most of the same code from the search function below
void deleteMedia(vector<digitalMedia*> & database) {
  //If there is no media in the database, tell the user
  if(database.empty()) {
    cout << "Sorry, there is currently no media in the database!" << endl;
    cout << "Please try again after data has been ADDed." << endl;
  } else {
    //local variables
    int searchType = 0; //1 for title, 2 for year
    char* title = new char[31];
    for(int i = 0; i < 31; i++) {
      title[i] = '\0';
    }
    int year = 0;
    bool foundResult = false;
    int searchAgain = 0;
    vector<int> deleteMarking;
    int markConfirm = 0;
    
    //Ask for what they want to search by in order to delete items
    cout << "Do you want to delete items by title or year? " << endl;
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

    //Start delete loop (until they find something and verify that they want
    //to delete it or not, or until they want to get out of delete)
    while(!foundResult) {
      //Ask them to give the value they want to use to find and delete
      if(searchType == 1) { //If they are deleting by title, ask for the title
	cout << "What is the title of the media you want to delete?" << endl;
	cin.getline(title, 31);
	cout << endl;
	
      } else { //If they are deleting by year, ask for the year
	cout << "What is the release year of the media you want to delete?" << endl;
	cout << "(positive numbers as A.D., negative as B.C.)" << endl;
	cin >> year;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
      }
      
      //Check for everything in the student list vector and print each out
      //Before asking the user if they'd like to delete the item
      int index = 0;
      for(vector<digitalMedia*>::iterator it = database.begin(); it != database.end(); it++) {
	//If search term matches with one of the corresponding fields in
	//the classes in the media database...
	if((searchType == 1 && strcmp((*it) -> getTitle(), title) == 0) || (searchType == 2 && (*it) -> getYear() == year)) {
	  //If a matching title or year was found, print out whole media class
	  //Based on the type it is
	  if((*it) -> getID() == 1) { //If the media is a videogame
	    //header line
	    cout << "Video Game: " << endl;
	    cout << "TITLE, YEAR, PUBLISHER, RATING" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getRating() << endl;
	    cout << "---------------------------------------------" << endl;
	    
	  } else if((*it) -> getID() == 2) { //If the media is music
	    //header line
	    cout << "Music (duration in seconds): " << endl;
	    cout << "TITLE, YEAR, PUBLISHER, ARTIST, DURATION" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getArtist() << ", ";
	    cout << (*it) -> getDuration() << endl;
	    cout << "---------------------------------------------" << endl;
	    
	  } else if((*it) -> getID() == 3) { //If the media is a movie
	    //header line
	    cout << "Movie (duration in minutes): " << endl;
	    cout << "TITLE, YEAR, DIRECTOR, RATING, DURATION" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getDirector() << ", ";
	    cout << (*it) -> getRating() << ", ";
	    cout << (*it) -> getDuration() << endl;
	    cout << "---------------------------------------------" << endl;
	  }

	  //note that a result was found and function was sucessful
	  foundResult = true;

	  //ask the user if they'd like to delete the item
	  cout << "Are you sure you want to delete this media?" << endl;
	  cout << "Enter 1 for yes, or 2 for no." << endl;
	  //take and validate their input
	  while(markConfirm != 1 && markConfirm != 2) {
	    cin >> markConfirm;
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << endl;
	    
	    //If input is invalid
	    if(searchType != 1 && searchType != 2) {
	      cout << "Sorry, that's not one of the available options." << endl;
	      cout << "Please enter 1 for yes, or 2 for no." << endl;
	      cout << endl;
	    }
	  }
	  //based on their input delete or don't delete the item
	  if(markConfirm == 1) { //if they said yes, mark item for deletion
	    deleteMarking.push_back(index);
	  }

	  //change variables for next loop
	  markConfirm = 0;
	  index++;
	}
      }

      //If no results were found
      if(!foundResult) {
	//Ask them if they'd like to try deleting again
	cout << "Sorry, no results were found. Would you like to " << endl;
	cout << " try again with a different search term?" << endl;
	cout << "Enter 1 for yes, or 2 for no." << endl;

	//validate their answer input
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
	} else { //if the say no, exit the function
	  foundResult = true;
	}
      } else { //If a result was found, delete all the marked items
	while(!deleteMarking.empty()) {
	  /*
	    I got help with deleting everything marked in my vector with the
	    help of cplusplus doc's pages on the vector at function and the
	    erase function.
	    URL: https://cplusplus.com/reference/vector/vector/at/
	    URL: https://cplusplus.com/reference/vector/vector/erase/
	    The at function on vectors helped me pick out items in the
	    vector at certain indexes. The erase doc's example showed me
	    that to erase something with an index you can add that index
	    to a .begin() call on the same vector (which turns the value
	    into an iterator position).
	   */
	  delete database.at(deleteMarking.back());
	  database.erase(database.begin() + deleteMarking.back());
	  deleteMarking.pop_back();
	}
      }
    }

    //delete heap data pointed to made in function
    delete title;
  }
  
  cout << endl;
}

//This function helps the user to search for media in the database and print
//out media that matches with their search (based on title or year released)
void searchDatabase(vector<digitalMedia*> & database) {
  //If there is no media in the database, tell the user
  if(database.empty()) {
    cout << "Sorry, there is currently no media in the database!" << endl;
    cout << "Please try again after data has been ADDed." << endl;
  } else {
    //local variables
    int searchType = 0; //1 for title, 2 for year
    char* title = new char[31];
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
	//If search term matches with one of the corresponding fields in
	//the classes in the media database...
	if((searchType == 1 && strcmp((*it) -> getTitle(), title) == 0) || (searchType == 2 && (*it) -> getYear() == year)) {
	  //If a matching title or year was found, print out whole media class
	  //Based on the type it is
	  if((*it) -> getID() == 1) { //If the media is a videogame
	    //header line
	    cout << "Video Game: " << endl;
	    cout << "TITLE, YEAR, PUBLISHER, RATING" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getRating() << endl;
	    cout << "---------------------------------------------" << endl;
	    
	  } else if((*it) -> getID() == 2) { //If the media is music
	    //header line
	    cout << "Music (duration in seconds): " << endl;
	    cout << "TITLE, YEAR, PUBLISHER, ARTIST, DURATION" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getPublisher() << ", ";
	    cout << (*it) -> getArtist() << ", ";
	    cout << (*it) -> getDuration() << endl;
	    cout << "---------------------------------------------" << endl;
	    
	  } else if((*it) -> getID() == 3) { //If the media is a movie
	    //header line
	    cout << "Movie (duration in minutes): " << endl;
	    cout << "TITLE, YEAR, DIRECTOR, RATING, DURATION" << endl;
	    cout << "---------------------------------------------" << endl;
	    //database information
	    cout << (*it) -> getTitle() << ", ";
	    cout << (*it) -> getYear() << ", ";
	    cout << (*it) -> getDirector() << ", ";
	    cout << (*it) -> getRating() << ", ";
	    cout << (*it) -> getDuration() << endl;
	    cout << "---------------------------------------------" << endl;
	  }

	  //note that a result was found and function was sucessful
	  foundResult = true;
	}
      }

      //If no results were found
      if(!foundResult) {
	//Ask them if they'd like to search again
	cout << "Sorry, no results were found. Would you like to " << endl;
	cout << " try again with a different search term?" << endl;
	cout << "Enter 1 for yes, or 2 for no." << endl;

	//validate their answer input
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
	} else { //if the say no, exit the function
	  foundResult = true;
	}
      }
    }

    //delete heap data pointed to made in function
    delete title;
  }
  
  cout << endl;
}
