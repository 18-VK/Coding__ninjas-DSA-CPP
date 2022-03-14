#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
/*
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not.
Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
*/
bool isSibling(BinaryTreeNode *root,int p,int q)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->left !=NULL && root->right!=NULL)
    {
        int left=root->left->data;
        int right=root->right->data;
        if(left==p && right==q)
        {
            return true;
        }
        else if(left==q && right==p)
        {
            return true;
        }
    }
    if(root->left!=NULL)
    {
        isSibling(root->left,p,q);
    }
    if(root->right!=NULL)
    {
        isSibling(root->right,p,q);
    }
}
int level(BinaryTreeNode *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    int l = 1 + level(root->left, key);
    if (l != 0)
    {
        return l;
    }
    else
        return 1 + level(root->right, key);
}
bool check_cousin(BinaryTreeNode *root, int p, int q)
{
    if (root == NULL)
    {
        return false;
    }
  if(level(root,p)==level(root,q) && isSibling(root,p,q)==false)
  {
      return true;
  }
  else
  {
      return false;
  }
}

int main()
{
    BinaryTreeNode *head = take_input();
    int p, q;
    cout << "Enter p and q" << endl;
    cin >> p >> q;
    if(check_cousin(head, p, q))
    {
        cout<<"true"<<endl;
    }
    else
    cout<<"false"<<endl;
    return 0;
}