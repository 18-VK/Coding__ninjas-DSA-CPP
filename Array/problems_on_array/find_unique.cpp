#include <iostream>
using namespace std;
/*
Problem Statement: Find the Unique Element
Problem Level: MEDIUM
Problem Description:
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
Note:
Unique element is always present in the array/list according to the given condition.
*/
/* 
  we are gonna use XOR bitwise operator(^). XOR need one true and one false.
  e.g - 1 ^ 0 = 1, 1^ 1= 1
*/
int find_uni(int arr[],int size)
{
    int temp=arr[0];
    for(int i=1;i<size;i++)
    {
       temp=temp^arr[i];
    }
    return temp;
}
int main()
{
    int size;
    cout<<"Enter size of arr "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int result=find_uni(arr,size);
    cout<<"Unique element is: "<<result<<endl;
    return 0;
}