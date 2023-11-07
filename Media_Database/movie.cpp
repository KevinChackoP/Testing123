#include <cstring>
#include "movie.h"

//constructor for music child class
movie::movie(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  director = directorInput;
  rating = ratingInput;
  duration = durationInput;
}

//title getter function
char* movie::getTitle() {
  return title;
}

//getter function for director
char* movie::getDirector() {
  return director;
}

//year getter function
int movie::getYear() {
  return year;
}

//year setter function
void movie::setYear(int newYear) {
  year = newYear;
}

//getter function for rating
int movie::getRating() {
  return rating;
}

//setter function for rating
void movie::setRating(int newRating) {
  rating = newRating;
}

//getter function for duration
int movie::getDuration() {
  return duration;
}

//setter function for duration
void movie::setDuration(int newDuration) {
  duration = newDuration;
}
