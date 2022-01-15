#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
int height_(treeNode *root)
{
    if (root == NULL)
    {
        return INT16_MIN;
    }
    int high = 1; // assume  height from 1 ,In some case it can start from 0
    // recursion call for subtree
    for (int i = 0; i < root->children.size(); i++)
    {
        int subtree = height_(root->children[i]);
        if(subtree>=high)  
        {high = subtree + 1; }// total height= max subtree height + 1 for root
    }
    return high;
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << "Height: " << height_(root) << endl;
    return 0;
}