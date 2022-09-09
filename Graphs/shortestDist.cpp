// shortest dist in an undirected graph with no weights

/*
0-> 1 ,3
1->0,2,3
2->1,6
3->0,4
4->3,5
5->4,6
6->2,5,7,8
7->6,8
8->6,7
*/

#include <bits/stdc++.h>
#define ll long long int
#define inf 1e5
using namespace std;

void shortestDistfromSrc(int n, vector<int> adj[], int src) // src-->starting point
{
    vector<int> dist(n, inf);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &i : adj[node])
        {
            if (dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    for (auto &&i : dist)   cout << i << " ";
    cout << "\n";
}

int main()
{
    ll m, n;
    ll u, v;
    cin >> n >> m;
    vector<int> vec[n + 1];     // declaring the adjacency matrix
    for (int i = 0; i < m; i++) // taking edges as input
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u); // not for directed graphs
    }
    shortestDistfromSrc(n, vec, 0);
    return 0;
}
