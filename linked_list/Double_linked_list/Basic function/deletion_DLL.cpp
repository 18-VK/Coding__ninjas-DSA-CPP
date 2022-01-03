#include <iostream>
#include "input_DLL.cpp"
using namespace std;
node *delete_begin(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *to_delete = head;
    head = head->next;
    head->prev = NULL;
    delete to_delete;
    return head;
}
node *delete_end(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *to_delete = temp;
    temp = temp->prev;
    temp->next = NULL;
    delete to_delete;
    return head;
}
int main()
{
    node *head = input_DLL();
    print(head);
    cout << "After deletion at beginning" << endl;
    head = delete_begin(head);
    print(head);
    cout << "After deletion at ending" << endl;
    head = delete_end(head);
    print(head);
    return 0;
}