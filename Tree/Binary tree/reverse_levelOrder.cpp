#include<iostream>
#include<bits/stdc++.h>
#include"Impl_binary_tree.cpp"
using namespace std;
// Method-1 find height 
// Time O(n^2) with constant space
int height(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return 1+height(root->left)+height(root->right);
}
void printCurrentLevel(BinaryTreeNode *root,int level)
{
   if(root==NULL)
   {
       return;
   }
   if(level==1)
   {
       cout<<root->data<<" ";
   }
   else if(level >1)
   {
       printCurrentLevel(root->left,level-1);
       printCurrentLevel(root->right,level-1);
   }
}
void Print_ReverseLevelOrder(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    int high=height(root);
    for(int i=high;i>=1;i--)  // bottom to up approach
    {
       printCurrentLevel(root,i);
    }
}
//method 2- using queue and stack
// time O(n) with extra space
void print_reverse_optimise(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode *> q;
    stack<BinaryTreeNode *> s;
    q.push(root);
   while(!q.empty())
   {
     BinaryTreeNode *node=q.front();
     q.pop();
     s.push(node);
     if(node->right!=NULL)// NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
     {
         q.push(node->right);
     }
     if(node->left!=NULL)
     {
         q.push(node->left);
     }
   }
   // print using stack
   while(!s.empty())
   {
       BinaryTreeNode *node=s.top();
       s.pop();
       cout<<node->data<<" ";
   }
}
int main()
{
    BinaryTreeNode *root=take_input();
    //Print_ReverseLevelOrder(root);
    print_reverse_optimise(root);
    return 0;
}