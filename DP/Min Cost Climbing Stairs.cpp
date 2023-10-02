#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, vector<int> &cost)
    {
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        }
        int val = min(solve(n - 1, cost), solve(n - 2, cost)) + cost[n];
        return val;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans = min(solve(n - 1, cost), solve(n - 2, cost));
        return ans;
    }
};

// recursion + memoisation
// T.C->O(n)
// S.C->O(n)+O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, vector<int> &cost, vector<int> &dp)
    {

        // Base case
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp)) + cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
        return ans;
    }
};

// Tabular method
// T.C->O(n)
// S.C->O(n)
class Solution
{
public:
    int solve(int n, vector<int> &cost)
    {
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans = solve(n, cost);
        return ans;
    }
};

//Space optimization
// T.C->O(n)
// S.C->O(1)
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int p1 = cost[1];
        int p2 = cost[0];
        int n = cost.size();
        int val;
        for (int i = 2; i < n; i++)
        {
            val = min(p1, p2) + cost[i];
            p2 = p1;
            p1 = val;
        }
        return min(p1, p2);
    }
};