#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
// use same approach of path from node to root
bool helper(BinaryTreeNode *root, int target, vector<int> &output)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (helper(root->left, target, output) == true)
    {
        output.push_back(root->data);
        return true;
    }
    if (helper(root->right, target, output) == true)
    {
        output.push_back(root->data);
        return true;
    }
    return false;
}
vector<int> Ancestors(BinaryTreeNode *root, int target)
{
    vector<int> output;
    if (root == NULL)
    {
        return output;
    }
    helper(root, target, output);
    return output;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    int k;
    cin>>k;
    vector<int>output;
    output=Ancestors(root,k);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}
