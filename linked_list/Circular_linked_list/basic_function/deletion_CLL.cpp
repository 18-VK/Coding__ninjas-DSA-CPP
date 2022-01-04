#include <iostream>
#include "input_CLL.cpp"
using namespace std;
node *delete_begin(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }
    else if (head->next == head) // if only one node in list
    {
        node *to_delete = head;
        delete to_delete;
        return NULL;
    }
    else
    {
        node *to_delete = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head; // joining tail with new head
        delete to_delete;
    }
    return head;
}
node *delete_end(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return head;
    }
    else if (head->next == head) // only one element in list
    {
        delete head;
        return NULL;
    }
    node *temp = head;
    while (temp->next->next != head) //stop at second last element from end
    {
        temp = temp->next;
    }
    node *to_delete = temp->next; // element to delete
    temp->next=head; // joining new tail with head;
    delete to_delete;
    return head;
}
// int main()
// {
//     node *head = input_CLL();
//     print(head);
//     // cout << "After deletion at beginning " << endl;
//     // head = delete_begin(head);
//     // print(head);
//     cout << "After deletion at ending " << endl;
//     head = delete_end(head);
//     print(head);
// }