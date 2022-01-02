#include<iostream>
#include"input_byuser.cpp"
// added input file to take inputs
using namespace std;
node *insert_begin(node *head,int data)
{
  
   node *new_node=new node(data);
   new_node->next=head;
   head=new_node;
   return head; 
}
// inset at end
node *insert_end(node *head,int data)
{
    node *temp=head;
    node *new_node=new node(data);
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}
int main()
{
    node *head=input();
    print(head);
    // insert at begining
    int data;
    cout<<"Enter the data of node you want to add"<<endl;
    cin>>data;
   // head= insert_begin(head,data);
   // print(head);
   head=insert_end(head,data);
   print(head);
   return 0;
}