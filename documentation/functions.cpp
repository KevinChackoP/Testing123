#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//function prototypes
float pow(float a, int x);

//start of main function
int main() {
  float number = 3.0;
  int power = 2;
  float result = pow(number, power);
  cout << "Number is: " << number << endl;
  cout << "Answer is: " << result << endl;

  //If nothing went bad, return 0
  return 0;
}

//This function raises a number to the power of an exponent
float pow(float a, int x) {
  float answer = a;
  for(int i = 0; i < x - 1; i++) {
    answer = answer * a;
  }

  //Even if we do this, the variables going into the parameters will revert
  //back to what they were beforehand
  a = 27.0;
  
  return answer;
}
