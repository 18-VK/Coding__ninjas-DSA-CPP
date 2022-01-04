#include <iostream>
using namespace std;
/* In circular linked list last node contain the address of
   first node(create loop)
*/
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
// int main()
// {
//     node n1(1); // creating node
//     node n2(2);
//     node n3(3);
//     node n4(4);
//     n1.next = &n2;
//     n2.next = &n3;
//     n3.next = &n4;
//     n4.next = &n1;
//     node *head=&n1;
//     print(head);
//     return 0;
// }