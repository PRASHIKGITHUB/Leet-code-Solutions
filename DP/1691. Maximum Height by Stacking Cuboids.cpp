#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<int> &Base, vector<int> &newBox)
    {
        if (newBox[0] <= Base[0] && newBox[0] <= Base[0] && newBox[0] <= Base[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int solve(vector<vector<int>> &a)
    {
        int n = a.size();
        if (n == 0)
        {
            return 0;
        }
        int ans = a[0][2];
        int finalans = 0;
        for (int i = 1; i < n; i++)
        {
            if (isSafe(a[i - 1], a[i]))
            {
                ans = ans + a[i][2];
            }
            else
            {
                finalans = max(finalans, ans);
                ans = 0;
            }
        }
        finalans = max(finalans, ans);
        return finalans;
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end(), greater<int>());
        return solve(cuboids);
    }
};