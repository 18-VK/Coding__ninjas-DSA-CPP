
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// find the length of singly linked list
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
 int count=0;
node *input()
{
    int data;
    cout << "Enter the first element of list,and to end the list enter -1" << endl;
    cin >> data;
    node *head = NULL;
    //create a tail that will store address of end of list
    node *tail=NULL;
    
    while (data != -1)
    {
         :: count++;
        node *new_node = new node(data);
        // every iteration new_node will change according to data value
        if (head == NULL)
        {
            head = new_node; 
            tail=new_node;
        }
        else // if list has one element already
        {
            tail->next=new_node;
            tail=tail->next; // travel to the end 
        }
        cin >> data;
    }
    return head;
    
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}
int main()
{
    node *head = input();
  
    print(head);
    cout<<"\n"<<::count;
    return 0;
}