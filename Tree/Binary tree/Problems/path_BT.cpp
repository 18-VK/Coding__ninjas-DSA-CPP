#include<iostream>
#include<vector>
#include"print_identical_structure.cpp"
using namespace std;
// Given BT and a node value return path from root to that node
bool helper(BinaryTreeNode *root,vector<int> &ans,int k)
{
  if(root==NULL)
  {
      return false;
  }
  ans.push_back(root->data);
  if(root->data==k)
  {
      return true;
  }
  // call recursion and check if element found 
 if(helper(root->left,ans,k)==true || helper(root->right,ans,k)==true)
 {
     return true;
 }
 ans.pop_back(); // node  not found then pop and return false
 return false;
}
vector<int> path_root_to_node(BinaryTreeNode *root,int k)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    helper(root,ans,k);
    return ans;
}
// Given BT and a node value return path from node to root
// we have to use traversal LRN(left right then root)
bool helper_2(BinaryTreeNode *root,vector<int> &ans,int k)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==k)
    {
        ans.push_back(root->data);
        return true;
    }
    // whenever function call get true push that calling node
    if(helper_2(root->left,ans,k)==true )
    {
        ans.push_back(root->data);
        return true;
    }
    if( helper_2(root->right,ans,k)==true)
    {
     ans.push_back(root->data);
     return true;
    }
    return false;
}
vector<int> path_node_to_root(BinaryTreeNode *root,int k)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    helper_2(root,ans,k);
    return ans;
}
int main()
{
    BinaryTreeNode *root=take_input();
    print_identical(root);
    int k;
    cin>>k;

    vector<int> output;
    output = path_root_to_node(root,k);
    cout<<"Path from root to given node "<<endl;
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    vector<int> output2;
    output2 = path_node_to_root(root,k);
    cout<<"Path from given node to root "<<endl;
    for(int i=0;i<output2.size();i++)
    {
        cout<<output2[i]<<" ";
    }
    cout<<endl;
    return 0;
}