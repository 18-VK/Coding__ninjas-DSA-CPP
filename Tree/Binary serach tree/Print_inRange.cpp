#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
void print_xy(BinaryTreeNode *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }
    // we have to print in ascending order/increasing oder so we can use inorder
    // In,Inorder of BST elements come out in ascending order
    if(x< root->data)
    {
        print_xy(root->left,x,y);
    }
    if(root->data >=x && root->data <=y)
    {
      cout<<root->data<<" ";
    }
    // x > root->data or y > root->data that means all elemnets are in right subtree
    print_xy(root->right,x,y);
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    int x, y;
    cout << "Enter x and y range respectively " << endl;
    cin >> x >> y;
    print_xy(root, x, y);
    return 0;
}