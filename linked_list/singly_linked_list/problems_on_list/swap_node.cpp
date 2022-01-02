#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"
using namespace std;
/* input-3 4 5 2 6 1 9 -1
         3 4
    output- 3 4 5 6 2 1 9 
    expalin - swap 3 index with 4 index 
*/       
node *swap_two_nodes(node *head, int i  ,int j)
{
    node*temp=head;
    node *first=head;
    node *second= head;
    int count_1=0;
    int count_2=0;
    if(head==NULL)
    {
        return head;
    }
    // to travel to ith position
    while(temp!=NULL)
    {
        if(count_1==i)
        {
            first=temp;
        }
        if(count_2==j)
        {
            second=temp;
        }
        if(first->data==second->data)
        {
            node *temp_var= second;
            second=first;
            first=temp_var;
        }
        temp=temp->next;
        count_1++;
        count_2++;
    }
}  
int main()
{
    
return 0;
}