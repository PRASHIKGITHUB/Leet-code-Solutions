#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &satisfaction, int index, int time)
    {
        if (index >= satisfaction.size())
        {
            return 0;
        }

        int include = 0;
        include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);

        int exclude = 0;
        exclude = solve(satisfaction, index + 1, time);

        return max(include, exclude);
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
};

// Top down ********************************************************************************
class Solution
{
public:
    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        if (index >= satisfaction.size())
        {
            return 0;
        }

        if (dp[index][time] != -1)
        {
            return dp[index][time];
        }
        int include = 0;
        include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);

        int exclude = 0;
        exclude = solve(satisfaction, index + 1, time, dp);

        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(satisfaction, 0, 0, dp);
    }
};
// Bottom up *****************************************************************************************
class Solution
{
public:
    int solve(vector<int> &satisfaction)
    {

        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int include = 0;
        int exclude = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--) // index se start kiya hai
            {
                include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                exclude = dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};

// space optimisation
class Solution
{
public:
    int solve(vector<int> &satisfaction)
    {

        int n = satisfaction.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        int include = 0;
        int exclude = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                include = satisfaction[index] * (time + 1) + next[time + 1];
                exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};

//isme single array bhi use kr sakte hai
//and greedy ka use krke O(1) me bhi kr sakte