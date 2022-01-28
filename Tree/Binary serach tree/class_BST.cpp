#include <iostream>
using namespace std;
/*Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children,
 replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y

wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
    BinaryTreeNode *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool search_helper(int x, BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data == x)
        {
            return true;
        }
        else if (x < root->data)
        {
            return search_helper(x, root->left);
        }
        else if (x > root->data)
        {
            return search_helper(x, root->right);
        }
    }
    void printTree_helper(BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree_helper(root->left);
        printTree_helper(root->right);
    }
    BinaryTreeNode *insert_helper(int element, BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode *new_node = new BinaryTreeNode(element);
            return new_node;
        }
        if (element < root->data)
        {
            root->left = insert_helper(element, root->left);
        }
        else
        {
            root->right = insert_helper(element, root->right);
        }
        return root;
    }
    BinaryTreeNode *Delete_helper(int element, BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == element)
        {
            // condition 1
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            //condition 2
            if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode *temp = root->left;
                root->left = NULL; // breaking connection
                delete root;
                return temp; // updated root
            }
            // condition 3
            if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode *temp = root->right;
                root->right = NULL; // breaking connection
                delete root;
                return temp; // updated root
            }
            // condition 4 - if both are not NULL
            // find perfect replacement for root- it can be max element of left subtree or min element of right subtree
            // so that after replacement Tree should match BST  properties
            else
            {
                BinaryTreeNode *R_min = root->right; // root of right subtree
                while (R_min->left != NULL)          // we will get minimum element in left side of right subtree
                {
                    R_min = R_min->left;
                }
                root->data = R_min->data;
                // delete R_min from right subtree
                root->right = Delete_helper(R_min->data, root->right);
                return root;
            }
        }
        // calling subtree
        if (element > root->data)
        {
            root->right = Delete_helper(element, root->right);
        }
        else if (element < root->data)
        {
            root->left = Delete_helper(element, root->left);
        }
        return root;
    }

public:
    bool search(int x)
    {
        return search_helper(x, root);
    }
    void PrintTree()
    {
        printTree_helper(this->root);
    }
    void insert(int element)
    {
        // BST class root
        this->root = insert_helper(element, this->root);
    }
    void Delete(int element)
    {
        this->root = Delete_helper(element, this->root);
    }
};
int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.PrintTree();
    b.Delete(20);
    b.Delete(10);

    b.PrintTree();
    if (b.search(7))
    {
        cout << "Node found" << endl;
    }
    else
    {
        cout << "Node is not found" << endl;
    }
    return 0;
}