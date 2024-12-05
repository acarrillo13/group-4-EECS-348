#include "BiTrNode.h"
#include <string>
using namespace std;

class BiTree
{
   public:
      BiTree();
      ~BiTree();
      void parenIndex(const string& str, int size, int* priIndex);
      bool isValid(const string& str, int size);
      void Clear();
      void test();
      string calculateEq(const string& str);
   private:
      BiTrNode* root;
      void deleteNodes(BiTrNode* node);
      void parse(const string& str, BiTrNode* curNode);
      void recCalculateEq(const string& str, BiTrNode* curNode);
      void Print(BiTrNode* curNode);
};
