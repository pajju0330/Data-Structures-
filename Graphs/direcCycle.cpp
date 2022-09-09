#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(int node, vector<ll> &vis, vector<ll> vec[], vector<ll> &storeDFs)
{
    storeDFs.push_back(node);
    vis[node] = 1;
    for (auto &&i : vec[node])
        if (!vis[i])
            dfs(i, vis, vec, storeDFs);
}

bool checkForCycleBFs(int s, int v, vector<int> vec[], vector<int> visited)
{
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        for (auto &&i : vec[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, node});
            }
            else if (parent != i)
                return true;
        }
    }
    return false;
}

vector<ll> bfsOfGraph(int n, vector<ll> vec[])
{
    vector<ll> bfs;
    vector<ll> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) // becoz graph is multiComponent
    {
        if (!vis[i])
        {
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto &&i : vec[node])
                {
                    if (!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{
    ll m, n;
    ll u, v;
    cin >> n >> m;
    vector<ll> vec[n + 1];      // declaring the adjacency matrix
    for (int i = 0; i < m; i++) // taking edges as input
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u); // not for directed graphs
    }

    vector<ll> bfs = bfsOfGraph(n, vec);
    for (auto &&i : bfs)
    {
        cout << i << " ";
    }
    cout << "\n";
    vector<ll> storeDFs;
    vector<ll> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, vec, storeDFs);
        }
    }
    for (auto &&i : storeDFs)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}