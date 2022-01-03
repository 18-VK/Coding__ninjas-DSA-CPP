#include <iostream>
using namespace std;
/* DLL consists three part data,next,prev
   it is a bi-directional list
   advantage over SLL
   :- IN DLL, backward travseral is possible
*/
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void print(node *head)
{
    if (head == NULL)
        return;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void print_back(node *tail)
{
    if (tail== NULL)
        return;
    node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout<<endl;
}
int main()
{
    node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    n1.next = &n2;
    n2.prev=&n1;
    n2.next = &n3;
    n3.prev=&n2;
    n3.next = &n4;
    n4.prev=&n3;
    node *head = &n1;
    node *tail = &n4;
    print(head); 
    //print reverse using tail
    print_back(tail);
}