#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;

// print singly linked list in reverse order
// As we know that in case of SLL we can't travel backward
// this is not actually reverse it is just print
void reverse_order(node *head)
{
    int count = 0;
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }

    reverse_order(temp->next);
    cout << temp->data << " ";
}
// int main()
// {
//     node *head = input();
//     print(head);
//     cout << endl;
//     reverse_order(head);
//     return 0;
// }