#include <iostream>
using namespace std;
/*You have been given an integer array / list(ARR) of size N which contains numbers from 0 to(N - 2).
Each number is present at least once.That is, if N = 5, the array / list constitutes values ranging from 0 to 3, and
 among these, there is a single integer value that is present twice.You need to find and return that duplicate number present in the array.
*/
/*
Approach :-
sum of all numbers - sum of first n-2 numbers
e.g sum of first n number is n(n-1)/2
*/
int duplicate(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    int n = size;
    int temp = (n - 2) * (n - 1) / 2;
    return sum - temp;
}
int main()
{
    int size;
    cout << "Enter size of arr " << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int result = duplicate(arr, size);
    cout << "duplicate element is: " << result << endl;
    return 0;
}