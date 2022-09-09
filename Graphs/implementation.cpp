//fails for large n

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// int main()
// {
//     //without weight of the edge
//     ll m, n;
//     ll u, v;
//     cin >> n >> m;
//     vector<vector<ll>> vec(n + 1, vector<ll>()); //declaring the adjacency matrix
//     for (int i = 0; i < m; i++) //taking edges as input
//     {
//         cin>>u>>v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);//not for directed graphs
//     }
//     for (auto &&i : vec)
//     {
//         for (auto &&j : i)
//         {
//             cout<<j<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }


int main()
{
    //with weight of the edge
    ll m, n;
    ll u, v,w;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> vec(n + 1, vector<pair<ll,ll>>()); //declaring the adjacency matrix
    for (int i = 0; i < m; i++) //taking edges as input
    {
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});//not for directed graphs
    }
    for (auto &&i : vec)
    {
        for (auto &&j : i)
        {
            cout<<j.first<<" "<<j.second<<"\n";
        } 
    }
    return 0;
}

