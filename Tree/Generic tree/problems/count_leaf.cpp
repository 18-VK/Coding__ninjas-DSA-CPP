#include<iostream>
#include"Print_and_take_input.cpp"
using namespace std;
int count_leaf(treeNode *root)
{
    if(root==NULL)//edge case
    {
        return INT16_MIN;
    }
    int count=0;
    if(root->children.size()==0) // 
    {
        return 1;
    }
    for(int i=0;i<root->children.size();i++)
    {
       int subtree=count_leaf(root->children[i]);
       count+=subtree;
    }
    return count;
}
int main()
{
 treeNode *root=input_levelWise();
 print_levelWise(root);
 cout<<"Leaf Nodes: "<<count_leaf(root)<<endl;
    return 0;
}