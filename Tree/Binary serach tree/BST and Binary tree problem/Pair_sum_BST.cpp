/*Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

#include <bits/stdc++.h>
#include "Impl_binary_tree.h"
using namespace std;
// use inorder to get sorted array of elements
void InOrder(BinaryTreeNode *root, vector<int> &output)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, output);
    output.push_back(root->data);
    InOrder(root->right, output);
}
void nodesSumToS(BinaryTreeNode *root, int target)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> output;
    InOrder(root, output);
    int i = 0;
    int j = output.size() - 1;
    while (i < j)
    {
        if (output[i] + output[j] == target)
        {
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
        else if (output[i] + output[j] < target)
        {
            i++;
        }
        else if (output[i] + output[j] > target)
        {
            j--;
        }
    }
}
    int main()
    {
        BinaryTreeNode *root = take_input();
        print_identical(root);
        cout << "Sum" << endl;
        int sum;
        cin >> sum;
        nodesSumToS(root, sum);
        return 0;
    }