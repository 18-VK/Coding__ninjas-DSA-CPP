#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
// Given a generic tree, find and return the node for which sum of its data and
//  data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
class Pair
{
  public:
   int sum;
   treeNode *temp;
};
Pair max_sum(treeNode *root)
{
    // create pair to store that node and sum of that node
    Pair p; 
    p.sum=INT16_MIN;
    p.temp=NULL;
    if (root->data > p.sum)
    {
        p.sum = root->data;
        p.temp = root;
    }
    // sum of given root's children
    for (int i = 0; i < root->children.size(); i++)
    {
        p.sum = p.sum + root->children[i]->data;
    }
    // call recursion for subtrees
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair subtree = max_sum(root->children[i]);
        if (subtree.sum > p.sum)
        {
            p.sum = subtree.sum;
            p.temp=subtree.temp;
        }
    }
    return p;
}
int main()
{

    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << "Node with max sum: " << max_sum(root).temp->data<< endl;
    return 0;
}