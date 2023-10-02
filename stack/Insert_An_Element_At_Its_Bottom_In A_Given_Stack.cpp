#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> &myStack, int x)
{
    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    else
    {
        int temp = myStack.top();
        myStack.pop();
        solve(myStack, x);
        myStack.push(temp);
    }
    return;
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{

    solve(myStack, x);
    return myStack;
}