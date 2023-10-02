#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
// Recursion ***********************************************************
int add(int a, int b)
{
    int ans = (a % mod + b % mod) % mod;
    return ans;
}
int mul(int a, int b)
{
    int ans;
    ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
int solve(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    return add(mul(k - 1, solve(n - 2, k)), mul(k - 1, solve(n - 1, k)));
}
int numberOfWays(int n, int k)
{
    return solve(n, k);
}
// Recursion + memoisation **************************************************
// T.C->O(n)
// S.C->O(n)+O(n)
#include <bits/stdc++.h>
#define mod 1000000007
int add(int a, int b)
{
    int ans = (a % mod + b % mod) % mod;
    return ans;
}
int mul(int a, int b)
{
    int ans;
    ans = ((a % mod) * 1LL * (b % mod)) % mod;
    return ans;
}
int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = add(mul(k - 1, solve(n - 2, k, dp)), mul(k - 1, solve(n - 1, k, dp)));
    return dp[n];
}
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}
// Tabulation *********************************************************************
// T.C->O(n)
// S.C->O(n)
#include <bits/stdc++.h>
#define mod 1000000007
int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int mul(int a, int b)
{
    int ans;
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int solve(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(k - 1, dp[i - 2]), mul(k - 1, dp[i - 1]));
    }
    return dp[n];
}
int numberOfWays(int n, int k)
{
    return solve(n, k);
}
// Memory Optimization
//  T.C->O(n)
//  S.C->O(1)
#include <bits/stdc++.h>
#define mod 1000000007
int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int mul(int a, int b)
{
    int ans;
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int solve(int n, int k)
{

    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        int temp = add(mul(k - 1, prev2), mul(k - 1, prev1));
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    return solve(n, k);
}
