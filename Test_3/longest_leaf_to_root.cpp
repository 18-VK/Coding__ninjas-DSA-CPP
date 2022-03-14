#include <iostream>
#include "Impl_binary_tree.h"
#include <vector>
using namespace std;
vector<int> longest_L2R(BinaryTreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> left_long;
    vector<int> right_long;
    left_long = longest_L2R(root->left);
    right_long = longest_L2R(root->right);

    if (left_long.size() > right_long.size())
    {
        left_long.push_back(root->data);
    }
    else
    {
        right_long.push_back(root->data);
    }
    return left_long.size() > right_long.size() ? left_long : right_long;
}
int main()
{
    BinaryTreeNode *root = take_input();
    vector<int> result;
    result = longest_L2R(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}