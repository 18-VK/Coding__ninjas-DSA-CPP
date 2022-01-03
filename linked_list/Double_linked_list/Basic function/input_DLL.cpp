#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void print(node *head)
{
    if (head == NULL)
        return;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void print_back(node *tail)
{
    if (tail== NULL)
        return;
    node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout<<endl;
}
// take input function
node *input_DLL()
{
  int data;
  cout<<"Enter data of node or Enter -1 to stop"<<endl;
  cin>>data;
  node *head=NULL;
  node *tail=NULL;
  while(data!=-1)
  {
     node *new_node=new  node(data);
     if(head==NULL )
     {
         head=new_node;
         tail=new_node;
     }
     else
     {
         tail->next=new_node;
         new_node->prev=tail;
         tail=tail->next;
     }
     cin>>data;
  }
  return head;
}
node *find_tail(node *head)
{
    if(head==NULL || head->next==NULL)
    {
      return head;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
// int main()
// {
//     node *head=input_DLL();
//     print(head); 
//     node *tail=find_tail(head); 
//     print_back(tail); 
//     return 0; 
// }