#include <cstring>
#include "music.h"

//constructor for music child class
music::music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  strcpy(artist, artistInput);
  strcpy(publisher, publisherInput);
  duration = durationInput;
  
  //Also set id to identify class
  id = 2;
}

//destructor for music child class
music::~music() {
  delete title;
  delete artist;
  delete publisher;
}

//getter function for artist
char* music::getArtist() {
  return artist;
}

//getter function for publisher
char* music::getPublisher() {
  return publisher;
}

//getter function for duration
int music::getDuration() {
  return duration;
}

//ID getter function
int music::getID() {
  return id;
}
