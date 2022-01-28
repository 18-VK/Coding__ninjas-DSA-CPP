#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
/*
Given a Binary tree, find the largest BST subtree.
That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
*/
class Pair
{
public:
    bool isBST;
    int height;
};
Pair helper(BinaryTreeNode *root, int min = INT16_MIN, int maxi = INT16_MAX)
{
    if (root == NULL)
    {
        Pair ans;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }
    Pair ans;
    if (root->data < min || root->data > maxi)
    {
        ans.isBST = false;
        ans.height = 0;
        return ans;
    }
    Pair left = helper(root->left, min, root->data - 1);
    Pair right = helper(root->right, root->data, maxi);
    if (left.isBST == true && right.isBST == true)
    {
        ans.isBST = true;
        ans.height = 1 + max(left.height, right.height);
        return ans;
    }
    else if(left.isBST==true )
    {
        ans.isBST=true;
        ans.height=left.height;
        return ans;
    }
    else if(right.isBST==true)
    {
      ans.isBST=true;
      ans.height=right.height;
      return ans;
    }
    return ans;
}
int Largest_BST(BinaryTreeNode *root)
{
    return helper(root).height;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    cout << "Height of largest BST: " << Largest_BST(root) << endl;
    return 0;
}