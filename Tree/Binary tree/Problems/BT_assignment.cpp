#include <iostream>
#include "print_identical_structure.cpp"
using namespace std;
int count_node(BinaryTreeNode *root)
{
    if (root == NULL) // base case
    {
        return 0;
    }
    int count = 1;
    // method 1
    // if (root->left != NULL)
    // {
    //     int temp1 = count_node(root->left);
    //     count = count + temp1;
    // }
    // if (root->right != NULL)
    // {
    //     int temp2 = count_node(root->right);
    //     count = count + temp2;
    // }
    // method-2
    return count+count_node(root->left)+count_node(root->right);
}
bool check(BinaryTreeNode* root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    bool ans=false;
    if(root->data==x)
    {
        ans=true;
        return ans ;
    }
    if(root->left!=NULL)
    {
       ans= check(root->left,x);
       if(ans==true)
       {
           return ans;
       }
    }
    if(root->right!=NULL)
    {
        ans=check(root->right,x);
         if(ans==true)
       {
           return ans;
       }
    }
    return ans;
}
int height_(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int height=1;
    int count=height_(root->left);
    int count1=height_(root->right);
    height=height +max(count,count1);
    return height;
}
void mirror_tree(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    // swaping left and right
    BinaryTreeNode *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror_tree(root->left);
    mirror_tree(root->right);
}
int main()
{
    BinaryTreeNode *root = take_input();
   // print_levelwise(root);
    cout << "Count node : " << count_node(root) << endl;
    // int x;
    // cout<<"enter element "<<endl;
    // cin>>x;
    // if(check(root,x))
    // {
    //     cout<<"true"<<endl;
    // }
    // else{cout<<"false"<<endl;}
   // cout<<"Height: "<<height_(root)<<endl;
     print_identical(root);
     mirror_tree(root);
     cout<<"after mirror"<<endl;
     print_identical(root);
    return 0;
}