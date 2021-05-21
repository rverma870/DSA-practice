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
vector<int>bfsOfGraph(int V, vector<int> adj[])
{
  vector<int>ans;
  vector<bool>vis(V,false);
  queue<int>q;
  q.push(0);
  vis[0]=true;
  ans.push_back(q.front());
  while(!q.empty())
  {
    for(auto x : adj[q.front()])
    {
      if(vis[x]==false)
      {
        q.push(x);
        ans.push_back(x);
        vis[x]=true;
      }
    }
    q.pop();
  }
  return ans;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  for(auto e: bfsOfGraph(nodes,adj))
  cout<<e<<" ";
}
