#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*
the graph which can be coloured using exactly 2 colors but 2 adjecent nodes shouldn't have same color
(bookish: a biparstite graph is graph which can be devided into two sets such that no edge connects the elements of the same set)

g -> green , b --> blue

          (g)-(b)
          /     \
(b)-(g)-(b)     (g)-(b)-(g) ----> bipartite
          \     /
          (g)-(b)

            (g)
          /     \
(b)-(g)-(b)     (b)-(g)-(b) ----> non-bipartite
          \     /
          (g)-(b)

obersevation:
odd length cycle --> non-bipartite
else --> bipartite

*/
bool bipartiteBFs(int idx,vector<ll>vec[],ll color[]){
    queue<int>q;
    q.push(idx);
    color[idx] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (auto &&i : vec[node])
        {
            if(color[i] == -1){
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if(color[i] == color[node]) return false;
        }
    }
    return true;
}
bool bipartiteDFs(int idx,vector<ll>vec[],ll color[]){
    if(color[idx] == -1) color[idx] = 1;
    for (auto &&i : vec[idx])
    {
        if(color[i] == -1){
            color[i] = 1-color[idx];
            if(!bipartiteDFs(i,vec,color)) return false;
        }
        else if(color[i] == color[idx]) return false;
    }    
    return true;
}
bool checkBipartiteBFs(vector<ll> vec[], ll n)
{
    ll color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            if(!bipartiteBFs(i,vec,color)) return false;
        }
    }
    return true;
}
bool checkBipartiteDFs(vector<ll> vec[], ll n)
{
    ll color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if(color[i] == -1){
            if(!bipartiteDFs(i,vec,color)) return false;
        }
    }
    return true;
}

int main()
{
    ll m, n;
    ll u, v;
    cin >> n >> m;
    vector<ll> vec[n + 1];      // declaring the adjacency list
    for (int i = 0; i < m; i++) // taking edges as input
    {
      cin >> u >> v;
      vec[u].push_back(v);
      vec[v].push_back(u); // not for directed graphs
    }
}