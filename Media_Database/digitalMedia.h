#ifndef DIGITAL_MEDIA_H
#define DIGITAL_MEDIA_H

#include <iostream>
#include <cstring>

class digitalMedia {
 public:
  digitalMedia(char* titleInput, int yearInput);
  char* getTitle();
  //Don't need a setter for title, it will be passed in by reference
  int getYear();
  void setYear(int newYear);
 protected:
  char* title;
  int year;
};

#endif
