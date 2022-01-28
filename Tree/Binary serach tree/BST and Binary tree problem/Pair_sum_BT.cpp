/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:
5 10
6 9
*/
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include "Impl_binary_tree.h"
using namespace std;
void convert(BinaryTreeNode *root,vector<int> &v)
{
   if(root==NULL)
   {
       return;
   }
   v.push_back(root->data);
   convert(root->left,v);
   convert(root->right,v);
}
void Pair_sum(BinaryTreeNode *root, int sum)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> v;
    convert(root,v);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while(i<j)
    {
      if(v[i]+v[j]==sum)
      {
          cout<<v[i]<<" "<<v[j]<<endl;
          i++;
          j--;
      }
      else if(v[i]+v[j] >sum)
      {
         j--;
      }
      else if(v[i]+v[j]<sum)
      {
          i++;
      }
    }
}
int main()
{
    BinaryTreeNode *root=take_input();
    print_identical(root);
    int sum;
    cin>>sum;
    cout<<"Pairs are: "<<endl;
    Pair_sum(root,sum);
    return 0;
}