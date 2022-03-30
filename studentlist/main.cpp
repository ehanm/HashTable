// With help from Nathan Zou
// Completed 3/16/22
// Written by Ehan Masud
// This is a program that functions similarly to the other studentlist programs, but instead implementing a hashtable

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "node.h"
#include <cstdlib>

using namespace std;

void addingtohash(int &add, Node** student, Node* next, char* (&first)[1000], char* (&last)[1000], int &idnum, int &x, int &y, int &listsize);
int hashfunction(int idnum, int tablesize);
void printfunction(Node** hashtable, int i);
int randomizer(int x);
void addmanually(Node** &student, int &tablesize);
void deletefunction(Node** student, int tablesize);
void rehash(Node** &student, int &tablesize);


int main(){

  Node* head = NULL;

  int tablesize = 100;
  
  Node** hashtable;

  hashtable = new Node*[100];
 

  srand(time(NULL));
  
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

  int idnum;
  int adding;
  Node* next = NULL;
  Node* current = NULL;

  int x;
  int y;

  
  while (stilladding == true){ // loop
    
    cout << "What would you like to do? (ADD, RANDOM, DELETE, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "RANDOM") == 0){ // add students randomly

      idnum = 0;
      
      cout << "How many students are you adding?" << endl;

      cin >> adding;

      while (adding != 0){

        x = randomizer(x); // randomizes x and y each time it adds a new student
	y = randomizer(y);
	
	addingtohash(adding, hashtable, next, firstname, lastname, idnum, x, y, tablesize);
	
      }
    }

    if (strcmp(input, "ADD") == 0) { // adds

      addmanually(hashtable, tablesize);

    }

    if (strcmp(input, "DELETE") == 0){ // deletes

      deletefunction(hashtable, tablesize);
      
    }

    if (strcmp(input, "PRINT") == 0) { // prints
      
      for (int i = 0; i < tablesize; i++){

        printfunction(hashtable, i);

      }

    }
    
    if (strcmp(input, "QUIT") == 0) { // quits program
      
      stilladding = false; 
	  
    }	
      
  }
}
int randomizer(int x){ // returns random number for randomnum gen

  x = (rand() % 20);

  return x;

}

void addmanually(Node** &student, int &tablesize){

  Node* temp = new Node();
  
  cout << "Enter the first name: ";

  cin >> temp->firstname;

  cout << "Enter the last name: ";

  cin >> temp->lastname;

  cout << "Enter the gpa: ";

  cin >> temp->gpa;

  cout << "Enter the id: ";

  cin >> temp->id;

  int position = hashfunction(temp->id, tablesize);
  
  if (student[position] == NULL){

    student[position] = temp;

  }

  else if (student[position]->next == NULL){

    student[position]->next = temp;
    
  }

  else if (student[position]->next->next == NULL) {

    student[position]->next->next = temp;
    
  }

  else {

    rehash(student, tablesize);

    student[position+(tablesize/2)] = temp;
    
  }


}

void addingtohash(int &add, Node** student, Node* next, char* (&first)[1000], char* (&last)[1000], int &idnum, int &x, int &y, int &listsize){
  
  int position = hashfunction(idnum, listsize); // determines where student will go based on id and listsize

  x = randomizer(x);

  cout << x;
    
  y = randomizer(y);
  
  while (add != 0) {
                
      if (student[position] == NULL) {
	
	float maxgrade = 4.0;

	float grade = (float)rand()/RAND_MAX * maxgrade;

	while (grade > 4){

	  grade--;
	  
	}
		
	idnum++;
	
        Node* newstudent = new Node();

	strcpy(newstudent->firstname, first[x]);
	strcpy(newstudent->lastname, last[y]);

	newstudent->gpa = grade;
	
	newstudent->id = idnum;
	
	next = newstudent;
        
	student[position] = next;
	
	add--;

	position = hashfunction(idnum, listsize);

	break;
	
      }      
      
      else if (student[position]->next == NULL) { // a lot of code is repeated, which in hindsight just made things harder to read

        float maxgrade = 4.0;

        float grade = (float)rand()/RAND_MAX * maxgrade;

        while (grade > 4){

          grade--;

        }

        idnum++;

        Node* newstudent = new Node();

        strcpy(newstudent->firstname, first[x]);
        strcpy(newstudent->lastname, last[y]);

        newstudent->gpa = grade;

        newstudent->id = idnum;

        student[position]->next = newstudent;
	
        add--;

	position = hashfunction(idnum, listsize);

	break;
      }

      else if (student[position]->next->next == NULL) {

        float maxgrade = 4.0;

        float grade = (float)rand()/RAND_MAX * maxgrade;

        while (grade > 4){

          grade--;

        }

        idnum++;

        Node* newstudent = new Node();

        strcpy(newstudent->firstname, first[x]);
        strcpy(newstudent->lastname, last[y]);

        newstudent->gpa = grade;

        newstudent->id = idnum;

        student[position]->next->next = newstudent;
        add--;

	position = hashfunction(idnum, listsize);

	break;
	
      }

      else {

	float maxgrade = 4.0;
	
	float grade = (float)rand()/RAND_MAX * maxgrade;
 
        while (grade > 4){

          grade--;

        }

        idnum++;
	
	Node* newstudent = new Node();

        strcpy(newstudent->firstname, first[x]);
        strcpy(newstudent->lastname, last[y]);

        newstudent->gpa = grade;

        newstudent->id = idnum;

        student[position]->next->next = newstudent;
        add--;

        position = hashfunction(idnum, listsize);

	
	rehash(student, listsize);

	student[position+(listsize/2)] = newstudent;

	add--;
	
      }

      
  }

}

