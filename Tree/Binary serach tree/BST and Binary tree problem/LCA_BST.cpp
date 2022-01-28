#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
/*
Given a binary search tree and two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.

*/
int LCA_BST(BinaryTreeNode *root, int node_1, int node_2)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node_1 || root->data == node_2)
    {
        return root->data;
    }
    // recursion call
    if (node_1 < root->data && node_2 < root->data)
    {
        return LCA_BST(root->left, node_1, node_2);
    }
    if (node_1 > root->data && node_2 > root->data)
    {
        return LCA_BST(root->right, node_1, node_2);
    }
    // if one node may present in left tree and another in right tree
    // else
    // {
    //     int left = LCA_BST(root->left, node_1, node_2);
    //     int right = LCA_BST(root->right, node_1, node_2);
    //     if (left == -1 && right == -1) // if not present
    //     {
    //         return -1;
    //     }
    //     else if (left != -1 && right != -1)
    //     {
    //         return root->data;
    //     }
    //     return left != -1 ? left : right;
    return root->data;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    int node1, node2;
    cin >> node1 >> node2;
    cout << "LCA of  (" << node1 << ", " << node2 << " ) : " << LCA_BST(root, node1, node2);
    return 0;
}