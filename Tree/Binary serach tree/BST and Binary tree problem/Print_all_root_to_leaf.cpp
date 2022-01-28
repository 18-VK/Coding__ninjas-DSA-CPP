#include<iostream>
#include"Impl_binary_tree.h"
using namespace std;
/*
https://www.youtube.com/watch?v=JPspskkZn9E&t=193s
https://www.youtube.com/watch?v=t2Ui-ePoDqs&t=326s
solution video 
*/
void print_path(int temp[],int idx)
{
    for(int i=0;i<idx;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void helper(BinaryTreeNode *root,int temp[],int idx)
{
    if(root==NULL)
    {
        return;
    }
    temp[idx]=root->data;
    idx++;
    if(root->left==NULL && root->right==NULL)
    {
        print_path(temp,idx);
    }
    else
    {
        helper(root->left,temp,idx);
        helper(root->right,temp,idx);
    }
}
void print_all_root_to_leaf(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    int temp[1000];
    helper(root,temp,0);
}
int main()
{
    BinaryTreeNode *root=take_input();
    print_identical(root);
    cout<<"All paths from root to leaf "<<endl;
    print_all_root_to_leaf(root);
    // we can also create vector of vector to store all paths
    return 0;
}