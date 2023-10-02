#include <bits/stdc++.h>
using namespace std;
// T.C->O(n^2logn)
// S.C->O(n^2)
int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sub;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            sub.push_back(sum);
        }
    }
    sort(sub.begin(), sub.end());
    return sub[sub.size() - k];
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include <bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
    //	Write your code here.
    priority_queue<int, vector<int>, greater<int>> q;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (q.size() < k)
            {
                q.push(sum);
            }
            else
            {
                if (sum > q.top())
                {
                    q.pop();
                    q.push(sum);
                }
            }
        }
    }
    return q.top();
}