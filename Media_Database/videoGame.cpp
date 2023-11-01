#include <cstring>
#include "videoGame.h"

//contructor for videoGame child class
videoGame::videoGame(char* titleInput, int yearInput, char* publisherInput, int ratingInput) {
  //On construction, set each of the variables to the corresponding parameters
  title = titleInput;
  year = yearInput;
  publisher = publisherInput;
  rating = ratingInput;
}

//getter function for title
char* getTitle() {
  return title;
}

//getter function for year
int getYear() {
  return year;
}

//setter function for year
void setYear(int newYear) {
  year = newYear;
}

//getter function for publisher
char* getPublisher() {
  return publisher;
}

//getter function for rating
int getRating() {
  return rating;
}

//setter function for rating
void setRating(int newRating) {
  rating = newRating;
}
