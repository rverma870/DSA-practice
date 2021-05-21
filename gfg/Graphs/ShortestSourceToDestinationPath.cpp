#include<bits/stdc++.h>
using namespace std;
//for undirected Graph;

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
vector<int>SourceToDestination(int V, vector<int> adj[])
{
  vector<int>dis(V,INT_MAX);
  queue<int>q;
  q.push(0);
  dis[0]=0;
  while(!q.empty())
  {
    for(auto x : adj[q.front()])
    {
      if(dis[q.front()]+1 < dis[x])
      {
         dis[x] = dis[q.front()]+1;
         q.push(x);
      }
    }
    q.pop();
  }
  return dis;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  for(auto e:SourceToDestination(nodes,adj))
  cout<<e<<" ";
}
