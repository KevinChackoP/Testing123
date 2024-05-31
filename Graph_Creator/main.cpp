/* 
   This project...
   Author: Kevin Chacko
   Last Updated: WRITE END DATE HERE
   Period 6, C++ / Data Structures
*/

/*
  I got help with learning about what a graph is and what Djikstra's
  Algorithm is from the "Advanced Trees and Graphs" canvas module. Among
  these resources was a video made by Mr. Galbraith on graph concepts and
  what graphs are composed of.

  Also in the canvas module was a youtube video made by user Computer Science
  called "Graph Data Structure 4. Dijkstra’s Shortest Path Algorithm".
  URL: https://www.youtube.com/watch?v=pVfj6mxhdMw
  This video helped walk me through the process of Dijkstra's model and how
  it handles the graph and its data to find the shorted path, something which
  I used for my Find Shortest Path function.

  ADD MORE CITATIONS HERE
*/

//imports
#include <iostream>
#include <cstring>
#include <cctype>
#include <ios>
#include <limits>
#include <math.h>
#include <cstdlib>

//create std shortcut
using namespace std;

//Function Prototypes
void instructions();
int askCommand();
void addVertex(char vertices[20]);
void addEdge(char vertices[20], int adjacencyTable[][20]);
void removeVertex(char vertices[20], int adjacencyTable[][20]);
void removeEdge(char vertices[20], int adjacencyTable[][20]);
void findShortestPath(char vertices[20], int adjacencyTable[][20]);
void printGraph(char vertices[20], int adjacencyTable[][20]);

//Start of main function
int main() {
  //local variable declarations
  bool inUse = true;
  int commandKey = 0;
  char vertices[20];
  for(int i = 0; i < 20; i++) {
    vertices[i] = '-'; //Set no vertex as '-' character
  }
  int adjacencyTable[20][20];
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      adjacencyTable[i][j] = 0; //Set no edge as '0' number
    }
  }
  
  //Tell the user how the program works
  instructions();

  //Put them through the loop of interacting with the graph until they
  //are done with it
  while(inUse) {
    //ask the user to choose a command
    commandKey = askCommand();

    //Based on their command, do something with the graph or quit the program
    if(commandKey == 1) {
      //If they want to add a vertex to the graph, do so
      cout << "Adding vertex to the graph." << endl;
      cout << endl;

      addVertex(vertices);
      
    } else if(commandKey == 2) {
      //If they want to add an edge to the graph, do so
      cout << "Adding edge to the graph." << endl;
      cout << endl;

      addEdge(vertices, adjacencyTable);

    } else if(commandKey == 3) {
      //If they want to delete a vertex from the graph, do so
      cout << "Deleting vertex from the graph." << endl;
      cout << endl;

      removeVertex(vertices, adjacencyTable);
      
    } else if(commandKey == 4) {
      //If they want to delete an edge from the graph, do so
      cout << "Deleting edge from the graph." << endl;
      cout << endl;

      removeEdge(vertices, adjacencyTable);
      
    } else if(commandKey == 5) {
      //If they want to find the shortest path in the graph from one vertex
      //to another vertex, do so
      cout << "Finding shortest path in graph." << endl;
      cout << endl;

      findShortestPath(vertices, adjacencyTable);
      
    }  else if(commandKey == 6) {
      //If they want to print the current graph out and see how it's
      //structured, do so
      cout << "Printing out the current graph as it is." << endl;
      cout << endl;

      printGraph(vertices, adjacencyTable);
      
    }  else if(commandKey == 7) {
      //If they want to quit the program, do so
      cout << "Ok then, I hope this was helpful!" << endl;
      cout << endl;

      //change the boolean that determines if the program continues running
      inUse = false;
    }
  }

  //If nothing went wrong, return 0
  return 0;
}

