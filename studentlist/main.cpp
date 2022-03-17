#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "node.h"
#include <cstdlib>

using namespace std;

void addingtohash(int &add, Node* (&student)[100], Node* next, char* (&first)[1000], char* (&last)[1000], int &idnum, int &x, int &y);
int hashfunction(int idnum);
void printfunction(Node* hashtable[], int i);
int randomizer(int x);

int main(){

  Node* head = NULL;
  
  Node* hashtable[100];

  int tablesize = 100;

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

  
  while (stilladding == true){
    
    cout << "What would you like to do? (ADD, DELETE, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      idnum = 0;
      
      cout << "How many students are you adding?" << endl;

      cin >> adding;

      while (adding != 0){

        x = randomizer(x);
	y = randomizer(y);
	
	addingtohash(adding, hashtable, next, firstname, lastname, idnum, x, y);
	
      }
    }

    if (strcmp(input, "DELETE") == 0){

      // delete function

    }

    if (strcmp(input, "PRINT") == 0) {
      
      for (int i = 0; i < tablesize; i++){

        printfunction(hashtable, i);

      }

    }
    
    if (strcmp(input, "QUIT") == 0) {
      
      stilladding = false;
	  
    }	
      
  }
}
int randomizer(int x){

  x = (rand() % 20);

  return x;

}

void addmanually(Node* (*student)[100], Node* next){

  Node* temp = new Node();
  
  cout << "Enter the first name: ";

  cin >> temp->firstname;

  cout << "Enter the last name: ";

  cin >> temp->lastname;

  cout << "Enter the gpa: ";

  cin >> temp->gpa;

  cout << "Enter the id: ";

  cin >> temp->id;

  int position = hashfunction(temp->id);
  
  


}

void addingtohash(int &add, Node* (&student)[100], Node* next, char* (&first)[1000], char* (&last)[1000], int &idnum, int &x, int &y){
  
  int position = hashfunction(idnum);

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

	position = hashfunction(idnum);

	break;
	
      }      
      
      else if (student[position]->next == NULL) {

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

	position = hashfunction(idnum);

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

	position = hashfunction(idnum);

	break;
	
      }

      
  }

  
  
}

int hashfunction(int idnum){

  int hash = idnum  % 100;
  
  return hash;
  

}
 
void printfunction(Node* hashtable[], int i){

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

    cout << endl;
    
    
    if (hashtable[i]->next != NULL){
      
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
