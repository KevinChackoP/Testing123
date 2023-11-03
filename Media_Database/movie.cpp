#include <cstring>
#include "movie.h"

//constructor for music child class
music::music(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput) {
  //On construction, set each of the variables to the corresponding parameters
  title = titleInput;
  director = directorInput;
  year = yearInput;
  rating = ratingInput;
  duration = durationInput;
}

//getter function for title
char* getTitle() {
  return title;
}

//getter function for director
char* getDirector() {
  return director;
}

//getter function for year
int getYear() {
  return year;
}

//setter function for year
void setYear(int newYear) {
  year = newYear;
}

//getter function for rating
int getRating() {
  return rating;
}

//setter function for rating
void setRating(int newRating) {
  rating = newRating;
}

//getter function for duration
int getDuration() {
  return duration;
}

//setter function for duration
void setDuration(int newDuration) {
  duration = newDuration;
}
