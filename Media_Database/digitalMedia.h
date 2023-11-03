#ifndef DIGITAL_MEDIA_H
#define DIGITAL_MEDIA_H

#include <iostream>
#include <cstring>

class digitalMedia {
 public:
  digitalMedia(char* titleInput, int yearInput);
  virtual char* getTitle();
  //Don't need a setter for title, it will be passed in by reference
  virtual int getYear();
  virtual void setYear(int newYear);
 protected:
  char* title;
  int year;
};

#endif
