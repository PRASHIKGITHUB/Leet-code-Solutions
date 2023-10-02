#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &values, vector<int> &weights, int index, int capacity)
{
    if (index == 0)
    {
        if (weights[index] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    if (weights[index] <= capacity)
    {

        include = values[index] +
                  solve(values, weights, index - 1, capacity - weights[index]);
    }
    int exclude = solve(values, weights, index - 1, capacity);

    return max(include, exclude);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return solve(values, weights, n - 1, w);
}

// Recursion + memoisation (top down)
int solve(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weights[index] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + solve(values, weights, index - 1, capacity - weights[index], dp);
    }
    int exclude = solve(values, weights, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(values, weights, n - 1, w, dp);
}

// Tabulation (bottom up)***********************************************************************8
int solve(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step:1
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // step:2
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    // step:3
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            int exclude = dp[index - 1][w];
            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n - 1][capacity];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return solve(weights, values, n, w);
}

// Space optimisation**********************************************************************
int solve(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step:1

    vector<int> curr(capacity + 1, 0);
    vector<int> prev(capacity + 1, 0);

    // step:2
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    // step:3
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + prev[w - weight[index]];
            }
            int exclude = prev[w];
            curr[w] = max(exclude, include);
        }
        prev = curr;
    }
    return prev[capacity];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    return solve(weights, values, n, w);
}

// using one curr vector*****************************************************************
int solve(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step:1

    vector<int> curr(capacity + 1, 0);

    // step:2
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    // step:3
    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--) //travelling from back
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w - weight[index]];
            }
            int exclude = curr[w];
            curr[w] = max(exclude, include);
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, maxWeight);
}