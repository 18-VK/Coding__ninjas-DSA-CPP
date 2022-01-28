#include <iostream>
#include <vector>
#include "Impl_binary_tree.h"
using namespace std;
/*
 Given a binary tree and a number k,
 print out all root to leaf paths where the sum of all nodes value is same as the given number k.
 solution video
 https://www.youtube.com/watch?v=QmCHj7NX1TU&t=367s
*/
void print_vec(vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
void helper(BinaryTreeNode *root, vector<int> &temp, int target, int sum)
{
    if (root == NULL)
    {
        return;
    }
    temp.push_back(root->data);
    sum = sum + root->data;
    // if we sum is equals to target and we are at leaf node
    if (sum == target and root->left == NULL and root->right == NULL)
    {
        print_vec(temp);
    }
    helper(root->left, temp, target, sum);
    helper(root->right, temp, target, sum);
    // we we dont get path that we want then pop element from  vector
    temp.pop_back(); // removing elements using backtracking
}
void print_root_to_leaf_k(BinaryTreeNode *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> temp;
    int sum = 0;
    helper(root, temp, k, sum);
    return;
}
// method 2
void rootToLeafPathsSumToK(BinaryTreeNode *root, int k, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);
    k = k - root->data; // updating target value

    if (!root->left && !root->right) // leaf node
    {
        if (k == 0) // if root to leaf sum is equal to k then print
        {
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        path.pop_back(); // removing element from vector path
        return;
    }
    rootToLeafPathsSumToK(root->left, k, path);
    rootToLeafPathsSumToK(root->right, k, path);
}
void rootToLeafPathsSumToK(BinaryTreeNode *root, int k)
{
    vector<int> v;
    rootToLeafPathsSumToK(root, k, v);
    return;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_identical(root);
    int k;
    cin >> k;
    cout << "Paths " << endl;
    // print_root_to_leaf_k(root, k);
    rootToLeafPathsSumToK(root, k);
    return 0;
}