#include <iostream>
#include <vector>
using namespace std;
// using vector
// children of root node are created by vector
template<typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T>*> children; //storing  pointer in vector
    treeNode(int data)
    {
        this->data = data;
    }
};
int main()
{
    treeNode<int> *root = new treeNode<int>(1); // created root node
     // created children nodes
    treeNode<int> *node1 = new treeNode<int>(2);
    treeNode<int> *node2 = new treeNode<int>(3);
    // all nodes are independence becoz we have'nt linked  them yet
    // root node contain a  vector children
    // To create children of root node we have to push nodes to that vector
    root->children.push_back(node1);
    root->children.push_back(node2);
    cout<<root->data<<endl;
    cout<<root->children.at(0)->data<<endl;
    cout<<root->children.at(1)->data<<endl;

    return 0;
}