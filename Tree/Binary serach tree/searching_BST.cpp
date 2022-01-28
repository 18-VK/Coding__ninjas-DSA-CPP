#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
// time compexity - O(logn)
BinaryTreeNode *Search(BinaryTreeNode *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (x == root->data)
    {
        return root;
    }
    if (x > root->data)
    {
        return Search(root->right, x);
    }
    else if (x < root->data)
    {
        return Search(root->left, x);
    }
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    int x;
    cout << "Enter the node data " << endl;
    cin >> x;
    if (Search(root, x) != NULL)
        cout << "yes it is present " << endl;
    else
        cout << "Not Present " << endl;
    return 0;
}