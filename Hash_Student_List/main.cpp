/* 
   This project creates a student list using a hash table that the user
   can interact with. The program will give the user instructions on
   how to use it and prompt the user to enter a command telling the
   program to do something. The user can add a student to the list,
   specifying what the student's first and last name is, what their
   assigned 6 number id is, and what the student's gpa is. They can
   also remove a student from the list by entering the student's id,
   print the whole list out, generate random students to add to the
   list, or quit the program. The program uses a hash table and function
   to work with the data. The adding student, deleting student, and adding
   generated students function use the hash function to properly store
   the student into the right slot in the hash table. If more than one
   student fits a slot, they'll be chained in a linked list. If any
   of the slots in the hash table has more than 3 students in the
   linked list, the whole table will be rehashed to have double the
   number of slots. When the user is done using the program, all
   the slots in the hash table will be deleted and the program will end. 
   Author: Kevin Chacko
   Last Updated: 2/8/2024
   Period 6, C++ / Data Structures
*/

/*
  I got a lot of help with learning what a hash table is from the 
  "Hash Table" module

  I got the structure for this whole program from my Student list project. 
  I used this as the base and modified that program to instead use a hash 
  table such that it would be more efficient. 

  For getting help with reading in from a file I got help from W3Schools' 
  article on "C++ Files"
  URL: https://www.w3schools.com/cpp/cpp_files.asp
  This showed me how to read in inputs from a file. More specifically, it 
  showed me that by using ifstream and a while loop I can read through each 
  line in a file and use it in my program. With a recommendation from 
  Mr. Galbraith, I can use this to put all the names into a vector which I can 
  then pull from randomly to generate students. 

  Also for getting help with reading in from a file I got help from 
  Mr. Galbraith.
  He gave me sample code to use for a file line by line reader which 
  doesn't require a String and can instead input into a cstring 
  using the >>.

  I got help with transferring cstrings into integers from
  Cplusplus's article on "atoi".
  URL: https://cplusplus.com/reference/cstdlib/atoi/
  This is useful for getting the number value of the student's ID of 
  which I want to use for my hash function key.  

  To get help with generating random number values to use for my
  random student generator, Mr. Galbraith recommended that I looked
  into rand() and srand() which I found cplusplus articles on.
  URL: https://cplusplus.com/reference/cstdlib/srand/
  URL: https://cplusplus.com/reference/cstdlib/rand/
  Srand makes it so that I can make a random seed that rand can pull
  from multiple times and get various different random numbers. This
  is great for me since I can use this for picking random names in my
  names vectors and generate a random id and gpa with the help of the
  modulus (%) operator. 
  
  In order to convert a random number into a cstring for my student 
  id formatting I got help from cplusplus's page on itoa.
  URL: https://cplusplus.com/reference/cstdlib/itoa/
  This is the inverse of atoi converting the inputted integer into a 
  string in the numerical base of your choice. This is useful since I 
  can just pass in a random int into my id to get a randomly generated 
  id. However, this didn't work since the function is a bit funky with 
  what compilers will accept it. So instead I used the alternative they 
  recommended which was sprintf(str, "%d", int).
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

//struct declarations
struct Student {
  char firstName[16];
  char lastName[16];
  char id[7];
  float gpa;
};

struct Node {
  Student* student;
  Node* next = NULL;
};

//Function prototypes
void instructions();
int askCommand();
void addStudent(Node** & table, int & hashLength);
void printList(Node** & table, int & hashLength);
void deleteStudent(Node** & table, int & hashLength);
int hashFunction(char* id, int & hashLength);
void growTable(Node** & table, int & hashLength);
void generateStudents(Node** & table, int & hashLength, vector<char*> & firstNames, vector<char*> & lastNames);

//Start of main function
int main() {
  //local variable declarations
  vector<char*> firstNames;
  /*
    For this section I got help from Mr. Galbraith.
    He gave me the following sample code to use for a file line by line 
    reader which doesn't require a String and can instead input into a 
    cstring using the >>.
   */
  ifstream fin("firstNames.txt");
  char* fileInput = new char[16];
  while(fin >> fileInput) {
    char* tmp = new char[16];
    strcpy(tmp, fileInput);
    firstNames.push_back(tmp);
  }
  fin.close();
  vector<char*> lastNames;
  ifstream fin2("lastNames.txt");
  while(fin2 >> fileInput) {
    char* tmp = new char[16];
    strcpy(tmp, fileInput);
    lastNames.push_back(tmp);
  }
  fin2.close();
  bool inUse = true;
  int commandKey = 0;
  int tableLength = 100;
  Node** studentTable = new Node*[tableLength];
  for(int i = 0; i < tableLength; i++) {
    //Set everything in the hash table to null
    studentTable[i] = NULL;
  }
  
  //Tell them how the program works
  instructions();

  //Put them through the loop of interacting with the list until
  //they are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something to the list or quit from the program
    if(commandKey == 1) {
      //If they want to add a student to the list, do so
      cout << "Adding a student to list." << endl;
      cout << endl;
      addStudent(studentTable, tableLength);
      
    } else if(commandKey == 2) {
      //If they want to delete a student from the list, do so
      cout << "Deleting a student from list." << endl;
      cout << endl;
      deleteStudent(studentTable, tableLength);
      
    } else if(commandKey == 3) {
      //If they want to print out the list, do so
      cout << "Printing current student list out." << endl;
      cout << endl;
      printList(studentTable, tableLength);
      
    } else if(commandKey == 4) {
      //If they want to randomly generate students into list, do so
      cout << "Generating new students to add to list." << endl;
      cout << endl;
      generateStudents(studentTable, tableLength, firstNames, lastNames);
      
    } else if(commandKey == 5) {
      //If they want to quit the program, do so
      cout << "Ok then, have a good day!" << endl;

      //delete everything on the heap from my hash table
      for(int i = 0; i < tableLength; i++) {
	//check to see if there is anything in the hash table slot
	if(studentTable[i] != NULL) {
	  do {
	    //if so, delete every node in the linked list in that slot
	    Node* placeholder = studentTable[i];
	    studentTable[i] = studentTable[i] -> next;
	    delete placeholder;
	  } while(studentTable[i] != NULL);
	}
      }

      //change the boolean that determines if the program continues
      inUse = false;
    }
  }
  
  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program that can keep track of students in a class" << endl;
  cout << "using a list! You can use various commands to interact with the list." << endl;
  cout << "That is to say, you can add students to the list, print out the list, " << endl;
  cout << "delete students from the list, randomly generate new students into the" << endl;
  cout << "list, or exit out of the program. I hope this program is of use to you!" << endl;
  cout << endl;
}

