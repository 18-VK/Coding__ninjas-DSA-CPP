#include <iostream>
#include <bits/stdc++.h>
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
//Method 1 :- complexity O(n2)
// node *input()
// {
//     int data;
//     cout << "Enter the first element of list,and to end the list enter -1" << endl;
//     cin >> data;
//     node *head = NULL;
    
//     while (data != -1)
//     {
//         // create node and passing value enterd by user
//         // node n(data);  it will be dynamic otherwise static will be deleted after end of while loop
//         node *new_node = new node(data);
//         // every iteration new_node will change according to data value
//         if (head == NULL)
//         {
//             head = new_node; // give address to head
//         }

//         else // if list has one element already
//         {
//             node *temp = head;
//             while (temp->next != NULL) //  for travel across list
//             {
//                 temp = temp->next;
//             }
//             // with end link another node
//             temp->next = new_node;
//         }
//         cin >> data;
//     }
//     return head;
// }

// Method 2:- complexity O(n)
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
    cout<<endl;
}
// int main()
// {
//     node *head = input();
    
//     print(head);

//     return 0;
// }