#include<bits/stdc++.h>
using namespace std;

void GraphInput(int edge,vector<int>adj[])
{
  for(int i=0; i<edge ; i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

bool dfs(int v, vector<bool>& visited, int parent ,vector<int>adj[])
{
    visited[v] = true;

    for (auto i:adj[v])
    {
        if (!visited[i])
        {
           if (dfs(i, visited, v,adj))
              return true;
        }
        else if (i != parent)
           return true;
    }
    return false;
}
bool isCycle(int V, vector<int>adj[])
{
  vector<bool>visited(V,false);
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
          if (dfs(u, visited, -1,adj))
             return true;
    }
    return false;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  cout<<isCycle(nodes,adj);
}
