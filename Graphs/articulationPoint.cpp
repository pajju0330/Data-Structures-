/*
articulation point is a node which divides the graph into differnt components
low[adj] >= insertionTime[node] && parent != -1
*/


#include <bits/stdc++.h>
#define ll long long int
#define inf 1e5
using namespace std;

void dfs(int node, int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer, vector<int>adj[],vector<int>&isArticulation)
{
    vis[node] = 1;
    vis[node] = low[node] = timer++;
    int child = 0;
    for (auto &&i : adj[node])
    {
        if(i == parent) continue;
        if(!vis[i]){
            dfs(i,node,vis,tin,low,timer,adj,isArticulation);
            low[node] = min(low[node],low[i]);
            if(low[i] >= tin[node] && parent != -1){
                isArticulation[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node] , tin[i]);
        }
    }
    if(parent == -1 && child > 1) isArticulation[node]  =  1;
    
}

int main()
{
    ll m, n;
    ll u, v;
    cin >> n >> m;
    vector<int> adj[n];    
    for (int i = 0; i < m; i++) 
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>vis(n,0);
    vector<int>isArticulation(n,-1);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
    }
    for (int i = 0; i < n; i++)
    {
        if(isArticulation[i] == 1) cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}
