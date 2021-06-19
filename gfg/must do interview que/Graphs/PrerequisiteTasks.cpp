#include<bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<bool>& visited,vector<int>adj[], vector<bool> &incall)
{
  visited[v] = true;
  incall[v] = true;
  for (auto i:adj[v])
  {
    if (!visited[i])
    {
       if(dfs(i, visited,adj,incall))
          return true;
        else
          return false;
    }
    else if(incall[i])
      return true;
  }
  return false;
}
bool isCycle(int V, vector<int>adj[])
{
  vector<bool>visited(V,false);
  vector<bool>incall(V,false);
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
          incall.assign(V,false);
          if (dfs(u, visited, adj,incall))
          return true;
        }
    }
    return false;
}

bool isPossible(int N, vector<pair<int,int>>& graph)
{
  vector<int>adj[N];
  for(int i=0;i<graph.size();i++)
  {
    adj[graph[i].second].push_back(graph[i].first);
  }
  return !isCycle(N ,adj);
}

int main()
{
  int n,p;
  cin>>n>>p;
  vector<pair<int,int>> v(p);
  for(int i=0;i<p;i++)
  {
    cin>>v[i].first>>v[i].second;
  }
  cout<<isPossible(n,v);
}
