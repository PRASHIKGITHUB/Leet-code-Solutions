
#include <bits/stdc++.h>
using namespace std;
void SortedInsert(stack<int> &stack, int a)
{
    if (stack.empty())
    {
        stack.push(a);
    }
    else if (stack.top() < a)
    {
        stack.push(a);
    }
    else
    {
        int b = stack.top();
        stack.pop();
        SortedInsert(stack, a);
        stack.push(b);
    }
    return;
}
void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int a = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);
    SortedInsert(stack, a);
}