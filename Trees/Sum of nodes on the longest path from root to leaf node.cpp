#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
class Solution
{
public:
    void solve(Node *root, int &maxlen, int len, int &maxsum, int sum)
    {
        if (root == NULL)
        {
            if (len > maxlen)
            {
                maxlen = len;
                maxsum = sum;
            }
            else if (maxlen == len)
            {
                maxsum = max(maxsum, sum);
            }
            return;
        }
        sum = sum + root->data;

        solve(root->left, maxlen, len + 1, maxsum, sum);
        solve(root->right, maxlen, len + 1, maxsum, sum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans;
        int len = 0;
        int maxlen = 0;
        int maxsum = INT_MIN;
        int sum = 0;

        solve(root, maxlen, len, maxsum, sum);
        return maxsum;
    }
};