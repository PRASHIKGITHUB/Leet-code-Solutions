#include<bits/stdc++.h>
using namespace std;
void insertAtbottom(stack<int> &myStack, int x)
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
        insertAtbottom(myStack, x);
        myStack.push(temp);
    }
    return;
}
void reverse(stack<int> &stack)
{
    if (stack.size() == 1)
    {
        return;
    }
    int a = stack.top();
    stack.pop();
    reverse(stack);
    insertAtbottom(stack, a);
    return;
}

void reverseStack(stack<int> &stack)
{
    if (stack.size() == 0)
    {
        return;
    }
    reverse(stack);
}