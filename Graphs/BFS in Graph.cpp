#include <bits/stdc++.h>
using namespace std;
// T.C->o(vertex+edges)
// S.C->o(vertex+edges)
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int v = edges[i].first;
        int u = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;
    prepareAdjList(adjList, edges);
    for (int i = 0; i < vertex; i++) //ensures no graph left
    {
        if (visited[i] != 1)
        {

            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}