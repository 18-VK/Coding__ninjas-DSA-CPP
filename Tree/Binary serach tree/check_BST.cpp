#include<iostream>
#include"Impl_binary_tree.h"
using namespace std;
//method 1 
// time complexity- O(nlogn) or O(N*H),h=height of tree
int maximum(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return INT16_MIN;
    }
    // maximum of root, maximum return by left subtree and right subtree
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        return INT16_MAX;
    }
     // minimum of root, minimum return by left subtree and right subtree
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool check_BST(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return true;
    }
    int max_left=maximum(root->left);
    int mini_right=minimum(root->right);
    // check condition on root node
    bool output = (max_left < root->data) && (mini_right >= root->data);
    // call recursion for check on left and right subtree also
    bool output1= (check_BST(root->left) && check_BST(root->right)); 
    return output && output1;
}
int main()
{
    BinaryTreeNode*root= take_input();
    print_identical(root);
    if(check_BST(root))
    {
        cout<<"True"<<endl;
    }
    else
    cout<<"False "<<endl;
    return 0;
}