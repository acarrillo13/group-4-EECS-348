#include "BiTrNode.h"
#include <string>
using namespace std;
BiTrNode::BiTrNode(const string& data, BiTrNode* left, BiTrNode* right) 
     : value(data),left(left),right(right){}
