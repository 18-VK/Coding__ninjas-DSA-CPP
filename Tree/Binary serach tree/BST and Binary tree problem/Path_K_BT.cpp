#include <iostream>
#include <vector>
#include "Impl_binary_tree.h"
using namespace std;
bool helper_path(BinaryTreeNode *root, BinaryTreeNode* target, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root == target)
    {
        return true;
    }
    else if (helper_path(root->left, target, path) == true)
    {
        return true;
    }
    else if (helper_path(root->right, target, path) == true)
    {
        return true;
    }
    path.pop_back();
    return false;
}
vector<int> path_root_to_leaf(BinaryTreeNode *root, BinaryTreeNode *target)
{
    vector<int> path;
    if (root == NULL)
    {
        return path;
    }
    helper_path(root, target, path);
    return path;
}
vector<BinaryTreeNode *> output;
vector<BinaryTreeNode *> find_leaf(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return output;
    }
    if (root->left == NULL && root->right == NULL)
    {
        output.push_back(root);
    }
    output = find_leaf(root->left);
    output = find_leaf(root->right);
    return output;
}
void print_ans(vector<int> ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    BinaryTreeNode *root = take_input();
    print_levelwise(root);
    vector<BinaryTreeNode *> leafs;
    leafs = find_leaf(root);
    vector<vector<int>> ans;
    for (int i = 0; i < leafs.size(); i++)
    {
        vector<int> temp;
        temp = path_root_to_leaf(root, leafs[i]);
        ans.push_back(temp);
    }
    int k;
    cin>>k;
    for(int i=0;i<ans.size();i++)
    {
       int sum=0;
       for(int j=0;j<ans[i].size();j++)
       {
          sum=sum+ans[i][j];
       }
       if(sum==k)
       {
           print_ans(ans[i]);
           sum=0;
       }
    }
    return 0;
}