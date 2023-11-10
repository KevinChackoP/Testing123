//imports
#include <iostream>
#include <cstring>
#include "digitalMedia.h"

//start of music child class of digital media parent class
class music : public digitalMedia {
 public:
  //Public variables and functions open for use
  music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput);
  ~music();
  char* getArtist();
  char* getPublisher();
  int getDuration();
  int getID();
 protected:
  //secured variables that can't be changed or used outside of class
  char* title;
  char* artist;
  int year;
  char* publisher;
  int duration;
  int id;
};
