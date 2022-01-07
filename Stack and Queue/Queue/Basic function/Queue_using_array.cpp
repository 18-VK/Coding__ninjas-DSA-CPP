#include <iostream>
using namespace std;
/* implementation of Queue using array with size issue
   Queue:- In queue, add from rear delete from front
*/
class Queue_arr
{
    int *arr;
    int next_idx;
    int size;
    int front_idx;
    int capacity;

public:
    Queue_arr()
    {
        arr = new int[5]; // initial size
        capacity = 5;
        next_idx = 0;
        size = 0;
        front_idx = -1;
    }
    bool isEmpty()
    {
        return size == 0; // front_idx==-1;
    }
    int Size()
    {
        return size;
    }
    void enqueue(int data)
    {
        if (size == capacity)// means full
        {
            int *new_arr=new int[capacity*2];
            int j=0;
            for(int i=front_idx;i<capacity;i++) // from front idx to capacity
            {
                new_arr[j]=arr[i];
                j++;
            }
            for(int i=0;i<front_idx;i++)  // left elements from 0th index to front_idx-1
            {
              new_arr[j]=arr[i];
              j++;
            }
            delete[] arr;
            arr=new_arr;
            front_idx==0;
            next_idx=capacity;
            capacity*=2;
        }
        if (front_idx == -1)
        {
            front_idx = 0;
        }
        arr[next_idx] = data;
        next_idx = (next_idx + 1) % capacity;
        size++;
        return;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return INT16_MIN;
        }
        int x = arr[front_idx];
        front_idx = (front_idx + 1) % capacity;
        size--;
        return x;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return INT16_MIN;
        }
        return arr[front_idx];
    }
};
int main()
{
    Queue_arr q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.Size()<<endl;
   if( q1.isEmpty())
   {
       cout<<"Empty Queue"<<endl;
   }
    return 0;
}