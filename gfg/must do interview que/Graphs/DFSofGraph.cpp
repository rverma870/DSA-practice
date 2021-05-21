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

void DFS(int node , vector<bool>&vis , vector<int>adj[] ,vector<int>&ans)
{
  vis[node]=true;
  ans.push_back(node);
  for(auto e:adj[node])
  {
    if(vis[e]==false)
      DFS(e,vis,adj,ans);
  }
}

vector<int>dfsOfGraph(int V, vector<int> adj[])
{
  vector<int>ans;
  vector<bool>vis(V,false);
  DFS(0,vis,adj,ans);
  return ans;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  for(auto e: dfsOfGraph(nodes,adj))
  cout<<e<<" ";
}
