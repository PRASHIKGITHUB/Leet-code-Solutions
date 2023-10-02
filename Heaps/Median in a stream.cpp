#include <bits/stdc++.h>
using namespace std;
// T.C->O(n^2);
// S.C->O(1);
// bekar solution
vector<int> findMedian(vector<int> &arr, int n)
{

    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int current = arr[i];
        for (; j >= 0; j--)
        {
            if (arr[j] > current)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = current;
        int size = ans.size();
        if (size % 2 == 1)
        {
            int val;
            val = arr[size / 2] + arr[(size / 2) + 1];
            ans.push_back(val / 2);
        }
        else
        {
            int val;
            val = arr[size / 2];
            ans.push_back(val);
        }
    }
    return ans;
}

// heap solution #$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%%%#####333333333333333333
#include <bits/stdc++.h>
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }

        break;

    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }
}
vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;
    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}
