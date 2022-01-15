#include <iostream>
#include "Print_and_take_input.cpp"
using namespace std;
bool identical(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    bool answer = true;
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (root1->children[i]->data != root2->children[i]->data)
        {
            answer = false;
            return answer;
        }
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        answer = identical(root1->children[i], root2->children[i]);
        if (answer == false)
        {
            return answer;
        }
    }
    return answer;
}
int main()
{
    treeNode *root1 = input_levelWise();
    print_levelWise(root1);
    treeNode *root2 = input_levelWise();
    print_levelWise(root2);

    if (identical(root1, root2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}