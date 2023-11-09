#ifndef DIGITAL_MEDIA_H
#define DIGITAL_MEDIA_H

#include <iostream>
#include <cstring>

class digitalMedia {
 public:
  digitalMedia(char* titleInput, int yearInput);
  ~digitalMedia();
  virtual char* getTitle();
  virtual int getYear();
  virtual char* getPublisher();
  virtual char* getArtist();
  virtual char* getDirector();
  virtual int getRating();
  virtual int getDuration();
  virtual int getID();
 protected:
  char* title;
  int year;
  int id;
};

#endif
