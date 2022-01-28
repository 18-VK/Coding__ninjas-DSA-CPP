#include <iostream>
#include "print_identical_structure.cpp"
using namespace std;
BinaryTreeNode *Build_helper(int *post, int *In, int postS, int postE, int InS, int InE)
{
    if (InS > InE) // if empty
    {
        return NULL;
    }
    int rootData = post[postE];
    int root_idx = -1; // root index in Inorder
    for (int i = InS; i <= InE; i++)
    {
        if (rootData == In[i])
        {
            root_idx = i;
            break;
        }
    }
    // all left indices
    int L_InS = InS;
    int L_InE = root_idx - 1;
    int L_postS = postS;
    //  left of post and Inorder size are same so, end will also same
    // size = end-start
    int L_postE = postS+root_idx-InS-1;
    // all right Indices
    int R_InS = root_idx + 1;
    int R_InE = InE;
    int R_postS = L_postE + 1;
    int R_postE = postE - 1;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    root->left = Build_helper(post, In, L_postS, L_postE, L_InS, L_InE);
    root->right = Build_helper(post, In, R_postS, R_postE, R_InS, R_InE);
    return root;
}
BinaryTreeNode *Build_tree(int *post, int *In, int size)
{
    return Build_helper(post, In, 0, size - 1, 0, size - 1);
}
int main()
{
    int size;
    cin >> size;
    int postOrder[size];
    int InOrder[size];

    for (int i = 0; i < size; i++)
    {
        cin >> postOrder[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> InOrder[i];
    }
    BinaryTreeNode *root = Build_tree(postOrder, InOrder, size);
    print_identical(root);
    return 0;
}