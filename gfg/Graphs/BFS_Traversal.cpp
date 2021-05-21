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
vector<int>BFS_Graph(int V, vector<int> adj[])
{
  vector<int>ans;
  vector<bool>vis(V,false);
  for(int i=0 ; i<V ;i++)
  {
    if(vis[i]==false)
    {
      queue<int>q;
      q.push(i);
      vis[i]=true;
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
  for(auto e: BFS_Graph(nodes,adj))
  cout<<e<<" ";
}
