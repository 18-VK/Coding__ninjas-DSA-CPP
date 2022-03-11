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
class AVL_node
{
public:
    int data;
    AVL_node *left;
    AVL_node *right;
    int height;
    AVL_node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1; // height of every leaf node is 1
    }
    ~AVL_node()
    {
        delete left;
        delete right;
    }
};
// return height at given node
int get_height(AVL_node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}
int getbalance_fact(AVL_node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return get_height(node->right) - get_height(node->left);
}
// we dont need to code for double rotation, we can use single rotation
// to perform double rotation
AVL_node *single_Rotation_RR(AVL_node *y)
{
    AVL_node *x = y->left;
    AVL_node *T2 = x->right;
    x->right = y;
    y->left = T2;
    // update heights
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    return x;
}
AVL_node *single_Rotation_LL(AVL_node *x)
{
    AVL_node *y = y->right;
    AVL_node *T2 = y->left;
    y->left = x;
    x->right = T2;
    // update heights
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    return y;
}
AVL_node *insert(int data, AVL_node *node)
{
    if (node == NULL)
    {
        AVL_node *new_node = new AVL_node(data);
        return new_node;
    }
    if (data > node->data)
    {
        node->right = insert(data, node->right);
    }
    else
    {
        node->left = insert(data, node->left);
    }
    return node;
    // update height after insertion
    node->height = 1 + max(get_height(node->right), get_height(node->left));
    // check balance factor if not balance then make it balanced
    int bf = getbalance_fact(node);
    // now there are 4 cases

    // 1. left left insertion case - insertion in left of left subtree make tree unbalance
    // perform- RR rotation
    if (bf > 1 && data < node->left->data)
    {
        return single_Rotation_RR(node);
    }
    // 2. right right insertion case- insertion in right of right subtree make tree unbalance
    // perform- LL rotation
    if (bf <-1 && data > node->right->data)
    {
        return single_Rotation_LL(node);
    }
    // 3. left right insertion- insertion in left of right subtree make tree unbalance
    // perform- RL rotation
    if (bf <-1 && data < node->right->data)
    {
        node->right = single_Rotation_RR(node->right);
        return single_Rotation_LL(node);
    }
    // 4.right left insertion- insertion in right of left subtree make tree unbalance
    //  perform- LR rotation
    if (bf > 1 && data > node->left->data)
    {
        node->left = single_Rotation_LL(node->left);
       return  single_Rotation_RR(node);
    }
    return node;
}
void PreOrder(AVL_node *root)
{
    if (root != NULL) // base case
    {
     cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    }
}
void inorder(AVL_node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}
int main()
{
    AVL_node *root =NULL;
    root=insert(1,root);
    root= insert(2,root);
    root= insert(4,root);
    root= insert(5,root);
    root= insert(6,root);
    root= insert(3,root);
    PreOrder(root);
    cout<<endl;
    inorder(root);
 return 0;
}