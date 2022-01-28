#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
// method 3- Time complexity-O(N)
bool check_BST(BinaryTreeNode *root, int min = INT16_MIN, int max = INT16_MAX) // default values
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data < min || root->data > max)
    {
        return false;
    }
    // setting min and max for left subtree and call recursion
    bool isLeft= check_BST(root->left,min,root->data-1);
    // setting min and max for right subtree and call recursion
    bool isright= check_BST(root->right,root->data,max); // min  for right should be equal or bigger than root 
    return isLeft && isright;
}
// method -4 using inorder traversal
// if In,Inorder traversal of BST,all nodes are in increasing order
bool check_BST4(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return true;
    }
    // call for left tree 
    if(check_BST4(root->left)==false) 
    // if left tree return false dont need to check right tree
    {
        return false;
    }
    static BinaryTreeNode* prev=NULL ;  
    if(prev!=NULL && root->data < prev->data)
    {
        return false;
    }
    prev=root;
    // call right tree
    if(check_BST4(root->right)==false)
    {
        return 0;
    }
    return true;
}
// int main()
// {
//     BinaryTreeNode *root = take_input();
//     print_identical(root);
//     if(check_BST(root))
//     {
//         cout<<"True"<<endl;
//     }
//     else
//     {
//         cout<<"false"<<endl;

//     }
//     return 0;
// }