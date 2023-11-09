#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

//digital Media class constructor
digitalMedia::digitalMedia(char* titleInput, int yearInput) {
  //On construction, set variables based on parameters
  title = new char[31];
  strcpy(title, titleInput);
  year = yearInput;

  //Also set id to identify class
  id = 0;
}

//digital Media class deconstructor
digitalMedia::~digitalMedia() {
  delete title;
}

//title getter function
char* digitalMedia::getTitle() {
  return title;
}

//year getter function
int digitalMedia::getYear() {
  return year;
}

//publisher getter function
char* digitalMedia::getPublisher() {
  return NULL;
}

//artist getter function
char* digitalMedia::getArtist() {
  return NULL;
}

//director getter function
char* digitalMedia::getDirector() {
  return NULL;
}

//rating getter function
int digitalMedia::getRating() {
  return 0;
}

//duration getter function
int digitalMedia::getDuration() {
  return 0;
}

//ID getter function
int digitalMedia::getID() {
  return id;
}
