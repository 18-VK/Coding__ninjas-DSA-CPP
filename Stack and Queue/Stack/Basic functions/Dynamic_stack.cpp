#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int next_idx;
    int capacity;

public:
    Stack()
    {
        arr = new int[5]; // initial size 5
        capacity = 5;
        next_idx = 0;
    }
    bool isempty()
    {
        return next_idx == 0;
    }
    int size()
    {
        return next_idx;
    }
    void push(int data)
    {
        if (next_idx == capacity) // means full
        {
            int *new_arr = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                new_arr[i] = arr[i];
            }
            arr = new_arr;
            capacity *= 2;
        }
        arr[next_idx] = data;
        next_idx++;
        return;
    }
    int pop()
    {
        if (isempty())
        {
            cout << "Stack is empty nothing to pop" << endl;
            return -1;
        }
        next_idx--;
        int x = arr[next_idx];
        return x;
    }
    int top()
    {
        if (isempty())
        {
            cout << "Stack is empty nothing to pop" << endl;
            return -1;
        }
        return arr[next_idx - 1];
    }
};
int main()
{
    Stack s1;
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