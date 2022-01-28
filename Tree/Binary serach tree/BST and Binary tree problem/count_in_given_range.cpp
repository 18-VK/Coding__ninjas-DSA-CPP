#include<iostream>
#include"Impl_binary_tree.h"
using namespace std;
int getCount(BinaryTreeNode *root, int l, int h)
{
  if(root==NULL)
  {
      return 0;
  }
  if(root->data>=l && root->data<=h) // if range start from left tree and end to right tree
  {
      return 1+ getCount(root->right,l,h)+getCount(root->left,l,h);
  }
  else if(l>root->data) // range lies in right subtree
  {
     return getCount(root->right,l,h);
  }
  else 
  {
      return getCount(root->left,l,h);
  }
}
int main()
{
    BinaryTreeNode *root=take_input();
    print_identical(root);
    int low,high;
    cin>>low>>high;
    cout<<"Count between given  range "<<getCount(root,low,high);
    return 0;
}