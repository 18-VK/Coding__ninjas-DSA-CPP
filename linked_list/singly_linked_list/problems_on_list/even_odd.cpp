// #include <iostream>
// #include <bits/stdc++.h>
// #include "input_byuser.cpp"
// using namespace std;
// // seprate even and odd data and place even at the front and all odds at the end make sure
// // order should be same
// node *even_odd(node *head)
// {
//     node *oddHead = NULL;
//     node *oddTail = NULL;
//     node *evenHead = NULL;
//     node *evenTail = NULL;
//     while (head != NULL)
//     {
//         if (head->data % 2 == 0)
//         {
//             if (evenHead == NULL)
//             {
//                 evenHead = head;
//                 evenTail = head;
//             }
//             else
//             {
//                 evenTail->next = head;
//                 evenTail = evenTail->next;
                
//             }
//         }
//         else
//         {
//             if (oddHead == NULL)
//             {
//                 oddHead = head;
//                 oddTail = head;
                
//             }
//             else
//             {
//                 oddTail->next = head;
//                 oddTail = oddTail->next;
                
//             }
//         }
//         head = head->next;
//     }

//     if (oddHead == NULL)
//     {
//         return evenHead;
//     }
//     if (evenHead == NULL)
//     {
//         return oddHead;
//     }
//     oddTail->next = evenHead ;
//     evenTail->next=NULL;
//     return oddHead;
// }
// int main()
// {
//     node *head = input();
//     print(head);
//     cout << endl;

//     head = even_odd(head);
//     print(head);
//     return 0;
// }
