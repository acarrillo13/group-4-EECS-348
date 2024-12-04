#include <string>
using namespace std;
class BiTrNode
{
public:
     BiTrNode(const string& data, BiTrNode* left = nullptr, BiTrNode* right = nullptr);
     string value;
     BiTrNode* left;
     BiTrNode* right;
};
