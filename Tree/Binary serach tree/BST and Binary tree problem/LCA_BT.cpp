#include <iostream>
#include <vector>
#include "Impl_binary_tree.h"
using namespace std;
/*
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree.
 Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
*/
// Method-1 find root to node  path of both node and  compare them if get uncommon node return previous matched node
// Time O(n) with extra space
bool find_path(BinaryTreeNode *root, vector<int> &temp, int node)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == node)
    {
        temp.push_back(root->data);
        return true;
    }
    temp.push_back(root->data);
    if (find_path(root->left, temp, node) == true)
    {
        return true;
    }
    if (find_path(root->right, temp, node) == true)
    {
        return true;
    }
    // if node not found
    temp.pop_back();
    return false;
}
int LCA_BT(BinaryTreeNode *root, int node_1, int node_2)
{
    if (root == NULL)
    {
        return INT16_MIN;
    }
    vector<int> path1, path2;
    find_path(root, path1, node_1);
    find_path(root, path2, node_2);
    // if both nodes not found
    if (path1.empty() && path2.empty())
    {
        return -1;
    }
    // if only one node is present them return that node
    if (path1.empty() && !path2.empty())
    {
        return node_2;
    }
    if (!path1.empty() && path2.empty())
    {
        return node_1;
    }
    int i = 0;
    for (i; i < path1.size() && path2.size(); i++)
    {
        if (path1[i] != path2[i])
        {
            break;
        }
    }
    return path1[i - 1];
}
// Method -2 time O(N) without extra space
int LCA_BT_2(BinaryTreeNode *root, int node_1, int node_2)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node_1 || root->data == node_2)
    {
        return root->data;
    }
    int left = LCA_BT(root->left, node_1, node_2);
    int right = LCA_BT(root->right, node_1, node_2);
    // if out of 2 one is found in left and another in right subtree
    if (left != -1 && right != -1)
    {
        return root->data;
    }
    // if both not present
    if (left == -1 && right == -1)
    {
        return -1;
    }
    // if one is found and another is not found
    return left != -1 ? left:right;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    int node1, node2;
    cin >> node1 >> node2;
    cout << "LCA of  (" << node1 << ", " << node2 << " ) : " << LCA_BT_2(root, node1, node2);
    return 0;
}