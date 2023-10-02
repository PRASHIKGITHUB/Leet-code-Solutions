#define MOD 1000000007
using namespace std;
//tc exponential
long long int countDerangements(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int ans =
        (((n - 1) % MOD) * ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) % MOD) % MOD;
    return ans;
}
// Recursion + memoisation***************************************************************
//T.C->O(n)
//S.C->O(n)+O(n)
#define MOD 1000000007
#include <bits/stdc++.h>
long long int solve(int n, vector<long long> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (((n - 1) % MOD) *
             ((solve(n - 1, dp) % MOD) + (solve(n - 2, dp) % MOD)) % MOD) %
            MOD;
    return dp[n];
}
long long int countDerangements(int n)
{
    vector<long long> dp(n + 1, -1);
    long long int ans = solve(n, dp);
    return ans;
}
// tabulation **************************************************
//T.C->O(n)
//S.C->O(n)
#define MOD 1000000007
#include <bits/stdc++.h>

long long int solve(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) % MOD * (sum) % MOD) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n)
{

    return solve(n);
}
// space optimisation ****************************************************
//T.C->O(n)
//S.C->O(1)
#define MOD 1000000007
#include <bits/stdc++.h>

long long int solve(int n)
{

    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {

        long long temp = ((i - 1) % MOD * (prev2 % MOD + prev1 % MOD) % MOD) % MOD;
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}
long long int countDerangements(int n)
{

    return solve(n);
}