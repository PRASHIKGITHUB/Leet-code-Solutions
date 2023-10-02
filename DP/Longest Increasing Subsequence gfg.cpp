#include <bits/stdc++.h>
using namespace std;
// tc O(2^n)
// tc O(n)
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int solve(int arr[], int n, int curr, int prev)
    {
        if (curr == n)
        {
            return 0;
        }

        // inlcude
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
        {
            include = 1 + solve(arr, n, curr + 1, curr);
        }

        // exclude
        int exclude = 0 + solve(arr, n, curr + 1, prev);

        return max(include, exclude);
    }
    int longestSubsequence(int n, int a[])
    {
        return solve(a, n, 0, -1);
    }
};

// top down *****************************************************************************
// tc o(n^2)
// sc o(n^2)
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int solve(int arr[], int n, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }
        // inlcude
        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
        {
            include = 1 + solve(arr, n, curr + 1, curr, dp);
        }

        // exclude
        int exclude = 0 + solve(arr, n, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(a, n, 0, -1, dp);
    }
};

// bottom up
// tc o(n^2)
// sc o(n^2)
class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int solve(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // inlcude
                int include = 0;
                if (prev == -1 || arr[curr] > arr[prev]) // index ki  bohat bkchodi hai yaha fuck
                {
                    include = 1 + dp[curr + 1][curr + 1];
                }

                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    int longestSubsequence(int n, int a[])
    {

        return solve(a, n);
    }
};

// space optimistion ******************************************************************************************
// tc o(n^2)
// sc o(n^2)
class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int solve(int arr[], int n)
    {

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // inlcude
                int include = 0;
                if (prev == -1 || arr[curr] > arr[prev])
                {
                    include = 1 + nextRow[curr + 1];
                }

                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
    int longestSubsequence(int n, int a[])
    {

        return solve(a, n);
    }
};
//Optimised *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//tc O(nlogn)
//sc O(n)
#include<bits/stdc++.h>
class Solution
{
    public:
    int optimised(int n,int a[]){
        if(n==0){
            return 0;
        }
        
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just bada element
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       return optimised(n,a);
    }
};