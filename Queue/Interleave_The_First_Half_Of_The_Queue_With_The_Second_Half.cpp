#include <bits/stdc++.h> 
using namespace std;
void interLeaveQueue(queue < int > & q) {
    queue<int>temp;
    int n=q.size();
    for(int i=0;i<n/2;i++){
        int val=q.front();
        q.pop();
        temp.push(val);
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<temp.front()<<" ";
        temp.pop();
        
    }
    cout<<endl;
    // while(!temp.empty()){
    //     int first;
    //     int second;
    //     first=temp.front();
    //     temp.pop();
    //     q.push(first);
    //     second=q.front();
    //     q.pop();
    //     q.push(second);


    // }
    // return q;
}
int main(){
    queue<int>q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i+1);
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    cout<<"before"<<endl;
    interLeaveQueue(q);
    
    for (int i = 0; i < 10; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"after"<<endl;
    return 0;
}