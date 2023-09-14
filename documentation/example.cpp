#include <iostream>
#include<math.h>
#include<cstring>

using namespace std;

int main() {
  //Math Stuff
  int input = 0;
  int input2 = 0;
  int input3 = 0;

  cout << "Please input your first number." << endl;
  cin >> input;
  cout << "You entered: " << input << endl;
  input = input + 5;
  cout << "add 5: " << input << endl;
  input = input - 3;
  cout << "subtract 3: " << input << endl;
  input = input * 3;
  cout << "multiply 3: " << input << endl;
  input = input / 3;
  cout << "divide 3: " << input << endl;
  input = pow(input, 2);
  cout << "raise to the second power: " << input << endl;
  input = input % 3;
  cout << "find the modulus of 3: " << input << endl;
  input += 1;
  cout << "Add 1: " << input << endl;
  input -= 1;
  cout << "Subtract 1: " << input << endl;
  input *= 2;
  cout << "Multiply by 2: " << input << endl;
  input /= 2;
  cout << "Divide by 2: " << input << endl;

  cout << endl;
  cout << "Please input your second number." << endl;
  cin >> input2;
  cout << "Your second input: " << input2++ << endl;
  cout << input2 << endl;

  cout << endl;
  cout << "Please input your third number." << endl;
  cin >> input3;
  cout << "Your third input: " << ++input3 << endl;
  cout << input3 << endl;

  //Formatting Output
  cout << endl;
  float input4 = 1.2000;
  cout.setf(ios::showpoint);
  //cout.precision(3);
  cout << input4 << endl;
  cout.unsetf(ios::showpoint);
  cout << input4 << endl;

  cout << endl;
  float input5 = 100.2000;
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "$" << input5 << endl;

  //Conditionals
  cout << endl;
  cout << "Please input a 3 or 4." << endl;
  int input6 = 0;
  cin >> input6;
  if(input6 == 3) {
    cout << "You inputted a 3!" << endl;
    input++;
  } else if(input6 == 4) {
    cout << "You inputted a 4!" << endl;
  } else {
    cout << "You didn't put in a 3 or 4!" << endl;
  }

  int input7 = 0;
  cout << endl;
  cout << "Please input a 5 or 6" << endl;
  cin >> input7;
  switch(input7) {
  case 5: cout << "You put in a 5!" << endl;
    break;
  case 6: cout << "You put in a 6!" << endl;
    break;
  default: cout << "You didn't input a 5 or 6!" << endl;
    break;
  }

  int input8 = 0;
  cout << endl;
  cout << "Please input an 8 or something greater than or equal to 13." << endl;
  cin >> input8;
  if(input8 == 8 || input8 >= 13) {
    cout << "You inputted 8 or something greater than or equal to 13!" << endl;
  }

  int input9 = 0;
  cout << endl;
  cout << "Please DON'T input 4" << endl;
  cin >> input9;
  if(input9 != 4 && input9 != 8) {
    cout << "Good Job!" << endl;
  } else if(!(input9 == 4) && input9 == 8) {
    cout << "You inputted an 8... but at least it's not a 4." << endl;
  } else {
    cout << "Why?" << endl;
  }

  //Loops
  cout << endl;
  int input10 = 0;
  cout << "You are now in a while loop. Please input a number." << endl;
  //Note that if the condition in the while loop isn't met on the first run
  //It won't be run through at all
  while(input10 != 5) {
    cin >> input10;
    cout << "Your input was: " << input10 << endl;
    if(input10 == 5) {
      cout << "Nice, your input is a 5!" << endl;
    } else {
      cout << "Could you input a 5?" << endl;
    }
  }

  cout << endl;
  int input11 = 0;
  cout << "You are now entering a do-while loop. Please input a number." << endl;
  do {
    cin >> input11;
    cout << "You inputted: " << input11 << endl;
    if(input11 <= 3) {
      cout << "Your input was less than or equal to 3, you may continue." << endl;
    } else {
      cout << "Your input was greater than three. Could you input something less than or equal to three?" << endl;
    }
  } while (input11 > 3);

  cout << endl;
  int input12 = 0;
  cout << "Before loop: " << input12 << endl;
  while(input12 <= 5) {
    cout << "In loop: " << input12 << endl;
    input12++;
  }
  cout << "After loop: " << input12 << endl;

  cout << endl;
  cout << "Now entering for loop." << endl;
  for(int input13 = 0; input13 <= 5; input13++) {
    cout << "In for loop: " << input13 << endl;
  }
  //Remember that the variable in the for loop if initialized there will go after the for loop. If its defined before just set a value to it before the loop.

  cout << endl;
  char ch = 'a';
  cout << "This is a char variable: " << ch << endl;

  cout << endl;
  char str[5];
  cout << "Please enter a 5 letter or less string" << endl;
  cin >> str;
  cout << "You entered: " << str << endl;
  //Keep in mind the C++ doesn't recognize out of bounds errors and will keep going through a string until it finds '\0'. This can ruin your data.
  //Thankfully cin will automatically do this for you

  //This is something to be careful of when looking at inputs
  cout << endl;
  char str2[20];
  char str3[20];
  cout << "Please enter two words with a space between them" << endl;
  cin >> str2;
  cin >> str3;
  cout << "Variable 1: " << str2 << endl;
  cout << "Variable 2: " << str3 << endl;
  //Basically cin ends at the first white space, which in this case is a space

  //To include spaces in your string, use cin.get, and to prevent cin from just getting skipped over make sure to ignore enters
  cout << endl;
  char str4[20];
  cout << "Please enter two words with a space between." << endl;
  /*
    To see how this works check out the tutorialspoint article "What is the use of cin.ignore() in C++"
    URL: https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
   */
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get(str4, 20);
  cin.get(); //Here to get rid of return character at end
  cout << "The one output for the one input: " << str4 << endl;

  //For string comparisons use <cstring> and strcmp
  cout << endl;
  char str5[20];
  char str6[20];
  cout << "Enter one string for comparison." << endl;
  cin.get(str5, 20);
  cin.get();
  cout << "Enter another string for comparison." << endl;
  cin.get(str6, 20);
  cin.get();
  if(strcmp(str5, str6) == 0) {
    cout << "The two strings are the same!" << endl;
  } else {
    cout << "The two strings are not the same!" << endl;
  }

  //For copying one string into another use strcpy
  //DO NOT DO str1 = str2, that will make str1 point to str2 always and it is equal to str2 always, even when str2 changes
  char str7[20];
  char str8[20];
  cout << "Please input two strings seperately." << endl;
  cin.get(str7, 20);
  cin.get();
  cin.get(str8, 20);
  cin.get();
  cout << "Your first string: " << str7 << endl;
  cout << "Your second string: " << str8 << endl;
  cout << "Now lets copy the second one into the first one!" << endl;
  strcpy(str7, str8);
  cout << "Your first string: " << str7 << endl;
  cout << "Your second string: " << str8 << endl;
  
  //end code if everything worked
  return 0;
}
