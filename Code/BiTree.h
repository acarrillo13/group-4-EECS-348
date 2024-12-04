#include "BiTrNode.h"
#include <string>
using namespace std;

class BiTree
{
   public:
      BiTree();
      ~BiTree();
      void test();
      void testPrint(BiTrNode* curNode);
      void parenIndex(const string& str, int size, int* priIndex);
      bool isValid(const string& str, int size);
      void Clear();
   private:
      BiTrNode* root;
      void deleteNodes(BiTrNode* node);
      void parse(const string& str, BiTrNode* curNode);
};
