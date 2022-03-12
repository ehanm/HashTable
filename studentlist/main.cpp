
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "node.h"

using namespace std;

void addingtohash(int add, Node* (&student)[100], char* (&first)[1000], char* (&last)[1000], int &idnum);

int main(){

  Node* hashtable[100];
  
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

    firstname[i] = new char[80];
    newfile >> firstname[i];

  }

  newfile.close();

  newfile.open("lastname.txt");
  for (int i = 0; i < 20; i++){

    lastname[i] = new char[80];
    newfile >> lastname[i];

  }

  newfile.close();

  int idnum = 0;

  while (stilladding == true){
  
    cout << "What would you like to do? (ADD, DELETE, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      int adding;
      
      cout << "How many students are you adding?" << endl;

      cin >> adding;

      addingtohash(adding, hashtable, firstname, lastname, idnum);
      
    }

    if (strcmp(input, "DELETE") == 0){

      // delete function

    }

    if (strcmp(input, "PRINT") == 0) {

      // print function

    }

    if (strcmp(input, "QUIT") == 0) {

      stilladding = false;

    }
  }

}


void addingtohash(int add, Node* (&student)[100], char* (&first)[1000], char* (&last)[1000], int &idnum){
  
  for (int i = 0; i < add; i++){

    int x = rand() % 20;

    if (student == NULL){

      float grade = rand() % 4; // haha

      idnum++;

      Node* student = new Node();
      
      strcpy(student->firstname, first[x]);
      strcpy(student->lastname, last[x]);
      
      student->gpa = grade;
      
      student->id = idnum;
    }
    

  }
}
