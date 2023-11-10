//imports
#include <iostream>
#include <cstring>
#include "digitalMedia.h"

//start of video game child class of digital media parent class
class videoGame : public digitalMedia {
 public:
  //Public variables and functions open for use
  videoGame(char* titleInput, int yearInput, char* publisherInput, int ratingInput);
  ~videoGame();
  char* getPublisher();
  int getRating();
  int getID();
 protected:
  //secured variables that can't be changed or used outside of class
  char* title;
  int year;
  char* publisher;
  int rating;
  int id;
};
