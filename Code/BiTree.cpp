#include "BiTree.h"
#include "operators.h"
#include <iostream>
#include <string>
using namespace std;
/*
Creates a binary tree for holding and calculating a given equation.
Checks validity of the given equation.
Parses given equation into a tree.
Calculates parsed equation.
Returns either an error message or answer in the calculateEq function.
*/
//Constructor
BiTree::BiTree()
     :root(nullptr)
{}

//Destructor
BiTree::~BiTree(){
      Clear();
}

//Clears the tree and resets the root to nullptr
void BiTree::Clear(){
      deleteNodes(root);
      root = nullptr;
}

//Recursively deletes each node in the tree
void BiTree::deleteNodes(BiTrNode* node){
      /*Deletes all nodes in the tree recursively*/
      if(node != nullptr){
            deleteNodes(node->left);
            deleteNodes(node->right);
            delete node;
      }
}

//Prints the post-order of the tree (or post-fix notation of the equation)
void BiTree::Print(BiTrNode* curNode){
      if(curNode != nullptr){
            Print(curNode->left);
            Print(curNode->right);
            cout << curNode->value << endl;
      }
}

//Just a function for testing purposes
void BiTree::test(){
     string z;
     cout << "Enter equation: ";
     cin >> z;
     root = new BiTrNode(z);
     parse(z, root);
     Print(root);
     cout << calculateEq(z) << endl;
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
      //Checking for right most, lowest priority symbol in order of operations to become the root value
      //5 is highest priority, 1 is lowest, 6 is there for preset to nothing
      int priority = 6;
      int priorityIndex = -1;
      int size = str.length();
      //Location of parenthesis pairs
      int parenthesisIndex[size];
      parenIndex(str, size, parenthesisIndex);
     //Goes through given equation to find the root value and branches off into left and right subtrees of the left and right sides of the root value
      for(int i = 0; i < size; i++){
            //Checking for if current symbol is within a parenthesis pair, and ignores if so
            bool external = true;
            for(int j = 0; j < size; j++){
                  if(parenthesisIndex[j] > 0){
                        if(i > j && i < parenthesisIndex[j]){
                              external = false;
                        }
                  }
            }
           //If not within a parenthesis
            if(external){
                  //Sets priority value to priority of current symbol and resets priority index if it has a lower or equal priority to the current recorded priority
                  //For + and - (Priority 1)
                  if(str[i] == '+' || str[i] == '-'){
                        if(priority >= 1){
                              priority = 1;
                              priorityIndex = i;
                        }
                  }
                  //For / and % (Priority 2)
                  else if(str[i] == '/' || str[i] == '%'){
                        if(priority >= 2){
                              priority = 2;
                              priorityIndex = i;
                        }
                  }
                  //For * and ** (Priority 2 and 3)
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
                  //For ( and ) (Priority 4)
                  //Does not branch off if this is the lowest priority but recurses on the current node to an equation without the brackets
                  else if(str[i] == '(' || str[i] == ')'){
                        if(priority >= 4){
                              priority = 4;
                              priorityIndex = i;
                        }
                  //For number values (Priority 5)
                  //These are the leaf nodes
                  }else if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
                        if(priority >= 5){
                              priority = 5;
                              priorityIndex = i;
                        }
                  }
            }
      }
      //opr string is used to be the value of the current node
      //If root is + or -
      if(priority == 1){
            string opr(1,str[priorityIndex]);
            //If the + or - is used for positive or negative sign assignment
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
            //If the + or - is for addition or subtraction
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
      //If root is *, /, or %
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
      //If root is **
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
      //If root is )
      if(priority == 4){
            string internal = "";
            //Pops off prackets and recurses on current node
            for(int m = 1; m < size - 1; m++){
                  internal += str[m];
            }
            curNode->value = internal;
            parse(internal, curNode);
      }
      //Creates leaf node if root is a number
      if(priority == 5){
            curNode->value = str;
      }
}

string BiTree::calculateEq(const string& str){
      /*Takes in a string equation and returns a string answer*/
      //Checks that the given equation is valid
      if(isValid(str,str.length())){
            //Parses equation into a tree then recursively calculates along the tree
            root = new BiTrNode(str);
            parse(str, root);
            recCalculateEq(str, root);
            //If the tree returns an error value (e)
            if(root->value == "e"){
                  string errString = "The given equation was invalid, please try again.";
                  return errString;
            //Returns answer as string if equation was proper
            }else{
                  return root->value;
            }
      //If equation was invalid
      }else{
            string errString = "The given equation was invalid, please try again.";
            return errString;
      }
}

void BiTree::recCalculateEq(const string& str, BiTrNode* curNode){
      /*Recurses through the equation binary tree in post-order and calculates the values*/
      if(curNode != nullptr){
            recCalculateEq(str, curNode->left);
            recCalculateEq(str, curNode->right);
            //Addition and positive sign assignment
            if(curNode->value == "+"){
                  if(curNode->left->value == "Q"){
                        curNode->value = positive(curNode->right->value);
                  }else{
                        curNode->value = add(curNode->left->value, curNode->right->value);
                  }
            //Subtraction and negative sign assignment
            }else if(curNode->value == "-"){
                  if(curNode->left->value == "Q"){
                        curNode->value = negative(curNode->right->value);
                  }else{
                        curNode->value = subtract(curNode->left->value, curNode->right->value);
                   }
            //Multiplication
            }else if(curNode->value == "*"){
                        curNode->value = multiply(curNode->left->value, curNode->right->value);
            //Division
            }else if(curNode->value == "/"){
                  curNode->value = divide(curNode->left->value, curNode->right->value);
            //Moduluous
            }else if(curNode->value == "%"){
                  curNode->value = modulate(curNode->left->value, curNode->right->value);
            //Exponentiation
            }else if(curNode->value == "^"){
                  curNode->value = exponent(curNode->left->value, curNode->right->value);
            }
      }
}
