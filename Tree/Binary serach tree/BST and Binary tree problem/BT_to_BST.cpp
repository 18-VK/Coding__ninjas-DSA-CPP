#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include "Impl_binary_tree.h"
using namespace std;
void BST_to_vec(BinaryTreeNode *root, vector<int> &output)
{
    if (root == NULL)
    {
        return;
    }
    output.push_back(root->data);
    BST_to_vec(root->left, output);
    BST_to_vec(root->right, output);
}
void convert(BinaryTreeNode *root, vector<int> &output, int &idx)
{
    if (root == NULL)
    {
        return;
    }
    // for creating left subtree
    convert(root->left, output, idx);
    root->data = output[idx];
    idx++;
    // for creating right subtree
    convert(root->right, output, idx);
}
BinaryTreeNode *binaryTreeToBST(BinaryTreeNode *root)
{
    // Your code goes here
    if (root == NULL)
    {
        return root;
    }
    vector<int> output;
    BST_to_vec(root, output);
    sort(output.begin(), output.end());
    int end = output.size() - 1;
    int idx = 0;
    convert(root, output, idx);
    return root;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    root=binaryTreeToBST(root);
    cout<<"After conversion "<<endl;
    print_identical(root);
    return 0;
}