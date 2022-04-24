#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void addfunction(Node* &node, int num);
void printfunction(Node* node, int depth);
void search(Node* node, int num);
void deletefunction(Node* &parent, Node* &child, int num);

int main(){

  char input[100];
  int x;
  
  Node* head = NULL;

  Node* child = NULL;

  bool running = true;
  
  cout << "Welcome to Binary Search Tree! This program reads in numbers, organizes them, and allows you to delete and print them!" << endl;

  while (running == true){

    cout << "What would you like to do? (ADD, SEARCH, PRINT, DELETE, QUIT)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      cout << "Enter the number you would like to add:" << endl;

      cin >> x;

      addfunction(head, x);
      
    }
    if (strcmp(input, "SEARCH") == 0){

      cout << "What number are you searching for?" << endl;

      cin >> x;

      search(head, x);
      
      
    }
    if (strcmp(input, "PRINT") == 0){

      printfunction(head, 0);
      
    }
    if (strcmp(input, "DELETE") == 0){

      child = NULL;
      
      cout << "What number do you want to delete?" << endl;

      cin >> x;
      
      deletefunction(child, head, x);
      
    }
    if (strcmp(input, "QUIT") == 0){

      running = false;
      break;

    }

  }

  return 0;

}

void addfunction(Node* &node, int num){
  
  if (node == NULL){

    Node* temp = new Node();
    
    temp->data = num;

    node = temp;
    return;
  }
  
  if (node != NULL){

    if (node->data > num){

      addfunction(node->left, num);

    }

    if (node->data < num){

      addfunction(node->right, num);

    }

  }

  return;
  
}

void printfunction(Node* node, int depth){

  if (node == NULL){

    cout << "tree is empty!" << endl;
    return;
    
  }
  
  if (node->right != NULL){

    printfunction(node->right, depth + 1);
    
  }

  for (int i = 0; i < depth; i++){

    cout << "\t";
    
  }

  cout << node->data << endl;

  if (node->left != NULL){

    printfunction(node->left, depth + 1);

  }

}

void search(Node* node, int num){

  if (node == NULL){

    cout << "not in the tree!" << endl;

  }

  else if (node != NULL){

    if (node->data == num){

      cout << "in the tree!" << endl;

    }

    else {

      if (node->data > num) {

	search(node->left, num);

      }

      else if (node->data < num) {

	search(node->right, num);

      }

    }

  }
    
}

void deletefunction(Node* &parent, Node* &child, int num){

  if (parent != NULL){

    cout << "parent is " << parent->data << endl;

  }
  
  cout << "child is " << child->data << endl;

  if (child->left != NULL){

    cout << "child left is " << child->left->data << endl;
    
  }

  if (child->right != NULL){

    cout << "child right is " << child->right->data << endl;

  }

  

  
  if (child == NULL){

    cout << "can't delete!" << endl;

  }
  
  if (child->data < num){

    deletefunction(child, child->right, num);

  }
  else if (child->data > num) {

    deletefunction(child, child->left, num);

  }
  else {
    // case 1: its a leaf
    
    if (child->right == NULL && child->left == NULL){

      if (parent == NULL){

	child = NULL;
	return;
	
      }
      
      else if (parent->right == child){

	parent->right = NULL;
	
      }
      else if (parent->left == child){

	parent->left = NULL;
	
      }

      
      delete child;
      return;
      
    }

    // case 2: it has a child (left or right but not both)

    else if (child->right != NULL && child->left == NULL){

      if (parent == NULL){

        Node* temp = child;

	child = child->right;

	delete temp;
	return;
      }

      else if (parent->left == child){

        parent->left = child->right;

      }
      else if (parent->right == child){

        parent->right = child->right;

      }
      delete child;
      return;

      
    } 
      
    else if (child->left != NULL && child->right == NULL){

      if (parent == NULL){

	Node* temp = child;

	child = child->left;

	delete temp;
	return;
      }
      
      else if (parent->left == child){
      
	parent->left = child->left;

      }
      else if (parent->right == child){

	parent->right = child->left;

      }
      delete child;
      return;
      
    }
    
  }

}
