#include <cstring>
#include "videoGame.h"

//contructor for videoGame child class
videoGame::videoGame(char* titleInput, int yearInput, char* publisherInput, int ratingInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  title = titleInput;
  year = yearInput;
  publisher = publisherInput;
  rating = ratingInput;
}

//getter function for title
char* videoGame::getTitle() {
  return title;
}

//getter function for year
int videoGame::getYear() {
  return year;
}

//setter function for year
void videoGame::setYear(int newYear) {
  year = newYear;
}

//getter function for publisher
char* videoGame::getPublisher() {
  return publisher;
}

//getter function for rating
int videoGame::getRating() {
  return rating;
}

//setter function for rating
void videoGame::setRating(int newRating) {
  rating = newRating;
}
