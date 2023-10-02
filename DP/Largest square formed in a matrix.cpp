#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<vector<int>> mat, int i, int j, int &maxi)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }

        int right = solve(mat, i, j + 1, maxi);
        int diagonal = solve(mat, i + 1, j + 1, maxi);
        int down = solve(mat, i + 1, j, maxi);

        if (mat[i][j] == 1)
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;
        solve(mat, 0, 0, maxi);
        return maxi;
    }
};

// Recursion+Memoisation (top down)*******************************************************************************
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = solveMem(mat, i, j + 1, maxi, dp);
        int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
        int down = solveMem(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(dp[i][j], maxi);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solveMem(mat, 0, 0, maxi, dp);
        return maxi;
    }
};

// Tabulation (bottom up ) **************************************************************
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(int &maxi, vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int i = row - 1; i >= 0; i++)
        {
            for (int j = col - 1; j >= 0; j++)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (dp[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j], maxi);
                }
                else
                {
                    return dp[i][j] = 0;
                }
            }
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;

        return solveTab(maxi, mat);
    }
};

// Sapce optimisation *****************************************************************
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(int &maxi, vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();

        vector<int> current(col + 1, 0);
        vector<int> next(col + 1, 0);

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                int right = current[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if (mat[i][j] == 1)
                {
                    current[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(current[j], maxi);
                }
                else
                {
                    current[j] = 0;
                }
            }
            next = current;
        }
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        int maxi = 0;

        solveSO(maxi, mat);
        return maxi;
    }
};


//This can be done in O(1) find it &%&$%^%&*^&($*#$%%^&*(&((&#^@%!*()_(*&^%$#@!)))))