#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
// time O(n2)
// method 1
// node *reverse_list(node *head)
// {
//     if (head == NULL || head->next == NULL) //base case
//     {
//         return head;
//     }
//     // recursion call
//     node *small_ans = reverse_list(head->next);
//     //now we are at the end of list means at the head of our reversed list which is savedin small_ans

//     // small calculation
//     node *temp = small_ans;
//     // travel to the end of reversed list
//     // we don't need to travel end find tail of list becoz our ori. head is still pointing
//    // to tail of reversed list e.g 1 is pointing to 2 which is tail of reverse list
//   // tail =head->next, and tail->next=head, head->next =NULL so we dont need to use while loop
//   // and our time will save  now time comlexity is O(n) same in method second
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     head->next = NULL;
//     return small_ans;
//}

//method 2 time O(n)
// now we have to retrun two parameters head and tail so we have to create a class
class pairs
{
public:
    node *head;
    node *tail;
};

// return type will be pair instead of node
pairs reverse_list_2(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        pairs ans;
        ans.head = head;
        ans.tail = head;
        return ans; // return type pair
    }
    // recursion call
    pairs small_ans = reverse_list_2(head->next);

    small_ans.tail->next = head;
    head->next = NULL;
    pairs ans;
    ans.head = small_ans.head;
    ans.tail = head;
    return ans;
}
node* reverse_list_better(node *head)
{
    return reverse_list_2(head).head;
}
int main()
{
    node *head = input();
    print(head);

    cout << endl;
    head = reverse_list_better(head);
    print(head);
    return 0;
}