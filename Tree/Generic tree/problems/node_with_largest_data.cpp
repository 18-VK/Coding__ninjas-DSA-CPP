#include<iostream>
#include"Print_and_take_input.cpp"
using namespace std;
treeNode* largest_node(treeNode *root)
{
   if(root==NULL){return NULL;} //edge case

   treeNode *ans=root;
   for(int i=0;i<root->children.size();i++)
   {
       treeNode* subtree=largest_node(root->children[i]);
       if(subtree->data>ans->data)
       {
           ans=subtree;
       }
   }
   return ans;
}
int main()
{
treeNode* root=input_levelWise();
print_levelWise(root);
treeNode *answer=largest_node(root);
cout<<"Node with maximum data: "<<answer->data<<endl;
return 0;
}