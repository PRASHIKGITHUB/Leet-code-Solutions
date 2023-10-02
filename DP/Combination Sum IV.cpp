#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &num, int tar)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans = ans + solve(num, tar - num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

// Recursion + memoisation *******************************
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    if (dp[tar] != -1)
    {
        return dp[tar];
    }
    dp[tar] = 0;
    for (int i = 0; i < num.size(); i++)
    {
        dp[tar] = dp[tar] + solve(num, tar - num[i], dp);
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> dp(n + 1, -1);
    return solve(num, tar, dp);
}
// Tabulation**************************************************
int solve(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
            {

                dp[i] = dp[i] + dp[i - num[j]];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{

    return solve(num, tar);
}
//Space optimization is not possible