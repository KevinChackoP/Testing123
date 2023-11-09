#include <cstring>
#include "videoGame.h"

//contructor for videoGame child class
videoGame::videoGame(char* titleInput, int yearInput, char* publisherInput, int ratingInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  publisher = publisherInput;
  rating = ratingInput;
  
  //Also set id to identify class
  id = 1;
}

//destructor for videoGame child class
videoGame::~videoGame() {
  delete title;
  delete publisher;
}

//getter function for title
char* videoGame::getTitle() {
  return title;
}

//getter function for year
int videoGame::getYear() {
  return year;
}

//getter function for publisher
char* videoGame::getPublisher() {
  return publisher;
}

//getter function for rating
int videoGame::getRating() {
  return rating;
}

//ID getter function
int videoGame::getID() {
  return id;
}
