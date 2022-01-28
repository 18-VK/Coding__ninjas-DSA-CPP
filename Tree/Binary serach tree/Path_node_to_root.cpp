#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
// return path from node to root(not root to node)
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class helper
{
public:
    Node *head;
    Node *tail;
};
// use post order traversal
helper *helper_func(BinaryTreeNode *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    helper *left_tree;
    helper *right_tree;
    Node *root_node = new Node(root->data);
    helper *output = new helper();
    if (root->data == k)
    {
        output->head = root_node;
        output->tail = root_node;
        return output;
    }
    if (k < root->data)
    {
        left_tree = helper_func(root->left, k);
        if (left_tree->head == NULL)
        {
            return NULL;
        }
        output->head = left_tree->head;
        // if path found connect root
        left_tree->tail->next = root_node;
        output->tail=root_node;
        return output;
    }
    if (k > root->data)
    {
        right_tree = helper_func(root->right, k);
        if (right_tree->head == NULL)
        {
            return NULL;
        }
        output->head = right_tree->head;
        // if path found connect root
        right_tree->tail->next = root_node;
        output->tail=root_node;
        return output;
    }
}
Node *Path_node_to_root(BinaryTreeNode *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    helper *output = helper_func(root, k);
    return output->head;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    print_identical(root);
    int k;
    cin >> k;
    Node *head = Path_node_to_root(root, k);
    Node *temp = head;
    cout << "Output List" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}