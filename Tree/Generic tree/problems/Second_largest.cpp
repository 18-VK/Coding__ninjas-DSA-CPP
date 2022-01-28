#include<iostream>
#include"Print_and_take_input.cpp"
using namespace std;
class Pair
{
 public:
   int maximum;
   int second_max;
   Pair()
   {
       maximum=INT16_MIN;
       second_max=INT16_MIN;
   }
};
Pair helper(treeNode *root)
{
    if(root==NULL)
    {
        Pair temp;
        return temp;
    }
    Pair ans;
    ans.maximum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        Pair subtree=helper(root->children[i]);
        int temp=-1;
        if(subtree.maximum > ans.maximum)  // maximum between root and subtree's maximum
        {
           temp=ans.maximum;
           ans.maximum=subtree.maximum;
        }
        else{ temp=subtree.maximum;} 
        if(ans.second_max==INT16_MIN && subtree.second_max==INT16_MIN)
        {
                ans.second_max=temp;
        }
        if(ans.second_max==INT16_MIN && subtree.second_max!=INT16_MIN)
        {
            ans.second_max=max(temp,subtree.second_max);
        }
        else
        {
            ans.second_max=max(ans.second_max,temp);
        }
    }
    return ans;
}
int sec_largest(treeNode *root)
{
   Pair ans= helper(root);
   return ans.second_max;
}
int main()
{
    treeNode *root=input_levelWise();
    print_levelWise(root);
    cout<<"Second largest element: "<<sec_largest(root)<<endl;
    return 0;
}