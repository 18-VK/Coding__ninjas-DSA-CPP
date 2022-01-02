#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"

using namespace std;
// find the middle node
// int length_of_list(node *head)
// {
//     int count=0;
//     node *temp=head;
//     while(temp!=NULL)
//     {
//         temp=temp->next;
//         count++;
//     }
//     return count;
// }
// method -1
// node* middle(node *head,int length)
// {
//   node *temp=head;
//   node*middle=NULL;
  
//   int len=length;
//   if(temp!=NULL )
//   {
//     for (int i = 0; i < length/2; i++) 
// instead of length /2 we can use (length-1)/2 becoz when length will even we will have two mid
// if we want to return first mid then use (length-1)/2 
//     {
//         temp=temp->next;
//     }
//      middle=temp;
//   }

//   return middle;
// }

// method 2 using two pointers
node*middle(node *head)
{
    
    node *slow_ptr=head;
    node *fast_ptr=head->next; // same 
    while(fast_ptr!=NULL && fast_ptr->next !=NULL)
    {
        slow_ptr=slow_ptr->next;  // jump 1 postion
        fast_ptr=fast_ptr->next->next;  // jump 2 position
    }
    return slow_ptr;
}

int main()
{
    node*head=input();
    print(head);
    cout<<endl;

    // int length=length_of_list(head);
    

    node *mid=middle(head);

    cout<<mid->data<<endl;
return 0;
}