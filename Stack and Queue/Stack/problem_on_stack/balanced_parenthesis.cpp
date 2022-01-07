#include <iostream>
#include <stack>
using namespace std;
/* given a string containing brackets
  we have to check that,are brackets balance or not
*/
bool check(char open, char close)
{
  if (open == '(' && close == ')')
  {
    return true;
  }
  else if (open == '{' && close == '}')
  {
    return true;
  }
  else if (open == '[' && close == ']')
  {
    return true;
  }
  return false;
}
bool balance_paren(string exp)
{
  // Your code here
  stack<char> s;
  int n = exp.size();
  // travesing to the string exp
  for (int i = 0; i < n; i++)
  {
    // if opening brackets then push onto the stack
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    {
      s.push(exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {
      char x = exp[i];
      // check if stack is empty and parantheses are not balance   return false
      // if balance and stack is not empty pop the top of stack
      if (s.empty() || !check(s.top(), x))
      {
        return false;
      }
      else
      {
        s.pop();
      }
    }
  }
  // after loop if stack is empty that means parantheses is balanced
  return s.empty() ? true : false;
}
int main()
{

  string s;
  cin >> s;
  int size = s.size();
  if (balance_paren(s))
    cout << "Balanced" << endl;
  else
    cout << "not balanced" << endl;
  return 0;
}