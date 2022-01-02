#include<iostream>
#include<bits/stdc++.h>
#include"input_byuser.cpp"
// using file 
using namespace std;
int get(node *head,int index)
{
int count=0;  
node *current=head;
while(current!=NULL)
{
    if(count==index)
    {
        return(current->data);
    }
    count++; // increment index
    current=current->next;
}

}
int main()
{
    node *head=input();
    int index;
    cin>>index;
   cout<< get(head,index);
return 0;
}