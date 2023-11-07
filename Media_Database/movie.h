#include <iostream>
#include <cstring>
#include "digitalMedia.h"

class movie : public digitalMedia {
 public:
  movie(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput);
  char* getTitle();
  //Don't need a setter for title, it will be passed in by reference
  int getYear();
  void setYear(int newYear);
  char* getDirector();
  //Don't need a setter for director, it will be passed in by reference
  int getRating();
  void setRating(int newRating);
  int getDuration();
  void setDuration(int newDuration);
 protected:
  char* title;
  char* director;
  int year;
  int rating;
  int duration;
};
