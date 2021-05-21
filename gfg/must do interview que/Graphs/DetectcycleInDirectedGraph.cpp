#include<bits/stdc++.h>
using namespace std;

void GraphInput(int edge,vector<int>adj[])
{
  for(int i=0; i<edge ; i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }
}

bool dfs(int v, vector<bool>& visited, vector<bool>& dfsvis, vector<int>adj[])
{
    visited[v] = true;
    dfsvis[v] = true;
    for(auto i:adj[v])
    {
        if (!visited[i])
        {
           if(dfs(i, visited, dfsvis, adj))
              return true;
        }
        else if (dfsvis[i])
           return true;
    }
    dfsvis[v]=false;
    return false;
}

bool isCyclic(int V, vector<int>adj[])
{
  vector<bool>visited(V,false);
  vector<bool>dfsvis(V,false);
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
          if (dfs(u, visited, dfsvis, adj))
             return true;
    }
    return false;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes+1];
  GraphInput(edge,adj);
  cout<<isCycle(nodes,adj);
}
