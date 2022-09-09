/*
spanning tree::
converting a graph into tree and every node should be reachable by every other node
minimum spanning tree :: spanning tree having minimum edge weight sum

Prim's Algo::
1)collect 3 arrays
1.1)key array -> initialized to inf
1.2)mst array --> initialized to false
1.3)parent array --> initialized to -1
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
Brute force implementation
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int u,v,wt;
    while(m--){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>key(n,1e6);
    vector<int>parent(n,-1);
    vector<bool>mstSet(n,false);
    key[0] = 0;
    for(int cnt = 0;cnt<n-1;cnt++){
        int mini = INT_MAX,a;
        for (int b = 0; b < n; b++)
        {
            if(!mstSet[b] && key[b] < mini)
                mini = key[b],a=b;
        }
        mstSet[a] = true;
        for (auto &&i : adj[a])
        {
            int b = i.first;
            int weight = i.second;
            if(!mstSet[b] && weight < key[b]) parent[b] = u,key[b] = weight;
        }
    }
    for (int i = 0; i < n; i++) cout<<parent[i]<<" "<<i<<"\n";
    return 0;
}
*/

//priority queue implementation

int main2()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int u,v,wt;
    while(m--){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>key(n,1e6);
    vector<int>parent(n,-1);
    vector<bool>mstSet(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[0] = 0;
    parent[0]  = -1;
    pq.push({0,0});
    for(int cnt = 0;cnt<n-1;cnt++){
        u = pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for (auto &&i : adj[u])
        {
            int b = i.first;
            int weight = i.second;
            if(!mstSet[b] && weight < key[b]) parent[b] = u,key[b] = weight;
        }
    }
    for (int i = 0; i < n; i++) cout<<parent[i]<<" "<<i<<"\n";
    return 0;
    
}