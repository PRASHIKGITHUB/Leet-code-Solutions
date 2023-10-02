#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    for (int i = 0; i <arr.size() - 2; i++)
    {
        for (int j = i + 1; j <arr.size() - 1; j++)
        {
            for (int k = j + 1; k <arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == n)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }
}

//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.************************************
    // T.C->O(n^2)
    // S.C->O(1)
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
           int j=i+1;
           int k=n-1;
           while(j<k){
               if(arr[i]+arr[j]+arr[k]==0){
                   return true;
               }
               else if(arr[i]+arr[j]+arr[k]<0){
                   j++;
               }
               else{
                   k--;
               }
           }
        }
        return false;
    }
};

 bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n;i++){
           int j=i+1;
           int k=n-1;
           while(j<k){
               if(A[i]+A[j]+A[k]==X){
                   return true;
               }
               else if(A[i]+A[j]+A[k]<X){
                   j++;
               }
               else{
                   k--;
               }
           }
        }
        return false;
    }

//{ Driver Code Starts.**********************************************
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends