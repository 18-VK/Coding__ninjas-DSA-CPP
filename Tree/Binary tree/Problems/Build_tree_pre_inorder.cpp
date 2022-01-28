#include <iostream>
#include"print_identical_structure.cpp"
using namespace std;
// given arrays preOrder and Inorder and given their starting and ending point
BinaryTreeNode *build_helper(int *pre, int *In,int preS,int preE,int InS,int InE)
{
    if(preS > preE) // if empty preS =0, preE=-1
    {
        return NULL;
    }
    int rootData=pre[preS];// preOrder start is the root 
    int root_idx=-1; // root index in Inorder
    for(int i=InS;i<=InE;i++)
    {
        if(In[i]==rootData)
        {
            root_idx=i;
            break;
        }
    }
    // all left tree indices 
    int L_InS=InS; // InS is the left node start
    int L_InE=root_idx-1; // Left ending in Inorder
    int L_preS=preS+1; // root node +1 in preOrder
    int L_preE= L_InE-L_InS +L_preS; // size of array for both traversal is same 
    // ending index  of inOrder Left + start index of preOrder left is the left end in preOrder
    
    // all right tree indices
    int R_preS=L_preE+1;
    int R_preE=preE;
    int R_InE=InE;
    int R_InS=root_idx+1;
    BinaryTreeNode *root=new BinaryTreeNode(rootData);
    // // call for left subtree so, giving all variables of Left 
    root->left=build_helper(pre,In,L_preS,L_preE,L_InS,L_InE); 
    root->right=build_helper(pre,In,R_preS,R_preE,R_InS,R_InE);
    return root;
}
BinaryTreeNode *Build_tree(int *pre, int *In, int size)
{
    // passing pre and In array, pre's start,pre's end and In's start,In's end
    BinaryTreeNode *root = build_helper(pre, In, 0, size - 1, 0, size - 1);
    return root;
}
int main()
{
    int size;
    cin >> size;
    int preOrder[size];
    int InOrder[size];

    for (int i = 0; i < size; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> InOrder[i];
    }
    BinaryTreeNode *root = Build_tree(preOrder, InOrder, size);
    print_identical(root);
    return 0;
}