#include<iostream>
#include"Impl_binary_tree.h"
using namespace std;
// method 2 time complexity- O(N)
class IsBST_return
{
   public:
    bool isBST;
    int maxi,mini;
};
IsBST_return helper(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        IsBST_return output;
        output.isBST=true;
        output.maxi=INT16_MIN;
        output.mini=INT16_MAX;
        return output;
    }
    // call left and right subtree
    IsBST_return LeftOutput=helper(root->left); //1
    IsBST_return rightOutput =helper(root->right); //2
    // overall max and min
    int maxi=max(root->data,max(LeftOutput.maxi,rightOutput.maxi)); //3
    int mini=min(root->data,min(LeftOutput.mini,rightOutput.mini));  //4
    // check condition 1 and 2
    bool temp= LeftOutput.isBST && rightOutput.isBST;
    bool temp1= (root->data >LeftOutput.maxi) && (root->data<=rightOutput.mini);
    bool final_BST =temp1 && temp;  // storing final ouput
    
    IsBST_return output;
    output.isBST=final_BST;
    output.maxi=maxi; 
    output.mini=mini;
    return output;
}
bool check_BST2(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return true;
    }
    IsBST_return ans=helper(root);
    return ans.isBST;
}
int main()
{
    BinaryTreeNode *root=take_input();
    print_identical(root);
     if(check_BST2(root))
    {
        cout<<"True"<<endl;
    }
    else
    cout<<"False "<<endl;
    return 0;
}