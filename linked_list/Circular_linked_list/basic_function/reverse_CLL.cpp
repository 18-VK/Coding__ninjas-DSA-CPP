#include<iostream>
#include"input_CLL.cpp"
using namespace std;
node *reverse(node *head)
{
    if(head==NULL && head->next==head)
    {
        return head;
    }
    node *curr=head;
    node *previous=NULL;
    node *next_node=NULL;
    do
    {
         next_node=curr->next;
         curr->next=previous;
         previous=curr;
         curr=next_node;
    } while (curr!=head);
    // now head is tail and tail is head
    // previous is new head after reverse
    head->next=previous;
    head=previous;
    return head;
}
int main()
{
    node *head=input_CLL();
    print(head);
    cout<<"After reverse "<<endl;
    head=reverse(head);
    print(head);
    head=reverse(head);
    print(head);
    return 0;
}
