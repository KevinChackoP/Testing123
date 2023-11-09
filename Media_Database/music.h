#include <iostream>
#include <cstring>
#include "digitalMedia.h"

class music : public digitalMedia {
 public:
  music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput);
  ~music();
  char* getTitle();
  char* getArtist();
  int getYear();
  char* getPublisher();
  int getDuration();
  int getID();
 protected:
  char* title;
  char* artist;
  int year;
  char* publisher;
  int duration;
  int id;
};
