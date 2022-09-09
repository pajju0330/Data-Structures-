/*
Bridge is a edge which devides the graph into differnt components
low[adj] > insertionTime[node] 
*/


#include <bits/stdc++.h>
#define ll long long int
#define inf 1e5
using namespace std;

void dfs(int node, int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer, vector<int>adj[])
{
    vis[node] = 1;
    vis[node] = low[node] = timer++;
    for (auto &&i : adj[node])
    {
        if(i == parent) continue;
        if(!vis[i]){
            dfs(i,node,vis,tin,low,timer,adj);
            low[node] = min(low[node],low[i]);
            if(low[i] > tin[node]){
                cout<<node<<" "<<i<<"\n";
            }
        }
        else{
            low[node] = min(low[node] , tin[i]);
        }
    }
    
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
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) dfs(i,-1,vis,tin,low,timer,adj);
    }
    
    return 0;
}
