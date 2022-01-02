#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"
using namespace std;

node* append_at_begin(node *head, int n,int length)
{
    node *temp=head;
    node*current=head;
    int i=1;
    if(temp== NULL)
    {
        return NULL;
    }
    while(temp->next!=NULL)
    {
         if(i<length-n)
        {
            current=current->next;
            i++;
        }
        temp=temp->next;
    }
   
    node *head2=current->next;
     temp->next=head;
    
    current->next=NULL;
    return head2;
}

int main()
{
    node *head=input();
    print(head);

    node *temp=head;
    int length=0;
    cout<<endl;
    
    while (temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
   
    head=  append_at_begin(head,2,length);
   print(head);
    
return 0;
}