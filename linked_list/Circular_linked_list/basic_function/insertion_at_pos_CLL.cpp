#include<iostream>
#include"insertion_CLL.cpp"
using namespace std;
int length(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int len = 0;
    node *temp = head;
    do
    {
        len++;
        temp = temp->next;
    } while (temp != head);
    return len;
}
node *insert_at_pos(node *head,int data,int pos,int length)
{
    node *temp=head;
    node*previous=NULL;
    node *next_node=NULL;
    int len=length;
    int count=0;
    node *new_node=new node(data);
    if(temp==NULL)
    {
        cout<<"Empty List"<<endl;
        return temp;
    }
    else if(pos==0)
    {
        return insert_begin(head,data);
    }
    else if(pos==len)// at end 
    {
        return insert_end(head,data);
    }
    else if(pos>len)
    {
        cout<<"Invaild psoition "<<endl;
        return head;
    }
    else
    {
        do
        {
            temp=temp->next;
            count++;
        } while (temp!=head && count<pos-1);
        previous=temp;
        next_node=previous->next;
        previous->next=new_node;
        new_node->next=next_node;
    }
    return head;
}
int main()
{
  node *head = input_CLL();
  print(head);
  int data,pos;
  int len=length(head);
  cout << "Enter the data you want to insert" << endl;
  cin >> data;
  cout << "Enter the position at which  you want to insert" << endl;
  cin >> pos;
  head = insert_at_pos(head, data,pos,len);
  print(head);
  return 0;
}