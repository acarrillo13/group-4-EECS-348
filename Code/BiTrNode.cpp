#include "BiTrNode.h"
//Constructor
BiTrNode::BiTrNode(char data, BiTrNode* left, BiTrNode* right) 
     : value(data),left(right),right(right){}
