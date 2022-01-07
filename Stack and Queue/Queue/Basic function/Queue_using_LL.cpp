#include <iostream>
using namespace std;
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
class Queue_LL
{
  private: 
     node *head;
     node*tail;
     int size;
  public:
     Queue_LL()
     {
         head=NULL;
         tail=NULL;
         size=0;
     }
     bool isEmpty()
     {
         return size==0;
     }
     int Size()
     {
         return size;
     }
     void enqueue(int data)
     {
       node *new_node =new node(data);
       if(head==NULL)
       {
           head=new_node;
           tail=new_node;
       }
       tail->next=new_node;
       tail=tail->next;
       size++;
       return;
     }
     int dequeue()
     {
         if(isEmpty())
         {
             cout<<"Queue is empty "<<endl;
             return INT16_MIN;
         }
         node *temp=head;
         int x=head->data;
         head=head->next;
         delete temp;
         size--;
         return x;
     }
     int front()
     {
         if(isEmpty())
         {
             cout<<"Queue is empty"<<endl;
             return INT16_MIN;
         }
         return head->data;
     }
};
int main()
{
    Queue_LL q1;
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