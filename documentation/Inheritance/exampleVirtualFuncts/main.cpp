#include <iostream>

using namespace std;

//Normal classes
class Parent {
public:
  void printStuff() {
    cout << "I am a parent" << endl;
  }
};

class Child : public Parent {
public:
  void printStuff() {
    cout << "I am a child" << endl;
  }
};

class Sibling : public Parent {
public:
  void printStuff() {
    cout << "I am a sibiling" << endl;
  }
};

//Virtual Classes
class vParent {
public:
  virtual void printStuff() {
    cout << "I am a parent" << endl;
  }
};

class vChild : public vParent {
public:
  virtual void printStuff() {
    cout << "I am a child" << endl;
  }
};

class vSibling : public vParent {
public:
  virtual void printStuff() {
    cout << "I am a sibiling" << endl;
  }
};

int main() {
  Parent* p = new Parent();
  p->printStuff();
  cout << "Hello World!" << endl;
  delete p;

  cout << endl;
  
  Child* c = new Child();
  c->printStuff();
  Sibling* s = new Sibling();
  s->printStuff();
  cout << "Nice to meet you!" << endl;
  delete c;
  delete s;

  cout << endl;

  Child* child = new Child();
  Sibling* sibling = new Sibling();
  Parent* parent;
  parent = child;
  parent->printStuff();
  parent = sibling;
  parent->printStuff();
  //This prints out the parent's print stuff twice because the compilier
  //Sees that you are calling print stuff on a parent pointer so it only
  //looks at the parent class and not its children
  delete child;
  delete sibling;

  cout << endl;

  //Now lets try it with virtual functions
  vChild* vchild = new vChild();
  vSibling* vsibling = new vSibling();
  vParent* vparent;
  vparent = vchild;
  vparent->printStuff();
  vparent = vsibling;
  vparent->printStuff();
  //This prints out the vchild and vsibling printStuff functions because
  //Instead of basing what the variable is off of compile time (when the)
  //program is built, it bases it off of what to call while the program is
  //being run
  delete vchild;
  delete vsibling;
  
}
