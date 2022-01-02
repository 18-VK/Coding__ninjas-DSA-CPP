#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
// create a function which will insert and return the updated head of list

node *insert(node *head, int pos, int data) 
{
    node *new_node = new node(data);
    int count = 0;
    node *temp = head;
    // for insert at front
    if (pos == 0)
    {
        new_node->next = head;
        head = new_node;
        return head; // updated head
    }

    // we have to travel to the previous node of ith position e.g pos=2,count=1 and indexing from 0
    // and we have to check position under the length of list
    // next of last node should not be NULL
    // with this we can insert in end of list but at run time we have to insert carefully 
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    } // now,we are at before a position from position and temp has it address
    if (temp != NULL)
    {
        new_node->next = temp->next; // new_node is linked to rest list
        temp->next = new_node;       // previous position's next has linked to new node
    }
    return head; // previous head
}
int main()
{
    node *head = input();
    print(head);
    cout << endl;
    int pos,value;
    cout<<"Enter the index at which you want to insert node (indexing from 0)"<<endl;
    cin>>pos;
    cout<<"Enter the value you want to insert"<<endl;
    cin>>value;
    head = insert(head, pos, value); // indexing from 0
    print(head);                // updated head in, insert in front condition

    return 0;
}