//This function tells the user how to use the program
void instructions() {
  cout << "Hello, this is a program that helps you make a graph of up " << endl;
  cout << "to 20 vertices that hold integer values. You can use various " << endl;
  cout << "commands to interact with the graph. You can interact " << endl;
  cout << "with the graph by adding vertices with labels from A - Z " << endl;
  cout << "to the graph, adding edges between vertices that are " << endl;
  cout << "directed (one way) and hold an integer weight value, " << endl;
  cout << "deleting vertices from the graph, deleting edges from the " << endl;
  cout << "graph, searching for the shortest path between two " << endl;
  cout << "vertices in the graph (being the path with the least " << endl;
  cout << "weight while going through edges), and printing out the " << endl;
  cout << "graph as an adjacency table to visually see its current " << endl;
  cout << "structure. I hope this program is of use to you!" << endl;
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
  cout << "Input ADDV to add a vertex to the graph." << endl;
  cout << "Input ADDE to add an edge between vertices." << endl;
  cout << "Input DELV to delete a vertex from the graph." << endl;
  cout << "Input DELE to delete an edge from the graph." << endl;
  cout << "Input FSH to find the shortest path between two vertices." << endl;
  cout << "Input PRINT to print out the graph's adjacency table." << endl;
  cout << "Input QUIT to exit the program." << endl;
  cout << endl;

  //ask them for a command input, if the input is valid return an int for the
  //command key, if invalid have them reinput their desired command.
  while(true) {
    //Ask for input
    cin.getline(input, 10);

    //Clean input up by making it all upper case
    for(int i = 0; i < 10; i++) {
      input[i] = toupper(input[i]);
    }

    //return the corresponding command key to their command
    if(strcmp(input, "ADDV") == 0) {
      return 1;
    } else if(strcmp(input, "ADDE") == 0) {
      return 2;
    } else if(strcmp(input, "DELV") == 0) {
      return 3;
    } else if(strcmp(input, "DELE") == 0) {
      return 4;
    } else if(strcmp(input, "FSH") == 0) {
      return 5;
    } else if(strcmp(input, "PRINT") == 0) {
      return 6;
    } else if(strcmp(input, "QUIT") == 0) {
      return 7;
    } else { //If their command is invalid, tell them and have them try again
      cout << "Sorry, I don't recognize that command." << endl;
      cout << "Please input one of the following commands: " << endl;
      cout << "ADDV, ADDE, DELV, DELE, FSH, PRINT, QUIT." << endl;
      cout << endl;
    }
  }
}

//This function takes in a user input to add a vertex to the graph
void addVertex(char vertices[20]) {
  //check to make sure the graph isn't full on vertices
  bool hasSpace = false;
  for(int i = 0; i < 20; i++) {
    if(vertices[i] == '-') {
      hasSpace = true;
    }
  }

  if(hasSpace) {
    //continue on with adding a vertex
    char input = '-';
    bool validInput = false;

    while(!(validInput)) {
      //keep taking the user's input until they give a valid input
      cout << "Please enter a character from A-Z for the vertex " << endl;
      cout << "you want to add to the graph (no repeats!)." << endl;
      cin >> input;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl;
      input = toupper(input);

      if(isalpha(input)) {
	//go through graph to make sure there are no repeats
	validInput = true;
	
	for(int i = 0; i < 20; i++) {
	  if(vertices[i] == input) {
	    validInput = false;
	    cout << input << " was already a vertex in the graph." << endl;
	    cout << "Please try a different vertex label or enter " << endl;
	    cout << "0 to quit adpding a vertex." << endl;
	    cout << endl;
	  }
	}

	if(validInput) {
	  //add the vertex to the next available slot in the graph
	  bool notAdded = true;
	  
	  for(int i = 0; i < 20; i++) {
	    if(vertices[i] == '-' && notAdded) {
	      notAdded = false;
	      vertices[i] = input;
	    }
	  }
	}
	
      } else if(input == '0') {
	//the user no longer wants to add vertex to graph
	validInput = true;

	cout << "Quitting adding vertex to graph." << endl;
	cout << endl;
	
      } else {
	//User's input wasn't an alphabetic character, so tell them
	cout << "That isn't a valid vertex name. Please label " << endl;
	cout << "your vertex a character from A-Z. Alternativally, " << endl;
	cout << "if you no longer want to add a vertex to the graph, " << endl;
	cout << "please enter 0 to quit." << endl;
	cout << endl;
      }
    }

  } else {
    //the graph is full, so tell the user
    cout << "Sorry but the graph is full and no more vertices " << endl;
    cout << "may be added. Please remove a vertex before trying " << endl;
    cout << "to add more." << endl;
    cout << endl;
  }
}

