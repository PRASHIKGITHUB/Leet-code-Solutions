#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, vector<int> &arr)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, arr[i] * arr[k] * arr[j] + solve(i, k, arr) + solve(k, j, arr));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        return solve(0, n - 1, values);
    }
};
// recursion + memoisation ********************************************************
class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, arr[i] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k, j, arr, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, values, dp);
    }
};
//bottom up**************************************************************************************
class Solution
{
public:
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
    int minScoreTriangulation(vector<int> &values)
    {
        return solve(values);
    }
};