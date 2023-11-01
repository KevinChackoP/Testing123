#include <iostream>
#include <cstring>
#include "parent.h"

class music : public digitalMedia {
 public:
  music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput);
  char* getTitle();
  //Don't need a setter for title, it will be passed in by reference
  char* getArtist();
  //Don't need a setter for artist, it will be passed in by reference
  int getYear();
  void setYear(int newYear);
  char* getPublisher();
  //Don't need a setter for publisher, it will be passed in by reference
  int getDuration();
  void setDuration(int newDuration);
 protected:
  char* title;
  char* artist;
  int year;
  char* publisher;
  int duration;
};
