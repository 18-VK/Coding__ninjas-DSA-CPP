#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    //constructor
    node(int data)
    {
        this->data = data;
        next = NULL; // next as null
    }
};
void print(node *head)
{
    // print list one by one
    // cout<<head->data<<" ";
    // head=head->next;  // now head has address of second element of list
    // cout<<head->data<<" ";
    // head=head->next;  // now head has address of third element of list
    // cout<<head->data<<" ";
    // using loop
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // instead of changing our real head we have to create a temp pointer to travel across list
    // becoz we don't want to lost our head's initial address
}
int main()
{
    // statically creating nodes
    node n1(1);
    node *head = &n1; // starting  point is head
    node n2(2);
    n1.next = &n2;
    node n3(3);
    n2.next = &n3;
    // list = 1->2->3
    print(head);
    // print list
    // cout<<n1.data<<" "<<n2.data<<endl;
    // // print using head
    // cout<<head->data<<" "<<<<endl;

    // dynamically creating node using new keyword
    cout << endl;
    node *m3 = new node(3);
    node *m4 = new node(4);
    node *m5 = new node(5);
    node *head1 = m3;
    m3->next = m4;
    m4->next = m5;
   // list= 3->4->5
    print(head1); 
    // call by value change in head's value will not reflect in main head value will remain same

    return 0;
}