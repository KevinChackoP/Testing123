#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//function prototypes
float pow(float a, int x);
float powReference(float & a, int x);
void swap(int & a, int & b);

//Global variables (can be used by all functions, avoid using these!)
char input[80];

//start of main function
int main() {
  //local variables
  float number = 3.0;
  int power = 2;

  //passing by value
  float result = pow(number, power);
  cout << "Number is: " << number << endl; //number isn't changed by function
  cout << "Answer is: " << result << endl;

  //passing by reference
  result = powReference(number, power);
  cout << "Number is: " << number << endl; //number is changed by function
  cout << "Answer is: " << result << endl;

  //Swap example
  int george = 7, fred = 3;
  cout << "Before swap: george = " << george << ", fred = " << fred << endl;
  swap(george, fred);
  cout << "After swap: george = " << george << ", fred = " << fred << endl;
  //This is something that you are only capable of doing by passing by reference

  //If nothing went bad, return 0
  return 0;
}

//This function raises a number to the power of an exponent
float pow(float a, int x) { //Parameters are passing by value
  float answer = a;
  for(int i = 0; i < x - 1; i++) {
    answer = answer * a;
  }

  //Even if we do this, the parameter is a copy local variable for this
  //function so this doesn't affect what was passed into it
  a = 27.0;

  //if your function is of a variable type make sure to return something
  //if it is void just put "return;"
  return answer;
}

//This function is the power function, but it passes by reference!
float powReference(float & a, int x) { //through using the &, we are passing
  //in the actual variable as a value, and any changes we make to it in this
  //function will actually also effect it in the function it is local to!
  float answer = a;
  for(int i = 0; i < x - 1; i++) {
    answer = answer * a;
  }

  a = 27.0;
  return answer;
}

//This function swaps the memory places of the two integers
void swap(int & a, int & b) { //Uses passing by reference to do this!
  int temp = a;
  a = b;
  b = temp;
};
