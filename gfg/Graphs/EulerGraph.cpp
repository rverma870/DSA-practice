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

void DFS(int u,vector<int>adj[],vector<bool>&vis)
{
  vis[u]=true;
  for(auto e:adj[u])
  {
    if(!vis[e])
    DFS(e,adj,vis);
  }
}
bool connected(int V, vector<int>adj[])
{
  int node=-1;//initial node for DFS to Start
  vector<bool>vis(V,false);
  for(int i=0;i<V;i++)
  {
    if(adj[i].size()>0)
    {
      node=i;
    }
  }
  if(node==-1)
  return false;//means no starting edge is found and every node has degree 0 or 1
              //therefore it is EULER circuit
  DFS(node,adj,vis);

  for(int i=0;i<V;i++)
  {
    if(!vis[i] && adj[i].size()>0)//checking for unvisited // nd unconnected egdes in all component with greater degree greater than 0
    return false;
  }
  return true;
}
void findEuler(int V, vector<int>adj[])
{
  if(!connected(V,adj))//checking if all the edges are present in one component only and if not its component must have degree 0;
    cout<<"NOT EULER"<<endl;
  int oddDegree=0;//number of nodes having odd degree
  for(int i=0;i<V;i++)
  {
    if(adj[i].size() & 1)
      oddDegree++;
  }
  if(oddDegree==0)
  cout<<"EULER CIRCUIT"<<endl;
  else if(oddDegree==2)
  cout<<"SEMI EULER CURCUIT"<<endl;
  else
  cout<<"NOT EULER CIRCUIT"<<endl;
}
int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];//nodes or nodes +1 according to 1 or 0 based indexing respectively given in que;
  GraphInput(edge,adj);
  findEuler(nodes,adj);
}
