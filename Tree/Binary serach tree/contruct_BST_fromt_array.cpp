#include <iostream>
#include"check_BST3.cpp"
using namespace std;
// Give sorted array ,construct BST 
BinaryTreeNode *BST_From_sorted_arr(int arr[], int start, int end)
{
    if (start > end) // if empty array
    {
        return NULL;
    }
    // middle will be root of BST
    int mid = (start + end ) / 2;
    int rootData = arr[mid];
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    BinaryTreeNode *left_tree = BST_From_sorted_arr(arr, start, mid - 1);
    BinaryTreeNode *right_tree = BST_From_sorted_arr(arr, mid + 1, end);
    root->left = left_tree;
    root->right = right_tree;
    return root;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    BinaryTreeNode *root = BST_From_sorted_arr(arr, 0, size-1);
    cout << "  preOrder  " << endl;
    printPreOrder(root);
     if(check_BST4(root))
     {
         cout<<"true"<<endl;
     }
     else
     {
         cout<<"False"<<endl;
     }
    return 0;
}