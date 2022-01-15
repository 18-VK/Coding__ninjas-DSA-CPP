#include<iostream>
#include"Impl_binary_tree.cpp"
using namespace std;
void print_identical(BinaryTreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode*> pending;
    pending.push(root);
    pending.push(NULL);
    while(!pending.empty())
    {
        BinaryTreeNode *front=pending.front();
        pending.pop();
        if(front==NULL)
        {
            if(pending.empty()) 
            {
                break;
            }
            cout<<endl;
            pending.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        if(front->left!=NULL)
        {
            pending.push(front->left);
        }
        if(front->right!=NULL)
        {
            pending.push(front->right);
        }
    }
    cout<<endl;
}
// int main()
// {
//     BinaryTreeNode *root=take_input();
//     print_identical(root);
// return 0;
// }