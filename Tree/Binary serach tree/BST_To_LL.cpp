#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
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
class Pair
{
public:
    Node *head;
    Node *tail;
};
void print_LL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// use Inorder traversal so, we will get LL in sorted order
Pair helper(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;
    }
    // all nodes in left tree has smaller data than root
    // all nodes in right tree has bigger data than root
    Node *new_node=new Node(root->data);
    Pair left_tree =helper(root->left); // left subtree call
    Pair right_tree=helper(root->right);// right subtree call
    Pair ans;
    if(left_tree.head!=NULL)
    {
        ans.head=left_tree.head;
        ans.tail=left_tree.tail;
        // connecting root to end of left subtree
        ans.tail->next=new_node;
        ans.tail=new_node;
    }
    else if(left_tree.head==NULL)
    {
        ans.head=new_node;
    }
    if(right_tree.head!=NULL)
    {
        // connecting root to head of right subtree
        new_node->next=right_tree.head;
        ans.tail=right_tree.tail;
    }
    else if(right_tree.head==NULL)
    {
        ans.tail=new_node;
    }

    return ans;
}
Node *BST_To_LL(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Pair output = helper(root);
    return output.head;
}

int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    Node *head = BST_To_LL(root);
    cout << "Output Linked list " << endl;
    print_LL(head);
    return 0;
}