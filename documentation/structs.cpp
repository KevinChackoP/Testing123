#include <iostream>

using namespace std;

//Just like objects and object oriented design!
struct Student {
  char name[10];
  int id;
  float gpa;
};

//Main function of program
int main() {
  Student george;
  //to go inside the struct and access its variables just put the name of the
  //struct first then a period after before putting its key to access its value
  cout << "What is George's name?" << endl;
  cin >> george.name;
  george.id = 1234;
  george.gpa = 3.0;
  cout << "Name: " << george.name << ", ID: " << george.id << ", GPA: ";
  cout << george.gpa << endl;
}
