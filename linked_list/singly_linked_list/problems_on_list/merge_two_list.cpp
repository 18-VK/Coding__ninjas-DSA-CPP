#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"

using namespace std;
// merge two sorted linked list
// method 1 -time O(length of both node e.g M + N) and space O(1), method by coding ninjas

// node *merge_two_list(node *head1, node *head2)
// {
//     // if both lists are empty then merged list is also empty
//     // if one of the lists is empty then other is the merged list
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     else if (head2 == NULL)
//     {
//         return head1;
//     }

//     node *final_head = NULL;
//     node *final_tail = NULL;
//     // condition when final head is NULL
//     if (head1->data <= head2->data)
//     {
//         final_head = head1;
//         final_tail = head1;
//         head1 = head1->next;
//     }
//     else
//     {
//         final_head = head2;
//         final_tail = head2;
//         head2 = head2->next;
//     }
//     // now we have final head and final tail is pointing to final head

//     while (head1 != nullptr && head2 != nullptr)
//     {
//         node *temp=NULL;
//         if (head1->data <= head2->data)
//         {
//             final_tail->next= head1;
//             final_tail=head1; // travel to next node
//             head1 = head1->next;
//         }
//         else
//         {
//             final_tail->next= head2;
//             final_tail=head2; // travel to next node
//             head2 = head2->next;
//         }

//     }

//     // while loop will exit if any list will point to the NULL
//     // check if any node of any list is left if yes then link to final list
//     if(head1!= NULL)
//     {
//         final_tail->next=head1;
//         head1=head1->next;
//     }
//     else if(head2!=NULL)
//     {
//         final_tail->next=head2;
//         head2 =head2->next;
//     }
//     return final_head;
// }

// method 2 same complexity
// using dummy node  method by apna college

node *merge_two_list(node *head1, node *head2)
{
    node *head_1 = head1;
    node *head_2 = head2;

    node *dummy_node = new node(-1); // -1 means node has no value
    node *final_head = dummy_node;

    while (head_1 != NULL && head_2 != NULL)
    {
        if (head_1->data <= head_2->data)
        {
            dummy_node->next = head_1;
            head_1 = head_1->next;
            dummy_node=dummy_node->next;
        }
        else if (head_2->data <= head_1->data)
        {
            dummy_node->next = head_2;
            head_2 = head_2->next;
            dummy_node=dummy_node->next;
        }
    }

    // check if any list nodes are left
    if (head_1 != NULL)
    {
        dummy_node->next = head_1;
        head_1 = head_1->next;
        dummy_node = dummy_node->next;
    }
    else if (head_2 != NULL)
    {
        dummy_node->next = head_2;
        head_2 = head_2->next;
        dummy_node = dummy_node->next;
    }
    return final_head->next; // A we now at head of dummy node is -1 so we have to return next of dummy node
}

int main()
{
    node *head1 = input();
    print(head1);
    cout << endl;

    node *head2 = input();
    print(head2);
    cout << endl;

    node *final_list = merge_two_list(head1, head2);
    print(final_list);
    return 0;
}
