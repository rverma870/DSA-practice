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
// void printGraph(vector<int> adj[], int nodes)
// {
//   for(int i=0;i<nodes;i++)
//   {
//     cout<<i<<" -> ";
//     for(int j=0;j<adj[i].size();j++)
//     cout<<adj[i][j]<<" ";
//     cout<<endl;
//   }
// }
void DFS(int node , vector<bool>&vis , vector<int>adj[] ,vector<int>&ans)
{
  vis[node]=true;
  ans.push_back(node);
  for(auto e:adj[node])
  {
    if(vis[e]==false)
    {
      DFS(e,vis,adj,ans);

    }
  }
}
vector<int>DFS_Graph(int V, vector<int> adj[])
{
  vector<int>ans;
  vector<bool>vis(V,false);
  for(int i=0 ; i<V ;i++)
  {
    if(vis[i]==false)
    {
      DFS( i,vis,adj,ans);
    }
  }
  return ans;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  //printGraph(adj,nodes);
  for(auto e: DFS_Graph(nodes,adj))
  cout<<e<<" ";
}
