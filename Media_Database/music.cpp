#include <cstring>
#include "music.h"

//constructor for music child class
music::music(char* titleInput, char* artistInput, int yearInput, char* publisherInput, int durationInput) {
  //On construction, set each of the variables to the corresponding parameters
  title = titleInput;
  artist = artistInput;
  year = yearInput;
  publisher = publisherInput;
  duration = durationInput;
}

//getter function for title
char* getTitle() {
  return title;
}

//getter function for artist
char* getArtist() {
  return artist;
}

//getter function for year
int getYear() {
  return year;
}

//setter function for year
void setYear(int newYear) {
  year = newYear;
}

//getter function for publisher
char* getPublisher() {
  return publisher;
}

//getter function for duration
int getDuration() {
  return duration;
}

//setter function for duration
void setDuration(int newDuration) {
  duration = newDuration;
}
