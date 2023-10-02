#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    int incl = nums[n] + solve(nums, n - 2);
    int excl = solve(nums, n - 1);

    return max(incl, excl);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    int ans = solve(nums, n - 1);
    return ans;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// recursion + memoisation
// T.C->O(n)
// S.C->O(n)+O(n)
#include <bits/stdc++.h>
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int incl = nums[n] + solve(nums, n - 2, dp);
    int excl = solve(nums, n - 1, dp);

    dp[n] = max(incl, excl);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solve(nums, n - 1, dp);
    return ans;
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// Tabulation
// T.C->O(n)
// S.C->O(n)
#include <bits/stdc++.h>
int solve(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int incld;
        if (i == 1)
        {
            incld = nums[i];
        }
        incld = nums[i] + dp[i - 2];
        int exclu = dp[i - 1];

        dp[i] = max(incld, exclu);
    }
    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums);
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
// space optimization
// T.C->O(n)
// S.C->O(1)
#include <bits/stdc++.h>
int solve(vector<int> &nums)
{
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int incld = nums[i] + prev2;
        int exclu = prev1;

        int ans = max(incld, exclu);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums);
}