#include<bits/stdc++.h>
using namespace std;
//by using tarjans Algorithm;
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

void DFS(int v, vector<int>adj[], vector<int>&disc, vector<int>&low,
            vector<int>&parent, vector<pair<int,int>>&ans)
{
  static int time=0;
  disc[v]=low[v]=time;
  time++;
  for(auto e:adj[v])
  {
    if(disc[e]==-1 )
    {
      parent[e]=v;
      DFS(e,adj,disc,low,parent,ans);
      low[v]=min(low[v],low[e]);
      if(low[e]>disc[v])
        ans.push_back({v,e});
    }
    else if(e!=parent[v])
      low[v]=min(low[v],disc[e]);
  }
}

vector<pair<int,int>> tarjans(int V, vector<int> adj[])
{
  vector<int>disc(V,-1);//discovery Time;
  vector<int>low(V,-1);//Lowest discovery node available;
  vector<int>parent(V,-1);//elements present in stack;
  vector<pair<int,int>>ans;
  for(int i=0;i<V;i++)
  {
    if(disc[i]==-1)
    DFS(i,adj,disc,low,parent,ans);
  }
  return ans;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  vector<pair<int,int>>ans=tarjans(nodes,adj);
  for(auto e:ans)
  {
    cout<<e.first<<"  "<<e.second<<endl;
  }
}
