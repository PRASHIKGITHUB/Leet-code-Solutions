#include <bits/stdc++.h>
using namespace std;
vector<int> reverse(vector<int> arr){
	int i=0;
	int j=arr.size()-1;
	while(i<j){
		swap(arr[i++],arr[j--]);
	}
    return arr;
}
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    
    vector<int> ans;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        cout<<endl;
        cout<<carry<<endl;
        sum = sum % 10;
        // cout<<sum<<" ";
        ans.push_back(sum);
        i--;
        j--;
    }

    // first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        cout<<endl;
        cout<<carry<<endl;
        sum = sum % 10;
        // cout<<sum<<" ";
        ans.push_back(sum);
        i--;
    }

    // second case
    while (j >= 0)
    {
        int sum =  b[j] + carry;
        cout<<sum<<endl;
        carry = sum / 10;
        cout<<endl;
        cout<<carry<<endl;
        sum = sum % 10;
        // cout<<sum<<" ";
        ans.push_back(sum);
        j--;
    }

    // third case
    while (carry != 0)
    {
        int sum =  carry;
        carry = sum / 10;
        sum = sum % 10;
        // cout<<sum<<" ";
        ans.push_back(sum);
    }
	
    cout<<endl;
    return reverse(ans);
}
int main(){
    vector<int> arr1={9,8};
    vector<int> arr2={1,1,4};
    vector<int>ans=findArraySum(arr1,arr1.size(),arr2,arr2.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}