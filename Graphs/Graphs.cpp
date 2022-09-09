#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V; // No. of vertices
    vector<int> vis; //visited vector
    vector<int> storeDFs; //DFs storage
    vector<int> adj[]; //adjecency list

public:
    Graph(int V); // constructor
    void addEdge(int u, int v);
    vector<int> BFS(int s);                                                               // BFS traversal from given source s
    vector<int> DFS(int node, vector<int> &vis, vector<int> vec[], vector<int> storeDfs); // DFS traversal from given source s
    bool checkForCycleBFs(int s, int v, vector<int> vec[], vector<int> visited);          // un directed cycle detection using BFS
    bool bipartiteBFs(int idx, vector<int> vec[], int color[]);
    bool bipartiteDFs(int idx, vector<int> vec[], int color[]);
    bool checkBipartiteBFs(vector<int> vec[], int n); 
    bool checkBipartiteDFs(vector<int> vec[], int n); 
};

Graph::Graph(int V)
{
    this->V = V;
    adj->resize(V);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

vector<int> Graph::BFS(int s)
{
    vis.resize(V + 1, 0);
    vector<int> bfs;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto &&i : adj[node])
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

vector<int> Graph::DFS(int node, vector<int> &vis, vector<int> vec[], vector<int> storeDfs)
{
    vis.resize(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            storeDfs.push_back(node);
            vis[node] = 1;
            for (auto &&i : vec[node])
            {
                if (!vis[i])
                    DFS(i, vis, vec, storeDfs);
            }
        }
    }
    return storeDFs;
}

bool Graph::checkForCycleBFs(int s, int v, vector<int> vec[], vector<int> visited)
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

bool Graph::bipartiteBFs(int idx, vector<int> vec[], int color[])
{
    queue<int> q;
    q.push(idx);
    color[idx] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &&i : vec[node])
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if (color[i] == color[node])
                return false;
        }
    }
    return true;
}

bool Graph::bipartiteDFs(int idx, vector<int> vec[], int color[])
{
    if (color[idx] == -1)
        color[idx] = 1;
    for (auto &&i : vec[idx])
    {
        if (color[i] == -1)
        {
            color[i] = 1 - color[idx];
            if (!bipartiteDFs(i, vec, color))
                return false;
        }
        else if (color[i] == color[idx])
            return false;
    }
    return true;
}

bool Graph::checkBipartiteBFs(vector<int> vec[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            if(!bipartiteBFs(i,vec,color)) return false;
        }
    }
    return true;
}

bool Graph::checkBipartiteDFs(vector<int> vec[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            if(!bipartiteDFs(i,vec,color)) return false;
        }
    }
    return true;
}