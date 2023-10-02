#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*k logk)
//S.C->O(n*k)
class node
{
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    // step:1 sare arrays ke first elements insert crow
    for (int i = 0; i < k; i++)
    { // k is number of rows
        node *tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }
    // step:2
    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *tmp = minHeap.top();

        ans.push_back(tmp->data);
        minHeap.pop();

        int row = tmp->i;
        int col = tmp->j;

        if (col + 1 < kArrays[row].size())
        {
            node *next = new node(kArrays[row][col + 1], row, col + 1);
            minHeap.push(next);
        }
    }
    return ans;
}