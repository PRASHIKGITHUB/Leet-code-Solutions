#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr,int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    // if (studentCount<m)
    // {
    //     return false;
    // }
    
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        cout<<s<<"------"<<e<<endl;
        cout<<"mid: "<<mid<<endl;;
        cout<<"possible solution: "<<isPossible(arr,n,m,mid)<<endl;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
        cout<<"ans: "<<ans<<endl<<endl;
    }
    cout<<"s : "<<s<< " e : "<<e<<endl;
    return ans;
}
int main(){
    vector<int>arr={10,20,30,40};
    
    
        cout<<findPages(arr,4,4);
    
    
    
    return 0;
}


/*
bool isPossbile(vector<int> arr,int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n){
        return -1;
    }
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossbile(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
*/
