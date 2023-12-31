//imports
#include <cstring>
#include "movie.h"

//constructor for music child class
movie::movie(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  director = new char[16];
  strcpy(director, directorInput);
  rating = ratingInput;
  duration = durationInput;
  
  //Also set id to identify class
  id = 3;
}

//destructor for movie child class
movie::~movie() {
  delete title;
  delete director;
}

//getter function for director
char* movie::getDirector() {
  return director;
}

//getter function for rating
int movie::getRating() {
  return rating;
}

//getter function for duration
int movie::getDuration() {
  return duration;
}

//ID getter function
int movie::getID() {
  return id;
}
