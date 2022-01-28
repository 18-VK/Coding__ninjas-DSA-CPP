#include <iostream>
#include "Impl_binary_tree.h"
using namespace std;
/*
You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
1. Target Node: 5
2. K = 2
solution video-https://www.youtube.com/watch?v=f-oTsCUCiXk
*/

// case 1 node's subtree
void print_at_depth(BinaryTreeNode *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data <<endl;
        return;
    }
    print_at_depth(root->left, k - 1);
    print_at_depth(root->right, k - 1);
}
// case 2- Node's ancestors
// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int print_distance_k(BinaryTreeNode *root, int target,int k)
{
     // Base Case 1: If tree is empty, return -1 
    if (root == NULL)
    {
        return -1;
    }
      // If target is same as root.  Use the downward function 
    // to print all nodes at distance k in subtree rooted with 
    // target or root 
    if (root->data == target)
    {
        // case 1
        print_at_depth(root, k);
        return 0; // returning node's distance from it's ancestors
    }
     // Recur for left subtree 
    int dl = print_distance_k(root->left, target, k);
       // Check if target node was found in left subtree 
    if (dl != -1)
    {
          // If root is at distance k from target, print root 
         // Note that dl is Distance of root's left child from target 
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
          // Else go to right subtree and print all k-dl-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
        else
        {
            print_at_depth(root->right, k - dl - 2);
        }
         // Add 1 to the distance and return value for parent calls 
        return 1 + dl;
    }
      // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
    // Note that we reach here only when node was not found in left subtree 
    int dr = print_distance_k(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
      
        else
        {
            print_at_depth(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
      // If target was neither present in left nor in right subtree 
    return -1;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    int target, k;
    cin >> target >> k;
    cout<<"Nodes at distance k : "<<endl;
    print_distance_k(root, target, k);
    return 0;
}