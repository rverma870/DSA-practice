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

bool dfs(int v, vector<int>& colored,vector<int>adj[])
{
  if(colored[v]==-1)
  colored[v]=1;
    for (auto i:adj[v])
    {
        if (colored[i]==-1)
        {
           colored[i]=1-colored[v];
           if (!dfs(i, colored ,adj))
              return false;
        }
        else if (colored[i] == colored[v])
           return false;
    }
    return true;
}
//just to check weather graph contain odd length cycle or not
//cause only in this case this will not possible;
bool isBipartite(int V, vector<int>adj[])
{
  vector<int>colored(V,-1);
    for (int u = 0; u < V; u++)
    {
        if (colored[u]==-1)
        {
          if (!dfs(u, colored ,adj))
          return false;
        }
    }
    return true;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  cout<<isBipartite(nodes,adj);
}
