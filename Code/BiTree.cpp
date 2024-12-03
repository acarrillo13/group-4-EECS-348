#include "BiTree.h"
#include <iostream>

//Constructor
BiTree::BiTree()
     :root(nullptr)
{}

//Destructor
void BiTree::Clear(){
      deleteNodes(root);
      root = nullptr;
}

void BiTree::deleteNodes(BiTrNode* node){
      /*Deletes all nodes in the tree recursively*/
      if(node != nullptr){
            deleteNodes(node->left);
            deleteNodes(node->right);
            delete node;
      }
}

void BiTree::testInsert(){
     //Will delete Later
     char z = 'w';
     root = new BiTrNode(z);
}

void BiTree::testPrint(){
     //Will delete later
      if(root != nullptr){
            std::cout << root->value << std::endl;
      }else{
            std::cout << "Empty Tree" << std::endl;
      }
}

void BiTree::parenIndex(char arr[], int size, int* priIndex){
      /*Takes an equation string of length size and finds the index values of each parenthesis and their pair*/
      //priIndex is an empty array defined outside of function and edited from function
      //First element of priIndex will be -2 if the given equation has invalid parenthesis
      int parInCounter = 0;
      for(int i = 0; i < size; i++){
            //Each element of priIndex starts as -1
            priIndex[i] = -1;
            //If a ( is found, a 0 is placed in same index position as the (
            if(arr[i] == '('){
                  priIndex[i] = 0;
            }
            //Counter for backtracing through parIndex to find last inputted (
            parInCounter++;
            //If a ) is found, places its index placement value at index of its ( pair, or reports an error number if no pair found
            if(arr[i] == ')'){
                  //For checking if it has found a pair
                  bool pairNotFound = true;
                  //Looking for ( to match )
                  for(int j = parInCounter - 1; j >= 0; j--){
                        //If a pair is found
                        if(priIndex[j] == 0){
                              priIndex[j] = i;
                              pairNotFound = false;
                              //Ends loop to prevent double pairing
                              break;
                        }
                  }
                  //Returns error number if no ( found to match the )
                  if(pairNotFound){
                        priIndex[0] = -2;
                  }
            }
      }
      //Checking for unmatched (
      for(int k = 0; k < size; k++){
            if(priIndex[k] == 0){
                  priIndex[0] = -2;
                  break;
            }
      }
}

bool BiTree::isValid(char arr[], int size){
      /*Checks whether the inputted equation is valid*/
      //Checking for valid parenthesis usage
      //Write side outside of function as int size = std::end(arr) - std::begin(arr);
      int parenthesisIndex[size];
      parenIndex(arr, size, parenthesisIndex);
      if(parenthesisIndex[0] == -2){
            return false;
      }
      //Checking that the placement of each operator follows proper operator rules
      for(int i = 0; i < size; i++){
            //For unexpected symbols
            if(arr[i] != '0' && arr[i] != '1' && arr[i] != '2' && arr[i] != '3' && arr[i] != '4' && arr[i] != '5' && arr[i] != '6' && arr[i] != '7' && arr[i] != '8' && arr[i] != '9' && arr[i] != '+' && arr[i] != '-' && arr[i] != '/' && arr[i] != '%' && arr[i] != '*' && arr[i] != '(' && arr[i] != ')'){
                  return false;
            }
            //For Addition/Positive
            if(arr[i] == '+'){
                  if(i == 0){
                        if(arr[1] == ')' || arr[1] == '+' || arr[1] == '-' || arr[1] == '*' || arr[1] == '/' || arr[1] == '%'){
                              return false;
                        }
                  }else if(i != size - 1){
                        if(arr[i-1] == '+' || arr[i-1] == '-' || arr[i-1] == '*' || arr[i-1] == '/' || arr[i-1] == '%' || arr[i+1] == '+' || arr[i+1] == '-' || arr[i+1] == '*' || arr[i+1] == '/' || arr[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }
            }
            //For Subtraction/Negative
            if(arr[i] == '-'){
                  if(i == 0){
                        if(arr[1] == ')' || arr[1] == '+' || arr[1] == '-' || arr[1] == '*' || arr[1] == '/' || arr[1] == '%'){
                              return false;
                        }
                  }else if(i != size - 1){
                        if(arr[i-1] == '+' || arr[i-1] == '-' || arr[i-1] == '*' || arr[i-1] == '/' || arr[i-1] == '%' || arr[i+1] == '+' || arr[i+1] == '-' || arr[i+1] == '*' || arr[i+1] == '/' || arr[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
            //For Multiplication/Exponintiation
            if(arr[i] == '*'){
                  if(i == 0){
                        return false;
                  }else if(i != size - 1){
                        if(arr[i-1] == '*' && arr[i+1] == '*'){
                              return false;
                        }else if(arr[i-1] == '+' || arr[i-1] == '-' || arr[i-1] == '(' || arr[i-1] == '/' || arr[i-1] == '%' || arr[i+1] == '+' || arr[i+1] == '-' || arr[i+1] == ')' || arr[i+1] == '/' || arr[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
            //For Division/Modulous
            if(arr[i] == '/' || arr[i] == '%'){
                  if(i == 0){
                        return false;
                  }else if(i != size - 1){
                        if(arr[i-1] == '+' || arr[i-1] == '-' || arr[i-1] == '(' || arr[i-1] == '/' || arr[i-1] == '%' || arr[i-1] == '*' || arr[i+1] == '*' || arr[i+1] == '+' || arr[i+1] == '-' || arr[i+1] == ')' || arr[i+1] == '/' || arr[i+1] == '%' || arr[i+1] == '0'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
      }
      return true;
}

void BiTree::parse(char arr[], BiTrNode* node){
      /*Parses through given equation string and turns it into a binary tree*/
}
