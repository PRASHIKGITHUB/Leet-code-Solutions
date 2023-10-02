#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &obstacles, int currlane, int currpos)
    {
        int n = obstacles.size() - 1;
        if (currpos == n)
        {
            return 0;
        }

        if (obstacles[currpos + 1] != currlane)
        {
            return solve(obstacles, currlane, currpos + 1);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            { // i is lane
                if (obstacles[currpos] != i && currlane != i)
                {
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        int currlane = 2;
        int currpos = 0;
        return solve(obstacles, currlane, currpos);
    }
};

// top down ***********************************************************************
class Solution
{
public:
    int solveMem(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> dp)
    {
        int n = obstacles.size() - 1;
        if (currpos == n)
        {
            return 0;
        }

        if (dp[currlane][currpos] != -1)
        {
            return dp[currlane][currpos];
        }
        if (obstacles[currpos + 1] != currlane)
        {
            return solveMem(obstacles, currlane, currpos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            { // i is lane
                if (obstacles[currpos] != i && currlane != i)
                {
                    ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));
                }
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int> &obstacles)
    {
        int currlane = 2;
        int currpos = 0;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(obstacles, currlane, currpos, dp);
    }
};

//Tabulation ******************************************************************************
int solveTab(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obstacles[currpos + 1] != currlane)
            {
                dp[currlane] [currpos] = dp[currlane] [currpos + 1];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                { // i is lane
                    if (obstacles[currpos] != i && currlane != i)
                    {
                        ans = min(ans, 1 + dp[i][currpos+1]); //currpos+1 kiya hai instead of currpos*!@#$$%%^^
                    }
                }
                dp[currlane][currpos]=ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
}

//Space optimisation
int solveTab(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<int>curr(4,INT_MAX);
    vector<int>next(4,INT_MAX);
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            if (obstacles[currpos + 1] != currlane)
            {
                curr[currlane] = next[currlane];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                { // i is lane
                    if (obstacles[currpos] != i && currlane != i)
                    {
                        ans = min(ans, 1 + next[i]); //currpos+1 kiya hai instead of currpos*!@#$$%%^^
                    }
                }
                curr[currlane]=ans;
            }
        }
        next=curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}