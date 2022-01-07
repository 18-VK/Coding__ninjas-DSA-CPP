#include <iostream>
using namespace std;
/*
  list should be like
    30<-20<-10
   node :- inserting elements at head not at tail
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
class Stack_LL
{
private:
    node *head;
    int Size;

public:
    Stack_LL()
    {
        head = NULL;
        Size=0;
    }
    bool isempty()
    {
        return head == NULL;
    }
    int size()
    {
        return Size;
    }
    void push(int data)
    {
        node *new_node = new node(data);
        if (head == NULL)// dont need this now 
        {
            head = new_node;
            Size++;
            return;
        }
        new_node->next = head; // inserting node at 0th index
        head = new_node;
        Size++;
        return;
    }
    int pop()
    {
        if (head ==  NULL)
        {
            cout << "Stack is empty nothing to pop " << endl;
            return INT16_MIN;
        }
        node *to_delete = head;
        int x = head->data;
        head = head->next;
        delete to_delete;
        Size--;
        return x;
    }
    int top()
    {
        return head->data;
    }
};
int main()
{
    Stack_LL s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(90);
    s1.push(50);
    cout << "Poped element: " << s1.pop() << endl;
    cout << "Size of stack:" << s1.size() << endl;
    cout << "Top of stack: " << s1.top() << endl;
    cout << "Isempty?: " << s1.isempty() << endl;
    return 0;
}
