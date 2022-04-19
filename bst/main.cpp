#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void addfunction(Node* &node, int num);

int main(){

  char input[100];
  int x;
  
  Node* head = NULL;

  bool running = true;
  
  cout << "Welcome to Binary Search Tree! This program reads in numbers, organizes them, and allows you to delete and print them!" << endl;

  while (running == true){

    cout << "What would you like to do? (ADD, SEARCH, PRINT, DELETE, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      cout << "Enter the number you would like to add" << endl;

      cin >> x;

      addfunction(head, x);
      
    }
    if (strcmp(input, "SEARCH") == 0){

      // search (tuesday)

    }
    if (strcmp(input, "PRINT") == 0){

      // print (second) (monday)

    }
    if (strcmp(input, "DELETE") == 0){

      // delete (wednesday-weekend)

    }
    if (strcmp(input, "QUIT") == 0){

      running = false;
      break;

    }

  }

  return 0;

}
