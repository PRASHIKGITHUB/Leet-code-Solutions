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
    void solve(Node *root, vector<int> path, int &count, int k)
    {
        // base
        if (root == NULL)
        {
            return;
        }
        path.push_back(root->data);

        // left
        solve(root->left, path, count, k);
        // right
        solve(root->right, path, count, k);

        int sum = 0;
        int size = path.size();
        for (int i = size - 1; i >= 0; i--)
        {
            sum = sum + path[i];
            if (sum == k)
            {
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, path, count, k);
        return count;
    }
};