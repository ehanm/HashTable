#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main(){

  char input[100];

  bool stilladding = true;
  
  cout << "Welcome to Hash Table! This program is the same thing as Studentlist, but uses a Hash method instead!" << endl;


  while (stilladding == true){
  
    cout << "What would you like to do? (ADD, DELETE, PRINT, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      // add function

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
