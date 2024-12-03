class BiTrNode
/*Binary Node Class*/
{
public:
     BiTrNode(char data, BiTrNode* left = nullptr, BiTrNode* right = nullptr);
     char value;
     BiTrNode* left;
     BiTrNode* right;
};
