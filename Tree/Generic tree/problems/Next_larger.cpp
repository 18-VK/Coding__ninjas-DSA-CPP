#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
int next_larger(treeNode *root, int x)
{
    if (root == NULL)
    {
        return INT16_MIN;
    }
    int ans=0;
   if(root->data >x)
   {
      ans=root->data;
   }
   for(int i=0;i<root->children.size();i++)
   {
       int subtree=next_larger(root->children[i],x);
       if(subtree< ans || subtree >x)
       {
           ans=subtree;
       }
   }
   return ans;
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    int x;
    cout << "Enter the element " << endl;
    cin >> x;
    cout << "next larger: " << next_larger(root, x) << endl;
    return 0;
}