#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"
using namespace std;
int find_node(node *head,int value)
{
    int count=0;
    node *temp=head;
    if(temp==NULL)
    {
        return temp;
    }
    while(temp!=NULL)
    {
     temp=temp->next;
     count++;
     if(value==temp->data)
     {
         return count;
     }
     else
     {
          return -1;
     }
     
    }
   return 0;
}
int main()
{
    node *head=input();
    print(head);
    cout<<endl;
    
    int val;
    cout<<"enter the value of node which you want to find"<<endl;
    cin>>val;
    cout<<"Index of the node at which the value present "<<find_node(head,val)<<endl;
    
return 0;
}