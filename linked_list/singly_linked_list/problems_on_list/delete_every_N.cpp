#include <iostream>
#include <bits/stdc++.h>
#include "input_byuser.cpp"
using namespace std;
/* input- 1 2 3 4 5 6 7 8 -1
          2 2
   output - 1 2 5 6 
*/
//time O(n)- n  is length of linked list
node *delete_N_node(node *head, int M, int N)
{
   node *temp1 = head;
   node*temp2=head;

   int count_1 = 1;
   int count_2= 1;

   while(temp1!=NULL)
   {
      while(temp1 != NULL && count_1< M)
      {
         temp1=temp1->next;
         count_1++;
      }
      if(temp1 == NULL)
      {
         return head;
      }
      temp2=temp1->next;
      
      while(temp2 !=NULL && count_2<= N)
      {
         node *todelete=temp2;
         temp2=temp2->next;
         count_2++;
         delete todelete;
      }
      temp1->next=temp2;
      temp1=temp2;
      count_1=1;
      count_2=1;
   }
 return head;
   
}



int main()
{
   node *head = input();
   print(head);
   cout << endl;

    head = delete_N_node(head, 3, 2);
   
   print(head);
   
   return 0;
}