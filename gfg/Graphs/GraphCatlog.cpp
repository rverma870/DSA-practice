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
void printGraph(vector<int> adj[], int nodes)
{
  for(int i=0;i<nodes;i++)
  {
    cout<<i<<" -> ";
    for(int j=0;j<adj[i].size();j++)
    cout<<adj[i][j]<<" ";
    cout<<endl;
  }
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];//nodes or nodes +1 according to 1 or 0 based indexing respectively given in que;
  GraphInput(edge,adj);
  printGraph(adj,nodes);
}
