#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"

using namespace std;
/* if we read linked list from head  to tail to head and both are same then linked list called 
palindrome*/

// check palindrome or not
bool palindrome(node *head)
{
    node *temp = head;
    node *middle = NULL;
    // find middle
    node *slow_ptr = head;
    node *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;       // jump 1 postion
        fast_ptr = fast_ptr->next->next; // jump 2 position
    }
    middle = slow_ptr;

    // reverse second half of original list

      node *current=head,*perv=NULL,*next_node;
    while(current!=NULL)
    {
       next_node=current->next;
       current->next =perv;
       // now current has linked with perv

       // now we have to travel 1 position forward
       perv=current;
       current=next_node;
    }
    middle=perv; // prev has head of reverse list

    if (temp == NULL)
    {
        return temp;
    }
    while (temp != NULL )
    {
        if (temp->data != middle->data)
        {
            return false;
        }
        temp = temp->next;
        middle = middle->next;
    }
    return true;
}

int main()
{
    node *head = input();
    node *temp = head;
    print(head);
    cout << endl;

    ;
    cout << palindrome(head);

    return 0;
}