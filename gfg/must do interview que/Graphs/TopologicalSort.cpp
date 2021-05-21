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

void dfs(int v, vector<bool>& visited, vector<int>&ans ,vector<int>adj[])
{
    visited[v] = true;

    for (auto i:adj[v])
    {
        if (!visited[i])
          dfs(i, visited, ans, adj);
    }
    ans.push_back(v);
}
vector<int> topoSort(int V, vector<int>adj[])
{
  vector<bool>visited(V,false);
  vector<int>ans;
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
          dfs(u, visited, ans, adj);

    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  for(auto e:topoSort(nodes,adj))
  cout<<e<<" ";
}
