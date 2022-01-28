#include <iostream>
#include "print_identical_structure.cpp"
using namespace std;
// Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1.
// Return true if given binary tree is balanced, false otherwise.
int height(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool balanced(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) == 1 || abs(left - right) == 0)
    {
        bool flag = balanced(root->left);
        bool flag1 = balanced(root->right);
        return flag1 && flag;
    }
    return false;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    if (balanced(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}