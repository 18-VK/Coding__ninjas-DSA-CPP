#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"
using namespace std;

node* delete_at(node* head,int pos)
{
    int count=0;
    node *temp=head;
    node *previous=NULL;
    node *delete_head=NULL;
    node *delete_at_pos=NULL;
    // if we want to delete first node 
    if(pos==0)
    {
      delete_head=head; 
      head=temp->next;  // now head has address of element at index 1(second element)
      delete delete_head;
      return head; // updated head
    }
    else
    {
        while(temp!=NULL && count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        previous=temp; // a position before delete node
        delete_at_pos=previous->next;  // node which we want to delete
        previous->next=delete_at_pos->next;  // delete_at_pos->next; means next element from position
        delete delete_at_pos;

    }
    return head; // previous head
}
int main()
{
    node*head=input();
    print(head);
    int pos;
    cout<<endl;
    cout<<"Enter index of  which element  you want to delete "<<endl;
    cin>>pos;
    head=delete_at(head,pos);
    print(head);
return 0;
}