#include <iostream>
#include <cstring>
#include "digitalMedia.h"

class movie : public digitalMedia {
 public:
  movie(char* titleInput, char* directorInput, int yearInput, int ratingInput, int durationInput);
  ~movie();
  char* getTitle();
  int getYear();
  char* getDirector();
  int getRating();
  int getDuration();
  int getID();
 protected:
  char* title;
  char* director;
  int year;
  int rating;
  int duration;
  int id;
};
