#include<bits/stdc++.h>
using namespace std;

//used to find Strongly connnected component;

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
void revDFS(int v,vector<int>revAdj[],vector<bool>&vis)
{
  vis[v]=true;
  for(auto e:revAdj[v])
  {
    if(!vis[e])
    revDFS(e,revAdj,vis);
  }
  cout<<v<<" ";
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  vector<int>topOrder=topoSort(nodes,adj);//Topological order;

  vector<int>revAdj[nodes];
  for(int i=0;i<nodes;i++)
  {
    for(auto e:adj[i])
    revAdj[e].push_back(i);
  }
  vector<bool>vis(nodes,false);
  for(auto e:topOrder)
  {
    if(!vis[e])
    {
      cout<<"SCC : ";
      revDFS(e,revAdj,vis);
      cout<<endl;
    }
  }

}
