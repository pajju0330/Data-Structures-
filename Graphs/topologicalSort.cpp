#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
   vis[node] = 1;
   for (auto i : adj[node])
   {
      if (!vis[i])
      {
         findTopoSort(i, vis, st, adj);
      }
   }
   st.push(node);
}

vector<int> topoSort(int N, vector<int> adj[])
{
   stack<int> st;
   vector<int> vis(N, 0);
   for (int i = 0; i < N; i++)
   {
      if (vis[i] == 0)
         findTopoSort(i, vis, st, adj);
   }
   vector<int> topo;
   while (!st.empty())
   {
      topo.push_back(st.top());
      st.pop();
   }
   return topo;
}
vector<int> topoSortBFs(int N, vector<int> adj[])
{
   queue<int> q;
   vector<int> indegree(N, 0);
   for (int i = 0; i < N; i++)
   {
      for (auto &&i : adj[i])
         indegree[i]++;
   }
   for (int i = 0; i < N; i++)
   {
      if (indegree[i] == 0)
         q.push(i);
   }
   vector<int> topo;
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      topo.push_back(node);
      for (auto &&i : adj[node])
      {
         indegree[i]--;
         if (indegree[i] == 0)
            q.push(i);
      }
   }
   return topo;
}

int main()
{

   return 0;
}