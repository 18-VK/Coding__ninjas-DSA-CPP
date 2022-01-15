#include<iostream>
#include"Print_and_take_input.cpp"
using namespace std;
// Given a integer depth or level
// we have to print all elements on that level
void print_Klevel(treeNode* root,int k)
{
    if(root==NULL) //edge case
    {
        return;
    }
    if(k==0)
    {
     cout<<root->data<<" ";
     return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        print_Klevel(root->children[i],k-1);
    }
}
int main()
{
 treeNode *root=input_levelWise();
 int k;
 cout<<"Enter the level/depth from which you want to print "<<endl;
 cin>>k;
 print_Klevel(root,k);
 cout<<endl;
    return 0;
}