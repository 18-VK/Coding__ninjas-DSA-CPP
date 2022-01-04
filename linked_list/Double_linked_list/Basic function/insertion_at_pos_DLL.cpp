#include <iostream>
#include "input_DLL.cpp"
using namespace std;
int length(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
node *insertion_at_pos(node *head,int pos,int data)
{
    if(pos>length(head))
    {
        cout<<"Invaild position"<<endl;
        return head;
    }
    node *previous=NULL;
    node *temp=head;
    node *next_node=NULL;
    int count=0;
    node *new_node=new node(data);
    if(head==NULL && pos==0) // if list is empty and want to add element at beginning
    {
       head=new_node;
       return head;
    }
    else if(pos==0)
    { 
       new_node->next=head;
       head->prev=new_node;
       head=new_node;
       return head;
    }
    else if(pos==length(head)) // means want to insert at end
   {
      while(temp->next!=NULL)
      {
          temp=temp->next;
      }
      previous=temp;
      previous->next=new_node;
      new_node->prev=previous;
      return head;
   }
    else 
    {
        while(temp!=NULL && count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        previous=temp;
        next_node=temp->next;
        previous->next=new_node;
        next_node->prev=new_node;
        new_node->next=next_node;
    }
    return head;
}
int main()
{
    node *head = input_DLL();
    print(head);
    cout << "After insertion at given position" << endl;
    int pos;
    cout << "Enter position at which you want to delete element"<<endl
    << "(Note:- indexing start from 0)"<<endl;
    cin >> pos;
    int data;
    cout<<"Enter the data you want to insert at given position"<<endl;  
    cin>>data;
    head = insertion_at_pos(head, pos,data);
    print(head);
}