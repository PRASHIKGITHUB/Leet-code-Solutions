#include <bits/stdc++.h>
using namespace std;
//T.C->O(4^m*n)
//S.C->O(m*n)
bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && arr[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movement
    // D L R U

    visited[x][y] = 1;
    // Down
    if (isSafe(x + 1, y, arr, n, visited))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, arr, n, visited))
    {

        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, arr, n, visited))
    {

        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, arr, n, visited))
    {

        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    visited[x][y] = 0;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}