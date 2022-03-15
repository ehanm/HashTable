#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "node.h"

using namespace std;

void addingtohash(int &add, Node* (&student)[100], Node* &next, char* (&first)[1000], char* (&last)[1000], int &idnum);
int hashfunction(int idnum);

int main(){

  Node* hashtable[100];

  int tablesize = 100;
  
  for (int i = 0; i < tablesize; i++){

    hashtable[i] = NULL;

  }
  
  char input[100];

  bool stilladding = true;
  
  cout << "Welcome to Hash Table! This program is the same thing as Studentlist, but uses a Hash method instead!" << endl;

  // set up names

  char* firstname[1000];
  char* lastname[1000];

  // learned to do from https://www.tutorialspoint.com/how-to-read-a-text-file-with-cplusplus
  
  fstream newfirst;

  newfirst.open("firstname.txt");
  for (int i = 0; i < 20; i++){

    char* firstnames = new char[80];
    newfirst >> firstnames;
    firstname[i] = firstnames;

  }
  
  fstream newlast;
  
  newlast.open("lastname.txt");
  for (int i = 0; i < 20; i++){

    char* lastnames = new char[80];
    newlast >> lastnames;
    lastname[i] = lastnames;
  }
  
  
  int idnum = 0;

  while (stilladding == true){
  
    cout << "What would you like to do? (ADD, DELETE, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      int adding;
      
      cout << "How many students are you adding?" << endl;

      cin >> adding;

      Node* next = NULL;

      addingtohash(adding, hashtable, next, firstname, lastname, idnum);
      
    }

    if (strcmp(input, "DELETE") == 0){

      // delete function

    }

    if (strcmp(input, "PRINT") == 0) {

      for (int i = 0; i < tablesize; i++){

	if (hashtable[i] != NULL){

	  Node* temp = hashtable[i];

	  cout << "Name: ";
	  for (int i = 0; i < 100; i++){

	    cout << temp->firstname[i];

	  }

	  cout << " ";
	  for (int i = 0; i < 100; i++){

	    cout << temp->lastname[i];

	  }

	  cout << " GPA: ";
	  
	  cout << temp->gpa;

	  cout << " ";
	  
	  cout << "ID: ";
	  
	  cout << temp->id;
	  

	}

      }
      
    }

    if (strcmp(input, "QUIT") == 0) {

      stilladding = false;

    }
  }

}


void addingtohash(int &add, Node* (&student)[100], Node* &next, char* (&first)[1000], char* (&last)[1000], int &idnum){

  int position = hashfunction(idnum);
  
  if (add != 0) {
    for (int i = 0; i < add; i++){

      srand(time(NULL));
      
      int x = (rand() % 20);

      srand(time(NULL));

      int y = (rand() % 20);
            
      if (student[position] == NULL) {

	srand(time(NULL));

	float maxgrade = 4.0;

	float grade = (float)rand()/RAND_MAX * maxgrade;

	while (grade > 4){

	  grade--;

	}
	
	cout << grade;
	
	idnum++;

        Node* newstudent = new Node();

	strcpy(newstudent->firstname, first[x]);
	strcpy(newstudent->lastname, last[y]);

	for (int i = 0; i < 100; i++){
	  
	  cout << newstudent->firstname[i];

	}

	for (int i = 0; i < 100; i++) {

	  cout << newstudent->lastname[i];
	  
	}

	newstudent->gpa = grade;
	
	newstudent->id = idnum;

	student[position] = newstudent;

	add--;
      }

      else if (student[position] != NULL) {

	addingtohash(add, student, next, first, last, idnum);
	cout << "does this";
      }
    }
    
    
  }

}

int hashfunction(int idnum){

  int hash = (idnum + 26 * 7) % 100;

  return hash;
  

}

void print(){


}
