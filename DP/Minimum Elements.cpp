#include <bits/stdc++.h>
using namespace std;
//T.C->O(exponential)
int solve(vector<int> &num, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, target - num[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int target = x;
    int ans = solve(num, target);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// recursion + memoisation
//T.C->O(target*no of coins)+O(target*no of coins)
//S.C->O(target)
#include <bits/stdc++.h>
int solve(vector<int> &num, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, target - num[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[target] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int target = x;
    vector<int> dp(x + 1, -1);
    int ans = solve(num, target, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
//&&^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Tabulation
//T.C->O(target*no of coins)
//S.C->O(target)
#include <bits/stdc++.h>
int solve(vector<int> &num, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, target - num[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[target] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int target = x;
    vector<int> dp(x + 1, -1);
    int ans = solve(num, target, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}