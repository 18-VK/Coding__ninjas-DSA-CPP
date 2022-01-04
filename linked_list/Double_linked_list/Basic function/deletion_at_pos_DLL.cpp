#include <iostream>
#include "input_DLL.cpp"
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
node *delete_at_pos(node *head, int pos)
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
    node *to_delete = NULL;
    node *temp = head;
    node *previous = NULL;
    node *next_node = NULL;
    int count = 0;
    if (pos == 0)
    {
        to_delete = head;
        if(head->next==NULL) // when list has one element
        {
            return NULL;
        }
        head = head->next;
        head->prev = NULL;
        delete to_delete;
        return head;
    }
    // else if(pos==(length(head)-1)) // if last element of list
    // {

    // }
    else
    {
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
         previous = temp;
        to_delete = temp->next; // element that is gonna delete
        next_node = to_delete->next;
        previous->next = next_node;
        if(next_node!=NULL)
        {
          next_node->prev = previous;
        }
        // otherwise null->prev=previous which is not
        delete to_delete;
    }
    return head;
}
int main()
{
    node *head = input_DLL();
    print(head);
    cout << "After delete at given position" << endl;
    int pos;
    cout << "Enter position at which you want to delete element" << endl;
    cin >> pos;
    head = delete_at_pos(head, pos);
    print(head);
}