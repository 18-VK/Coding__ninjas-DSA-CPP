#include<iostream>
#include"input_DLL.cpp"
using namespace std;
node *insert_begin(node *head,int data)
{
     node *new_node= new node(data);
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    return head;
}
node *insert_end(node *head,int data)
{
    node *new_node= new node(data);
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    return head;
}
int main()
{
    node *head=input_DLL();
    print(head);
    int data;
    cout<<"Enter data of node you want to insert at beginning"<<endl;
    cin>>data;
    cout<<"After insertion at beginning"<<endl;
    head=insert_begin(head,data);
    print(head);
    cout<<"Enter data of node you want to insert at ending"<<endl;
    cin>>data;
    cout<<"After insertion at ending"<<endl;
    head=insert_end(head,data);
    print(head);
    return 0;
}