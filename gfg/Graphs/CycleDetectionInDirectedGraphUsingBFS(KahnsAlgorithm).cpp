//Kanh's Algorithm
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

bool isCyclic(int V, vector<int>adj[])
{
  vector<int>inDegree(V,0);
  vector<int>ans;
  for(int i=0 ;i<V;i++)
  {
    for(auto e:adj[i])
    {
      inDegree[e]+=1;//calculating inDegree
    }
  }
  queue<int>q;
  for(int i=0;i<V;i++)
    if(inDegree[i]==0)
      q.push(i);
  int count=0;
  while(!q.empty())
  {
    for(auto e:adj[q.front()])
    {
      inDegree[e]-=1;
      if(inDegree[e]==0)
        q.push(e);
    }
    count++;
    q.pop();
  }
  if(count==V)
  return false;
  return true;
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
