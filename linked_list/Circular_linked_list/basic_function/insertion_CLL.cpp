#include <iostream>
#include "input_CLL.cpp"
using namespace std;
node *insert_begin(node *head, int data)
{
  node *new_node = new node(data);
  node *temp = head;
  if (head == NULL)
  {
    head = new_node;
    head->next = head;
    return head;
  }
  // finding tail
  while (temp->next != head)
  {
    temp = temp->next;
  }
  // now temp at tail
  new_node->next = head;
  head = new_node;
  temp->next = head;
  return head;
}
node *insert_end(node *head, int data)
{
  node *new_node = new node(data);
  if (head == NULL)
  {
    head = new_node;
    return head;
  }
  node *temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->next = head;
  return head;
}
// int main()
// {
//   node *head = input_CLL();
//   print(head);
//   int data;
//   cout << "Enter the data you want to insert" << endl;
//   cin >> data;
//   head = insert_begin(head, data);
//   print(head);
//   cout << "Enter the data you want to insert" << endl;
//   cin >> data;
//   head = insert_end(head, data);
//   print(head);
//   return 0;
// }