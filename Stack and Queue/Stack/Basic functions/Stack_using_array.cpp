#include <iostream>
using namespace std;
/* 
In this implementation,There is a size issue.
To overcome this,We will implement a new dynamic stack
*/
class stack
{
private:
    int *arr;
    int next_idx;
    int total_size;

public:
    stack(int size)
    {
        total_size = size;
        arr = new int[size];
        next_idx = 0; // -1 means empty stack
    }
    bool isEmpty()
    {
        return next_idx == 0;
    }
    int size()
    {
        return next_idx + 1;
    }
    void push(int data)
    {
        if (next_idx == total_size)
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[next_idx] = data;
        next_idx++;
        return;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        next_idx--;
        return arr[next_idx];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[next_idx - 1];
    }
};
int main()
{
    stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Poped element: " << s1.pop() << endl;
    cout << "Size of stack:" << s1.size() << endl;
    cout << "Top of stack: " << s1.top() << endl;
    cout<<"Isempty?: "<<s1.isEmpty()<<endl;
    return 0;
}