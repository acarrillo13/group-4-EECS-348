#include "BiTree.h"
#include "operators.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
BiTree::BiTree()
     :root(nullptr)
{}

//Destructor
BiTree::~BiTree(){
      Clear();
}

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

void BiTree::Print(BiTrNode* curNode){
      if(curNode != nullptr){
            Print(curNode->left);
            Print(curNode->right);
            cout << curNode->value << endl;
      }
}

//Error checking functions
void BiTree::parenIndex(const string& str, int size, int* priIndex){
      /*Takes an equation string of length size and finds the index values of each parenthesis and their pair*/
      //priIndex is an empty array defined outside of function and edited from function
      //First element of priIndex will be -2 if the given equation has invalid parenthesis
      int parInCounter = 0;
      for(int i = 0; i < size; i++){
            //Each element of priIndex starts as -1
            priIndex[i] = -1;
            //If a ( is found, a 0 is placed in same index position as the (
            if(str[i] == '('){
                  priIndex[i] = 0;
            }
            //Counter for backtracing through parIndex to find last inputted (
            parInCounter++;
            //If a ) is found, places its index placement value at index of its ( pair, or reports an error number if no pair found
            if(str[i] == ')'){
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

bool BiTree::isValid(const string& str, int size){
      /*Checks whether the inputted equation is valid*/
      //Checking for valid parenthesis usage
      int parenthesisIndex[size];
      parenIndex(str, size, parenthesisIndex);
      if(parenthesisIndex[0] == -2){
            return false;
      }
      //Checking that the placement of each operator follows proper operator rules
      for(int i = 0; i < size; i++){
            //For unexpected symbols
            if(str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '%' && str[i] != '*' && str[i] != '(' && str[i] != ')'){
                  return false;
            }
            //For Addition/Positive
            if(str[i] == '+'){
                  if(i == 0){
                        if(str[1] == ')' || str[1] == '+' || str[1] == '-' || str[1] == '*' || str[1] == '/' || str[1] == '%'){
                              return false;
                        }
                  }else if(i != size - 1){
                        if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/' || str[i-1] == '%' || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }
            }
            //For Subtraction/Negative
            if(str[i] == '-'){
                  if(i == 0){
                        if(str[1] == ')' || str[1] == '+' || str[1] == '-' || str[1] == '*' || str[1] == '/' || str[1] == '%'){
                              return false;
                        }
                  }else if(i != size - 1){
                        if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/' || str[i-1] == '%' || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
            //For Multiplication/Exponintiation
            if(str[i] == '*'){
                  if(i == 0){
                        return false;
                  }else if(i != size - 1){
                        if(str[i-1] == '*' && str[i+1] == '*'){
                              return false;
                        }else if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '(' || str[i-1] == '/' || str[i-1] == '%' || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == ')' || str[i+1] == '/' || str[i+1] == '%'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
            //For Division/Modulous
            if(str[i] == '/' || str[i] == '%'){
                  if(i == 0){
                        return false;
                  }else if(i != size - 1){
                        if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '(' || str[i-1] == '/' || str[i-1] == '%' || str[i-1] == '*' || str[i+1] == '*' || str[i+1] == '+' || str[i+1] == '-' || str[i+1] == ')' || str[i+1] == '/' || str[i+1] == '%' || str[i+1] == '0'){
                              return false;
                        }
                  }else{
                         return false;
                  }

            }
      }
      return true;
}

//Parisng and Calculating
void BiTree::parse(const string& str, BiTrNode* curNode){
      /*Parses through given equation string and turns it into a binary tree*/
      //Assumes valid equation
      int priority = 6;
      int priorityIndex = -1;
      int size = str.length();
      int parenthesisIndex[size];
      parenIndex(str, size, parenthesisIndex);
      for(int i = 0; i < size; i++){
            bool external = true;
            for(int j = 0; j < size; j++){
                  if(parenthesisIndex[j] > 0){
                        if(i > j && i < parenthesisIndex[j]){
                              external = false;
                        }
                  }
            }
            if(external){
                  if(str[i] == '+' || str[i] == '-'){
                        if(priority >= 1){
                              priority = 1;
                              priorityIndex = i;
                        }
                  }
                  else if(str[i] == '/' || str[i] == '%'){
                        if(priority >= 2){
                              priority = 2;
                              priorityIndex = i;
                        }
                  }
                  else if(str[i] == '*'){
                        if(str[i-1] == '*' || str[i+1] == '*'){
                              if(priority >= 3){
                                    priority = 3;
                                    priorityIndex = i;
                              }
                        }else{
                              if(priority >= 2){
                                    priority = 2;
                                    priorityIndex = i;
                              }                            
                        }
                  }
                  else if(str[i] == '(' || str[i] == ')'){
                        if(priority >= 4){
                              priority = 4;
                              priorityIndex = i;
                        }
                  }else if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
                        if(priority >= 5){
                              priority = 5;
                              priorityIndex = i;
                        }
                  }
            }
      }
      if(priority == 1){
            string opr(1,str[priorityIndex]);
            if(priorityIndex == 0){
                  curNode->value = opr;
                  string q = "Q";
                  curNode->left = new BiTrNode(q);
                  string rStr = "";
                  for(int r = 1; r < size; r++){
                        rStr += str[r];
                  }
                  curNode->right = new BiTrNode(rStr);
                  parse(rStr, curNode->right);
            }else{
                  curNode->value = opr;
                  string lStr = "";
                  for(int l = 0; l < priorityIndex; l++){
                        lStr += str[l];
                  }
                  curNode->left = new BiTrNode(lStr);
                  parse(lStr, curNode->left);
                  string rStr = "";
                  for(int r = priorityIndex + 1; r < size; r++){
                        rStr += str[r];
                  }
                  curNode->right = new BiTrNode(rStr);
                  parse(rStr, curNode->right);
            }
      }
      if(priority == 2){
            string opr(1,str[priorityIndex]);
            curNode->value = opr;
            string lStr = "";
            for(int l = 0; l < priorityIndex; l++){
                  lStr += str[l];
            }
            curNode->left = new BiTrNode(lStr);
            parse(lStr, curNode->left);
            string rStr = "";
            for(int r = priorityIndex + 1; r < size; r++){
                  rStr += str[r];
            }
            curNode->right = new BiTrNode(rStr);
            parse(rStr, curNode->right);
      }
      if(priority == 3){
            string opr = "^";
            curNode->value = opr;
            string lStr = "";
            for(int l = 0; l < priorityIndex - 1; l++){
                  lStr += str[l];
            }
            curNode->left = new BiTrNode(lStr);
            parse(lStr, curNode->left);
            string rStr = "";
            for(int r = priorityIndex + 1; r < size; r++){
                  rStr += str[r];
            }
            curNode->right = new BiTrNode(rStr);
            parse(rStr, curNode->right);
      }
      if(priority == 4){
            string internal = "";
            for(int m = 1; m < size - 1; m++){
                  internal += str[m];
            }
            curNode->value = internal;
            parse(internal, curNode);
      }
      if(priority == 5){
            curNode->value = str;
      }
}

string BiTree::calculateEq(const string& str){
      if(isValid(str,str.length())){
            root = new BiTrNode(str);
            parse(str, root);
            recCalculateEq(str, root);
            return root->value;
      }else{
            string errString = "The given equation was invalid, please try again.";
            return errString;
      }
}

void BiTree::recCalculateEq(const string& str, BiTrNode* curNode){
      if(curNode != nullptr){
            recCalculateEq(str, curNode->left);
            recCalculateEq(str, curNode->right);
            if(curNode->value == "+"){
                  if(curNode->left->value == "Q"){
                        curNode->value = positive(curNode->right->value);
                  }else{
                        curNode->value = add(curNode->left->value, curNode->right->value);
                  }
            }else if(curNode->value == "-"){
                  if(curNode->left->value == "Q"){
                        curNode->value = negative(curNode->right->value);
                  }else{
                        curNode->value = subtract(curNode->left->value, curNode->right->value);
                  }
            }else if(curNode->value == "*"){
                  curNode->value = multiply(curNode->left->value, curNode->right->value);
            }else if(curNode->value == "/"){
                  curNode->value = divide(curNode->left->value, curNode->right->value);
            }else if(curNode->value == "%"){
                  curNode->value = modulate(curNode->left->value, curNode->right->value);
            }else if(curNode->value == "^"){
                  curNode->value = exponent(curNode->left->value, curNode->right->value);
            }
      }
}
