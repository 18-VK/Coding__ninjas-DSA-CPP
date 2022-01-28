#include <iostream>
#include "print_identical_structure.cpp"
using namespace std;
void nodesWithoutSibling(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->left && !root->right)
    {
        cout << root->left->data << endl;
    }
    else if (!root->left && root->right)
    {
        cout << root->right->data << endl;
    }
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    print_identical(root);
    cout << "Nodes with no siblings" << endl;
    nodesWithoutSibling(root);
    return 0;
}