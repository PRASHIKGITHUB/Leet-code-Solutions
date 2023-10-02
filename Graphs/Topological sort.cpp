#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
// using DFS
// this works for disconnected  components too
void topologicalSort(int src, unordered_map<int, list<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited)
{
    visited[src] = true;

    for (auto i : adj[src])
    {
        if (visited[i] == false)
        {
            topologicalSort(i, adj, ans, visited);
        }
    }

    ans.push_back(src);
}
vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
    vector<int> ans;
    unordered_map<int, bool> visited;

    // adjacency list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            topologicalSort(i, adj, ans, visited);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

//*******************************************************************************
// Kahn's algorithm
// using BFS
// this only works for connected components only
//tc O(n+e)
//sc O(n+e)
#include <bits/stdc++.h>
#include <bits/stdc++.h>
vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(N, 0);
    for (auto i : edges)
    {
        indegree[i.second]++;
    }

    // create queue
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
