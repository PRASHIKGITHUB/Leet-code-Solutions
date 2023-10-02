#include<bits/stdc++.h>
using namespace std;
bool isSorted(int * arr,int size){
    if(size==1 ){
        return 1;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1,size-1);
    }
}
int main(){
    int arr[]={9,2,3,3};
    cout<<isSorted(arr,4)<<endl;
    return 0;
}