#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    int m=q.size()-k;
    stack<int>s;
    for(int i=0;i<k;i++){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    while(m--){
        int element=q.front();
        q.pop();
        q.push(element);
    }
    return q;
}