//This function adds an weighted directed edge between two vertices
void addEdge(char vertices[20], int adjacencyTable[][20]) {
  char vertex1 = '-';
  char vertex2 = '-';
  char input = '-';
  int weight = 0;
  bool validInput = false;
  bool continueAdd = false;
  int vertexCount = 0;

  //make sure there are enough vertices to initiate edge adding
  for(int i = 0; i < 20; i++) {
    if(vertices[i] != '-') {
      vertexCount++;
    }
  }

  if(vertexCount < 2) {
    cout << "Sorry but your graph doesn't have enough vertices to " << endl;
    cout << "add edges between them. Please try again after you've " << endl;
    cout << "added at least 2 vertices to the graph." << endl;
    cout << endl;
  } else {
    continueAdd = true;
  }

  //take user's two inputs for the vertices they want to add the edge between
  while(!(validInput) && continueAdd) {
    //keep taking the user's input until they give a valid input
    cout << "Please enter a character from A-Z for the vertex " << endl;
    cout << "you want the edge to start from." << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    input = toupper(input);

    if(isalpha(input)) {
      //go through graph to find vertex
      for(int i = 0; i < 20; i++) {
	if(vertices[i] == input) {
	  validInput = true;
	  vertex1 = input;
	  cout << "Vertex " << input << " was found in the graph!" << endl;
	  cout << endl;
	}
      }

      if(!(validInput)) {
	//the user's inputted vertex doesn't exist in the graph, so tell them
	cout << "Sorry but " << input << " wasn't found in the " << endl;
	cout << "graph. Please try again or enter 0 to quit." << endl;
	cout << endl;
      }
	
    } else if(input == '0') {
      //the user no longer wants to add an edge to graph
      validInput = true;
      continueAdd = false;

      cout << "Quitting adding edge to graph." << endl;
      cout << endl;
	
    } else {
      //User's input wasn't an alphabetic character, so tell them
      cout << "That isn't a valid vertex name. Please enter a " << endl;
      cout << "character from A-Z for the vertex. Alternativally, " << endl;
      cout << "if you no longer want to add an edge to the graph, " << endl;
      cout << "please enter 0 to quit." << endl;
      cout << endl;
    }
  }

  input = '-';
  validInput = false;
  while(!(validInput) && continueAdd) {
    //keep taking the user's input until they give a valid input
    cout << "Please enter a character from A-Z for the vertex " << endl;
    cout << "you want the edge to end at." << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    input = toupper(input);

    if(isalpha(input)) {
      if(input != vertex1) {
	//go through graph to find vertex
	for(int i = 0; i < 20; i++) {
	  if(vertices[i] == input) {
	    validInput = true;
	    vertex2 = input;
	    cout << "Vertex " << input << " was found in the graph!" << endl;
	    cout << endl;
	  }
	}

	if(!(validInput)) {
	  //the user's inputted vertex doesn't exist in the graph, so tell them
	  cout << "Sorry but " << input << " wasn't found in the " << endl;
	  cout << "graph. Please try again or enter 0 to quit." << endl;
	  cout << endl;
	}
	
      } else {
	//The user inputted the same vertex from the starting vertex as the
	//ending vertex which you can't do to make an edge, so tell them
	cout << "The ending vertex you entered is the same as the " << endl;
	cout << "starting vertex which can't be possible. Please " << endl;
	cout << "choose a different vertex to be your ending vertex." << endl;
	cout << endl;
      }
	
    } else if(input == '0') {
      //the user no longer wants to add an edge to graph
      validInput = true;
      continueAdd = false;

      cout << "Quitting adding edge to graph." << endl;
      cout << endl;
	
    } else {
      //User's input wasn't an alphabetic character, so tell them
      cout << "That isn't a valid vertex name. Please enter a " << endl;
      cout << "character from A-Z for the vertex. Alternativally, " << endl;
      cout << "if you no longer want to add an edge to the graph, " << endl;
      cout << "please enter 0 to quit." << endl;
      cout << endl;
    }
  }

  //Ask the user to input a weight to give to the edge
  validInput = false;
  while(!(validInput) && continueAdd) {
    //keep taking the user's input until they give a valid input
    cout << "Please enter an integer value greater than 0 and less " << endl;
    cout << "than 999 to be the weight you're applying to this edge." << endl;
    cin >> weight;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    if(weight <= 0) {
      //the user's inputted weight is too small, so let them know
      cout << "Your weight that you are applying is too small." << endl;
      cout << "Please input a weight greater than 0.";
      cout << endl;
      
    } else if(weight > 999) {
      //the user's inputted weight is too small, so let them know
      cout << "Your weight that you are applying is too big." << endl;
      cout << "Please input a weight less than 1000.";
      cout << endl;
      
    } else {
      //the user's input is just right, so set it as the new weight
      validInput = true;

      //add the edge to the adjacency list
      for(int i = 0; i < 20; i++) {
	for(int j = 0; j < 20; j++) {
	  if(vertices[j] == vertex1 && vertices[i] == vertex2) {
	    if(adjacencyTable[j][i] != 0) {
	      //check if the edge has been made before, if so, tell the user
	      cout << "Edge between vertices has already been made " << endl;
	      cout << "before, so old edge will be overridden." << endl;
	      cout << endl;
	    }

	    adjacencyTable[j][i] = weight;
	  }
	}
      }
    }
  }
}

