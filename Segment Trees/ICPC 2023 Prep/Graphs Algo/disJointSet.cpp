/*
given multiple components and 2 nodes, you have to tell if they belong to same component or not
method :: union by Rank and path compression
*/

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int parent[100000];
int Rank[100000];
void makeset(int N){
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findParent(int node){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int u ,int v){
    u = findParent(u);
    v = findParent(v);
    if(Rank[u] < Rank[v]){
        parent[u] = v;
    }
    else if(Rank[v] < Rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main()
{   
    int n,m,u,v;
    cin>>n>>m;
    makeset(n);
    while(m--){
        cin>>u>>v;
        Union(u,v);
    }
    //if que is to check for node 2 ,node 5
    if(findParent(2) == findParent(5)) cout<<"YES same components\n";
    else cout<<"NO !! diff components";
    return 0;
}