#include <iostream>
using namespace std;
/* In circular linked list last node contain the address of
   first node(create loop)
*/
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)
{
   if(head==NULL)
   {
       return;
   }
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}
node *input_CLL()
{
  int data;
  cout<<"Enter the elements of list "<<
  "(Note :- To end list press -1)"<<endl;
  cin>>data;
  node *head=NULL;
  node *tail=NULL;
  while(data!=-1)
  {
    node *new_node=new node(data);
    if(head==NULL)
    {
        head=new_node;
        tail=new_node;
        tail->next=head; // connecting tail with head
    }
    else
    {
        tail->next=new_node;
        tail=tail->next;
        tail->next=head; // connecting tail with head

    }
    cin>>data;
  }
  return head;
}
// int main()
// {
//     node *head=input_CLL();
//     print(head);

// }