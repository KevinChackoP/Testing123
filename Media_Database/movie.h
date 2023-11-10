//imports
#include <iostream>
#include <cstring>
#include "digitalMedia.h"

//start of movie child class of digital media parent class
class movie : public digitalMedia {
 public:
  //Public variables and functions open for use
  movie(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput);
  ~movie();
  char* getDirector();
  int getRating();
  int getDuration();
  int getID();
 protected:
  //secured variables that can't be changed or used outside of class
  char* title;
  char* director;
  int year;
  int rating;
  int duration;
  int id;
};
