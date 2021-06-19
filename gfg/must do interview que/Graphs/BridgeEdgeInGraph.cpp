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

bool flag=false;

void DFS(int v, vector<int>adj[], vector<int>&disc, vector<int>&low,
            vector<int>&parent, int c,int d)
{
  static int time=0;
  disc[v]=low[v]=time;
  time++;
  for(auto e:adj[v])
  {
    if(disc[e]==-1 )
    {
      parent[e]=v;
      DFS(e,adj,disc,low,parent,c,d);
      low[v]=min(low[v],low[e]);
      if(low[e]>disc[v])
      {
        if((v==c && e==d) || (v==d && e==c))
          flag=true;
      }
    }
    else if(e!=parent[v])
      low[v]=min(low[v],disc[e]);
  }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
  vector<int>disc(V,-1);//discovery Time;
  vector<int>low(V,-1);//Lowest discovery node available;
  vector<int>parent(V,-1);//elements present in stack;
  for(int i=0;i<V;i++)
  {
    if(disc[i]==-1)
    DFS(i,adj,disc,low,parent,c,d);
  }
  return flag;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  
  int c,d;
  cin>>c>>d;
  cout<<isBridge(nodes,adj,c,d);
}