//This function asks the user for their command
int askCommand() {
  //make an input array and clean it up
  char input[10];
  for(int i = 0; i < 10; i++) {
    input[i] = '\0';
  }

  //Tell them how to input a command and what each of the commands do
  cout << "Please input a command to tell me what you want to do." << endl;
  cout << "Input ADD for adding a new student to the list." << endl;
  cout << "Input DELETE to delete a student from the list." << endl;
  cout << "Input PRINT to print out the current list of students." << endl;
  cout << "Input GENERATE randomly generate new students to the list." << endl;
  cout << "Input QUIT to exit the program." << endl;
  cout << endl;

  //ask them for a command input, if the input is valid return an int for the
  //command key, if invalid have them reinput their desired command.
  while(true) {
    //Ask for input
    cin.get(input, 10);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Clean input up by making it all upper case
    for(int i = 0; i < 10; i++) {
      input[i] = toupper(input[i]);
    }

    //return the corresponding command key to their command
    if(strcmp(input, "ADD") == 0) {
      return 1;
    } else if(strcmp(input, "DELETE") == 0) {
      return 2;
    } else if(strcmp(input, "PRINT") == 0) {
      return 3;
    } else if(strcmp(input, "GENERATE") == 0) {
      return 4;
    } else if(strcmp(input, "QUIT") == 0) {
      return 5;
    } else { //If their command is invalid, tell them and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADD, DELETE, PRINT, GENERATE, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function helps the user to add a student to the list
void addStudent(Node** & table, int & hashLength) {
  //These are a local variables being used
  Student* addedStudent = new Student();
  Node* newNode = new Node();
  char firstNameInput[16];
  char lastNameInput[16];
  for(int i = 0; i < 16; i++) {
    firstNameInput[i] = '\0';
    lastNameInput[i] = '\0';
  }
  char idInput[7];
  for(int i = 0; i < 7; i++) {
    idInput[i] = '\0';
  }
  char gpaInput1[5];
  for(int i = 0; i < 5; i++) {
    gpaInput1[i] = '\0';
  }
  float gpaInput2 = 10.00;

  //Take first name
  cout << "What's the student's first name?" << endl;
  cin.get(firstNameInput, 16);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //Add the first name to the pointer to the student struct
  strcpy((*addedStudent).firstName, firstNameInput);
  cout << endl;

  //Take last name
  cout << "What's the student's last name?" << endl;
  cin.get(lastNameInput, 16);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //Add the last name to the pointer to the student struct
  strcpy((*addedStudent).lastName, lastNameInput);
  cout << endl;

  //Get id and make sure that it is a 6 digit integer
  cout << "What's the student's id number (6 number integer)?" << endl;
  while(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
    cin.get(idInput, 7);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    //If the whole id isn't just numbers, let the user know they made a mistake
    if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
      cout << endl;
      cout << "You didn't enter a 6 digit integer." << endl;
      cout << "Could you try inputting the id again?" << endl;
      cout << "(i.e. 464877, 342907)" << endl;
      cout << endl;
    }
  }
  //Add the id to the pointer to the student struct
  strcpy((*addedStudent).id, idInput);
  cout << endl;

  //get student GPA and make sure that it is a two decimal number
  cout << "Please input the student's GPA to 2 decimal places (i.e. 3.00)." << endl;
  while((isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) || (gpaInput2 > 5.00 || gpaInput2 < 0.00)) {
    cin.get(gpaInput1, 5);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //If the user didn't enter a string with one leading number, a decimal
    //point, and two trailing numbers, tell them they need to do it again
    if(isdigit(gpaInput1[0]) == 0 || gpaInput1[1] != '.' || isdigit(gpaInput1[2]) == 0 || isdigit(gpaInput1[3]) == 0) {
      cout << "Your given gpa isn't in the corrent format of one leading " << endl;
      cout << "number, one decimal point, and two trailing numbers." << endl;
      cout << "(ie: 3.24, 4.22, 2.76, 3.00)" << endl;
      cout << "Could you please try inputting the gpa again?" << endl;
      
    } else { //If the gpa is in the right format, make sure it's in the range
      //transfer their string input into a float
      gpaInput2 = stof(gpaInput1);
      
      //If the gpa isn't a within 0.00 and 5.00 let the user know the gpa isn't
      //a valid gpa
      if(gpaInput2 > 5.00 || gpaInput2 < 0.00) {
	cout << endl;
	cout << "Sorry, the two decimal place gpa is either over 5.00" << endl;
	cout << "(5.00 is max weighted gpa) or is under 0.00 (gpa must " << endl;
	cout << "be positive or zero). Could you enter the student's " << endl;
	cout << "gpa again? (i.e. 2.34, 4.14, 3.59...)" << endl;
	cout << endl;
      }
    }
  }
  //Add the gpa to the pointer to the student struct
  (*addedStudent).gpa = gpaInput2;
  cout << endl;
  
  //When finished checking all the inputs and putting them all in, add the
  //finalized student pointer into a node
  newNode -> student = addedStudent;

  //Add the node into the correct place in the hash table
  Node* current = table[hashFunction(addedStudent -> id, hashLength)];
  if(current == NULL) {
    //If the first node of the linked list in the table is null set the new
    //node as the first node (use table itself because current is a copy of
    //the address in the table and we need to change the address in table)
    table[hashFunction(addedStudent -> id, hashLength)] = newNode;
    
  } else {
    int newLinkCount = 1;
    
    //Iterate through the linked list in the table until the next node is null
    while(current -> next != NULL) {
      newLinkCount++;
      current = current -> next;
    }

    //set the next pointer of the last node of the linked list to the new node
    //and make the new last node the new node
    current -> next = newNode;

    //Check to see if there are more than 3 collisions, and if so make the
    //linked list bigger
    if(newLinkCount >= 3) {
      growTable(table, hashLength);
    }
  }
}

//This function helps the user to delete a student from the list
void deleteStudent(Node** & table, int & hashLength) {
  //local variables for function
  char idInput[7];
  for(int i = 0; i < 7; i++) {
    idInput[i] = '\0';
  }
  bool matchingIdFound = false;

  //ask user for the id of the student they want to remove from the list
  //and make sure the inputted id is valid and matches a student
  cout << "What's the id of the student you want to remove from the list?" << endl;
  cout << "Please make it a 6 digit integer like before (i.e. 464877)." << endl;
  while((isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) || !matchingIdFound) {
    cin.get(idInput, 7);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Do something with their input or give them feedback on their input
    if(strcmp(idInput, "Exit") == 0 || strcmp(idInput, "exit") == 0 || strcmp(idInput, "EXIT") == 0) {
      //Does the user want to quit, if so, exit the function
      cout << endl;
      return;

    } else if(isdigit(idInput[0]) == 0 || isdigit(idInput[1]) == 0 || isdigit(idInput[2]) == 0 || isdigit(idInput[3]) == 0 || isdigit(idInput[4]) == 0 || isdigit(idInput[5]) == 0) {
      //If the whole id isn't just numbers, let the user know they
      //made a mistake
      cout << endl;
      cout << "You didn't enter a 6 digit integer." << endl;
      cout << "Could you try inputting the student's id again?" << endl;
      cout << "(i.e. 464877, 342907)" << endl;
      cout << endl;
      
    } else { //Is there a matching student id in the list?
      Node* current = table[hashFunction(idInput, hashLength)];

      if(table[hashFunction(idInput, hashLength)] != NULL) {
	//If the head of the table linked list is the match, delete it
	//as a special case in which table needs to be directly accessed
	if(strcmp(current -> student -> id, idInput) == 0) {
	  matchingIdFound = true;
	  cout << "Removing student " << current -> student -> firstName << " " << current -> student -> lastName << " from list." << endl;
	  cout << endl;
	  
	  Node* placeholder = table[hashFunction(idInput, hashLength)];
	  table[hashFunction(idInput, hashLength)] = table[hashFunction(idInput, hashLength)] -> next;
	  delete placeholder;
	  
	} else {
	  //go through linked list in hash table looking for an id match
	  while(current -> next != NULL) {
	    if(strcmp(current -> next -> student -> id, idInput) == 0) {
	      //There's a match
	      matchingIdFound = true;
	      cout << "Removing student " << current -> next -> student -> firstName << " " << current -> next -> student -> lastName << " from list." << endl;
	      cout << endl;

	      Node* placeholder = current -> next;
	      current -> next = current -> next -> next;
	      delete placeholder;
	    } else {
	      current = current -> next;
	    }
	  }
	}
      }
      
      //If no match could be found after going through the whole linked list,
      //let the user know that the student they're looking for doesn't exist
      //before letting them try again
      if(!matchingIdFound) {
	cout << "Sorry, I couldn't find a student with that id in the list." << endl;
	cout << "This is what your current list is like:" << endl;
	//Show the user their current list so they can see the right id
	//of who they want to delete off the list
	cout << endl;
	printList(table, hashLength);
	cout << "Could you reinput the id of the student you want " << endl;
	cout << "to remove from the list?" << endl;
	cout << "Alternativally, if you don't want to delete anymore " << endl;
	cout << "just type \"exit\"." << endl;
	cout << endl;
      }
    }
  }
}

//This function helps the user to view their current student list by printing
//it out
void printList(Node** & table, int & hashLength) {
  //give a header to the list
  cout << "firstname lastname, id, gpa" << endl;
  cout << "---------------------------------------------------" << endl;
  
  //Set precision for floats so that they always show two digits after the
  //decimal point
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //Go through every slot in the hash table and print the student if there is
  //a node
  for(int i = 0; i < hashLength; i++) {
    //if slot has a linked list with existing nodes, go through
    //each node in list and print it out
    Node* current = table[i];
    while(current != NULL) {
      cout << current -> student -> firstName << " ";
      cout << current -> student -> lastName << ", ";
      cout << current -> student -> id << ", ";
      cout << current -> student -> gpa << endl;
      current = current -> next;
    }
  }
  cout << endl;
}

//This is the hash function for my hash table which uses the student id as
//its key
int hashFunction(char* id, int & hashLength) {
  /*
    I got help with transferring cstrings into integers from
    Cplusplus's article on "atoi".
    URL: https://cplusplus.com/reference/cstdlib/atoi/
    This is useful for getting the number value of the student's ID of 
    which I want to use for my hash function key.
  */
  int index = atoi(id);
  index = index % hashLength;

  //return the hashed index value
  return index;
}

//This function will make a new hash table double the length of the current
//hash table, and will rehash all of the old table's students into the new
//bigger table
void growTable(Node** & table, int & hashLength) {
  //local variables
  int newTableLength = hashLength * 2;
  Node** newTable = new Node*[newTableLength];
  for(int i = 0; i < newTableLength; i++) {
    //Set everything in the new hash table to null
    newTable[i] = NULL;
  }
  bool rehashAgain = false;

  //Go through each student in the old table and rehash them into the
  //new table
  for(int i = 0; i < hashLength; i++) {
    while(table[i] != NULL) {
      //If the old table slot contains a node make a placeholder node
      //and add it to the new table
      Node* placeholder = table[i];
      table[i] = table[i] -> next; //go to next node in linked list
      placeholder -> next = NULL;
      char* id = placeholder -> student -> id;
      Node* current = newTable[hashFunction(id, newTableLength)];
      
      if(current == NULL) {
	//If the first node of the slot in the new table is null
	//set the placeholder node as the head node of the slot
	newTable[hashFunction(id, newTableLength)] = placeholder;
	
      } else {
	int newLinkCount = 1;
	//Iterate through the linked list in the new table's slot until the
	//next node is null
	while(current -> next != NULL) {
	  newLinkCount++;
	  current = current -> next;
	}
	
	//set the next pointer of the last node of the linked list to the
	//placeholder node and make the new last node the placeholder node
	current -> next = placeholder;

	//Check to see if there are more than 3 collisions, and if so make the
	//linked list bigger again after rehashing is finished
	if(newLinkCount >= 3) {
	  rehashAgain = true;
	}
      }
    }
  }

  //set the new rehashed table as the current table and delete old table
  delete table;
  table = newTable;
  hashLength = newTableLength;

  //If there are still more than 3 collisions in the new hash table
  //rehash again
  if(rehashAgain) {
    growTable(table, hashLength);
  }
}

//This function will randomly generate students into the list
void generateStudents(Node** & table, int & hashLength, vector<char*> & firstNames, vector<char*> & lastNames) {
  //local variables
  int newStudentNumber = 0;
  /*
    To get help with generating random number values to use for my
    random student generator, Mr. Galbraith recommended that I looked
    into rand() and srand() which I found cplusplus articles on.
    URL: https://cplusplus.com/reference/cstdlib/srand/
    URL: https://cplusplus.com/reference/cstdlib/rand/
    Srand makes it so that I can make a random seed that rand can pull
    from multiple times and get various different random numbers. This
    is great for me since I can use this for picking random names in my
    names vectors and generate a random id and gpa with the help of the
    modulus (%) operator. 
  */
  srand(time(NULL));

  //Ask the user to input the number of students they want generated
  cout << "How many students would you like to generate?" << endl;
  cout << "(Please input only a positive, non-zero integer number)" << endl;
  cin >> newStudentNumber;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  //Randomly generate the desired number of students
  for(int i = 0; i < newStudentNumber; i++) {
    //new student variable declarations
    Student* addedStudent = new Student();
    Node* newNode = new Node();
    char firstName[16];
    char lastName[16];
    for(int i = 0; i < 16; i++) {
      firstName[i] = '\0';
      lastName[i] = '\0';
    }
    char id[7];
    float gpa = 0.00;

    //Assign random student values
    strcpy(firstName, firstNames.at(rand() % firstNames.size()));
    strcpy(lastName, lastNames.at(rand() % lastNames.size()));
    /*
      In order to convert a random number into a cstring for my student 
      id formatting I got help from cplusplus's page on itoa.
      URL: https://cplusplus.com/reference/cstdlib/itoa/
      This is the inverse of atoi converting the inputted integer into a 
      string in the numerical base of your choice. This is useful since I 
      can just pass in a random int into my id to get a randomly generated 
      id. However, this didn't work since the function is a bit funky with 
      what compilers will accept it. So instead I used the alternative they 
      recommended which was sprintf(str, "%d", int).
    */
    sprintf(id, "%d", rand() % 1000000);
    while(strlen(id) < 6) {
      //Make sure to add any needed leading zeros
      id[5] = id[4];
      id[4] = id[3];
      id[3] = id[2];
      id[2] = id[1];
      id[1] = id[0];
      id[0] = '0';
    }
    gpa = float(rand() % 1000) / 200.0;

    //Add the student attributes into the new student
    strcpy(addedStudent -> firstName, firstName);
    strcpy(addedStudent -> lastName, lastName);
    strcpy(addedStudent -> id, id);
    addedStudent -> gpa = gpa;

    //Add the new student into the new node, and add the new node into the
    //correct slot in the hash table
    newNode -> student = addedStudent;
    Node* current = table[hashFunction(addedStudent -> id, hashLength)];
    if(current == NULL) {
      //If the first node of the slot in the table is null set the new
      //node as the head node (use table itself because current is a copy of
      //the address in the table and we need to change the address in table)
      table[hashFunction(addedStudent -> id, hashLength)] = newNode;
    } else {
      int newLinkCount = 1;
      
      //Iterate through the linked list in the table slot until the next node
      //is null
      while(current -> next != NULL) {
	newLinkCount++;
	current = current -> next;
      }
      
      //set the next pointer of the last node of the linked list to the
      //new node and make the new last node the new node
      current -> next = newNode;
      
      //Check to see if there are more than 3 collisions, and if so make the
      //linked list bigger
      if(newLinkCount >= 3) {
	growTable(table, hashLength);
      }
    }
  }

  cout << endl;
}
