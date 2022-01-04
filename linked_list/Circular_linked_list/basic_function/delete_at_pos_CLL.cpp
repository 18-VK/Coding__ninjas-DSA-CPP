#include <iostream>
#include "deletion_CLL.cpp"
using namespace std;
int length(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int len = 0;
    node *temp = head;
    do
    {
        len++;
        temp = temp->next;
    } while (temp != head);
    return len;
}
node *delete_at_pos(node *head, int pos, int length)
{
    int count = 0;
    node *temp = head;
    node *previous = NULL;
    node *next_node = NULL;
    node *to_delete = NULL;
    int size = length;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
        return temp;
    }
    else if (pos == 0)
    {
        return delete_begin(head); // function of file deletion_CLL.cpp
    }
    else if (pos == (size - 1)) // means last element of list
    {
        return delete_end(head);
    }
    else if (pos >= size)
    {
        cout << "Invaild position " << endl;
        return head;
    }
    else
    {
        do
        {
            temp = temp->next;
            count++;
        } while (temp != head && count < pos - 1);
        previous = temp;
        to_delete = temp->next;
        previous->next = to_delete->next;
        ;
        delete to_delete;
        return head;
    }
    return head;
}
int main()
{
    node *head = input_CLL();
    print(head);
    int pos;
    cout << "Enter index of  element which  you want to delete " << endl
         << "(Note:- indexing start from 0)" << endl;
    cin >> pos;
    // 0 based indexing
    int len = length(head);
    head = delete_at_pos(head, pos, len);
    print(head);
    return 0;
}