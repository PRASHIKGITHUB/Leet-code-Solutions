#include <bits/stdc++.h>
using namespace std;
// using recursion
long long int solve1(vector<int> &valueInHouse, int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return valueInHouse[1];
    }
    long long int include = valueInHouse[n] + solve1(valueInHouse, n - 2);
    long long int exclude = solve1(valueInHouse, n - 1);

    long long int ans = max(include, exclude);
    return ans;
}
long long int solve2(vector<int> &valueInHouse, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return valueInHouse[0];
    }
    long long int include = valueInHouse[n] + solve2(valueInHouse, n - 2);
    long long int exclude = solve2(valueInHouse, n - 1);

    long long int ans = max(include, exclude);
    return ans;
}
long long int houseRobber(vector<int> &valueInHouse)
{

    int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }
    return max(solve1(valueInHouse, n - 1), solve2(valueInHouse, n - 2));
}

// better sc ****************************************************************************
//T.C->O(n);
//S.C->O(n);
#include <bits/stdc++.h>
long long int solve(vector<int> &nums)
{
    int n = nums.size();

    long long int prev1 = nums[0];
    long long int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        long long int incld = nums[i] + prev2;
        long long int exclu = prev1;

        long long int ans = max(incld, exclu);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }
    long long int ans1 = solve(first);
    long long int ans2 = solve(second);
    return max(ans1, ans2);
}