/*
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 1:
10
10 30
20 30 60
20 50 60
40 50
40
*/
#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
BinaryTreeNode *Create_and_insert(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    BinaryTreeNode *new_node = new BinaryTreeNode(root->data);
    new_node->left = Create_and_insert(root->left);
    root->left = new_node; 
    root->right = Create_and_insert(root->right);
    return root;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    cout << "Modified tree " << endl;
    Create_and_insert(root);
    print_identical(root);
    return 0;
}
