#include<bits/stdc++.h>
using namespace std;

void GraphInput(int edge,vector<pair<int,int>>adj[])
{
  for(int i=0; i<edge ; i++)
  {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
}

void printGraph(vector<pair<int,int>>adj[], int nodes)
{
  for(int i=0;i<nodes;i++)
  {
    cout<<i<<" -> ";
    for(auto e:adj[i])
    cout<<e.first<<" "<<e.second<<" , ";
    cout<<endl;
  }
}

vector<int>SourceToDestination(int V, vector<pair<int,int>> adj[])
{
  vector<int>dis(V,INT_MAX);
  queue<int>q;
  q.push(0);
  dis[0]=0;
  while(!q.empty())
  {
    for(auto x : adj[q.front()])
    {
      if(dis[q.front()] + x.second < dis[x.first])
      {
         dis[x.first] = dis[q.front()] + x.second;
         q.push(x.first);
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
  vector<pair<int,int>>adj[nodes];
  GraphInput(edge,adj);
  printGraph(adj,nodes);
  for(auto e:SourceToDestination(nodes,adj))
  cout<<e<<" ";
}
