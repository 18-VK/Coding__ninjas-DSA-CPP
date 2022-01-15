#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
// using recursion
//  Apporach -count root node and call recursion of substrees
int count_node(treeNode *root)
{
    if (root == NULL) // edge case, not base case
    {
        return INT16_MIN;
    }
    int count = 1; // 1 for root
    // recursion call for children/subtrees
    for (int i = 0; i < root->children.size(); i++)
    {
        count += count_node(root->children[i]);
    }
    return count;
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << "Number(s) of node: " << count_node(root) << endl;

    return 0;
}