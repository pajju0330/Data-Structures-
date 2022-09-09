#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(int node, vector<ll> &vis, vector<ll> vec[], vector<ll> storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto &&i : vec[node])
    {
        if(!vis[i])
            dfs(i, vis, vec, storeDfs);
    }
}
vector<ll> dfsOfGraph(int n, vector<ll> vec[])
{
    vector<ll>storeDfs;
    vector<ll>vis(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i, vis, vec, storeDfs);
    }
    return storeDfs;
}

vector<ll> bfsOfGraph(int n, vector<ll> vec[])
{
    vector<ll> bfs;
    vector<ll> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
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
    return 0;
}