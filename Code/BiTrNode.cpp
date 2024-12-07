#include "BiTrNode.h"
#include <string>
/*
Creates a binary node to be used in a binary tree
*/
using namespace std;
BiTrNode::BiTrNode(const string& data, BiTrNode* left, BiTrNode* right) 
     : value(data),left(left),right(right){}