//this function removes a vertex from the graph and deletes all the
//edges between it and other vertices
void removeVertex(char vertices[20], int adjacencyTable[][20]) {
  //continue on with adding a vertex
  char input = '-';
  bool validInput = false;
  int vertexCount = 0;

  //check to make sure there are vertices to delete in the graph
  for(int i = 0; i < 20; i++) {
    if(vertices[i] != '-') {
      vertexCount++;
    }
  }

  if(vertexCount >= 1) {
    while(!(validInput)) {
      //keep taking the user's input until they give a valid input
      cout << "Please enter a character from A-Z for the vertex " << endl;
      cout << "you want to remove from the graph." << endl;
      cin >> input;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl;
      input = toupper(input);

      if(isalpha(input)) {
	//go through graph to find the vertex
	for(int i = 0; i < 20; i++) {
	  if(vertices[i] == input) {
	    validInput = true;

	    //vertex was found so remove it from the graph 
	    cout << "vertex " << input << " was found and will be deleted." << endl;
	    cout << endl;

	    //first delete the edges related to the vertex
	    for(int j = 0; j < 20; j++) {
	      adjacencyTable[i][j] = 0;
	      adjacencyTable[j][i] = 0;
	    }

	    //next delete the vertex itself
	    vertices[i] = '-';
	  }
	}

	if(!(validInput)) {
	  //the vertex wasn't found in the graph, so tell the user
	  cout << "Sorry but that vertex isn't in the graph, so " << endl;
	  cout << "it can't be deleted. Please try a different " << endl;
	  cout << "vertex label or enter 0 to quit." << endl;
	  cout << endl;
	}
	
      } else if(input == '0') {
	//the user no longer wants to remove a vertex from the graph
	validInput = true;

	cout << "Quitting removing vertex from graph." << endl;
	cout << endl;
	
      } else {
	//User's input wasn't an alphabetic character, so tell them
	cout << "That isn't a valid vertex name. Please label " << endl;
	cout << "your vertex a character from A-Z. Alternativally, " << endl;
	cout << "if you no longer want to remove a vertex from " << endl;
	cout << "the graph, please enter 0 to quit." << endl;
	cout << endl;
      }
    }
    
  } else {
    cout << "There aren't any vertices to be deleted from the graph." << endl;
    cout << "Please try to delete vertices from the graph after " << endl;
    cout << "adding a few to the graph." << endl;
    cout << endl;
  }
}

