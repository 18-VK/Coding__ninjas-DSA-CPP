#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
int sum_of_nodes(treeNode *root)
{
    if (root == NULL) // edge case
    {
        return INT16_MIN;
    }
    int sum = root->data;
    // taking sum of nodes of substrees using recursion
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sum_of_nodes(root->children[i]);
    }
    return sum;
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << "Sum of nodes: " << sum_of_nodes(root) << endl;

    return 0;
}