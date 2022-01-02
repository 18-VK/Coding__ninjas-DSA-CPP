#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
// length of linked list
// int length_recursive(node *head)
// {

//     node *temp = head;
//     if (temp==NULL) // base case
//     {
//        return 0;
//     }
    
//     return 1+length_recursive(temp->next); 
//     // at every recursive call it will return 1
//     // at 1 - 1,at 2 - 2,at 3- 3 and so on..
    
// }
// // insert a node 
// node *insert_recursivley(node *head,int pos,int value)
// {
//    node*temp=head;
  
//    if (temp==NULL) 
//    {
//        return head;
//    }
//    if(pos==0)  // small calculation on recursion
//    {
//     node* new_node=new node(value);
//     new_node->next=temp;
//     temp=new_node;
//     return temp; // updated head
//    }
//    // store the  head of list return by recursive function 
//    node *rest_list =insert_recursivley(temp->next,pos-1,value);
//    temp->next=rest_list;  // join the list small cal. and recursion work
//    return temp;
// }

// delete node using recursion
node *delete_recursively(node *head,int pos)
{
    node *temp=head;
    if(temp==NULL)
    {
        return head;
    }
    if(pos==0)
    {
        node *todelete=temp;
        temp=todelete->next; // update the head
        delete todelete; // deallocate 
        return temp;
    }
    node *rest_list=delete_recursively(temp->next,pos-1);
    temp->next=rest_list;
    return temp;
}
int main()
{
    node *head = input();
    print(head);
    cout<<endl;
    // cout <<"length of linked list :- "<< length_recursive(head) << endl;

    // head=insert_recursivley(head,0,20);
    // print(head);
     
     head=delete_recursively(head,4);
     print(head);
    return 0;
}