void deletefunction(Node** student, int tablesize){ // delete function

  int input;
  cout << "Enter the id of student you want to delete: ";

  cin >> input;

  int position = hashfunction(input, tablesize);
  
  if (student[position] == NULL) {

    cout << "No student to delete!" << endl;

  }

  else {
    if (student[position]->id == input) { // delete by id
            
      if (student[position]->next == NULL) {
	student[position] = NULL;
      }
      else {
	// replace with next node
	Node* newhead = student[position]->next;
	student[position] = newhead;
      }
    }
    else { // current position's head doesn't have same id
      if (student[position]->next == NULL) {
	cout << "No student to delete!" << endl;
      }
      else { // if next thing exists, delete
	if (student[position]->next->id == input) {

	  Node* newhead = student[position]->next->next;
	  student[position]->next = newhead;

	}
	else { // if next next thing exists, delete
	  if (student[position]->next->next == NULL) {
	    
	    cout << "No student to delete!" << endl;
	    
	  }

	  else {

	    if (student[position]->next->next->id == input) {

	      student[position]->next->next = NULL;

	    }
	    else { // 4th collision can't exist

	      cout << "No student to delete!" << endl;
	      
	    }

	  }
	  
	}
      }
    }
  }
  

}

int hashfunction(int idnum, int tablesize){ // simple function to determine position

  int hash = idnum % tablesize;

  while (hash > 100){

    hashfunction(hash, tablesize);

  }
  
  return hash;
  

}
 
void printfunction(Node** hashtable, int i){ // prints out the table and students

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
    
    cout << fixed << setprecision(2) << temp->gpa;
    
    cout << " ";
    
    cout << "ID: ";
    
    cout << temp->id;

    cout << endl;
    
    
    if (hashtable[i]->next != NULL){ // also repeated a lot :(
      // should definitely optimize if project is repeated with another implementation
      
      temp = hashtable[i]->next;
      
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

      cout << endl;
      
      if (hashtable[i]->next->next != NULL){

	temp = hashtable[i]->next->next;
	
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

	cout << endl;


      }
      
    }
    
  }
}

void rehash(Node** &student, int &tablesize){ // optimizes table so more things can be added
  
  Node** temp;

  int x = tablesize;
  
  temp = new Node*[x];
  
  for (int i = 0; i < x; i++) {
    temp[i] = student[i];
  }

  int oldsize = tablesize;
  
  tablesize = tablesize*2;
  
  student = new Node*[tablesize];
    
  for (int i = 0; i < tablesize; i++) { // null out table
    student[i] = NULL;
  }
  
  for (int i = 0; i < oldsize; i++) {
    
    if (temp[i] != NULL) {

      Node* move = temp[i];
      
      int position = hashfunction(move->id, tablesize);
    
      student[position] = move;
      
      if (move->next != NULL) {

        Node* node = move->next;
	move->next = NULL;

	student[position]->next = node;
	
	
	if (move->next->next != NULL) {

	  Node* node2 = move->next->next;
	  move->next->next = NULL;
	  student[position]->next->next = node2;
	    
	}

      }
      
    }

  }
  
}
