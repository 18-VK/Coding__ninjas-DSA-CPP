#include <iostream>
using namespace std;
/*
    y                               x
   / \    right rotation           / \
  x  T3      --------->           T1  y
 / \         <--------               / \
T1 T2     left rotation             T2  T3
 *follow above tree to implement rotation functions
Note- we have to perform rotation on the first node that is not satisfy
      AVL property, Not on the root
*/
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

Node *insert(Node *node, int key)
{
    /* 1. Perform the normal BST rotation */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this
        ancestor node to check whether
        this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left  insertion Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right  insertion Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right insertion  Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left insertion  Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
Node *minValueNode(Node *node)
{
    Node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
Node *Delete_helper(int element, Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == element)
    {
        // condition 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // condition 2
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            root->left = NULL; // breaking connection
            delete root;
            return temp; // updated root
        }
        // condition 3
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            root->right = NULL; // breaking connection
            delete root;
            return temp; // updated root
        }
        // condition 4 - if both are not NULL
        // find perfect replacement for root- it can be max element of left subtree or min element of right subtree
        // so that after replacement Tree should match BST  properties
        else
        {
            Node *R_min = root->right;  // root of right subtree
            while (R_min->left != NULL) // we will get minimum element in left side of right subtree
            {
                R_min = R_min->left;
            }
            root->key = R_min->key;
            // delete R_min from right subtree
            root->right = Delete_helper(R_min->key, root->right);
            return root;
        }
    }
    // calling subtree
    if (element > root->key)
    {
        root->right = Delete_helper(element, root->right);
    }
    else if (element < root->key)
    {
        root->left = Delete_helper(element, root->left);
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    root = Delete_helper(key, root);
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
            9
        / \
        1 10
        / \ \
    0 5 11
    / / \
    -1 2 6
    */

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
        / \
        0 9
        / / \
    -1 5	 11
        / \
        2 6
    */

    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);

    return 0;
}