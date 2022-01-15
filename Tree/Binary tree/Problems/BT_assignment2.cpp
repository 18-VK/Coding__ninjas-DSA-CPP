#include <iostream>
#include "Impl_binary_tree.cpp"
using namespace std;
int sum_nodes(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data;
    return sum + sum_nodes(root->left) + sum_nodes(root->right);
}
void level_order_traversal(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode *> pending;
    pending.push(root);
    pending.push(NULL);
    while (!pending.empty())
    {
        BinaryTreeNode *front = pending.front();
        pending.pop();
        if (front == NULL)
        {
            if (pending.empty())
            {
                break;
            }
            cout << endl;
            pending.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if (front->left != NULL)
        {
            pending.push(front->left);
        }
        if (front->right != NULL)
        {
            pending.push(front->right);
        }
    }
}
BinaryTreeNode *remove_leaf(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    root->left = remove_leaf(root->left);
    root->right = remove_leaf(root->right);
    return root;
}
int main()
{
    BinaryTreeNode *root = take_input();
    // printPreOrder(root);
    // cout<<"Sum of nodes: "<<sum_nodes(root)<<endl;
    level_order_traversal(root);
    root = remove_leaf(root);
    cout << endl<<"After removing leaf"<<endl;
    level_order_traversal(root);

    return 0;
}