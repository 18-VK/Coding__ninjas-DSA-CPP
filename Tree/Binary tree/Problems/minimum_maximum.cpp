#include <iostream>
#include "print_identical_structure.cpp"
using namespace std;
class Pair
{
public:
    int maximum;
    int minimum;
    Pair()
    {
        maximum = INT16_MIN;
        minimum = INT16_MAX;
    }
};
Pair max_and_min(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        Pair p;
        p.maximum = INT16_MIN;
        p.minimum = INT16_MAX;
        return p;
    }
    Pair ans;
    Pair temp1 = max_and_min(root->left);
    Pair temp2 = max_and_min(root->right);
    ans.maximum = max(max(temp1.maximum, temp2.maximum), root->data);
    ans.minimum = min(min(temp1.minimum, temp2.minimum), root->data);
    return ans;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    Pair p = max_and_min(root);
    
    cout <<"minimum : "<< p.minimum << " , " <<"maxiumum : "<< p.maximum << endl;
    return 0;
}