#include <iostream>
#include <cstring>

using namespace std;

class Node { // class for student information

public:
  
  Node* next = NULL;
  
  char firstname[1000];
  char lastname[1000];

  int id;
  float gpa;
  

};
