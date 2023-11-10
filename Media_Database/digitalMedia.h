//Implement a header guard
#ifndef DIGITAL_MEDIA_H
#define DIGITAL_MEDIA_H

//Add imports
#include <iostream>
#include <cstring>

//start of parent digital media class
class digitalMedia {
 public:
  //Public variables and functions open for use
  digitalMedia(char* titleInput, int yearInput);
  ~digitalMedia();
  char* getTitle();
  int getYear();
  virtual char* getPublisher();
  virtual char* getArtist();
  virtual char* getDirector();
  virtual int getRating();
  virtual int getDuration();
  virtual int getID();
 protected:
  //secured variables that can't be changed or used outside of class
  char* title;
  int year;
  int id;
};
//End of header guard
#endif
