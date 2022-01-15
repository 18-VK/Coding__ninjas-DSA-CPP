#include<iostream>
#include"Impl_binary_tree.cpp"
using namespace std;
// preOrder and level wise we have done in file Impl_binary_tree.cpp
void printPostOrder(BinaryTreeNode *root)
{
 if(root==NULL)//base case
 {
     return;
 }
 printPostOrder(root->left);
 printPostOrder(root->right);
 cout<<root->data<<" ";
}
int main()
{
    BinaryTreeNode *root=take_input();
  //  printPreOrder(root);
    cout<<endl<<" Print postOrder "<<endl;
    printPostOrder(root);
    return 0;
}