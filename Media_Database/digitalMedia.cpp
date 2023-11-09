#include <iostream>
#include <cstring>
#include "digitalMedia.h"

//digital Media class constructor
digitalMedia::digitalMedia(char* titleInput, int yearInput) {
  //On construction, set variables based on parameters
  strcpy(title, titleInput);
  year = yearInput;
}

//title getter function
char* digitalMedia::getTitle() {
  return title;
}

//year getter function
int digitalMedia::getYear() {
  return year;
}

//year setter function
void digitalMedia::setYear(int newYear) {
  year = newYear;
}
