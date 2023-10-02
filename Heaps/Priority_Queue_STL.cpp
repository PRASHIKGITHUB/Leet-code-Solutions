#include<bits/stdc++.h>
using namespace std;

int main(){
    //pq is in max heap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(7);
    pq.push(2);
    pq.push(0);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    if (pq.empty())
    {
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(3);
    minheap.push(7);
    minheap.push(2);
    minheap.push(0);
    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top()<<endl;
    if (minheap.empty())
    {
        cout<<"minheap is empty"<<endl;
    }
    else{
        cout<<"minheap is not empty"<<endl;
    }
    

    return 0;
}