//This function will remove the directed edge between two vertices
void removeEdge(char vertices[20], int adjacencyTable[][20]) {
  char vertex1 = '-';
  char vertex2 = '-';
  char input = '-';
  bool validInput = false;
  bool continueDel = false;
  int vertexCount = 0;

  //make sure there are enough vertices to initiate edge deletion
  for(int i = 0; i < 20; i++) {
    if(vertices[i] != '-') {
      vertexCount++;
    }
  }

  if(vertexCount < 2) {
    cout << "Sorry but your graph doesn't have enough vertices to " << endl;
    cout << "remove edges between them. Please try again after " << endl;
    cout << "you've added at least 2 vertices to the graph." << endl;
    cout << endl;
  } else {
    continueDel = true;
  }

  //take user's two inputs for the vertices they want to remove an edge between
  while(!(validInput) && continueDel) {
    //keep taking the user's input until they give a valid input
    cout << "Please enter a character from A-Z for the vertex " << endl;
    cout << "you want the edge you're deleting to start from." << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    input = toupper(input);

    if(isalpha(input)) {
      //go through graph to find vertex
      for(int i = 0; i < 20; i++) {
	if(vertices[i] == input) {
	  validInput = true;
	  vertex1 = input;
	  cout << "Vertex " << input << " was found in the graph!" << endl;
	  cout << endl;
	}
      }

      if(!(validInput)) {
	//the user's inputted vertex doesn't exist in the graph, so tell them
	cout << "Sorry but " << input << " wasn't found in the " << endl;
	cout << "graph. Please try again or enter 0 to quit." << endl;
	cout << endl;
      }
	
    } else if(input == '0') {
      //the user no longer wants to delete an edge from the graph
      validInput = true;
      continueDel = false;

      cout << "Quitting deleting edge from graph." << endl;
      cout << endl;
	
    } else {
      //User's input wasn't an alphabetic character, so tell them
      cout << "That isn't a valid vertex name. Please enter a " << endl;
      cout << "character from A-Z for the vertex. Alternativally, " << endl;
      cout << "if you no longer want to delete an edge from the " << endl;
      cout << "graph, please enter 0 to quit." << endl;
      cout << endl;
    }
  }

  input = '-';
  validInput = false;
  while(!(validInput) && continueDel) {
    //keep taking the user's input until they give a valid input
    cout << "Please enter a character from A-Z for the vertex " << endl;
    cout << "you want the edge you're deleting to end at." << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    input = toupper(input);

    if(isalpha(input)) {
      if(input != vertex1) {
	//go through graph to find vertex
	for(int i = 0; i < 20; i++) {
	  if(vertices[i] == input) {
	    validInput = true;
	    vertex2 = input;
	    cout << "Vertex " << input << " was found in the graph!" << endl;
	    cout << endl;
	  }
	}

	if(!(validInput)) {
	  //the user's inputted vertex doesn't exist in the graph, so tell them
	  cout << "Sorry but " << input << " wasn't found in the " << endl;
	  cout << "graph. Please try again or enter 0 to quit." << endl;
	  cout << endl;
	}
	
      } else {
	//The user inputted the same vertex from the starting vertex as the
	//ending vertex which you can't do to delete an edge, so tell them
	cout << "The ending vertex you entered is the same as the " << endl;
	cout << "starting vertex which can't be possible. Please " << endl;
	cout << "choose a different vertex to be your ending vertex." << endl;
	cout << endl;
      }
	
    } else if(input == '0') {
      //the user no longer wants to delete an edge from the graph
      validInput = true;
      continueDel = false;

      cout << "Quitting deleting edge from graph." << endl;
      cout << endl;
	
    } else {
      //User's input wasn't an alphabetic character, so tell them
      cout << "That isn't a valid vertex name. Please enter a " << endl;
      cout << "character from A-Z for the vertex. Alternativally, " << endl;
      cout << "if you no longer want to delete an edge from the " << endl;
      cout << "graph, please enter 0 to quit." << endl;
      cout << endl;
    }
  }

  //delete the edge from the starting vertex to the ending vertex
  if(continueDel) {
    for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 20; j++) {
	if(vertices[j] == vertex1 && vertices[i] == vertex2) {
	  if(adjacencyTable[j][i] != 0) {
	    //check if the edge exists before deleting
	    cout << "Edge between vertex " << vertex1 << " and " << endl;
	    cout << vertex2 << " exists and will be deleted." << endl;
	    cout << endl;

	    //delete it
	    adjacencyTable[j][i] = 0;
	  
	  } else {
	    //the edge doesn't exist, so let the user know
	    cout << "Sorry but an edge from " << vertex1 << " directed " << endl;
	    cout << "to " << vertex2 << " doesn't exist, so it won't be " << endl;
	    cout << "deleted from the graph." << endl;
	    cout << endl;
	  }
	}
      }
    }
  }
}

//This function uses Dijkstra's shortest path algorithm to find the shortest
//path between two vertices in the graph as desired by the user
void findShortestPath(char vertices[20], int adjacencyTable[][20]) {
  //local variable declarations
  char visited[20];
  for(int i = 0; i < 20; i++) {
    visited[i] = '-';
  }
  char unvisited[20];
  for(int i = 0; i < 20; i++) {
    unvisited[i] = vertices[i];
  }
  int shortestDistance[20];
  for(int i = 0; i < 20; i++) {
    shortestDistance[i] = 100000;
  }
  char previousVertex[20];
  for(int i = 0; i < 20; i++) {
    previousVertex[i] = '-';
  }

  //Take user input for which vertices they want to find the shortest path
  //between
  

  //Go through unvisited list and run through dijkstra's algorithm
  for(int i = 0; i < 20; i++) {
    if(unvisited[i] != '-') {
      //if the vertex exists
    }
  }
}

//This function prints out the graph as an adjacency table
void printGraph(char vertices[20], int adjacencyTable[][20]) {
  //explain how adjacency table works
  cout << "Column vertex: starting vertex" << endl;
  cout << "Row vertex: target vertex" << endl;
  cout << endl;

  //create header row for columns
  cout << '\t';
  for(int i = 0; i < 20; i++) {
    cout << vertices[i] << '\t';
  }
  cout << endl;
  cout << endl;
  
  for(int i = 0; i < 20; i++) {
    //create header to row
    cout << vertices[i] << '\t';
    for(int j = 0; j < 20; j++) {
      //output all the data in the table
      cout << adjacencyTable[j][i] << '\t';
    }
    cout << endl;
    cout << endl;
  }
  cout << endl;
}
