#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T *arr;
    int next_idx;
    int capacity;

public:
    Stack()
    {
        arr = new T[5];
        capacity = 5;
        next_idx = 0;
    }
    bool isempty();
    int size();
    void push(T  data);
    T pop();
    T top();
};
template <typename T>
bool Stack<T>::isempty()
{
    return next_idx == 0;
}
template <typename T>
int Stack<T>::size()
{
    return next_idx;
}
template <typename T>
void Stack<T>::push(T data )
{
    if (next_idx == capacity)
    {
        T *new_arr = new T[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            new_arr[i]= arr[i];
        }
        delete[] arr;  
        arr = new_arr;
        capacity *= 2;
    }
    arr[next_idx] = data;
    next_idx++;
}
template <typename T>
T Stack<T>::pop()
{
    if (isempty())
    {
        cout << "Stack is empty nothing to pop " << endl;
        return 0; // 0 is a standard value which is capable for all data type
    }
    next_idx--;
    T x = arr[next_idx];
    return x;
}
template <typename T>
T Stack<T>::top()
{
    if (isempty())
    {
        cout << "Stack is empty nothing to pop " << endl;
        return 0;
    }
    return arr[next_idx - 1];
}
int main()
{
    Stack<string> s1;
    s1.push("rahul");
    s1.push("Mayank");
    s1.push("Pujara");
    s1.push("Virat ");
    s1.push("Rahane");
    cout << "Poped element: " << s1.pop() << endl;
    cout << "Size of stack:" << s1.size() << endl;
    cout << "Top of stack: " << s1.top() << endl;
    cout << "Isempty?: " << s1.isempty() << endl;
    return 0;
}