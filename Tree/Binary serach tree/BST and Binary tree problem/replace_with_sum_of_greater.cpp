#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
/*
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it.
You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5)
and all nodes whose data is greater than or equal to 5.
*/
/*
23
31 17
33 28 24 9
*/
int helper(BinaryTreeNode *root, int sum)
{
    if (root == NULL)
    {
        return sum;
    }
    // we will get sum of all greater nodes than root in right subtree
    sum = helper(root->right, sum);
    sum = sum + root->data;
    root->data = sum;
    sum = helper(root->left, sum); // call left with updated sum
    return sum;
}
void replace_with_greater(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    helper(root, 0); // root and initial sum=0
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    replace_with_greater(root);
    print_identical(root);
    return 0;
}
