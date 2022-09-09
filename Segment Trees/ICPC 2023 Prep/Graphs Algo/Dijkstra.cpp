/* || Dijkstra's Algorithm || */
// shortest path in undirected weighted graph

/*
requisites:
priority queue with minimum heap ( dist,node)
distance array marked as inf
dist[src] = 0
and push src in pq.
TC - O(N+E)logN
SC - o(N)+o(N)+o(N)

5 6
1 2 2
1 4 1
2 5 5
2 3 4
4 3 3
3 5 1
1

*/

#include <bits/stdc++.h>
#define inf 1e8

using namespace std;

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    int u, v, wt;
    while (m--)
    {
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    cin >> source;

    // dijkstra's algo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, inf);
    distTo[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for (auto &&i : g[prev])
        {
            int next = i.first;
            int nextDist = i.second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next], next});
            }
        }
    }
    cout<<"Distances from the source "<<source<<" are: \n";
    for (int i = 1; i <= n; i++)
    {
        cout<<distTo[i]<<" ";
    }
    cout<<"\n";
    return 0;
    
    
}
