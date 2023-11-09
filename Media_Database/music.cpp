#include <cstring>
#include "music.h"

//constructor for music child class
music::music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput) : digitalMedia(titleInput, yearInput) {
  //On construction, set each of the variables to the corresponding parameters
  strcpy(title, titleInput);
  strcpy(artist, artistInput);
  year = yearInput;
  strcpy(publisher, publisherInput);
  duration = durationInput;
}

//getter function for title
char* music::getTitle() {
  return title;
}

//getter function for artist
char* music::getArtist() {
  return artist;
}

//getter function for year
int music::getYear() {
  return year;
}

//setter function for year
void music::setYear(int newYear) {
  year = newYear;
}

//getter function for publisher
char* music::getPublisher() {
  return publisher;
}

//getter function for duration
int music::getDuration() {
  return duration;
}

//setter function for duration
void music::setDuration(int newDuration) {
  duration = newDuration;
}
