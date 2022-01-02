#include<iostream>
#include<bits/stdc++.h>
 #include"input_byuser.cpp"
using namespace std;
// reverse the linked list by changing links
node *reverse(node *head)
{
    node *current=head,*perv=NULL,*next;
    while(current!=NULL)
    {
       next=current->next;
       current->next =perv;
       // now current has linked with perv

       // now we have to travel 1 position forward
       perv=current;
       current=next;
    }
    return perv; // updated head of reversed linked list
}
// int main()
// {
//     node*head= input();
//     print(head);
//     cout<<endl;

//     head= reverse(head);
//     cout<<"Reversed linked list "<<endl;
//     print(head);
// return 0;
// }