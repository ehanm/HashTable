#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
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
  
  fstream newfile;

  newfile.open("firstname.txt");
  for (int i = 0; i < 20; i++){

    char* firstnames = new char[80];
    newfile >> firstnames;
    firstname[i] = firstnames;

  }

  newfile.close();

  newfile.open("lastname.txt");
  for (int i = 0; i < 20; i++){

    char* lastnames = new char[80];
    newfile >> lastnames;
    lastname[i] = lastnames;
  }

  char* test = new char[80];

  strcpy(test, lastname[0]);

  cout << test;
  
  
  newfile.close();

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
	  
	  for (int i = 0; i < 100; i++){

	    cout << temp->firstname[i];

	  }
	  for (int i = 0; i < 100; i++){

	    cout << temp->lastname[i];

	  }
	  
	  cout << temp->gpa;
	  cout << temp->id;
	  

	}

      }
      
    }

    if (strcmp(input, "QUIT") == 0) {

      stilladding = false;

    }
  }

}


void addingtohash(int &add, Node* (&student)[100], Node* &next,  char* (&first)[1000], char* (&last)[1000], int &idnum){

  int position = hashfunction(idnum);
  
  if (add != 0) {
    for (int i = 0; i < add; i++){

      int x = rand() % 20;
      
      if (student[position] == NULL){

	float grade = rand() % 4; // haha

	idnum++;

	Node* student = new Node();

	strcpy(student->firstname, first[rand() % 20]);
	strcpy(student->lastname, last[rand() % 20]);

	cout << "gets here";
	
	for (int i = 0; i < 100; i++){
	  
	  cout << student->firstname[i];

	}

	for (int i = 0; i < 100; i++) {

	  cout << student->lastname[i];
	  
	}

	student->gpa = grade;
	
	student->id = idnum;

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
