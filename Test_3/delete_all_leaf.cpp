#include<iostream>
#include"Print_and_take_input.h"
using namespace std;
treeNode* remove_leaf(treeNode *root)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->children.size()==0)
    {
        delete root;
        return NULL;
    }
    for(int i=0;i< root->children.size();i++)
    {
    root->children[i]=remove_leaf(root->children[i]);
    }
    return root;
}
int main()
{
    treeNode *root=input_levelWise();
    root=remove_leaf(root);
    print_levelWise(root);
    return 0;
}