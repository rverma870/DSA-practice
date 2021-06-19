#include<bits/stdc++.h>
using namespace std;
//to find minimum spanning tree of a graph;
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

vector<int>PrimsAlgorithm(int V, vector<pair<int,int>> adj[])
{
  vector<int>val(V,INT_MAX);
  vector<int>parent(V);
  vector<bool>visited(V,false);
  priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>>q;
  q.push({0,0});//valtance,source;
  //NO need for visited array
  val[0]=0;
  parent[0]=-1; //strarting point;

  for(int i=0 ; i<V ; i++)
  {
    int minval=q.top().first;
    int prev=q.top().second;
    visited[prev]=true;
    q.pop();
    for(auto x : adj[prev])
    {
      if(visited[x.first]==false && x.second < val[x.first])
      {
        val[x.first] = x.second;
        q.push({val[x.first], x.first});
         parent[x.first]=prev;
      }
    }
  }
  return parent;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<pair<int,int>>adj[nodes];
  GraphInput(edge,adj);
  //printGraph(adj,nodes);
  for(auto e:PrimsAlgorithm(nodes,adj))
  cout<<e<<" ";
}
