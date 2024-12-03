#include "BiTrNode.h"

class BiTree
{
   public:
      BiTree();
      void testInsert();
      void testPrint();
      void parenIndex(char arr[], int size, int* priIndex);
      bool isValid(char arr[], int size);
      void parse(char arr[], BiTrNode* curNode);
      void Clear();
   private:
      BiTrNode* root;
      void deleteNodes(BiTrNode* node);
};
