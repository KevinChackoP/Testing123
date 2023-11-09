#include <iostream>
#include <cstring>
#include "digitalMedia.h"

class videoGame : public digitalMedia {
 public:
  videoGame(char* titleInput, int yearInput, char* publisherInput, int ratingInput);
  ~videoGame();
  char* getTitle();
  int getYear();
  char* getPublisher();
  int getRating();
  int getID();
 protected:
  char* title;
  int year;
  char* publisher;
  int rating;
  int id;
};
