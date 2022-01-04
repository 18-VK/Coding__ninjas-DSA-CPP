#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
int length(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
node *delete_at(node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
     else if (pos >= length(head)) // pos start from 0 and length start from 1
     {
         cout << "Invaild position " << endl;
        return head;
     }
    int count = 0;
    node *temp = head;
    node *previous = NULL;
    node *delete_head = NULL;
    node *delete_at_pos = NULL;
    // if we want to delete first node
    if (pos == 0)
    {
        delete_head = head;
        head = head->next; // now head has address of element at index 1(second element)
        delete delete_head;
        return head; // updated head
    }
    else
    {
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        previous = temp;                      // a position before delete node
        delete_at_pos = previous->next;       // node which we want to delete
        previous->next = delete_at_pos->next; // delete_at_pos->next; means next element from position
        delete delete_at_pos;
    }
    return head; // previous head
}
int main()
{
    node *head = input();
    print(head);
    int pos;
    cout << "Enter index of element which you want to delete " << endl
    << "(Note:- indexing start from 0)"<<endl;
    cin >> pos;
    // 0 based indexing
    head = delete_at(head, pos);
    print(head);
    return 0;
}