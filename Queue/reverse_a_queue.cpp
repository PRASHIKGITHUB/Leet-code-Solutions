#include<bits/stdc++.h>
using namespace std;
// T.C->O(n)
// S.C->O(n)
queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
// using recursion
// T.C->O(n)
// S.C->O(n)
void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    int element=q.front();
    q.pop();
    reverse(q);
    q.push(element);
    
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}