#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class treeNode
{
public:
    int data;
    vector<treeNode *> children; // storing  pointer in vector
    treeNode(int data)
    {
        this->data = data;
    }
};
// method 1
// disadvantage- creating confustion while giving input
// It is call preOrder traversal
// treeNode *input()
// {
//     int rootData;
//     cout << "Enter Data" << endl;
//     cin >> rootData;
//     // creating root node
//     treeNode *root = new treeNode(rootData);
//     int n;
//     cout << "Enter the numbers children of " << rootData << endl;
//     cin >> n;
//     // adding substree of root using recusion call
//     for (int i = 0; i < n; i++)
//     {
//         treeNode *child = input();
//         // connecting root with child
//         root->children.push_back(child);
//     }
//     return root;
// }

// method 1

// void print(treeNode *root)
// {
//     if (root == NULL) // its a egde case not a base case
//     {
//         return;
//     }
//     // note :- In this, we will never hit case where root is NULL
//     //    and we are call function uswing loop, loop will terminate itself
//     // so there are no need of base case
//     cout << root->data << ": ";
//     // printing children of given root
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children[i]->data << ", ";
//     }
//     cout << endl;
//     // recursive call for children of given root
//     // so children can print their child also
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         print(root->children[i]);
//     }
// }

// method 2 level wise take input and printing tree
// preferable to use
// It is call levelOrder traversal
treeNode *input_levelWise()
{
    int rootData;
    cout << "Enter the data of root node" << endl;
    cin >> rootData;
    treeNode *root = new treeNode(rootData);
    // use queue to maintain the order of input,saving addresses of all nodes in tree
    queue<treeNode *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0) // untill empty
    {
        treeNode *front = pendingNode.front();
        pendingNode.pop();
        int numChild;
        cout << "Enter the number of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            // creating children
            int childData;
            cout << "Enter the data of " << i << "th child of " << front->data << endl;
            cin >> childData;
            treeNode *child = new treeNode(childData);
            // connecting children
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    // queue empty mean tree has completed no node is pending
    return root;
}
void print_levelWise(treeNode *root)
{
    if (root == NULL) // edge case
    {
        return;
    }
    // queue to maintain order
    queue<treeNode *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        treeNode* front=pendingNode.front();
        pendingNode.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNode.push(front->children[i]);
        }
        cout<<endl;
    }
}
// Post order traversal
// root node will print in last 
void print_postOrder(treeNode* root)
{
     if(root==NULL)//edge case
     {
         return ;
     }
    for(int i=0;i<root->children.size();i++)
    {
        print_postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
// int main()
// {
//     treeNode *root = input_levelWise();
//     print_levelWise(root);
//     print_postOrder(root);
//     return 0;
// }