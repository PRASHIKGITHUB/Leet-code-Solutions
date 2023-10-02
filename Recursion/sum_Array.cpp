#include<bits/stdc++.h>
using namespace std;
int sum(int* arr,int size){
    if(size==0){
        return 0;
    }
    else{
        return arr[0]+sum(arr+1,size-1);
    }
}
int main(){
    int arr[]={2,4,9,9,9};
    cout<<sum(arr,5);
    
    return 0;
}