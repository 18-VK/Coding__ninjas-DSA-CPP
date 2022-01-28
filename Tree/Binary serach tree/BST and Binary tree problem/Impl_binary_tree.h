#include <iostream>
#include <queue>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        left = NULL;
        right = NULL;
        this->data = data;
    }
    // destructor for delete node and their children
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void printPreOrder(BinaryTreeNode *root)
{
    if (root == NULL) // base case
    {
        return;
    }
    // here we have need of base case because we are not using loop
    // we have to use base case to stop recusrion call
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printPreOrder(root->left);
    printPreOrder(root->right);
}
// level wise
BinaryTreeNode *take_input()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    // -1 means user dont want to add node
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    // queue to maintain order of nodes
    queue<BinaryTreeNode *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        BinaryTreeNode *front_ = pendingNode.front();
        pendingNode.pop();
        int left;
        cout << "Enter left node of " << front_->data << endl;
        cin >> left;
        if (left != -1)
        {
            BinaryTreeNode *leftChild = new BinaryTreeNode(left);
            pendingNode.push(leftChild);
            front_->left = leftChild;
        }
        int right;
        cout << "Enter right node of " << front_->data << endl;
        cin >> right;
        if (right != -1)
        {
            BinaryTreeNode *rightChild = new BinaryTreeNode(right);
            pendingNode.push(rightChild);
            front_->right = rightChild;
        }
    }
    return root;
}
// level wise print
void print_levelwise(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {
        BinaryTreeNode *front_=pendingNode.front();
        pendingNode.pop();
        cout<<front_->data<<" : ";
        if(front_->left!=NULL)
        {
            cout<<"L"<<front_->left->data<<" , ";
            pendingNode.push(front_->left);
        }
        else
        {
            cout<<"L-1"<<" , ";
        }
        if(front_->right!=NULL)
        {
            cout<<"R"<<front_->right->data;
            pendingNode.push(front_->right);
        }
        else
        {
            cout<<"R-1";
        }
        cout<<endl;
    }
}
void print_identical(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode*> pending;
    pending.push(root);
    pending.push(NULL);
    while(!pending.empty())
    {
        BinaryTreeNode *front=pending.front();
        pending.pop();
        if(front==NULL)
        {
            if(pending.empty()) 
            {
                break;
            }
            cout<<endl;
            pending.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        if(front->left!=NULL)
        {
            pending.push(front->left);
        }
        if(front->right!=NULL)
        {
            pending.push(front->right);
        }
    }
    cout<<endl;
}