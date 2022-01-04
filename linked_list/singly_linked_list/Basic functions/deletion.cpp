#include<iostream>
#include"input_byuser.cpp"
using namespace std;
node* delete_begin(node *head)
{
   if(head==NULL)
   {
       cout<<"List is empty"<<endl;
       return head;
   }
   else if(head->next==NULL)
   {
      node *to_delete=head;
      delete to_delete;
      return NULL; 
   }
   node *to_delete=head;
   head=head->next;
   delete to_delete;
   return head;
}
node *delete_end(node *head)
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return head;
    }
    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node *to_delete=temp->next;
    temp->next=NULL;
    delete to_delete;
    return head;
}
int main()
{
    node *head=input();
    print(head);
    // delete at beginning 
    // cout<<"After deletion at beginning"<<endl;
    // head=delete_begin(head);
    // print(head);
     cout<<"After deletion at ending"<<endl;
    head=delete_end(head);
    print(head);
    return 0;
}