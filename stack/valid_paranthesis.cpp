#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening bracket ,stack push
        // if close bracket ,stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing
            if (!s.empty())
            {
                char top = s.top();
                if (
                    (top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
        return false;
}
int main()
{

    string s="())";
    cout<<isValidParenthesis(s)<<endl;
    return 0;
}
