#include <bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    stack<int> s;
    s.push(node);
    visited[node] = true;
    while (!s.empty())
    {
        int top=s.top();
        s.pop();
        visited[top]=true;
        for(auto i:adj[top]){
            if(!visited[i]){
                s.push(i);
            }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {

            bfs(adj, visited, ans, i);
        }
    }
}
int main()
{
    return 0;
}