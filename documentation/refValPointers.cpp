#include <iostream>
using namespace std;

void intByValue(int paramVar);
void intByReference(int & paramVar);
void intPtrByValue(int * paramVar);
void intPtrByReference(int * & paramVar);

int main() {
  int localVar = 2;
  int *ptrVar = &localVar;
  cout << "Local: " << localVar << endl;
  cout << "Pointer: " << *ptrVar << endl;
  cout << "Pointer address: " << ptrVar << endl << endl;
  intByValue(localVar);
  cout << "After intByValue: " << localVar << endl << endl;
  intByReference(localVar);
  cout << "After intByReference: " << localVar << endl << endl;
  intPtrByValue(ptrVar);
  cout << "After intPtrByValue: " << *ptrVar << endl;
  cout << "Pointer address: " << ptrVar << endl << endl;
  intPtrByReference(ptrVar);
  cout << "After intPtrByReference: " << *ptrVar << endl;
  cout << "Pointer address: " << ptrVar << endl;

  //If everything went well, return 0
  return 0;
}

void intByValue(int paramVar) {
  cout << "Parameter value: " << paramVar << endl;
  paramVar = 3;
  cout << "Parameter after change: " << paramVar << endl;
}

void intByReference(int & paramVar) {
  cout << "Parameter value: " << paramVar << endl;
  paramVar = 4;
  cout << "Parameter after change: " << paramVar << endl;
}

void intPtrByValue(int* paramVar) {
  cout << "Parameter value: " << *paramVar << endl;
  cout << "Parameter address: " << paramVar << endl;
  *paramVar = 5;
  paramVar = new int(6);
  cout << "Parameter value: " << *paramVar << endl;
  cout << "Parameter address: " << paramVar << endl;
}

void intPtrByReference(int * & paramVar) {
  cout << "Parameter value: " << *paramVar << endl;
  cout << "Parameter address: " << paramVar << endl;
  *paramVar = 7;
  paramVar = new int(8);
  cout << "Parameter value: " << *paramVar << endl;
  cout << "Parameter address: " << paramVar << endl;
}
