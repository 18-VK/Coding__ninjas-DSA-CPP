#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
// eliminate duplicates from sorted linked list
node *duplicates(node *head)
{
    node *original_head = head;
    node *temp = head;
    node *current = original_head->next;
    if (temp == NULL) // if list has no node or only 1 node
    {
        return original_head;
    }
    while (temp->next!= NULL)
    {
        if (temp->data == current->data)
        {
            node *todelete = current;
            current = current->next; // travel to next node
            temp->next = current;    // now temp is linked to current->next;
            delete todelete;
        }
        else
        {
            temp = current;
            current = current->next;
        }
    }
    return original_head;
}
int main()
{
    node *head = input();
    print(head);

    cout << endl;

    head=duplicates(head);
   cout<<"after elimination"<<endl;
   print(head);
    return 0;
}