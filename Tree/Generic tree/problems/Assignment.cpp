#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
// Question 1 conatins x
bool check_x(treeNode *root, int x)
{
    if (root == NULL)
    {
        false;
    }
    bool answer = true;
    if (root->data == x)
    {
        return answer;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        answer = check_x(root->children[i], x);
        if (answer == true)
        {
            return answer;
        }
    }
    return false;
}
// Question 2 count nodes
// Given a tree and an integer x, find and
// return the number of nodes which contains data greater than x.
int greater_x(treeNode *root, int x)
{
    if (root == NULL) // edge case
    {
        return INT16_MIN;
    }
    int count = 0;
    if (root->data > x)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + greater_x(root->children[i], x);
    }
    return count;
}
int main()
{
    treeNode *root = input_levelWise();
    print_levelWise(root);
    cout << "Enter the elements " << endl;
    int x;
    cin >> x;
    // if(check_x(root,x))
    // {
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }
    cout<<"Nodes Greater than x: "<<greater_x(root,x)<<endl;
    return 0;
}