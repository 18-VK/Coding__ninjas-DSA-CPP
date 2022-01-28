#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
void helper(treeNode *root,int depth)
{
   root->data=depth;
   for(int i=0;i<root->children.size();i++)
   {
       helper(root->children[i],depth+1);
   }
}
void replace_depth(treeNode *root)
{
    if(root==NULL)
    {
        return;
    }
   int depth=0;
   helper(root,depth);
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << " after change " << endl;
    replace_depth(root);
    print_levelWise(root);
    return 0;
}