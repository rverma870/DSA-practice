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
bool bfsOfGraph(int start, vector<int> adj[] , vector<bool>&vis )
{
  queue<pair<int,int>>q;//element and parent;
  q.push({start,-1});
  vis[start]=true;
  while(!q.empty())
  {
    for(auto x : adj[q.front().first])
    {
      if(vis[x]==false)
      {
        q.push({x , q.front().first});
        vis[x]=true;
      }
      else if(x != q.front().second)
        return true;
    }
    q.pop();
  }
  return false;
}
bool isCycle(int V, vector<int>adj[])
{
  vector<bool>vis(V,false);
  for(int i=0; i<V ;i++)
  {
    if(vis[i]==false)
    {
      if(bfsOfGraph(i,adj,vis))
      return true;
    }
  }
  return false;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  // for(auto e: bfsOfGraph(nodes,adj))
  // cout<<e<<" ";
  cout<<isCycle(nodes,adj);
}
